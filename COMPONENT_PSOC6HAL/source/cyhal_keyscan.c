/***************************************************************************//**
* \file cyhal_keyscan.c
*
* \brief
* Provides a high level interface for interacting with the Cypress KeyScan.
* This is a wrapper around the lower level PDL API.
*
********************************************************************************
* \copyright
* Copyright 2021 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "cyhal_keyscan.h"
#include "cyhal_gpio.h"
#include "cyhal_hwmgr.h"
#include "cyhal_system.h"
#include "cyhal_syspm.h"
#include "cyhal_utils.h"
#include "cyhal_clock.h"

#if defined (CY_IP_MXKEYSCAN)

#if defined(__cplusplus)
extern "C"
{
#endif

/* Internal defines */
#define _CYHAL_KEYSCAN_MAX_COLS         MXKEYSCAN_NUM_COLS_OUT
#define _CYHAL_KEYSCAN_MAX_ROWS         MXKEYSCAN_NUM_ROWS_IN

/* Internal prototypes */
static void _cyhal_keyscan_irq_handler(void);
static void _cyhal_keyscan_cb_wrapper(void);
static bool _cyhal_keyscan_pm_callback(cyhal_syspm_callback_state_t state, cyhal_syspm_callback_mode_t mode, void* callback_arg);

/* Default KeyScan configuration */
static const cy_stc_ks_config_t _cyhal_keyscan_default_config = {
    .macroDownDebCnt            = 3,
    .macroUpDebCnt              = 3,
    .microDebCnt                = 3,
    .noofRows                   = 0,
    .noofColumns                = 0,
    .ghostEnable                = true,
    .cpuWakeupEnable            = true,
    .clkStayOn                  = true
};

/* LPM transition callback data */
static cyhal_syspm_callback_data_t _cyhal_keyscan_syspm_callback_data =
{
    .callback = &_cyhal_keyscan_pm_callback,
    .states = (cyhal_syspm_callback_state_t)(CYHAL_SYSPM_CB_CPU_DEEPSLEEP | CYHAL_SYSPM_CB_SYSTEM_HIBERNATE),
    .next = NULL,
    .args = NULL,
    .ignore_modes = CYHAL_SYSPM_CHECK_READY
};

/* Record of init structs */
static cyhal_keyscan_t *_cyhal_keyscan_config_structs[1];

static void _cyhal_keyscan_irq_handler(void)
{
    cyhal_keyscan_t *obj = _cyhal_keyscan_config_structs[0];
    Cy_Keyscan_Interrupt_Handler(obj->base, &(obj->context));
}

static void _cyhal_keyscan_cb_wrapper(void)
{
    cyhal_keyscan_t *obj = _cyhal_keyscan_config_structs[0];
    uint32_t hal_event = CYHAL_KEYSCAN_EVENT_ACTION_DETECTED |
                        (obj->context.curNumElements == obj->context.maxNumElements) ? CYHAL_KEYSCAN_EVENT_BUFFER_FULL : 0;
    cyhal_keyscan_event_t anded_events = (cyhal_keyscan_event_t)(obj->irq_cause & hal_event);
    if (anded_events)
    {
        cyhal_keyscan_event_callback_t callback = (cyhal_keyscan_event_callback_t) obj->callback_data.callback;
        callback(obj->callback_data.callback_arg, anded_events);
    }
}

static bool _cyhal_keyscan_pm_callback(cyhal_syspm_callback_state_t state, cyhal_syspm_callback_mode_t mode, void* callback_arg)
{
    CY_UNUSED_PARAMETER(state);
    CY_UNUSED_PARAMETER(callback_arg);

    uint32_t readMask;
    cyhal_keyscan_t *obj = _cyhal_keyscan_config_structs[0];
    Cy_Keyscan_GetInterruptMask(obj->base, &readMask);

    switch(mode)
    {
        case CYHAL_SYSPM_AFTER_TRANSITION:
        {
            Cy_Keyscan_EnableClockStayOn(obj->base);
            Cy_Keyscan_SetInterruptMask(obj->base, readMask & ~MXKEYSCAN_INTR_KEY_EDGE_DONE);
            break;
        }
        case CYHAL_SYSPM_BEFORE_TRANSITION:
        {
            Cy_Keyscan_DisableClockStayOn(obj->base);
            Cy_Keyscan_SetInterruptMask(obj->base, readMask | MXKEYSCAN_INTR_KEY_EDGE_DONE);
            break;
        }
        default:
        {
            break;
        }
    }
    return true;
}

cy_rslt_t cyhal_keyscan_init(cyhal_keyscan_t *obj, uint8_t num_columns, const cyhal_gpio_t *columns,
                                uint8_t num_rows, const cyhal_gpio_t *rows, const cyhal_clock_t *clock)
{
    CY_ASSERT(NULL != obj);
    memset(obj, 0, sizeof(cyhal_keyscan_t));

    // Explicitly marked not allocated resources as invalid to prevent freeing them.
    obj->resource.type = CYHAL_RSC_INVALID;
    for (uint8_t idx=0; idx < _CYHAL_KEYSCAN_MAX_COLS; idx++) obj->columns[idx] = NC;
    for (uint8_t idx=0; idx < _CYHAL_KEYSCAN_MAX_ROWS; idx++) obj->rows[idx] = NC;

    cy_rslt_t result = CY_RSLT_SUCCESS;
    const cyhal_resource_pin_mapping_t *columns_map[_CYHAL_KEYSCAN_MAX_COLS];
    const cyhal_resource_pin_mapping_t *rows_map[_CYHAL_KEYSCAN_MAX_ROWS];

    if ((num_columns > _CYHAL_KEYSCAN_MAX_COLS) || (num_rows > _CYHAL_KEYSCAN_MAX_ROWS ))
        result = CYHAL_KEYSCAN_RSLT_ERR_INVALID_ARG;

    // Reserve the column pins
    for (uint8_t idx=0; idx < num_columns; idx++)
    {
        if (result == CY_RSLT_SUCCESS)
        {
            columns_map[idx] = _CYHAL_UTILS_GET_RESOURCE(columns[idx], cyhal_pin_map_keyscan_ks_col);
            result = (columns_map[idx] == NULL) ? CYHAL_KEYSCAN_RSLT_ERR_INVALID_PIN : CY_RSLT_SUCCESS;
            if (result == CY_RSLT_SUCCESS)
            {
                result = _cyhal_utils_reserve_and_connect(columns[idx], columns_map[idx]);
                if (result == CY_RSLT_SUCCESS)
                    obj->columns[idx] = columns[idx];
            }
        }
    }

    // Reserve the row pins
    for (uint8_t idx=0; idx < num_rows; idx++)
    {
        if (result == CY_RSLT_SUCCESS)
        {
            rows_map[idx] = _CYHAL_UTILS_GET_RESOURCE(rows[idx], cyhal_pin_map_keyscan_ks_row);
            result = (rows_map[idx] == NULL) ? CYHAL_KEYSCAN_RSLT_ERR_INVALID_PIN : CY_RSLT_SUCCESS;
            if (result == CY_RSLT_SUCCESS)
            {
                result = _cyhal_utils_reserve_and_connect(rows[idx], rows_map[idx]);
                if (result == CY_RSLT_SUCCESS)
                    obj->rows[idx] = rows[idx];
            }
        }
    }

    // Clock allocation
    if (result == CY_RSLT_SUCCESS)
    {
        if (clock == NULL)
        {
            cyhal_clock_t clock_keyscan;
            cyhal_clock_get(&clock_keyscan, &CYHAL_CLOCK_MF);
            obj->clock = clock_keyscan;
        }
        else
        {
            /* This implementation does not support custom clocks */
            result = CYHAL_KEYSCAN_RSLT_ERR_INVALID_ARG;
        }
    }

    // KeyScan block configuration
    if (result == CY_RSLT_SUCCESS)
    {
        cy_stc_ks_config_t config = _cyhal_keyscan_default_config;
        config = _cyhal_keyscan_default_config;
        config.noofRows = num_rows;
        config.noofColumns = num_columns;

        result = Cy_Keyscan_Init(obj->base, &config, &(obj->context));
        if (result == CY_RSLT_SUCCESS)
            result = Cy_Keyscan_Enable(obj->base, &(obj->context));
    }

    // Interrupt configuration
    if (result == CY_RSLT_SUCCESS)
    {
        _cyhal_keyscan_config_structs[0] = obj;
        _cyhal_syspm_register_peripheral_callback(&_cyhal_keyscan_syspm_callback_data);

        obj->callback_data.callback = NULL;
        obj->callback_data.callback_arg = NULL;
        obj->irq_cause = CYHAL_KEYSCAN_EVENT_NONE;

        cy_stc_sysint_t irqCfg = { keyscan_interrupt_IRQn, CYHAL_ISR_PRIORITY_DEFAULT };
        Cy_SysInt_Init(&irqCfg, _cyhal_keyscan_irq_handler);
        NVIC_EnableIRQ(irqCfg.intrSrc);
    }

    if (result != CY_RSLT_SUCCESS)
    {
        cyhal_keyscan_free(obj);
    }

    return result;
}

void cyhal_keyscan_free(cyhal_keyscan_t *obj)
{
    CY_ASSERT(NULL != obj);

    if (obj->resource.type != CYHAL_RSC_INVALID)
    {
        _cyhal_keyscan_config_structs[0] = NULL;
        NVIC_DisableIRQ(keyscan_interrupt_IRQn);
        Cy_Keyscan_Disable(obj->base, &(obj->context));
        Cy_Keyscan_DeInit(obj->base, &(obj->context));
        cyhal_hwmgr_free(&(obj->resource));
    }
    // Free the column pins
    for (uint8_t idx=0; idx < _CYHAL_KEYSCAN_MAX_COLS; idx++)
    {
        _cyhal_utils_release_if_used(&(obj->columns[idx]));
    }
    // Free the row pins
    for (uint8_t idx=0; idx < _CYHAL_KEYSCAN_MAX_ROWS; idx++)
    {
        _cyhal_utils_release_if_used(&(obj->columns[idx]));
    }
}

cy_rslt_t cyhal_keyscan_read(cyhal_keyscan_t *obj, uint8_t* count, cyhal_keyscan_action_t* keys)
{
    cy_en_ks_status_t status = CY_KEYSCAN_SUCCESS;
    bool eventFlag = true;
    uint8_t eventCount = 0;
    cy_stc_key_event eventNext;

    while ((eventFlag) && (eventCount <= *count))
    {
        status = Cy_Keyscan_EventsPending(obj->base, &eventFlag, &(obj->context));
        if ((eventFlag) && (status == CY_KEYSCAN_SUCCESS))
            status = Cy_Keyscan_GetNextEvent(obj->base, &eventNext, &(obj->context));
        if (status == CY_KEYSCAN_SUCCESS)
        {
            // Note: Discard eventNext.scanCycleFlag
            keys[eventCount].keycode = eventNext.keyCode;
            keys[eventCount].action = (eventNext.upDownFlag == 0)
                ? CYHAL_KEYSCAN_ACTION_PRESS
                : CYHAL_KEYSCAN_ACTION_RELEASE;
            eventCount++;
        }
        else
            break;
    }
    *count = eventCount;

    return status;
}

void cyhal_keyscan_register_callback(cyhal_keyscan_t *obj, cyhal_keyscan_event_callback_t callback, void *callback_arg)
{
    uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
    obj->callback_data.callback = (cy_israddress) callback;
    obj->callback_data.callback_arg = callback_arg;
    obj->irq_cause = CYHAL_KEYSCAN_EVENT_NONE;
    cyhal_system_critical_section_exit(savedIntrStatus);
    Cy_Keyscan_Register_Callback(_cyhal_keyscan_cb_wrapper, &(obj->context));
}

void cyhal_keyscan_enable_event(cyhal_keyscan_t *obj, cyhal_keyscan_event_t event, uint8_t intr_priority, bool enable)
{
    uint32_t readMask;

    if (enable)
    {
        obj->irq_cause |= event;
        // Both events rely on FIFO threshold interrupt. Enable in both cases.
        if ((event & CYHAL_KEYSCAN_EVENT_ACTION_DETECTED) || (event & CYHAL_KEYSCAN_EVENT_BUFFER_FULL))
        {
            Cy_Keyscan_ClearInterrupt(obj->base, MXKEYSCAN_INTR_FIFO_THRESH_DONE);
            Cy_Keyscan_GetInterruptMask(obj->base, &readMask);
            Cy_Keyscan_SetInterruptMask(obj->base, readMask | MXKEYSCAN_INTR_FIFO_THRESH_DONE);
        }
    }
    else
    {
        obj->irq_cause &= ~event;
        // Both events rely on FIFO threshold interrupt. Only disable if we don't need either.
        if (obj->irq_cause == CYHAL_KEYSCAN_EVENT_NONE)
        {
            Cy_Keyscan_GetInterruptMask(obj->base, &readMask);
            Cy_Keyscan_SetInterruptMask(obj->base, readMask & ~MXKEYSCAN_INTR_FIFO_THRESH_DONE);
        }
    }

    NVIC_SetPriority(keyscan_interrupt_IRQn, intr_priority);
}

#if defined(__cplusplus)
}
#endif

#endif /* CY_IP_MXKEYSCAN */
