/***************************************************************************//**
* \file cyhal_cyw20829_56_qfn.c
*
* \brief
* CYW20829 device GPIO HAL header for 56-QFN package
*
* \note
* Generator version: 1.6.0.512
*
********************************************************************************
* \copyright
* Copyright 2016-2021 Cypress Semiconductor Corporation
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

#include "cy_device_headers.h"
#include "cyhal_hw_types.h"

#if defined(_GPIO_CYW20829_56_QFN_H_)
#include "pin_packages/cyhal_cyw20829_56_qfn.h"

/* Hardware Blocks */
static const cyhal_resource_inst_t CYHAL_ADCMIC_0 = { CYHAL_RSC_ADCMIC, 0, 0 };
static const cyhal_resource_inst_t CYHAL_CAN_0 = { CYHAL_RSC_CAN, 0, 0 };
static const cyhal_resource_inst_t CYHAL_KEYSCAN_0 = { CYHAL_RSC_KEYSCAN, 0, 0 };
static const cyhal_resource_inst_t CYHAL_LIN_0 = { CYHAL_RSC_LIN, 0, 0 };
static const cyhal_resource_inst_t CYHAL_PDM_0_0 = { CYHAL_RSC_PDM, 0, 0 };
static const cyhal_resource_inst_t CYHAL_PDM_0_1 = { CYHAL_RSC_PDM, 0, 1 };
static const cyhal_resource_inst_t CYHAL_SCB_0 = { CYHAL_RSC_SCB, 0, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_1 = { CYHAL_RSC_SCB, 1, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_2 = { CYHAL_RSC_SCB, 2, 0 };
static const cyhal_resource_inst_t CYHAL_SMIF_0 = { CYHAL_RSC_SMIF, 0, 0 };
static const cyhal_resource_inst_t CYHAL_TCPWM_0_0 = { CYHAL_RSC_TCPWM, 0, 0 };
static const cyhal_resource_inst_t CYHAL_TCPWM_0_1 = { CYHAL_RSC_TCPWM, 0, 1 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_0 = { CYHAL_RSC_TCPWM, 1, 0 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_1 = { CYHAL_RSC_TCPWM, 1, 1 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_2 = { CYHAL_RSC_TCPWM, 1, 2 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_3 = { CYHAL_RSC_TCPWM, 1, 3 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_4 = { CYHAL_RSC_TCPWM, 1, 4 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_5 = { CYHAL_RSC_TCPWM, 1, 5 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_6 = { CYHAL_RSC_TCPWM, 1, 6 };
static const cyhal_resource_inst_t CYHAL_TDM_0 = { CYHAL_RSC_TDM, 0, 0 };

/* Pin connections */
/* Connections for: adcmic_clk_pdm */
const cyhal_resource_pin_mapping_t cyhal_pin_map_adcmic_clk_pdm[2] = {
    {&CYHAL_ADCMIC_0, P3_2, (uint8_t)CY_GPIO_DM_HIGHZ, P3_2_ADCMIC_CLK_PDM},
    {&CYHAL_ADCMIC_0, P5_0, (uint8_t)CY_GPIO_DM_HIGHZ, P5_0_ADCMIC_CLK_PDM},
};

/* Connections for: adcmic_gpio_adc_in */
/* The drive mode will always be ANALOG because that is how the ADCMIC block works. But the ADC driver needs.
   to know the bit index on the analog_in signal. So store that in the drive_mode field instead. */
const cyhal_resource_pin_mapping_t cyhal_pin_map_adcmic_gpio_adc_in[8] = {
    {&CYHAL_ADCMIC_0, P3_0, (uint8_t)0u, HSIOM_SEL_GPIO},
    {&CYHAL_ADCMIC_0, P3_1, (uint8_t)1u, HSIOM_SEL_GPIO},
    {&CYHAL_ADCMIC_0, P3_2, (uint8_t)2u, HSIOM_SEL_GPIO},
    {&CYHAL_ADCMIC_0, P3_3, (uint8_t)3u, HSIOM_SEL_GPIO},
    {&CYHAL_ADCMIC_0, P3_4, (uint8_t)4u, HSIOM_SEL_GPIO},
    {&CYHAL_ADCMIC_0, P3_5, (uint8_t)5u, HSIOM_SEL_GPIO},
    {&CYHAL_ADCMIC_0, P3_6, (uint8_t)6u, HSIOM_SEL_GPIO},
    {&CYHAL_ADCMIC_0, P3_7, (uint8_t)7u, HSIOM_SEL_GPIO},
};

/* Connections for: adcmic_pdm_data */
const cyhal_resource_pin_mapping_t cyhal_pin_map_adcmic_pdm_data[2] = {
    {&CYHAL_ADCMIC_0, P3_3, (uint8_t)CY_GPIO_DM_HIGHZ, P3_3_ADCMIC_PDM_DATA},
    {&CYHAL_ADCMIC_0, P5_1, (uint8_t)CY_GPIO_DM_HIGHZ, P5_1_ADCMIC_PDM_DATA},
};

/* Connections for: canfd_ttcan_rx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_canfd_ttcan_rx[1] = {
    {&CYHAL_CAN_0, P3_2, (uint8_t)CY_GPIO_DM_HIGHZ, P3_2_CANFD0_TTCAN_RX0},
};

/* Connections for: canfd_ttcan_tx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_canfd_ttcan_tx[1] = {
    {&CYHAL_CAN_0, P3_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_3_CANFD0_TTCAN_TX0},
};

/* Connections for: keyscan_ks_col */
const cyhal_resource_pin_mapping_t cyhal_pin_map_keyscan_ks_col[20] = {
    {&CYHAL_KEYSCAN_0, P0_0, (uint8_t)CY_GPIO_DM_HIGHZ, P0_0_KEYSCAN_KS_COL3},
    {&CYHAL_KEYSCAN_0, P0_1, (uint8_t)CY_GPIO_DM_HIGHZ, P0_1_KEYSCAN_KS_COL4},
    {&CYHAL_KEYSCAN_0, P0_2, (uint8_t)CY_GPIO_DM_HIGHZ, P0_2_KEYSCAN_KS_COL11},
    {&CYHAL_KEYSCAN_0, P0_3, (uint8_t)CY_GPIO_DM_HIGHZ, P0_3_KEYSCAN_KS_COL12},
    {&CYHAL_KEYSCAN_0, P1_2, (uint8_t)CY_GPIO_DM_HIGHZ, P1_2_KEYSCAN_KS_COL17},
    {&CYHAL_KEYSCAN_0, P1_3, (uint8_t)CY_GPIO_DM_HIGHZ, P1_3_KEYSCAN_KS_COL16},
    {&CYHAL_KEYSCAN_0, P1_4, (uint8_t)CY_GPIO_DM_HIGHZ, P1_4_KEYSCAN_KS_COL16},
    {&CYHAL_KEYSCAN_0, P1_4, (uint8_t)CY_GPIO_DM_HIGHZ, P1_4_KEYSCAN_KS_COL15},
    {&CYHAL_KEYSCAN_0, P1_5, (uint8_t)CY_GPIO_DM_HIGHZ, P1_5_KEYSCAN_KS_COL5},
    {&CYHAL_KEYSCAN_0, P1_6, (uint8_t)CY_GPIO_DM_HIGHZ, P1_6_KEYSCAN_KS_COL6},
    {&CYHAL_KEYSCAN_0, P3_2, (uint8_t)CY_GPIO_DM_HIGHZ, P3_2_KEYSCAN_KS_COL13},
    {&CYHAL_KEYSCAN_0, P3_3, (uint8_t)CY_GPIO_DM_HIGHZ, P3_3_KEYSCAN_KS_COL17},
    {&CYHAL_KEYSCAN_0, P3_3, (uint8_t)CY_GPIO_DM_HIGHZ, P3_3_KEYSCAN_KS_COL14},
    {&CYHAL_KEYSCAN_0, P3_4, (uint8_t)CY_GPIO_DM_HIGHZ, P3_4_KEYSCAN_KS_COL7},
    {&CYHAL_KEYSCAN_0, P3_5, (uint8_t)CY_GPIO_DM_HIGHZ, P3_5_KEYSCAN_KS_COL8},
    {&CYHAL_KEYSCAN_0, P3_6, (uint8_t)CY_GPIO_DM_HIGHZ, P3_6_KEYSCAN_KS_COL9},
    {&CYHAL_KEYSCAN_0, P3_7, (uint8_t)CY_GPIO_DM_HIGHZ, P3_7_KEYSCAN_KS_COL10},
    {&CYHAL_KEYSCAN_0, P5_0, (uint8_t)CY_GPIO_DM_HIGHZ, P5_0_KEYSCAN_KS_COL0},
    {&CYHAL_KEYSCAN_0, P5_1, (uint8_t)CY_GPIO_DM_HIGHZ, P5_1_KEYSCAN_KS_COL1},
    {&CYHAL_KEYSCAN_0, P5_2, (uint8_t)CY_GPIO_DM_HIGHZ, P5_2_KEYSCAN_KS_COL2},
};

/* Connections for: keyscan_ks_row */
const cyhal_resource_pin_mapping_t cyhal_pin_map_keyscan_ks_row[8] = {
    {&CYHAL_KEYSCAN_0, P0_4, (uint8_t)CY_GPIO_DM_HIGHZ, P0_4_KEYSCAN_KS_ROW0},
    {&CYHAL_KEYSCAN_0, P0_5, (uint8_t)CY_GPIO_DM_HIGHZ, P0_5_KEYSCAN_KS_ROW1},
    {&CYHAL_KEYSCAN_0, P1_0, (uint8_t)CY_GPIO_DM_HIGHZ, P1_0_KEYSCAN_KS_ROW5},
    {&CYHAL_KEYSCAN_0, P1_1, (uint8_t)CY_GPIO_DM_HIGHZ, P1_1_KEYSCAN_KS_ROW6},
    {&CYHAL_KEYSCAN_0, P3_0, (uint8_t)CY_GPIO_DM_HIGHZ, P3_0_KEYSCAN_KS_ROW7},
    {&CYHAL_KEYSCAN_0, P3_1, (uint8_t)CY_GPIO_DM_HIGHZ, P3_1_KEYSCAN_KS_ROW4},
    {&CYHAL_KEYSCAN_0, P4_0, (uint8_t)CY_GPIO_DM_HIGHZ, P4_0_KEYSCAN_KS_ROW2},
    {&CYHAL_KEYSCAN_0, P4_1, (uint8_t)CY_GPIO_DM_HIGHZ, P4_1_KEYSCAN_KS_ROW3},
};

/* Connections for: lin_lin_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_lin_lin_en[2] = {
    {&CYHAL_LIN_0, P1_4, (uint8_t)CY_GPIO_DM_HIGHZ, P1_4_LIN0_LIN_EN1},
    {&CYHAL_LIN_0, P3_1, (uint8_t)CY_GPIO_DM_HIGHZ, P3_1_LIN0_LIN_EN0},
};

/* Connections for: lin_lin_rx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_lin_lin_rx[2] = {
    {&CYHAL_LIN_0, P1_5, (uint8_t)CY_GPIO_DM_HIGHZ, P1_5_LIN0_LIN_RX1},
    {&CYHAL_LIN_0, P3_2, (uint8_t)CY_GPIO_DM_HIGHZ, P3_2_LIN0_LIN_RX0},
};

/* Connections for: lin_lin_tx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_lin_lin_tx[2] = {
    {&CYHAL_LIN_0, P1_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_6_LIN0_LIN_TX1},
    {&CYHAL_LIN_0, P3_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_3_LIN0_LIN_TX0},
};

/* Connections for: pdm_pdm_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pdm_pdm_clk[3] = {
    {&CYHAL_PDM_0_1, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_PDM_PDM_CLK1},
    {&CYHAL_PDM_0_0, P3_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_2_PDM_PDM_CLK0},
    {&CYHAL_PDM_0_0, P5_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_0_PDM_PDM_CLK0},
};

/* Connections for: pdm_pdm_data */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pdm_pdm_data[3] = {
    {&CYHAL_PDM_0_1, P0_1, (uint8_t)CY_GPIO_DM_HIGHZ, P0_1_PDM_PDM_DATA1},
    {&CYHAL_PDM_0_0, P3_3, (uint8_t)CY_GPIO_DM_HIGHZ, P3_3_PDM_PDM_DATA0},
    {&CYHAL_PDM_0_0, P5_1, (uint8_t)CY_GPIO_DM_HIGHZ, P5_1_PDM_PDM_DATA0},
};

/* Connections for: peri_tr_io_input */
/* Since the GPIO pin is already specified there is no need to specify a particular resource for every entry.
   Instead set the resource_inst field to the index of the input or output trigger line. */
const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_input[8] = {
    {(cyhal_resource_inst_t*)4, P0_2, (uint8_t)CY_GPIO_DM_HIGHZ, P0_2_PERI_TR_IO_INPUT4},
    {(cyhal_resource_inst_t*)5, P0_3, (uint8_t)CY_GPIO_DM_HIGHZ, P0_3_PERI_TR_IO_INPUT5},
    {(cyhal_resource_inst_t*)0, P0_4, (uint8_t)CY_GPIO_DM_HIGHZ, P0_4_PERI_TR_IO_INPUT0},
    {(cyhal_resource_inst_t*)1, P0_5, (uint8_t)CY_GPIO_DM_HIGHZ, P0_5_PERI_TR_IO_INPUT1},
    {(cyhal_resource_inst_t*)2, P1_2, (uint8_t)CY_GPIO_DM_HIGHZ, P1_2_PERI_TR_IO_INPUT2},
    {(cyhal_resource_inst_t*)3, P1_3, (uint8_t)CY_GPIO_DM_HIGHZ, P1_3_PERI_TR_IO_INPUT3},
    {(cyhal_resource_inst_t*)6, P3_2, (uint8_t)CY_GPIO_DM_HIGHZ, P3_2_PERI_TR_IO_INPUT6},
    {(cyhal_resource_inst_t*)7, P3_3, (uint8_t)CY_GPIO_DM_HIGHZ, P3_3_PERI_TR_IO_INPUT7},
};

/* Connections for: peri_tr_io_output */
/* Since the GPIO pin is already specified there is no need to specify a particular resource for every entry.
   Instead set the resource_inst field to the index of the input or output trigger line. */
const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_output[2] = {
    {(cyhal_resource_inst_t*)0, P1_0, (uint8_t)CY_GPIO_DM_HIGHZ, P1_0_PERI_TR_IO_OUTPUT0},
    {(cyhal_resource_inst_t*)1, P1_1, (uint8_t)CY_GPIO_DM_HIGHZ, P1_1_PERI_TR_IO_OUTPUT1},
};

/* Connections for: scb_i2c_scl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_scl[4] = {
    {&CYHAL_SCB_0, P0_2, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P0_2_SCB0_I2C_SCL},
    {&CYHAL_SCB_2, P1_2, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P1_2_SCB2_I2C_SCL},
    {&CYHAL_SCB_2, P3_2, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P3_2_SCB2_I2C_SCL},
    {&CYHAL_SCB_0, P4_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P4_0_SCB0_I2C_SCL},
};

/* Connections for: scb_i2c_sda */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_sda[4] = {
    {&CYHAL_SCB_0, P0_3, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P0_3_SCB0_I2C_SDA},
    {&CYHAL_SCB_2, P1_3, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P1_3_SCB2_I2C_SDA},
    {&CYHAL_SCB_2, P3_3, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P3_3_SCB2_I2C_SDA},
    {&CYHAL_SCB_0, P4_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P4_1_SCB0_I2C_SDA},
};

/* Connections for: scb_spi_m_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_clk[3] = {
    {&CYHAL_SCB_0, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_SCB0_SPI_CLK},
    {&CYHAL_SCB_1, P1_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_1_SCB1_SPI_CLK},
    {&CYHAL_SCB_1, P3_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_1_SCB1_SPI_CLK},
};

/* Connections for: scb_spi_m_miso */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_miso[4] = {
    {&CYHAL_SCB_0, P0_3, (uint8_t)CY_GPIO_DM_HIGHZ, P0_3_SCB0_SPI_MISO},
    {&CYHAL_SCB_1, P1_3, (uint8_t)CY_GPIO_DM_HIGHZ, P1_3_SCB1_SPI_MISO},
    {&CYHAL_SCB_1, P3_3, (uint8_t)CY_GPIO_DM_HIGHZ, P3_3_SCB1_SPI_MISO},
    {&CYHAL_SCB_0, P4_1, (uint8_t)CY_GPIO_DM_HIGHZ, P4_1_SCB0_SPI_MISO},
};

/* Connections for: scb_spi_m_mosi */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_mosi[4] = {
    {&CYHAL_SCB_0, P0_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_2_SCB0_SPI_MOSI},
    {&CYHAL_SCB_1, P1_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_2_SCB1_SPI_MOSI},
    {&CYHAL_SCB_1, P3_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_2_SCB1_SPI_MOSI},
    {&CYHAL_SCB_0, P4_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_0_SCB0_SPI_MOSI},
};

/* Connections for: scb_spi_m_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select0[4] = {
    {&CYHAL_SCB_1, P1_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_0_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_1, P3_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_0_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_1, P5_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_0_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_0, P5_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_1_SCB0_SPI_SELECT0},
};

/* Connections for: scb_spi_m_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select1[3] = {
    {&CYHAL_SCB_0, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_SCB0_SPI_SELECT1},
    {&CYHAL_SCB_1, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_SCB1_SPI_SELECT1},
    {&CYHAL_SCB_1, P3_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_6_SCB1_SPI_SELECT1},
};

/* Connections for: scb_spi_m_select2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select2[3] = {
    {&CYHAL_SCB_0, P0_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_1_SCB0_SPI_SELECT2},
    {&CYHAL_SCB_1, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_SCB1_SPI_SELECT2},
    {&CYHAL_SCB_1, P3_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_5_SCB1_SPI_SELECT2},
};

/* Connections for: scb_spi_m_select3 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select3[2] = {
    {&CYHAL_SCB_1, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_SCB1_SPI_SELECT3},
    {&CYHAL_SCB_1, P3_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_4_SCB1_SPI_SELECT3},
};

/* Connections for: scb_spi_s_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_clk[3] = {
    {&CYHAL_SCB_0, P0_4, (uint8_t)CY_GPIO_DM_HIGHZ, P0_4_SCB0_SPI_CLK},
    {&CYHAL_SCB_1, P1_1, (uint8_t)CY_GPIO_DM_HIGHZ, P1_1_SCB1_SPI_CLK},
    {&CYHAL_SCB_1, P3_1, (uint8_t)CY_GPIO_DM_HIGHZ, P3_1_SCB1_SPI_CLK},
};

/* Connections for: scb_spi_s_miso */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_miso[4] = {
    {&CYHAL_SCB_0, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_SCB0_SPI_MISO},
    {&CYHAL_SCB_1, P1_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_3_SCB1_SPI_MISO},
    {&CYHAL_SCB_1, P3_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_3_SCB1_SPI_MISO},
    {&CYHAL_SCB_0, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_SCB0_SPI_MISO},
};

/* Connections for: scb_spi_s_mosi */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_mosi[4] = {
    {&CYHAL_SCB_0, P0_2, (uint8_t)CY_GPIO_DM_HIGHZ, P0_2_SCB0_SPI_MOSI},
    {&CYHAL_SCB_1, P1_2, (uint8_t)CY_GPIO_DM_HIGHZ, P1_2_SCB1_SPI_MOSI},
    {&CYHAL_SCB_1, P3_2, (uint8_t)CY_GPIO_DM_HIGHZ, P3_2_SCB1_SPI_MOSI},
    {&CYHAL_SCB_0, P4_0, (uint8_t)CY_GPIO_DM_HIGHZ, P4_0_SCB0_SPI_MOSI},
};

/* Connections for: scb_spi_s_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select0[4] = {
    {&CYHAL_SCB_1, P1_0, (uint8_t)CY_GPIO_DM_HIGHZ, P1_0_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_1, P3_0, (uint8_t)CY_GPIO_DM_HIGHZ, P3_0_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_1, P5_0, (uint8_t)CY_GPIO_DM_HIGHZ, P5_0_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_0, P5_1, (uint8_t)CY_GPIO_DM_HIGHZ, P5_1_SCB0_SPI_SELECT0},
};

/* Connections for: scb_spi_s_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select1[3] = {
    {&CYHAL_SCB_0, P0_0, (uint8_t)CY_GPIO_DM_HIGHZ, P0_0_SCB0_SPI_SELECT1},
    {&CYHAL_SCB_1, P0_5, (uint8_t)CY_GPIO_DM_HIGHZ, P0_5_SCB1_SPI_SELECT1},
    {&CYHAL_SCB_1, P3_6, (uint8_t)CY_GPIO_DM_HIGHZ, P3_6_SCB1_SPI_SELECT1},
};

/* Connections for: scb_spi_s_select2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select2[3] = {
    {&CYHAL_SCB_0, P0_1, (uint8_t)CY_GPIO_DM_HIGHZ, P0_1_SCB0_SPI_SELECT2},
    {&CYHAL_SCB_1, P0_4, (uint8_t)CY_GPIO_DM_HIGHZ, P0_4_SCB1_SPI_SELECT2},
    {&CYHAL_SCB_1, P3_5, (uint8_t)CY_GPIO_DM_HIGHZ, P3_5_SCB1_SPI_SELECT2},
};

/* Connections for: scb_spi_s_select3 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select3[2] = {
    {&CYHAL_SCB_1, P0_3, (uint8_t)CY_GPIO_DM_HIGHZ, P0_3_SCB1_SPI_SELECT3},
    {&CYHAL_SCB_1, P3_4, (uint8_t)CY_GPIO_DM_HIGHZ, P3_4_SCB1_SPI_SELECT3},
};

/* Connections for: scb_uart_cts */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_cts[3] = {
    {&CYHAL_SCB_1, P1_0, (uint8_t)CY_GPIO_DM_HIGHZ, P1_0_SCB1_UART_CTS},
    {&CYHAL_SCB_2, P3_0, (uint8_t)CY_GPIO_DM_HIGHZ, P3_0_SCB2_UART_CTS},
    {&CYHAL_SCB_2, P5_0, (uint8_t)CY_GPIO_DM_HIGHZ, P5_0_SCB2_UART_CTS},
};

/* Connections for: scb_uart_rts */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rts[2] = {
    {&CYHAL_SCB_1, P1_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_1_SCB1_UART_RTS},
    {&CYHAL_SCB_2, P3_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_1_SCB2_UART_RTS},
};

/* Connections for: scb_uart_rx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rx[2] = {
    {&CYHAL_SCB_1, P1_2, (uint8_t)CY_GPIO_DM_HIGHZ, P1_2_SCB1_UART_RX},
    {&CYHAL_SCB_2, P3_2, (uint8_t)CY_GPIO_DM_HIGHZ, P3_2_SCB2_UART_RX},
};

/* Connections for: scb_uart_tx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_tx[2] = {
    {&CYHAL_SCB_1, P1_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_3_SCB1_UART_TX},
    {&CYHAL_SCB_2, P3_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_3_SCB2_UART_TX},
};

/* Connections for: smif_spi_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_clk[1] = {
    {&CYHAL_SMIF_0, P2_5, (uint8_t)CY_GPIO_DM_STRONG, P2_5_SMIF_SPIHB_CLK},
};

/* Connections for: smif_spi_data0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data0[1] = {
    {&CYHAL_SMIF_0, P2_4, (uint8_t)CY_GPIO_DM_STRONG, P2_4_SMIF_SPIHB_DATA0},
};

/* Connections for: smif_spi_data1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data1[1] = {
    {&CYHAL_SMIF_0, P2_3, (uint8_t)CY_GPIO_DM_STRONG, P2_3_SMIF_SPIHB_DATA1},
};

/* Connections for: smif_spi_data2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data2[1] = {
    {&CYHAL_SMIF_0, P2_2, (uint8_t)CY_GPIO_DM_STRONG, P2_2_SMIF_SPIHB_DATA2},
};

/* Connections for: smif_spi_data3 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data3[1] = {
    {&CYHAL_SMIF_0, P2_1, (uint8_t)CY_GPIO_DM_STRONG, P2_1_SMIF_SPIHB_DATA3},
};

/* Connections for: smif_spi_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select0[1] = {
    {&CYHAL_SMIF_0, P2_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_0_SMIF_SPIHB_SELECT0},
};

/* Connections for: smif_spi_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select1[1] = {
    {&CYHAL_SMIF_0, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_SMIF_SPIHB_SELECT1},
};

/* Connections for: tcpwm_line */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line[26] = {
    {&CYHAL_TCPWM_0_1, P0_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_1_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_0, P0_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_1_TCPWM0_LINE256},
    {&CYHAL_TCPWM_0_0, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_1, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_TCPWM0_LINE257},
    {&CYHAL_TCPWM_0_1, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_2, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_TCPWM0_LINE258},
    {&CYHAL_TCPWM_0_0, P1_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_1_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_3, P1_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_1_TCPWM0_LINE259},
    {&CYHAL_TCPWM_0_1, P1_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_3_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_4, P1_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_3_TCPWM0_LINE260},
    {&CYHAL_TCPWM_0_0, P1_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_5_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_5, P1_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_5_TCPWM0_LINE261},
    {&CYHAL_TCPWM_0_0, P3_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_0_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_0, P3_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_0_TCPWM0_LINE256},
    {&CYHAL_TCPWM_0_1, P3_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_2_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_1, P3_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_2_TCPWM0_LINE257},
    {&CYHAL_TCPWM_0_0, P3_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_4_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_2, P3_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_4_TCPWM0_LINE258},
    {&CYHAL_TCPWM_0_1, P3_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_6_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_3, P3_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_6_TCPWM0_LINE259},
    {&CYHAL_TCPWM_0_0, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_6, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_TCPWM0_LINE262},
    {&CYHAL_TCPWM_0_0, P5_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_0_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_4, P5_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_0_TCPWM0_LINE260},
    {&CYHAL_TCPWM_0_1, P5_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_2_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_5, P5_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_2_TCPWM0_LINE261},
};

/* Connections for: tcpwm_line_compl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line_compl[26] = {
    {&CYHAL_TCPWM_0_0, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_6, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_TCPWM0_LINE_COMPL262},
    {&CYHAL_TCPWM_0_1, P0_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_2_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_0, P0_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_2_TCPWM0_LINE_COMPL256},
    {&CYHAL_TCPWM_0_0, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_1, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_TCPWM0_LINE_COMPL257},
    {&CYHAL_TCPWM_0_1, P1_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_0_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_2, P1_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_0_TCPWM0_LINE_COMPL258},
    {&CYHAL_TCPWM_0_0, P1_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_2_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_3, P1_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_2_TCPWM0_LINE_COMPL259},
    {&CYHAL_TCPWM_0_1, P1_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_4_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_4, P1_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_4_TCPWM0_LINE_COMPL260},
    {&CYHAL_TCPWM_0_0, P1_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_6_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_5, P1_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_6_TCPWM0_LINE_COMPL261},
    {&CYHAL_TCPWM_0_0, P3_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_1_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_0, P3_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_1_TCPWM0_LINE_COMPL256},
    {&CYHAL_TCPWM_0_1, P3_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_3_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_1, P3_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_3_TCPWM0_LINE_COMPL257},
    {&CYHAL_TCPWM_0_0, P3_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_5_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_2, P3_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_5_TCPWM0_LINE_COMPL258},
    {&CYHAL_TCPWM_0_1, P3_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_7_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_3, P3_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P3_7_TCPWM0_LINE_COMPL259},
    {&CYHAL_TCPWM_0_1, P4_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_0_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_5, P4_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_0_TCPWM0_LINE_COMPL261},
    {&CYHAL_TCPWM_0_0, P5_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_1_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_4, P5_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_1_TCPWM0_LINE_COMPL260},
};

/* Connections for: tdm_tdm_rx_fsync */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_fsync[1] = {
    {&CYHAL_TDM_0, P1_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P1_0_TDM_TDM_RX_FSYNC0},
};

/* Connections for: tdm_tdm_rx_mck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_mck[1] = {
    {&CYHAL_TDM_0, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_TDM_TDM_RX_MCK0},
};

/* Connections for: tdm_tdm_rx_sck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_sck[1] = {
    {&CYHAL_TDM_0, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_TDM_TDM_RX_SCK0},
};

/* Connections for: tdm_tdm_rx_sd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_sd[1] = {
    {&CYHAL_TDM_0, P1_1, (uint8_t)CY_GPIO_DM_HIGHZ, P1_1_TDM_TDM_RX_SD0},
};

/* Connections for: tdm_tdm_tx_fsync */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_fsync[1] = {
    {&CYHAL_TDM_0, P0_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_2_TDM_TDM_TX_FSYNC0},
};

/* Connections for: tdm_tdm_tx_mck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_mck[1] = {
    {&CYHAL_TDM_0, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_TDM_TDM_TX_MCK0},
};

/* Connections for: tdm_tdm_tx_sck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_sck[1] = {
    {&CYHAL_TDM_0, P0_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_1_TDM_TDM_TX_SCK0},
};

/* Connections for: tdm_tdm_tx_sd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_sd[1] = {
    {&CYHAL_TDM_0, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_TDM_TDM_TX_SD0},
};

#endif
