/*******************************************************************************
* File Name: cyhal_audio_common.c
*
* Description:
* Provides common functionality for the I2S and TDM audio drivers.
*
********************************************************************************
* \copyright
* Copyright 2018-2021 Cypress Semiconductor Corporation
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

#include <math.h>
#include <stdlib.h>
#include <string.h> // For memset
#include "cyhal_clock.h"
#include "cyhal_gpio.h"
#include "cyhal_hw_resources.h"
#include "cyhal_hwmgr.h"
#include "cyhal_utils.h"
#include "cyhal_dma.h"
#include "cyhal_syspm.h"
#include "cy_device.h"
#include "cyhal_audio_common.h"
#include "cyhal_system.h"

#if defined(CY_IP_MXAUDIOSS) || defined(CY_IP_MXTDM)

#if defined(__cplusplus)
extern "C"
{
#endif

#define _CYHAL_AUDIOSS_MAX_CHANNEL_LENGTH (32u)

#if defined(CY_IP_MXAUDIOSS)
static cy_rslt_t _cyhal_audioss_convert_length(uint8_t user_length, cy_en_i2s_len_t *pdl_length, const _cyhal_audioss_t *obj);
#define _CYHAL_AUDIOSS_FIFO_DEPTH (256)

#define _CYHAL_AUDIOSS_TX_SCK_MAP cyhal_pin_map_audioss_tx_sck
#define _CYHAL_AUDIOSS_TX_WS_MAP  cyhal_pin_map_audioss_tx_ws
#define _CYHAL_AUDIOSS_TX_SDO_MAP cyhal_pin_map_audioss_tx_sdo
#define _CYHAL_AUDIOSS_RX_SCK_MAP cyhal_pin_map_audioss_rx_sck
#define _CYHAL_AUDIOSS_RX_WS_MAP  cyhal_pin_map_audioss_rx_ws
#define _CYHAL_AUDIOSS_RX_SDI_MAP cyhal_pin_map_audioss_rx_sdi
#define _CYHAL_AUDIOSS_MCLK_MAP   cyhal_pin_map_audioss_clk_i2s_if

static I2S_Type *const _cyhal_audioss_base[] =
{
#if (CY_IP_MXAUDIOSS_INSTANCES == 1 && defined(AUDIOSS_I2S) && AUDIOSS_I2S)
    I2S,
#elif (CY_IP_MXAUDIOSS_INSTANCES >= 1 && defined(AUDIOSS0_I2S) && AUDIOSS0_I2S)
    I2S0,
#endif
#if (CY_IP_MXAUDIOSS_INSTANCES >= 2 && defined(AUDIOSS1_I2S) && AUDIOSS1_I2S)
    I2S1,
#endif

#if (CY_IP_MXS40AUDIOSS_INSTANCES > 2)
    #warning Unhandled audioss instance count
#endif
};

static _cyhal_audioss_t* _cyhal_audioss_config_structs[CY_IP_MXAUDIOSS_INSTANCES];

static const IRQn_Type _cyhal_audioss_irq_n[] =
{
#if (CY_IP_MXAUDIOSS_INSTANCES == 1 && defined(AUDIOSS_I2S) && AUDIOSS_I2S) // Without index suffix
    audioss_interrupt_i2s_IRQn,
#elif (CY_IP_MXAUDIOSS_INSTANCES >= 1 && defined(AUDIOSS0_I2S) && AUDIOSS0_I2S)
    audioss_0_interrupt_i2s_IRQn,
#endif
#if (CY_IP_MXAUDIOSS_INSTANCES >= 2 && defined(AUDIOSS1_I2S) && AUDIOSS1_I2S)
    audioss_1_interrupt_i2s_IRQn,
#endif

#if (CY_IP_MXS40AUDIOSS_INSTANCES > 2)
    #warning Unhandled audioss instance count
#endif
};

static uint8_t _cyhal_audioss_get_block_from_irqn(IRQn_Type irqn)
{
    switch (irqn)
    {
#if (CY_CPU_CORTEX_M4)
#if (CY_IP_MXAUDIOSS_INSTANCES == 1 && defined(AUDIOSS_I2S) && AUDIOSS_I2S) // Without index suffix
        case audioss_interrupt_i2s_IRQn:
            return 0;
#elif (CY_IP_MXAUDIOSS_INSTANCES >= 1 && defined(AUDIOSS0_I2S) && AUDIOSS0_I2S)
        case audioss_0_interrupt_i2s_IRQn:
            return 0;
#endif
#if (CY_IP_MXAUDIOSS_INSTANCES >= 2 && defined(AUDIOSS1_I2S) && AUDIOSS1_I2S)
        case audioss_1_interrupt_i2s_IRQn:
            return 1;
#endif
#if (CY_IP_MXS40AUDIOSS_INSTANCES > 2)
    #warning Unhandled audioss instance count
#endif
#endif /* (CY_CPU_CORTEX_M4) */
        default:
            CY_ASSERT(false); // Should never be called with a non-I2S IRQn
            return 0;
    }
}

static void _cyhal_audioss_irq_handler(void);
typedef cy_stc_i2s_config_t _cyhal_audioss_pdl_config_t;

#elif defined(CY_IP_MXTDM) && (CY_IP_MXTDM_INSTANCES > 0)
#define _CYHAL_AUDIOSS_FIFO_DEPTH (128)

#define _CYHAL_AUDIOSS_TX_SCK_MAP cyhal_pin_map_tdm_tdm_tx_sck
#define _CYHAL_AUDIOSS_TX_WS_MAP  cyhal_pin_map_tdm_tdm_tx_fsync
#define _CYHAL_AUDIOSS_TX_SDO_MAP cyhal_pin_map_tdm_tdm_tx_sd
#define _CYHAL_AUDIOSS_RX_SCK_MAP cyhal_pin_map_tdm_tdm_rx_sck
#define _CYHAL_AUDIOSS_RX_WS_MAP  cyhal_pin_map_tdm_tdm_rx_fsync
#define _CYHAL_AUDIOSS_RX_SDI_MAP cyhal_pin_map_tdm_tdm_rx_sd
/* Per cy_en_tdm_clock_sel_t, only TX mclk_in is selectable for both.
 * This is probably a bug in the PDL, will be updated as necessary
 * following the resolution of DRIVERS-5376
 */
#define _CYHAL_AUDIOSS_MCLK_MAP   cyhal_pin_map_tdm_tdm_tx_mck

#define Cy_I2S_Init           Cy_AudioTDM_Init
#define Cy_I2S_DeInit         Cy_AudioTDM_DeInit

static cy_rslt_t _cyhal_audioss_convert_length(uint8_t user_length, cy_en_tdm_ws_t *pdl_length, const _cyhal_audioss_t *obj);

static TDM_Type *const _cyhal_audioss_base[] =
{
#if (CY_IP_MXTDM_INSTANCES == 1)
    TDM0,
#else
    #warning Unhandled tdm instance count
#endif
};

static const uint8_t _cyhal_audioss_max_channels[] =
{
#if (CY_IP_MXTDM_INSTANCES == 1)
    #if (TDM_NR == 1)
        TDM_NR_CH_NR,
    #elif (TDM_NR == 2)
        TDM_NR0_CH_NR,
        TDM_NR1_CH_NR,
    #else
        #warning Unhandled TDM struct count
    #endif
#else
    #warning Unhandled tdm instance count
#endif
};

#define _CYHAL_AUDIOSS_USES_PCLK
static const en_clk_dst_t _cyhal_audioss_clock[] =
{
#if (CY_IP_MXTDM_INSTANCES == 1)
    PCLK_TDM0_CLK_IF_SRSS0,
#else
    #warning Unhandled tdm instance count
#endif
};

static _cyhal_audioss_t* _cyhal_audioss_config_structs[CY_IP_MXTDM_INSTANCES];

static const IRQn_Type _cyhal_audioss_tx_irq_n[] =
{
#if (CY_IP_MXTDM_INSTANCES == 1)
    tdm_0_interrupts_tx_0_IRQn,
#else
    #warning Unhandled tdm instance count
#endif
};

static const IRQn_Type _cyhal_audioss_rx_irq_n[] =
{
#if (CY_IP_MXTDM_INSTANCES == 1)
    tdm_0_interrupts_rx_0_IRQn,
#else
    #warning Unhandled tdm instance count
#endif
};

static uint8_t _cyhal_audioss_get_block_from_irqn(IRQn_Type irqn) {
    switch (irqn)
    {
#if (CY_IP_MXTDM_INSTANCES == 1)
        case tdm_0_interrupts_tx_0_IRQn:
        case tdm_0_interrupts_rx_0_IRQn:
            return 0;
#else
    #warning Unhandled tdm instance count
#endif
        default:
            CY_ASSERT(false); // Should never be called with a non-TDM IRQn
            return 0;
    }
}

static void _cyhal_audioss_irq_handler_rx(void);
static void _cyhal_audioss_irq_handler_tx(void);
typedef cy_stc_tdm_config_t _cyhal_audioss_pdl_config_t;

#else
#error "Unrecognized audio IP"
#endif

#define _CYHAL_AUDIOSS_DMA_BURST_SIZE (_CYHAL_AUDIOSS_FIFO_DEPTH / 2)
static void _cyhal_audioss_update_enabled_events(_cyhal_audioss_t* obj);
static void _cyhal_audioss_process_event(_cyhal_audioss_t *obj, uint32_t event);
static void _cyhal_audioss_update_rx_trigger_level(_cyhal_audioss_t* obj);
static uint32_t _cyhal_audioss_disable_events(_cyhal_audioss_t *obj, bool tx);
static void _cyhal_audioss_restore_events(_cyhal_audioss_t *obj, bool tx, uint32_t old_events);
static cy_rslt_t _cyhal_audioss_dma_perform_rx(_cyhal_audioss_t *obj);
static cy_rslt_t _cyhal_audioss_dma_perform_tx(_cyhal_audioss_t *obj);
static void _cyhal_audioss_dma_handler_rx(void *callback_arg, cyhal_dma_event_t event);
static void _cyhal_audioss_dma_handler_tx(void *callback_arg, cyhal_dma_event_t event);
static uint8_t _cyhal_audioss_rounded_word_length(_cyhal_audioss_t *obj);
static bool _cyhal_audioss_pm_callback(cyhal_syspm_callback_state_t state, cyhal_syspm_callback_mode_t mode, void* callback_arg);
static cy_rslt_t _cyhal_audioss_populate_pdl_config(_cyhal_audioss_t *obj, _cyhal_audioss_pdl_config_t* pdl_config, uint16_t sclk_div);
static cy_rslt_t _cyhal_audioss_compute_sclk_div(_cyhal_audioss_t *obj, uint32_t sample_rate_hz, uint16_t *sclk_div);
static uint32_t _cyhal_audioss_get_num_in_fifo(_cyhal_audioss_t *obj, bool is_tx);
static uint32_t _cyhal_audioss_read_fifo(_cyhal_audioss_t *obj);
static void _cyhal_audioss_write_fifo(_cyhal_audioss_t *obj, uint32_t value);

cy_rslt_t _cyhal_audioss_init(_cyhal_audioss_t *obj, const _cyhal_audioss_pins_t* tx_pins, const _cyhal_audioss_pins_t* rx_pins, cyhal_gpio_t mclk, const _cyhal_audioss_config_t* config, cyhal_clock_t* clk, const _cyhal_audioss_interface_t* interface)
{
    CY_ASSERT(NULL != obj);
    memset(obj, 0, sizeof(_cyhal_audioss_t));
    /* Explicitly marked not allocated resources as invalid to prevent freeing them. */
    obj->resource.type = CYHAL_RSC_INVALID;
    obj->pin_tx_sck    = CYHAL_NC_PIN_VALUE;
    obj->pin_tx_ws     = CYHAL_NC_PIN_VALUE;
    obj->pin_tx_sdo    = CYHAL_NC_PIN_VALUE;
    obj->pin_rx_sck    = CYHAL_NC_PIN_VALUE;
    obj->pin_rx_ws     = CYHAL_NC_PIN_VALUE;
    obj->pin_rx_sdi    = CYHAL_NC_PIN_VALUE;
    obj->pin_mclk      = CYHAL_NC_PIN_VALUE;

    obj->interface      = interface;
    obj->is_tx_slave    = config->is_tx_slave;
    obj->is_rx_slave    = config->is_rx_slave;
    obj->mclk_hz        = config->mclk_hz;
    obj->channel_length = config->channel_length;
    obj->word_length    = config->word_length;
    obj->sample_rate_hz = config->sample_rate_hz;
    obj->num_channels   = config->num_channels;
    obj->channel_mask   = config->channel_mask;
    obj->tx_ws_full     = config->tx_ws_full;
    obj->rx_ws_full     = config->rx_ws_full;
    obj->is_i2s         = config->is_i2s;

    /*
     * We will update this to owned later if appropriate - for now set to false
     * so we don't try to free if we fail before allocating a clock
     */
    obj->is_clock_owned = false;

    obj->user_enabled_events = 0u;

    obj->callback_data.callback = NULL;
    obj->callback_data.callback_arg = NULL;
    obj->async_mode = CYHAL_ASYNC_SW;
    obj->async_tx_buff = NULL;
    obj->async_rx_buff = NULL;
    obj->tx_dma.resource.type = CYHAL_RSC_INVALID;
    obj->rx_dma.resource.type = CYHAL_RSC_INVALID;

    cy_rslt_t result = CY_RSLT_SUCCESS;

    /* Determine which I2S instance to use */
    const cyhal_resource_pin_mapping_t *tx_sck_map = (NULL != tx_pins) ? _CYHAL_UTILS_GET_RESOURCE(tx_pins->sck, _CYHAL_AUDIOSS_TX_SCK_MAP) : NULL;
    const cyhal_resource_pin_mapping_t *tx_ws_map  = (NULL != tx_pins) ? _CYHAL_UTILS_GET_RESOURCE(tx_pins->ws, _CYHAL_AUDIOSS_TX_WS_MAP) : NULL;
    const cyhal_resource_pin_mapping_t *tx_sdo_map = (NULL != tx_pins) ? _CYHAL_UTILS_GET_RESOURCE(tx_pins->data, _CYHAL_AUDIOSS_TX_SDO_MAP) : NULL;

    const cyhal_resource_pin_mapping_t *rx_sck_map = (NULL != rx_pins) ? _CYHAL_UTILS_GET_RESOURCE(rx_pins->sck, _CYHAL_AUDIOSS_RX_SCK_MAP) : NULL;
    const cyhal_resource_pin_mapping_t *rx_ws_map  = (NULL != rx_pins) ? _CYHAL_UTILS_GET_RESOURCE(rx_pins->ws, _CYHAL_AUDIOSS_RX_WS_MAP) : NULL;
    const cyhal_resource_pin_mapping_t *rx_sdi_map = (NULL != rx_pins) ? _CYHAL_UTILS_GET_RESOURCE(rx_pins->data, _CYHAL_AUDIOSS_RX_SDI_MAP) : NULL;

    const cyhal_resource_pin_mapping_t *mclk_map = _CYHAL_UTILS_GET_RESOURCE(mclk, _CYHAL_AUDIOSS_MCLK_MAP);

    if(NULL != tx_pins) /* It is valid to leave either tx or rx empty */
    {
        if(NULL != tx_sck_map && NULL != tx_ws_map && NULL != tx_sdo_map
            && _cyhal_utils_resources_equal_all(3, tx_sck_map->inst, tx_ws_map->inst, tx_sdo_map->inst))
        {
            obj->resource = *(tx_sck_map->inst);
        }
        else
        {
            result = obj->interface->err_invalid_pin;
        }
    }

    if(CY_RSLT_SUCCESS == result && NULL != rx_pins)
    {
        if(NULL == rx_sck_map || NULL == rx_ws_map || NULL == rx_sdi_map ||
            (false == _cyhal_utils_resources_equal_all(3, rx_sck_map->inst, rx_ws_map->inst, rx_sdi_map->inst)))
        {
            result = obj->interface->err_invalid_pin;
        }
        else
        {
            if((obj->resource.type != CYHAL_RSC_INVALID)
                && (false == _cyhal_utils_resources_equal(&(obj->resource), rx_sck_map->inst)))
            {
                /* TX pins and RX pins don't map to the same instance */
                result = obj->interface->err_invalid_pin;
            }
            obj->resource = *(rx_sck_map->inst);
        }
    }

    if(CYHAL_RSC_INVALID == obj->resource.type) /* If this happens it means neither rx nor tx was specified */
    {
        result = obj->interface->err_invalid_pin;
    }

    if(CY_RSLT_SUCCESS == result && CYHAL_NC_PIN_VALUE != mclk )
    {
        if(NULL == mclk_map || (false == _cyhal_utils_resources_equal(&(obj->resource), mclk_map->inst)))
        {
            result = obj->interface->err_invalid_pin;
        }
    }

#if defined(CY_IP_MXAUDIOSS)
    const uint8_t MAX_CHANNELS = 8u; /* I2S will already have limited to a lower count */
#elif defined(CY_IP_MXTDM)
    const uint8_t MAX_CHANNELS = _cyhal_audioss_max_channels[obj->resource.block_num];
#endif
    if(CY_RSLT_SUCCESS == result && obj->num_channels > MAX_CHANNELS)
    {
        result = obj->interface->err_invalid_arg;
    }

#if defined(CY_IP_MXAUDIOSS)
    // This IP doesn't support disabling individual channels, just reducing the overall count
    for(size_t i = 0; i < sizeof(obj->channel_mask) * 8 /* bits per byte */; ++i)
    {
        bool chan_enabled = (0u != (obj->channel_mask & (1u << i)));
        bool is_selected_channel = (i < obj->num_channels);
        if(is_selected_channel != chan_enabled)
        {
            result = obj->interface->err_invalid_arg;
            break;
        }
    }
#endif

    if(CY_RSLT_SUCCESS == result)
    {
        result = cyhal_hwmgr_reserve(&(obj->resource));
#if defined(CY_IP_MXAUDIOSS)
        obj->base = _cyhal_audioss_base[obj->resource.block_num];
#elif defined(CY_IP_MXTDM)
        obj->base = &(_cyhal_audioss_base[obj->resource.block_num]->TDM_STRUCT[obj->resource.channel_num]);
#endif
    }

    if(CY_RSLT_SUCCESS != result)
    {
        // If we aren't successful by here, we didn't manage to reserve the hardware resource,
        // so mark it as invalid to ensure it isn't incorrectly freed.
        obj->resource.type = CYHAL_RSC_INVALID;
    }

    /* Reserve the pins */
    if(CY_RSLT_SUCCESS == result && NULL != tx_pins)
    {
        result = _cyhal_utils_reserve_and_connect(tx_pins->sck, tx_sck_map);
        if(CY_RSLT_SUCCESS == result)
        {
            obj->pin_tx_sck = tx_pins->sck;
            result = _cyhal_utils_reserve_and_connect(tx_pins->ws, tx_ws_map);
        }
        if(CY_RSLT_SUCCESS == result)
        {
            obj->pin_tx_ws = tx_pins->ws;
            result = _cyhal_utils_reserve_and_connect(tx_pins->data, tx_sdo_map);
        }
        if(CY_RSLT_SUCCESS == result)
        {
            obj->pin_tx_sdo = tx_pins->data;
        }

        // In slave mode, the clock and word select pins are inputs
        if(CY_RSLT_SUCCESS == result && obj->is_tx_slave)
        {
            result = cyhal_gpio_configure(obj->pin_tx_sck, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
            if(CY_RSLT_SUCCESS == result)
            {
                result = cyhal_gpio_configure(obj->pin_tx_ws, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
            }
        }
    }

    if(CY_RSLT_SUCCESS == result && NULL != rx_pins)
    {
        result = _cyhal_utils_reserve_and_connect(rx_pins->sck, rx_sck_map);
        if(CY_RSLT_SUCCESS == result)
        {
            obj->pin_rx_sck = rx_pins->sck;
            result = _cyhal_utils_reserve_and_connect(rx_pins->ws, rx_ws_map);
        }
        if(CY_RSLT_SUCCESS == result)
        {
            obj->pin_rx_ws = rx_pins->ws;
            result = _cyhal_utils_reserve_and_connect(rx_pins->data, rx_sdi_map);
        }
        if(CY_RSLT_SUCCESS == result)
        {
            obj->pin_rx_sdi = rx_pins->data;
        }

        // In slave mode, the clock and word select pins are inputs
        if(CY_RSLT_SUCCESS == result && obj->is_rx_slave)
        {
            result = cyhal_gpio_configure(obj->pin_rx_sck, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
            if(CY_RSLT_SUCCESS == result)
            {
                result = cyhal_gpio_configure(obj->pin_rx_ws, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
            }
        }
    }

    if(CY_RSLT_SUCCESS == result && CYHAL_NC_PIN_VALUE != mclk)
    {
        if(obj->mclk_hz == 0)
        {
            // Must specify mclk frequency when using mclk
            result = obj->interface->err_invalid_arg;
        }
        else
        {
            result = _cyhal_utils_reserve_and_connect(mclk, mclk_map);
            if(CY_RSLT_SUCCESS == result)
            {
                obj->pin_mclk = mclk;
            }
        }
    }

    if(CY_RSLT_SUCCESS == result && CYHAL_NC_PIN_VALUE == mclk)
    {
        // Must not specify mclk frequency when mclk pin is not in use
        if(obj->mclk_hz != 0)
        {
            result = obj->interface->err_invalid_arg;
        }
    }

    if(CY_RSLT_SUCCESS == result && obj->word_length > obj->channel_length)
    {
        // Word length must be less than or equal to channel length
        result = obj->interface->err_invalid_arg;
    }

    if(CY_RSLT_SUCCESS == result && obj->channel_length > _CYHAL_AUDIOSS_MAX_CHANNEL_LENGTH)
    {
        // Channel length on MXAUDIOSS is more restricted than this, but that is
        // checked in populate_pdl_config. There is also a lower bound of 4
        // on MXTDM but that is taken care of by the check above because
        // 8 bits is the smallest word length we support.
        result = obj->interface->err_invalid_arg;
    }


    if (CY_RSLT_SUCCESS == result)
    {
        if (clk != NULL)
        {
            obj->clock = *clk;
        }
        else if (CYHAL_NC_PIN_VALUE == mclk) // No need to reserve a clock if we're using the mclk pin
        {
            // The hardware is generally going to be hardwired to an hfclk, which has very limited divider options. In the event
            // that we're hooked up a PERI divider, we don't have any particular expectations about its width - so just ask for 8-bit or larger
            result = _cyhal_utils_allocate_clock(&(obj->clock), &(obj->resource), CYHAL_CLOCK_BLOCK_PERIPHERAL_16BIT, true);
            if(CY_RSLT_SUCCESS == result)
            {
                obj->is_clock_owned = true;
                result = cyhal_clock_set_enabled(&(obj->clock), true, true);
            }
        }
    }
#if defined(_CYHAL_AUDIOSS_USES_PCLK)
    // If we're not using MCLK, and we're using a peri divider, hook it up to ourself
    if (CY_RSLT_SUCCESS == result && CYHAL_NC_PIN_VALUE == mclk && obj->clock.block != CYHAL_CLOCK_BLOCK_HF)
    {
        en_clk_dst_t pclk = _cyhal_audioss_clock[obj->resource.block_num];
        if (CY_SYSCLK_SUCCESS != _cyhal_utils_peri_pclk_assign_divider(pclk, &(obj->clock)))
            result = obj->interface->err_clock;
    }
#endif

    uint16_t sclk_div;
    if(CY_RSLT_SUCCESS == result)
    {
        result = _cyhal_audioss_compute_sclk_div(obj, obj->sample_rate_hz, &sclk_div);
    }

    _cyhal_audioss_pdl_config_t pdl_config;
#if defined(CY_IP_MXTDM)
    cy_stc_tdm_config_tx_t tx_config;
    cy_stc_tdm_config_rx_t rx_config;
    pdl_config.tx_config = &tx_config;
    pdl_config.rx_config = &rx_config;
#endif
    if (CY_RSLT_SUCCESS == result)
    {
        result = _cyhal_audioss_populate_pdl_config(obj, &pdl_config, sclk_div);
    }

    if (CY_RSLT_SUCCESS == result)
    {
        result = (cy_rslt_t)Cy_I2S_Init(obj->base, &pdl_config);
    }

    if (CY_RSLT_SUCCESS == result)
    {
#if defined(CY_IP_MXTDM)
        // PDL init doesn't automatically enable the RX-TX sub-blocks
        if(pdl_config.tx_config->enable)
        {
            Cy_AudioTDM_EnableTx(&obj->base->TDM_TX_STRUCT);
        }
        if(pdl_config.rx_config->enable)
        {
            Cy_AudioTDM_EnableRx(&obj->base->TDM_RX_STRUCT);
        }
#endif
        /* No way to explicitly clear the FIFO on the TDM IP, but
         * it is cleared as a side effect of the FIFO being disabled
         * which it should be both at startup and after a free/init cycle
         */
#if defined(CY_IP_MXAUDIOSS)
        if(pdl_config.txEnabled)
        {
            Cy_I2S_ClearTxFifo(obj->base);
        }
        if(pdl_config.rxEnabled)
        {
            Cy_I2S_ClearRxFifo(obj->base);
        }
#endif

        obj->pm_callback.states = (cyhal_syspm_callback_state_t)(CYHAL_SYSPM_CB_CPU_DEEPSLEEP | CYHAL_SYSPM_CB_SYSTEM_HIBERNATE);
        obj->pm_callback.callback = &_cyhal_audioss_pm_callback;
        obj->pm_callback.next = NULL;
        obj->pm_callback.args = (void*)obj;
        obj->pm_callback.ignore_modes = CYHAL_SYSPM_BEFORE_TRANSITION;
        obj->pm_transition_ready = false;
        _cyhal_syspm_register_peripheral_callback(&(obj->pm_callback));

        _cyhal_audioss_config_structs[obj->resource.block_num] = obj;
#if defined(CY_IP_MXAUDIOSS)
        cy_stc_sysint_t irqCfg = { _cyhal_audioss_irq_n[obj->resource.block_num], CYHAL_ISR_PRIORITY_DEFAULT };
        Cy_SysInt_Init(&irqCfg, _cyhal_audioss_irq_handler);
        NVIC_EnableIRQ(_cyhal_audioss_irq_n[obj->resource.block_num]);
#elif defined(CY_IP_MXTDM)
        cy_stc_sysint_t irqCfgRx = { _cyhal_audioss_rx_irq_n[obj->resource.block_num], CYHAL_ISR_PRIORITY_DEFAULT };
        Cy_SysInt_Init(&irqCfgRx, _cyhal_audioss_irq_handler_rx);
        NVIC_EnableIRQ(_cyhal_audioss_rx_irq_n[obj->resource.block_num]);

        cy_stc_sysint_t irqCfgTx = { _cyhal_audioss_tx_irq_n[obj->resource.block_num], CYHAL_ISR_PRIORITY_DEFAULT };
        Cy_SysInt_Init(&irqCfgTx, _cyhal_audioss_irq_handler_tx);
        NVIC_EnableIRQ(_cyhal_audioss_tx_irq_n[obj->resource.block_num]);
#else
#error "Unrecognized audio IP"
#endif
    }

    if (CY_RSLT_SUCCESS != result)
    {
        _cyhal_audioss_free(obj);
    }
    return result;
}

void _cyhal_audioss_free(_cyhal_audioss_t *obj)
{
    CY_ASSERT(NULL != obj);

    if(CYHAL_RSC_INVALID != obj->resource.type)
    {
#if defined(CY_IP_MXAUDIOSS)
        IRQn_Type irqn = _cyhal_audioss_irq_n[obj->resource.block_num];
        NVIC_DisableIRQ(irqn);
#elif defined(CY_IP_MXTDM)
        IRQn_Type irqn = _cyhal_audioss_rx_irq_n[obj->resource.block_num];
        NVIC_DisableIRQ(irqn);
        irqn = _cyhal_audioss_tx_irq_n[obj->resource.block_num];
        NVIC_DisableIRQ(irqn);
#endif

        _cyhal_syspm_unregister_peripheral_callback(&(obj->pm_callback));
        _cyhal_audioss_stop_rx(obj);
        _cyhal_audioss_stop_tx(obj);

#if defined(CY_IP_MXTDM)
        Cy_AudioTDM_DisableTx(&obj->base->TDM_TX_STRUCT);
        Cy_AudioTDM_DisableRx(&obj->base->TDM_RX_STRUCT);
#endif
        cyhal_hwmgr_free(&(obj->resource));
        obj->base = NULL;
        obj->resource.type = CYHAL_RSC_INVALID;
    }

    _cyhal_utils_release_if_used(&(obj->pin_tx_sck));
    _cyhal_utils_release_if_used(&(obj->pin_tx_ws));
    _cyhal_utils_release_if_used(&(obj->pin_tx_sdo));
    _cyhal_utils_release_if_used(&(obj->pin_rx_sck));
    _cyhal_utils_release_if_used(&(obj->pin_rx_ws));
    _cyhal_utils_release_if_used(&(obj->pin_rx_sdi));
    _cyhal_utils_release_if_used(&(obj->pin_mclk));

    if(obj->is_clock_owned)
    {
        cyhal_clock_free(&(obj->clock));
    }

    if(CYHAL_RSC_INVALID != obj->rx_dma.resource.type)
    {
        cyhal_dma_free(&obj->rx_dma);
    }

    if(CYHAL_RSC_INVALID != obj->tx_dma.resource.type)
    {
        cyhal_dma_free(&obj->tx_dma);
    }
}

static cy_rslt_t _cyhal_audioss_compute_sclk_div(_cyhal_audioss_t *obj, uint32_t sample_rate_hz, uint16_t *sclk_div)
{
#if defined(CY_IP_MXAUDIOSS)
    const uint8_t SCLK_INCREMENT = 1;
    const uint8_t MIN_SCLK_DIVIDER = 1;
    const uint8_t MAX_SCLK_DIVIDER = 64; // Divider value internal to the I2S block
#elif defined(CY_IP_MXTDM)
    const uint8_t MIN_SCLK_DIVIDER = 2;
    const uint8_t SCLK_INCREMENT = 2; // Per PDL, should be set to an even value to ensure 50/50 duty cycle
    const uint16_t MAX_SCLK_DIVIDER = 256; // Divider value internal to the I2S block
#endif

    const cyhal_clock_tolerance_t SCLK_TOLERANCE = { .type = CYHAL_TOLERANCE_PERCENT, .value = 1 };
    uint32_t sclk_target = sample_rate_hz * obj->channel_length * obj->num_channels;
    *sclk_div = 0;

    if(obj->is_clock_owned)
    {
        // Try each of the divider values that we support internally, and see whether any of them gets us
        // within our tolerance of a frequency that our source clock can provide.
        for(uint16_t i = MIN_SCLK_DIVIDER; i <= MAX_SCLK_DIVIDER; i += SCLK_INCREMENT)
        {
#if defined(CY_IP_MXAUDIOSS)
            // This IP has a hard-wired 8x divider
            uint32_t desired_source_freq = sclk_target * i * 8;
#elif defined(CY_IP_MXTDM)
            uint32_t desired_source_freq = sclk_target * i;
#endif
            cy_rslt_t freq_result = _cyhal_utils_set_clock_frequency(&(obj->clock), desired_source_freq, &SCLK_TOLERANCE);
            if(CY_RSLT_SUCCESS == freq_result)
            {
                *sclk_div = i;
                break;
            }
        }
    }
    else // Using user-provided clock, or using the mclk pin
    {
        // We can't change the clock, so just check if it's within tolerance
#if defined(CY_IP_MXAUDIOSS)
        uint32_t desired_divided_freq = sclk_target * 8; // I2S hw has a hard-wired 8x divider
#elif defined(CY_IP_MXTDM)
        uint32_t desired_divided_freq = sclk_target;
#endif
        uint32_t actual_source_freq = (CYHAL_NC_PIN_VALUE == obj->pin_mclk) ? cyhal_clock_get_frequency(&obj->clock) : obj->mclk_hz;
        uint32_t best_divider = (actual_source_freq + (desired_divided_freq / 2)) / desired_divided_freq; // Round to nearest divider
        uint32_t desired_source_freq = desired_divided_freq * best_divider;
        uint32_t diff = (uint32_t)abs(_cyhal_utils_calculate_tolerance(SCLK_TOLERANCE.type, desired_source_freq, actual_source_freq));
        if(diff <= SCLK_TOLERANCE.value && best_divider <= MAX_SCLK_DIVIDER)
        {
            *sclk_div = (uint16_t)best_divider;
        }
    }

    return (0 == *sclk_div) ? obj->interface->err_clock : CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_set_sample_rate(_cyhal_audioss_t *obj, uint32_t sample_rate_hz)
{
    uint16_t sclk_div;
    _cyhal_audioss_pdl_config_t pdl_config;
#if defined(CY_IP_MXTDM)
    cy_stc_tdm_config_tx_t tx_config;
    cy_stc_tdm_config_rx_t rx_config;
    pdl_config.tx_config = &tx_config;
    pdl_config.rx_config = &rx_config;
#endif

    cy_rslt_t result = _cyhal_audioss_compute_sclk_div(obj, sample_rate_hz, &sclk_div);
    if(CY_RSLT_SUCCESS == result)
    {
        result = _cyhal_audioss_populate_pdl_config(obj, &pdl_config, sclk_div);
    }
    if(CY_RSLT_SUCCESS == result)
    {
        Cy_I2S_DeInit(obj->base);
        result = (cy_rslt_t)Cy_I2S_Init(obj->base, &pdl_config);
    }
    if(CY_RSLT_SUCCESS == result)
    {
        obj->sample_rate_hz = sample_rate_hz;
    }

    return result;
}

void _cyhal_audioss_enable_event(_cyhal_audioss_t *obj, uint32_t event, uint8_t intr_priority, bool enable)
{
    CY_ASSERT(NULL != obj);

    if (enable)
    {
        obj->user_enabled_events |= event;
    }
    else
    {
        obj->user_enabled_events &= ~event;
    }

    _cyhal_audioss_update_enabled_events(obj);
#if defined(CY_IP_MXAUDIOSS)
    IRQn_Type irqn = _cyhal_audioss_irq_n[obj->resource.block_num];
    NVIC_SetPriority(irqn, intr_priority);
#elif defined(CY_IP_MXTDM)
    IRQn_Type irqn = _cyhal_audioss_tx_irq_n[obj->resource.block_num];
    NVIC_SetPriority(irqn, intr_priority);
    irqn = _cyhal_audioss_rx_irq_n[obj->resource.block_num];
    NVIC_SetPriority(irqn, intr_priority);
#endif
}

cy_rslt_t _cyhal_audioss_start_tx(_cyhal_audioss_t *obj)
{
    if (obj->pm_transition_ready)
    {
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
    }
#if defined(CY_IP_MXAUDIOSS)
    Cy_I2S_EnableTx(obj->base);
#elif defined(CY_IP_MXTDM)
    Cy_AudioTDM_ActivateTx(&obj->base->TDM_TX_STRUCT);
#endif
    return CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_stop_tx(_cyhal_audioss_t *obj)
{
#if defined(CY_IP_MXAUDIOSS)
    Cy_I2S_DisableTx(obj->base);
#elif defined(CY_IP_MXTDM)
    // Not disable - that is more aggressive than we want
    Cy_AudioTDM_DeActivateTx(&obj->base->TDM_TX_STRUCT);
#endif
    return CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_clear_tx(_cyhal_audioss_t *obj)
{
#if defined(CY_IP_MXAUDIOSS)
    Cy_I2S_ClearTxFifo(obj->base);
#elif defined(CY_IP_MXTDM)
    /* No way to explicitly clear the FIFO, so disable and re-enable
     * which will clear the FIFO as a side effect, while retaining
     * all other configuration */
     bool was_active = _cyhal_audioss_is_tx_enabled(obj);
     Cy_AudioTDM_DisableTx(&obj->base->TDM_TX_STRUCT);
     Cy_AudioTDM_EnableTx(&obj->base->TDM_TX_STRUCT);
     if(was_active)
     {
         Cy_AudioTDM_ActivateTx(&obj->base->TDM_TX_STRUCT);
     }
#endif
    return CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_start_rx(_cyhal_audioss_t *obj)
{
    if (obj->pm_transition_ready)
    {
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
    }
#if defined(CY_IP_MXAUDIOSS)
    Cy_I2S_EnableRx(obj->base);
#elif defined(CY_IP_MXTDM)
    Cy_AudioTDM_ActivateRx(&obj->base->TDM_RX_STRUCT);
#endif
    return CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_stop_rx(_cyhal_audioss_t *obj)
{
#if defined(CY_IP_MXAUDIOSS)
    Cy_I2S_DisableRx(obj->base);
#elif defined(CY_IP_MXTDM)
    // Not disable - that is more aggressive than we want
    Cy_AudioTDM_DeActivateRx(&obj->base->TDM_RX_STRUCT);
#endif
    return CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_clear_rx(_cyhal_audioss_t *obj)
{
#if defined(CY_IP_MXAUDIOSS)
    Cy_I2S_ClearRxFifo(obj->base);
#elif defined(CY_IP_MXTDM)
    /* No way to explicitly clear the FIFO, so disable and re-enable
     * which will clear the FIFO as a side effect, while retaining
     * all other configuration */
     bool was_active = _cyhal_audioss_is_rx_enabled(obj);
     Cy_AudioTDM_DisableRx(&obj->base->TDM_RX_STRUCT);
     Cy_AudioTDM_EnableRx(&obj->base->TDM_RX_STRUCT);
     if(was_active)
     {
         Cy_AudioTDM_ActivateRx(&obj->base->TDM_RX_STRUCT);
     }
#endif
    return CY_RSLT_SUCCESS;
}

// Reads until empty, then updates the length and buffer address to their new locations
static void _cyhal_audioss_read_until_empty(_cyhal_audioss_t *obj, void** buffer, size_t* length)
{
    // The buffer is the smallest type that will hold the word length
    // The structure of this function deliberately accepts duplication of the outer loop
    // structure in order to avoid having to recheck the word length every time around,
    // because this function is in a performance sensitive code path.
    if(obj->word_length <= 8)
    {
        uint8_t *cast_buffer = (uint8_t*)(*buffer);

        while(*length > 0 && _cyhal_audioss_get_num_in_fifo(obj, false) > 0)
        {
            *cast_buffer = (uint8_t)_cyhal_audioss_read_fifo(obj);
            ++cast_buffer;
            --(*length);
        }
        *buffer = (void*)cast_buffer;
    }
    else if(obj->word_length <= 16)
    {
        uint16_t *cast_buffer = (uint16_t*)(*buffer);

        while(*length > 0 && _cyhal_audioss_get_num_in_fifo(obj, false) > 0)
        {
            *cast_buffer = (uint16_t)_cyhal_audioss_read_fifo(obj);
            ++cast_buffer;
            --(*length);
        }
        *buffer = (void*)cast_buffer;
    }
    else
    {
        CY_ASSERT(obj->word_length <= 32);
        uint32_t *cast_buffer = (uint32_t*)(*buffer);

        while(*length > 0 && _cyhal_audioss_get_num_in_fifo(obj, false) > 0)
        {
            *cast_buffer = _cyhal_audioss_read_fifo(obj);
            ++cast_buffer;
            --(*length);
        }
        *buffer = (void*)cast_buffer;
    }
}

cy_rslt_t _cyhal_audioss_read(_cyhal_audioss_t *obj, void *data, size_t* length)
{
    CY_ASSERT(NULL != obj);
    if (obj->pm_transition_ready)
    {
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
    }

    size_t remaining = *length;
    _cyhal_audioss_read_until_empty(obj, &data, &remaining);
    *length -= remaining;
    return CY_RSLT_SUCCESS;
}

static void _cyhal_audioss_write_until_full(_cyhal_audioss_t *obj, const void** buffer, size_t *length)
{
    // The buffer is the smallest type that will hold the word length
    // The structure of this function deliberately accepts duplication of the outer loop
    // structure in order to avoid having to recheck the word length every time around,
    // because this function is in a performance sensitive code path.
    if(obj->word_length <= 8)
    {
        const uint8_t *cast_buffer = (const uint8_t*)(*buffer);

        while(*length > 0 && _cyhal_audioss_get_num_in_fifo(obj, true) < _CYHAL_AUDIOSS_FIFO_DEPTH)
        {
            _cyhal_audioss_write_fifo(obj, *cast_buffer);
            ++cast_buffer;
            --(*length);
        }
        *buffer = (void*)cast_buffer;
    }
    else if(obj->word_length <= 16)
    {
        const uint16_t *cast_buffer = (const uint16_t*)(*buffer);

        while(*length > 0 && _cyhal_audioss_get_num_in_fifo(obj, true) < _CYHAL_AUDIOSS_FIFO_DEPTH)
        {
            _cyhal_audioss_write_fifo(obj, *cast_buffer);
            ++cast_buffer;
            --(*length);
        }
        *buffer = (void*)cast_buffer;
    }
    else
    {
        CY_ASSERT(obj->word_length <= 32);
        const uint32_t *cast_buffer = (const uint32_t*)(*buffer);

        while(*length > 0 && _cyhal_audioss_get_num_in_fifo(obj, true) < _CYHAL_AUDIOSS_FIFO_DEPTH)
        {
            _cyhal_audioss_write_fifo(obj, *cast_buffer);
            ++cast_buffer;
            --(*length);
        }
        *buffer = (void*)cast_buffer;
    }
}

cy_rslt_t _cyhal_audioss_write(_cyhal_audioss_t *obj, const void *data, size_t *length)
{
    CY_ASSERT(NULL != obj);
    if (obj->pm_transition_ready)
    {
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
    }

    size_t remaining = *length;
    _cyhal_audioss_write_until_full(obj, &data, &remaining);
    *length -= remaining;
    return CY_RSLT_SUCCESS;
}

bool _cyhal_audioss_is_tx_enabled(_cyhal_audioss_t *obj)
{
    CY_ASSERT(NULL != obj);

#if defined(CY_IP_MXAUDIOSS)
    return (0 != (CY_I2S_TX_START & Cy_I2S_GetCurrentState(obj->base)));
#elif(defined(CY_IP_MXTDM))
    return (0u != (TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_ACTIVE_Msk & obj->base->TDM_TX_STRUCT.TX_FIFO_CTL));
#endif
}

bool _cyhal_audioss_is_tx_busy(_cyhal_audioss_t *obj)
{
    CY_ASSERT(NULL != obj);

    return (0 != _cyhal_audioss_get_num_in_fifo(obj, true)) || _cyhal_audioss_is_write_pending(obj);
}

bool _cyhal_audioss_is_rx_enabled(_cyhal_audioss_t *obj)
{
    CY_ASSERT(NULL != obj);
#if defined(CY_IP_MXAUDIOSS)
    return (0 != (CY_I2S_RX_START & Cy_I2S_GetCurrentState(obj->base)));
#elif(defined(CY_IP_MXTDM))
    return (0u != (TDM_TDM_STRUCT_TDM_RX_STRUCT_RX_FIFO_CTL_ACTIVE_Msk & obj->base->TDM_RX_STRUCT.RX_FIFO_CTL));
#endif
}

bool _cyhal_audioss_is_rx_busy(_cyhal_audioss_t *obj)
{
    CY_ASSERT(NULL != obj);

    return (0 != _cyhal_audioss_get_num_in_fifo(obj, false)) || _cyhal_audioss_is_read_pending(obj);
}

cy_rslt_t _cyhal_audioss_read_async(_cyhal_audioss_t *obj, void *rx, size_t rx_length)
{
    CY_ASSERT(NULL != obj);
    if (obj->pm_transition_ready)
    {
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
    }

    uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
    obj->async_rx_buff = rx;
    obj->async_rx_length = rx_length;
    cyhal_system_critical_section_exit(savedIntrStatus);
    switch(obj->async_mode)
    {
        case CYHAL_ASYNC_SW:
        {
            /* Read as much as we can now, then set up an interrupt to do the rest
             * This is a potentially long operation but we don't want other I2S operations to
             * interleave with it. So do a "mini critical section" and disable the interrupts for this block only.
             */
            uint32_t old_events = _cyhal_audioss_disable_events(obj, false);
            // Safe to cast away volatile here because we're calling read_until_empty from within
            // a critical section, so it should not change out from under us during this call
            _cyhal_audioss_read_until_empty(obj, (void**)(&obj->async_rx_buff), (size_t*)(&obj->async_rx_length));
            _cyhal_audioss_update_rx_trigger_level(obj);
            _cyhal_audioss_restore_events(obj, false, old_events);
            if(obj->async_rx_length > 0)
            {
                _cyhal_audioss_update_enabled_events(obj);
            }
            else
            {
                _cyhal_audioss_process_event(obj, obj->interface->event_rx_complete);
            }
           break;
        }
        case CYHAL_ASYNC_DMA:
        {
            // Don't directly kick off the DMA here - it will be triggered
            // from the interrupt handler when the FIFO rised above the threshold
            // (which may have already happened by the time we get here if the
            // application already had the full or half-full event enabled)
            _cyhal_audioss_update_rx_trigger_level(obj);
            _cyhal_audioss_update_enabled_events(obj);
            break;
        }
        default:
           CY_ASSERT(0); /* Unrecognized async mode */
    }

    return CY_RSLT_SUCCESS;
}

static cy_rslt_t _cyhal_audioss_populate_pdl_config(_cyhal_audioss_t *obj, _cyhal_audioss_pdl_config_t* pdl_config, uint16_t sclk_div)
{
#if defined(CY_IP_MXAUDIOSS)
    cy_en_i2s_len_t pdl_word_length, pdl_channel_length;
    cy_rslt_t result = _cyhal_audioss_convert_length(obj->channel_length, &pdl_channel_length, obj);
    if (CY_RSLT_SUCCESS == result)
    {
        result = _cyhal_audioss_convert_length(obj->word_length, &pdl_word_length, obj);
    }

    if(CY_RSLT_SUCCESS == result)
    {
        pdl_config->txEnabled = (CYHAL_NC_PIN_VALUE != obj->pin_tx_sdo);
        pdl_config->rxEnabled = (CYHAL_NC_PIN_VALUE != obj->pin_rx_sdi);
        pdl_config->txDmaTrigger = false;
        pdl_config->rxDmaTrigger = false;
        pdl_config->clkDiv = (uint8_t)sclk_div;
        pdl_config->extClk = (CYHAL_NC_PIN_VALUE != obj->pin_mclk);
        pdl_config->txMasterMode = !obj->is_tx_slave;
        /* TDM mode A == channel data starts on rising edge of WS */
        pdl_config->txAlignment = obj->is_i2s ? CY_I2S_I2S_MODE : CY_I2S_TDM_MODE_A;
        pdl_config->txWsPulseWidth = obj->tx_ws_full
                                ? CY_I2S_WS_ONE_CHANNEL_LENGTH : CY_I2S_WS_ONE_SCK_CYCLE;
        pdl_config->txWatchdogEnable = false;
        pdl_config->txWatchdogValue = 0u;
        pdl_config->txSdoLatchingTime = false;
        pdl_config->txSckoInversion = false;
        pdl_config->txSckiInversion = false;
        pdl_config->txChannels = obj->num_channels;
        pdl_config->txChannelLength = pdl_channel_length;
        pdl_config->txWordLength = pdl_word_length;
        pdl_config->txOverheadValue = CY_I2S_OVHDATA_ZERO; /* Per HAL API specification */
        pdl_config->txFifoTriggerLevel = _CYHAL_AUDIOSS_FIFO_DEPTH / 2 + 1; /* Trigger at half empty */

        pdl_config->rxMasterMode = !obj->is_rx_slave;
        pdl_config->rxAlignment = obj->is_i2s ? CY_I2S_I2S_MODE : CY_I2S_TDM_MODE_A;
        pdl_config->rxWsPulseWidth = obj->rx_ws_full
                                ? CY_I2S_WS_ONE_CHANNEL_LENGTH : CY_I2S_WS_ONE_SCK_CYCLE;
        pdl_config->rxWatchdogEnable = false;
        pdl_config->rxWatchdogValue = 0u;
        pdl_config->rxSdiLatchingTime = false;
        pdl_config->rxSckoInversion = false;
        pdl_config->rxSckiInversion = false;
        pdl_config->rxChannels = obj->num_channels;
        pdl_config->rxChannelLength = pdl_channel_length;
        pdl_config->rxWordLength = pdl_word_length;
        pdl_config->rxSignExtension = false; /* All MSB are filled by zeros, per HAL API specification */
        pdl_config->rxFifoTriggerLevel = _CYHAL_AUDIOSS_FIFO_DEPTH / 2 - 1; // Trigger at half full
    }
#elif defined(CY_IP_MXTDM)
    cy_en_tdm_ws_t pdl_word_length;
    cy_rslt_t result = _cyhal_audioss_convert_length(obj->word_length, &pdl_word_length, obj);
    if(CY_RSLT_SUCCESS == result)
    {
        /* Configure TX */
        pdl_config->tx_config->enable = (CYHAL_NC_PIN_VALUE != obj->pin_tx_sdo);
        pdl_config->tx_config->masterMode = obj->is_tx_slave ? CY_TDM_DEVICE_SLAVE : CY_TDM_DEVICE_MASTER;
        pdl_config->tx_config->wordSize = pdl_word_length;
        pdl_config->tx_config->format = obj->is_i2s ? CY_TDM_LEFT_DELAYED : CY_TDM_LEFT;
        pdl_config->tx_config->clkDiv = sclk_div;
        /* Only clock 0 from the srss hooked up on current hardware */
        pdl_config->tx_config->clkSel = (CYHAL_NC_PIN_VALUE != obj->pin_mclk)
                                       ? CY_TDM_SEL_MCLK_IN : CY_TDM_SEL_SRSS_CLK0;
        pdl_config->tx_config->sckPolarity = CY_TDM_CLK;
        /* For I2S, frame sync aka word select starts out low */
        pdl_config->tx_config->fsyncPolarity = obj->is_i2s ? CY_TDM_SIGN_INVERTED : CY_TDM_SIGN;
        pdl_config->tx_config->fsyncFormat = obj->tx_ws_full ? CY_TDM_CH_PERIOD : CY_TDM_BIT_PERIOD;
        pdl_config->tx_config->channelNUM = obj->num_channels;
        pdl_config->tx_config->channelSize = obj->channel_length;
        pdl_config->tx_config->fifoTriggerLevel = _CYHAL_AUDIOSS_FIFO_DEPTH / 2 + 1; /* Trigger at half empty */
        pdl_config->tx_config->chEN = obj->channel_mask;
        pdl_config->tx_config->signalInput = 0; /* TX and RX signaling independent */
        pdl_config->tx_config->i2sMode = obj->is_i2s;

        /* Configure RX */
        pdl_config->rx_config->enable = (CYHAL_NC_PIN_VALUE != obj->pin_rx_sdi);
        pdl_config->rx_config->masterMode = obj->is_rx_slave ? CY_TDM_DEVICE_SLAVE : CY_TDM_DEVICE_MASTER;
        pdl_config->rx_config->wordSize = pdl_word_length;
        pdl_config->rx_config->format = obj->is_i2s ? CY_TDM_LEFT_DELAYED : CY_TDM_LEFT;
        pdl_config->rx_config->clkDiv = sclk_div;
        /* Only clock 0 from the srss hooked up on current hardware */
        /* Yes, this intentionally references TX when we are using MCLK. See DRIVERS-5376 */
        pdl_config->rx_config->clkSel = (CYHAL_NC_PIN_VALUE != obj->pin_mclk)
                                       ? CY_TDM_SEL_MCLK_IN : CY_TDM_SEL_SRSS_CLK0;
        pdl_config->rx_config->sckPolarity = CY_TDM_CLK;
        /* For I2S, frame sync aka word select starts out low */
        pdl_config->rx_config->fsyncPolarity = obj->is_i2s ? CY_TDM_SIGN_INVERTED : CY_TDM_SIGN;
        pdl_config->rx_config->fsyncFormat = obj->rx_ws_full ? CY_TDM_CH_PERIOD : CY_TDM_BIT_PERIOD;
        pdl_config->rx_config->channelNUM = obj->num_channels;
        pdl_config->rx_config->channelSize = obj->channel_length;
        pdl_config->rx_config->fifoTriggerLevel = _CYHAL_AUDIOSS_FIFO_DEPTH / 2 + 1; /* Trigger at half empty */
        pdl_config->rx_config->chEN = obj->channel_mask;
        pdl_config->rx_config->signalInput = 0; /* TX and RX signaling independent */
        pdl_config->rx_config->i2sMode = obj->is_i2s;
    }
#else
#error "Unrecognized audio IP"
#endif
    return result;
}

// Round up the word length to the next power of 2
static uint8_t _cyhal_audioss_rounded_word_length(_cyhal_audioss_t *obj)
{
    CY_ASSERT(obj->word_length <= 32);
    if(obj->word_length <= 8)
    {
        return 8u;
    }
    else if(obj->word_length <= 16)
    {
        return 16u;
    }

    return 32u;
}

cy_rslt_t _cyhal_audioss_write_async(_cyhal_audioss_t *obj, const void *tx, size_t tx_length)
{
    CY_ASSERT(NULL != obj);
    if (obj->pm_transition_ready)
    {
        return CYHAL_SYSPM_RSLT_ERR_PM_PENDING;
    }

    uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
    obj->async_tx_buff = tx;
    obj->async_tx_length = tx_length;
    cyhal_system_critical_section_exit(savedIntrStatus);
    switch(obj->async_mode)
    {
        case CYHAL_ASYNC_SW:
        {
            /* Write as much as we can now, then set up an interrupt to do the rest
            * This is a potentially long operation but we don't want other I2S operations to
            * interleave with it. So do a "mini critical section" and disable the interrupts for this block only.
            */
            uint32_t old_events = _cyhal_audioss_disable_events(obj, true);
            // Safe to cast away volatile here because we're calling write_until_full from within
            // a critical section, so it should not change out from under us during this call
            _cyhal_audioss_write_until_full(obj, (const void**)(&obj->async_tx_buff), (size_t *)(&obj->async_tx_length));
            _cyhal_audioss_restore_events(obj, true, old_events);
            if(obj->async_tx_length > 0)
            {
                _cyhal_audioss_update_enabled_events(obj);
            }
            else
            {
                _cyhal_audioss_process_event(obj, obj->interface->event_tx_complete);
            }
            break;
        }
        case CYHAL_ASYNC_DMA:
        {
            // Don't directly kick off the DMA here - it will be triggered
            // from the interrupt handler when the FIFO drops below the threshold
            // (which may have already happened by the time we get here if the
            // application already had the half-empty or empty event enabled)
            _cyhal_audioss_update_enabled_events(obj);
            break;
        }
        default:
            CY_ASSERT(0); /* Unrecognized async mode */
            break;
    }

    return CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_set_async_mode(_cyhal_audioss_t *obj, cyhal_async_mode_t mode, uint8_t dma_priority)
{
    CY_ASSERT(NULL != obj);
    // We don't support swapping the async mode out from under a pending transfer.
    CY_ASSERT(false == _cyhal_audioss_is_read_pending(obj) && false == _cyhal_audioss_is_write_pending(obj));

    cy_rslt_t result = CY_RSLT_SUCCESS;

    if(mode == CYHAL_ASYNC_DMA)
    {
        // Reserve a DMA channel for each direction that is enabled
        if(CYHAL_NC_PIN_VALUE != obj->pin_tx_sck && CYHAL_RSC_INVALID == obj->tx_dma.resource.type)
        {
            /* Reserve a DMA channel for async transmit if tx is enabled */
            result = cyhal_dma_init(&obj->tx_dma, CYHAL_DMA_PRIORITY_DEFAULT, CYHAL_DMA_DIRECTION_MEM2PERIPH);
            cyhal_dma_register_callback(&obj->tx_dma, &_cyhal_audioss_dma_handler_tx, obj);
        }
        if(mode == CYHAL_ASYNC_DMA && CYHAL_NC_PIN_VALUE != obj->pin_rx_sck && CYHAL_RSC_INVALID == obj->rx_dma.resource.type)
        {
            /* Reserve a DMA channel for async receive if rx is enabled */
            result = cyhal_dma_init(&obj->rx_dma, CYHAL_DMA_PRIORITY_DEFAULT, CYHAL_DMA_DIRECTION_PERIPH2MEM);
            cyhal_dma_register_callback(&obj->rx_dma, &_cyhal_audioss_dma_handler_rx, obj);
        }
    }
    else
    {
        /* Free the DMA instances if we reserved them but don't need them anymore */
        if(CYHAL_RSC_INVALID != obj->tx_dma.resource.type)
        {
            cyhal_dma_free(&obj->tx_dma);
            obj->tx_dma.resource.type = CYHAL_RSC_INVALID;
        }
        if(CYHAL_RSC_INVALID != obj->rx_dma.resource.type)
        {
            cyhal_dma_free(&obj->rx_dma);
            obj->rx_dma.resource.type = CYHAL_RSC_INVALID;
        }
    }

    if(CY_RSLT_SUCCESS == result)
    {
        obj->async_mode = mode;
        obj->async_dma_priority = dma_priority;
    }
    return result;
}

bool _cyhal_audioss_is_read_pending(_cyhal_audioss_t *obj)
{
    return (NULL != obj->async_rx_buff);
}

bool _cyhal_audioss_is_write_pending(_cyhal_audioss_t *obj)
{
    return (NULL != obj->async_tx_buff);
}

cy_rslt_t _cyhal_audioss_abort_read_async(_cyhal_audioss_t *obj)
{
    uint32_t saved_intr = cyhal_system_critical_section_enter();
    obj->async_rx_buff = NULL;
    _cyhal_audioss_update_enabled_events(obj);
    cyhal_system_critical_section_exit(saved_intr);
    return CY_RSLT_SUCCESS;
}

cy_rslt_t _cyhal_audioss_abort_write_async(_cyhal_audioss_t *obj)
{
    uint32_t saved_intr = cyhal_system_critical_section_enter();
    obj->async_tx_buff = NULL;
    _cyhal_audioss_update_enabled_events(obj);
    cyhal_system_critical_section_exit(saved_intr);
    return CY_RSLT_SUCCESS;
}

#if defined(CY_IP_MXAUDIOSS)
static cy_rslt_t _cyhal_audioss_convert_length(uint8_t user_length, cy_en_i2s_len_t *pdl_length, const _cyhal_audioss_t *obj)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    switch(user_length)
    {
        case 8u:
            *pdl_length = CY_I2S_LEN8;
            break;
        case 16u:
            *pdl_length = CY_I2S_LEN16;
            break;
        case 18u:
            *pdl_length = CY_I2S_LEN18;
            break;
        case 20u:
            *pdl_length = CY_I2S_LEN20;
            break;
        case 24u:
            *pdl_length = CY_I2S_LEN24;
            break;
        case 32u:
            *pdl_length = CY_I2S_LEN32;
            break;
        default:
            result = obj->interface->err_invalid_arg;
    }
    return result;
}
#elif defined(CY_IP_MXTDM)
static cy_rslt_t _cyhal_audioss_convert_length(uint8_t user_length, cy_en_tdm_ws_t *pdl_length, const _cyhal_audioss_t *obj)
{
    cy_rslt_t result = CY_RSLT_SUCCESS;
    switch(user_length)
    {
        case 8u:
            *pdl_length = CY_TDM_SIZE_8;
            break;
        case 10u:
            *pdl_length = CY_TDM_SIZE_10;
            break;
        case 12u:
            *pdl_length = CY_TDM_SIZE_12;
            break;
        case 14u:
            *pdl_length = CY_TDM_SIZE_14;
            break;
        case 16u:
            *pdl_length = CY_TDM_SIZE_16;
            break;
        case 18u:
            *pdl_length = CY_TDM_SIZE_18;
            break;
        case 20u:
            *pdl_length = CY_TDM_SIZE_20;
            break;
        case 24u:
            *pdl_length = CY_TDM_SIZE_24;
            break;
        case 32u:
            *pdl_length = CY_TDM_SIZE_32;
            break;
        default:
            result = obj->interface->err_invalid_arg;
    }
    return result;
}
#else
#error "Unrecognized audio IP"
#endif

#if defined(CY_IP_MXAUDIOSS)
void _cyhal_audioss_irq_handler()
{
    IRQn_Type irqn = _CYHAL_UTILS_GET_CURRENT_IRQN();
    uint8_t block = _cyhal_audioss_get_block_from_irqn(irqn);
    _cyhal_audioss_t* obj = _cyhal_audioss_config_structs[block];

    uint32_t interrupt_status = Cy_I2S_GetInterruptStatusMasked(obj->base);
    Cy_I2S_ClearInterrupt(obj->base, interrupt_status);
    uint32_t event = obj->interface->convert_interrupt_cause(interrupt_status);
    _cyhal_audioss_process_event(obj, event);
}
#elif defined(CY_IP_MXTDM)
void _cyhal_audioss_irq_handler_rx()
{
    IRQn_Type irqn = _CYHAL_UTILS_GET_CURRENT_IRQN();
    uint8_t block = _cyhal_audioss_get_block_from_irqn(irqn);
    _cyhal_audioss_t* obj = _cyhal_audioss_config_structs[block];

    uint32_t interrupt_status = Cy_AudioTDM_GetRxInterruptStatusMasked(&obj->base->TDM_RX_STRUCT);
    Cy_AudioTDM_ClearRxInterrupt(&obj->base->TDM_RX_STRUCT, interrupt_status);
    uint32_t event = obj->interface->convert_interrupt_cause(interrupt_status, false);
    _cyhal_audioss_process_event(obj, event);
}

void _cyhal_audioss_irq_handler_tx()
{
    IRQn_Type irqn = _CYHAL_UTILS_GET_CURRENT_IRQN();
    uint8_t block = _cyhal_audioss_get_block_from_irqn(irqn);
    _cyhal_audioss_t* obj = _cyhal_audioss_config_structs[block];

    uint32_t interrupt_status = Cy_AudioTDM_GetTxInterruptStatusMasked(&obj->base->TDM_TX_STRUCT);
    Cy_AudioTDM_ClearTxInterrupt(&obj->base->TDM_TX_STRUCT, interrupt_status);
    uint32_t event = obj->interface->convert_interrupt_cause(interrupt_status, true);
    _cyhal_audioss_process_event(obj, event);
}
#endif

static void _cyhal_audioss_update_enabled_events(_cyhal_audioss_t *obj)
{
    uint32_t events = obj->user_enabled_events;
    if(NULL != obj->async_tx_buff && obj->async_tx_length > 0)
    {
        events |= (obj->interface->event_mask_empty | obj->interface->event_mask_half_empty);
    }
    if(NULL != obj->async_rx_buff && obj->async_rx_length > 0)
    {
        events |= (obj->interface->event_mask_full | obj->interface->event_mask_half_full);
    }

#if defined(CY_IP_MXAUDIOSS)
    uint32_t mask = obj->interface->convert_to_pdl(events);
    // The register is 24 bits wide but the hardware pads the value out with 1's when read.
    // So mask down to just the bits that we actually care about.
    uint32_t old_mask = Cy_I2S_GetInterruptMask(obj->base) & CY_I2S_INTR_MASK;

    // Clear the interrupts that are about to be enabled to avoid spurious firing
    uint32_t new_interrupts = mask & (~old_mask);
    Cy_I2S_ClearInterrupt(obj->base, new_interrupts);

    Cy_I2S_SetInterruptMask(obj->base, mask);
#elif defined(CY_IP_MXTDM)
    uint32_t tx_mask = obj->interface->convert_to_pdl(events, true);
    // The register is 24 bits wide but the hardware pads the value out with 1's when read.
    // So mask down to just the bits that we actually care about.
    uint32_t old_tx_mask = Cy_AudioTDM_GetTxInterruptMask(&obj->base->TDM_TX_STRUCT);

    // Clear the interrupts that are about to be enabled to avoid spurious firing
    uint32_t new_interrupts_tx = tx_mask & (~old_tx_mask);
    Cy_AudioTDM_ClearTxInterrupt(&obj->base->TDM_TX_STRUCT, new_interrupts_tx);
    Cy_AudioTDM_SetTxInterruptMask(&obj->base->TDM_TX_STRUCT, tx_mask);

    uint32_t rx_mask = obj->interface->convert_to_pdl(events, false);
    // The register is 24 bits wide but the hardware pads the value out with 1's when read.
    // So mask down to just the bits that we actually care about.
    uint32_t old_rx_mask = Cy_AudioTDM_GetRxInterruptMask(&obj->base->TDM_RX_STRUCT);

    // Clear the interrupts that are about to be enabled to avoid spurious firing
    uint32_t new_interrupts_rx = rx_mask & (~old_rx_mask);
    Cy_AudioTDM_ClearRxInterrupt(&obj->base->TDM_RX_STRUCT, new_interrupts_rx);
    Cy_AudioTDM_SetRxInterruptMask(&obj->base->TDM_RX_STRUCT, rx_mask);
#endif
}

static void _cyhal_audioss_update_rx_trigger_level(_cyhal_audioss_t *obj)
{
    // If we're doing an async read and the amount remaining is less than
    // the standard trigger level, temporarily reduce it so that we get
    // an interrupt as soon as the amount the user requested is ready
    uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
    uint8_t trigger_level = _CYHAL_AUDIOSS_FIFO_DEPTH / 2;
    if(NULL != obj->async_rx_buff
       && obj->async_rx_length < trigger_level
       && obj->async_rx_length > 0)
    {
        trigger_level = obj->async_rx_length;
    }

#if defined(CY_IP_MXAUDIOSS)
    // Safe to do a blind write of this register because the only other bits are
    // CLEAR, which is only set temporarily from clear_tx, and FREEZE, which is
    // never used by this driver (it exists for debugging purposes only)
    obj->base->RX_FIFO_CTL = (trigger_level << I2S_RX_FIFO_CTL_TRIGGER_LEVEL_Pos);
#elif defined(CY_IP_MXTDM)
    uint32_t value = obj->base->TDM_RX_STRUCT.RX_FIFO_CTL;
    value &= ~TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Msk;
    value |= trigger_level << TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Pos;
    obj->base->TDM_RX_STRUCT.RX_FIFO_CTL = value;
#endif
    cyhal_system_critical_section_exit(savedIntrStatus);
}

static uint32_t _cyhal_audioss_disable_events(_cyhal_audioss_t *obj, bool tx)
{
#if defined(CY_IP_MXAUDIOSS)
    CY_UNUSED_PARAMETER(tx);
    uint32_t old_interrupt_mask = Cy_I2S_GetInterruptMask(obj->base);
    Cy_I2S_SetInterruptMask(obj->base, 0u);
    return old_interrupt_mask;
#elif defined(CY_IP_MXTDM)
    uint32_t old_interrupt_mask;
    if(tx)
    {
        old_interrupt_mask = Cy_AudioTDM_GetTxInterruptMask(&obj->base->TDM_TX_STRUCT);
        Cy_AudioTDM_SetTxInterruptMask(&obj->base->TDM_TX_STRUCT, 0u);
    }
    else
    {
        old_interrupt_mask = Cy_AudioTDM_GetRxInterruptMask(&obj->base->TDM_RX_STRUCT);
        Cy_AudioTDM_SetRxInterruptMask(&obj->base->TDM_RX_STRUCT, 0u);
    }
    return old_interrupt_mask;
#endif
}

static void _cyhal_audioss_restore_events(_cyhal_audioss_t *obj, bool tx, uint32_t old_events)
{
#if defined(CY_IP_MXAUDIOSS)
    CY_UNUSED_PARAMETER(tx);
    Cy_I2S_SetInterruptMask(obj->base, old_events);
#elif defined(CY_IP_MXTDM)
    if(tx)
    {
        Cy_AudioTDM_SetTxInterruptMask(&obj->base->TDM_TX_STRUCT, old_events);
    }
    else
    {
        Cy_AudioTDM_SetRxInterruptMask(&obj->base->TDM_RX_STRUCT, old_events);
    }
#endif
}

static cy_rslt_t _cyhal_audioss_dma_perform_rx(_cyhal_audioss_t *obj)
{
    // We could have received an event after we started the DMA but before it
    // managed to bring the FIFO below the threshold
    if(cyhal_dma_is_busy(&(obj->rx_dma)))
        return CY_RSLT_SUCCESS;
    size_t transfer_size = _CYHAL_AUDIOSS_DMA_BURST_SIZE;
    if (transfer_size >= obj->async_rx_length)
    {
        transfer_size = obj->async_rx_length;
        // Only want the user callback to be call on the last dma transfer.
        cyhal_dma_enable_event(&(obj->rx_dma), CYHAL_DMA_TRANSFER_COMPLETE, obj->async_dma_priority, true);
    }

    cyhal_dma_cfg_t dma_cfg =
    {
#if defined(CY_IP_MXAUDIOSS)
        .src_addr = (uint32_t)(&(obj->base->RX_FIFO_RD)),
#elif defined(CY_IP_MXTDM)
        .src_addr = (uint32_t)(&(obj->base->TDM_RX_STRUCT.RX_FIFO_RD)),
#endif
        .src_increment = 0,
        .dst_addr = (uint32_t)obj->async_rx_buff,
        .dst_increment = 1,
        .transfer_width = _cyhal_audioss_rounded_word_length(obj),
        .length = transfer_size,
        .burst_size = 0,
        .action = CYHAL_DMA_TRANSFER_FULL,
    };
    cy_rslt_t result = cyhal_dma_configure(&(obj->rx_dma), &dma_cfg);

    // Update the buffer first so that it's guaranteed to be correct whenever the DMA completes
    if(CY_RSLT_SUCCESS == result)
    {
        size_t increment_bytes = transfer_size * (_cyhal_audioss_rounded_word_length(obj) / 8);
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        obj->async_rx_buff = (void*)(((uint8_t*) obj->async_rx_buff) + increment_bytes);
        obj->async_rx_length -= transfer_size;
        _cyhal_audioss_update_rx_trigger_level(obj);
        _cyhal_audioss_update_enabled_events(obj);
        cyhal_system_critical_section_exit(savedIntrStatus);

        result = cyhal_dma_start_transfer(&(obj->rx_dma));
    }

    return result;
}

static cy_rslt_t _cyhal_audioss_dma_perform_tx(_cyhal_audioss_t *obj)
{
    // We could have received an event after the DMA brought the FIFO below the
    // threshold but before the DMA is entirely complete
    if(cyhal_dma_is_busy(&(obj->tx_dma)))
        return CY_RSLT_SUCCESS;

    CY_ASSERT(NULL != obj->async_tx_buff);

    size_t transfer_size = _CYHAL_AUDIOSS_DMA_BURST_SIZE;
    if (transfer_size >= obj->async_tx_length)
    {
        transfer_size = obj->async_tx_length;
        // Only want the user callback to be call on the last dma transfer.
        cyhal_dma_enable_event(&(obj->tx_dma), CYHAL_DMA_TRANSFER_COMPLETE, obj->async_dma_priority, true);
    }

    cyhal_dma_cfg_t dma_cfg =
    {
        .src_addr = (uint32_t)obj->async_tx_buff,
        .src_increment = 1,
#if defined(CY_IP_MXAUDIOSS)
        .dst_addr = (uint32_t)(&(obj->base->TX_FIFO_WR)),
#elif defined(CY_IP_MXTDM)
        .dst_addr = (uint32_t)(&(obj->base->TDM_TX_STRUCT.TX_FIFO_WR)),
#endif
        .dst_increment = 0,
        .transfer_width = _cyhal_audioss_rounded_word_length(obj),
        .length = transfer_size,
        .burst_size = 0,
        .action = CYHAL_DMA_TRANSFER_FULL,
    };
    cy_rslt_t result = cyhal_dma_configure(&(obj->tx_dma), &dma_cfg);

    // Update the buffer first so that it's guaranteed to be correct whenever the DMA completes
    if(CY_RSLT_SUCCESS == result)
    {
        size_t increment_bytes = transfer_size * (_cyhal_audioss_rounded_word_length(obj) / 8);
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        obj->async_tx_buff = (void*)(((uint8_t*) obj->async_tx_buff) + increment_bytes);
        obj->async_tx_length -= transfer_size;

        // Do this after we've updated async_tx_buff/length because once we have kicked
        // off the final DMA transfer there is no further action we will take on the
        // half-empty/empty events, and we don't want those to wind upstarving the
        // DMA complete event
        _cyhal_audioss_update_enabled_events(obj);
        cyhal_system_critical_section_exit(savedIntrStatus);

        result = cyhal_dma_start_transfer(&(obj->tx_dma));
    }

    return result;
}

static uint32_t _cyhal_audioss_get_num_in_fifo(_cyhal_audioss_t *obj, bool is_tx)
{
#if defined(CY_IP_MXAUDIOSS)
    return is_tx ? Cy_I2S_GetNumInTxFifo(obj->base) : Cy_I2S_GetNumInRxFifo(obj->base);
#elif defined(CY_IP_MXTDM)
    return is_tx ? Cy_AudioTDM_GetNumInTxFifo(&obj->base->TDM_TX_STRUCT)
                 : Cy_AudioTDM_GetNumInRxFifo(&obj->base->TDM_RX_STRUCT);
#endif
}

static uint32_t _cyhal_audioss_read_fifo(_cyhal_audioss_t *obj)
{
#if defined(CY_IP_MXAUDIOSS)
    return Cy_I2S_ReadRxData(obj->base);
#elif defined(CY_IP_MXTDM)
    return Cy_AudioTDM_ReadRxData(&obj->base->TDM_RX_STRUCT);
#endif
}

static void _cyhal_audioss_write_fifo(_cyhal_audioss_t *obj, uint32_t value)
{
#if defined(CY_IP_MXAUDIOSS)
    Cy_I2S_WriteTxData(obj->base, value);
#elif defined(CY_IP_MXTDM)
    Cy_AudioTDM_WriteTxData(&obj->base->TDM_TX_STRUCT, value);
#endif
}

/* Callback argument is the I2S instance */
static void _cyhal_audioss_dma_handler_rx(void *callback_arg, cyhal_dma_event_t event)
{
    CY_UNUSED_PARAMETER(event);
    /* We only hook this handler up when we're doing the final transfer, so send the completed event */
    CY_ASSERT(CYHAL_DMA_TRANSFER_COMPLETE == event);

    _cyhal_audioss_t *obj = (_cyhal_audioss_t*)callback_arg;
    obj->async_rx_buff = NULL;
    cyhal_dma_enable_event(&obj->rx_dma, CYHAL_DMA_TRANSFER_COMPLETE, obj->async_dma_priority, false);
    _cyhal_audioss_process_event(obj, obj->interface->event_rx_complete);
}

/* Callback argument is the I2S instance */
static void _cyhal_audioss_dma_handler_tx(void *callback_arg, cyhal_dma_event_t event)
{
    CY_UNUSED_PARAMETER(event);
    /* We only hook this handler up when we're doing the final transfer, so send the completed event */
    CY_ASSERT(CYHAL_DMA_TRANSFER_COMPLETE == event);

    _cyhal_audioss_t *obj = (_cyhal_audioss_t*)callback_arg;
    obj->async_tx_buff = NULL;
    cyhal_dma_enable_event(&obj->tx_dma, CYHAL_DMA_TRANSFER_COMPLETE, obj->async_dma_priority, false);
    _cyhal_audioss_process_event(obj, obj->interface->event_tx_complete);
}

static void _cyhal_audioss_process_event(_cyhal_audioss_t *obj, uint32_t event)
{
    if(0 != (event & (obj->interface->event_mask_empty | obj->interface->event_mask_half_empty)))
    {
        /* We should normally not get the "empty" interrupt during an async transfer because we
         * should be topping the FIFO back up after each half-empty interrupt. But in case something
         * delays our response and the FIFO gets all the way to empty, listen for that as well
         */
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        if(NULL != obj->async_tx_buff && obj->async_tx_length > 0)
        {
            switch(obj->async_mode)
            {
                case CYHAL_ASYNC_SW:
                {
                    /* Write as much as we can out until the FIFO is full
                     * This is a potentially long operation but we don't want other I2S operations to
                     * interleave with it. So switch to a "mini critical section" and disable the
                     * interrupts for this block only while we're copying
                     */
                    uint32_t old_events = _cyhal_audioss_disable_events(obj, true);
                    cyhal_system_critical_section_exit(savedIntrStatus);
                    // Safe to cast away volatile here because we're calling write_until_full from within
                    // a critical section, so it should not change out from under us during this call
                    _cyhal_audioss_write_until_full(obj, (const void**)(&obj->async_tx_buff), (size_t *)(&obj->async_tx_length));

                    // Re-enter the global critical section so that the exit below behaves correctly
                    savedIntrStatus = cyhal_system_critical_section_enter();
                    _cyhal_audioss_restore_events(obj, true, old_events);
                    if(0 == obj->async_tx_length)
                    {
                        /* We finished the async transfer. */
                        event |= obj->interface->event_tx_complete;
                    }
                    break;
                }
                case CYHAL_ASYNC_DMA:
                {
                    cy_rslt_t result = _cyhal_audioss_dma_perform_tx(obj);
                    CY_UNUSED_PARAMETER(result);
                    CY_ASSERT(CY_RSLT_SUCCESS == result);
                    break;
                }
                default:
                    CY_ASSERT(0); /* Unrecognized async mode */
                    break;
            }
        }

        cyhal_system_critical_section_exit(savedIntrStatus);
    }
    if(0 != (event & (obj->interface->event_mask_full | obj->interface->event_mask_half_full)))
    {
        /* Similar to TX, we don't expect to receive the "full" interrupt, but check for it out of caution */
        uint32_t savedIntrStatus = cyhal_system_critical_section_enter();
        if(NULL != obj->async_rx_buff && obj->async_rx_length > 0)
        {
            switch(obj->async_mode)
            {
                case CYHAL_ASYNC_SW:
                {
                   /* Read as much as we can until the FIFO is empty
                     * This is a potentially long operation but we don't want other I2S operations to
                     * interleave with it. So switch to a "mini critical section" and disable the
                     * interrupts for this block only while we're copying
                    */
                   uint32_t old_events = _cyhal_audioss_disable_events(obj, false);
                   cyhal_system_critical_section_exit(savedIntrStatus);
                   // Safe to cast away volatile here because we're calling read_until_empty from within
                   // a critical section, so it should not change out from under us during this call
                   _cyhal_audioss_read_until_empty(obj, (void**)(&obj->async_rx_buff), (size_t*)(&obj->async_rx_length));
                   // Re-enter the global critical section so that the exit below behaves correctly
                   savedIntrStatus = cyhal_system_critical_section_enter();
                   _cyhal_audioss_restore_events(obj, false, old_events);
                   _cyhal_audioss_update_enabled_events(obj);
                   if(0 == obj->async_rx_length)
                   {
                       /* We finished the async transfer.  */
                       event |= obj->interface->event_rx_complete;
                   }
                   break;
                }
                case CYHAL_ASYNC_DMA:
                   _cyhal_audioss_dma_perform_rx(obj);
                   break;

                default:
                   CY_ASSERT(0); /* Unrecognized async mode */
            }

            // During async rx transfers, we may temporarily set the trigger level below half-full.
            // So make sure that it's a real "half full" and skip propagating to the user if it isn't
#if defined(CY_IP_MXAUDIOSS)
            uint8_t trigger_level = (obj->base->TX_FIFO_CTL & I2S_RX_FIFO_CTL_TRIGGER_LEVEL_Msk) >> I2S_RX_FIFO_CTL_TRIGGER_LEVEL_Pos;
#elif defined(CY_IP_MXTDM)
            uint8_t trigger_level = (obj->base->TDM_TX_STRUCT.TX_FIFO_CTL & TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Msk) >> TDM_TDM_STRUCT_TDM_TX_STRUCT_TX_FIFO_CTL_TRIGGER_LEVEL_Pos;
#endif
            if(trigger_level != _CYHAL_AUDIOSS_FIFO_DEPTH / 2)
            {
                event &= ~(obj->interface->event_mask_half_full);
            }
        }

        cyhal_system_critical_section_exit(savedIntrStatus);
    }

    /* Mark async transfer as complete if we just finished one. */
    if(0 != (event & obj->interface->event_tx_complete))
    {
        obj->async_tx_buff = NULL;
        _cyhal_audioss_update_enabled_events(obj);
    }
    if(0 != (event & obj->interface->event_rx_complete))
    {
        obj->async_rx_buff = NULL;
        _cyhal_audioss_update_enabled_events(obj);
    }

    if(0 != (event & obj->user_enabled_events))
    {
        obj->interface->invoke_user_callback(obj, event & obj->user_enabled_events);
    }
}

static bool _cyhal_audioss_pm_callback(cyhal_syspm_callback_state_t state, cyhal_syspm_callback_mode_t mode, void* callback_arg)
{
    _cyhal_audioss_t *obj = (_cyhal_audioss_t *)callback_arg;
    CY_UNUSED_PARAMETER(state);

    switch(mode)
    {
        case CYHAL_SYSPM_CHECK_READY:
        {
            bool is_active = _cyhal_audioss_is_rx_enabled(obj)
                          || _cyhal_audioss_is_tx_enabled(obj);
            obj->pm_transition_ready = !is_active && !(_cyhal_audioss_is_read_pending(obj) || _cyhal_audioss_is_tx_busy(obj));
            return obj->pm_transition_ready;
        }
        case CYHAL_SYSPM_CHECK_FAIL:
        case CYHAL_SYSPM_AFTER_TRANSITION:
            obj->pm_transition_ready = false;
            return true;
        default:
            return true;
    }
}

#if defined(__cplusplus)
}
#endif

#endif /* defined(CY_IP_MXAUDIOSS) || defined(CY_IP_MXTDM) */
