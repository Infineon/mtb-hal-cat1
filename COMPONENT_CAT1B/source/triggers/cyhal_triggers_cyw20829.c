/***************************************************************************//**
* \file cyhal_triggers_cyw20829.c
*
* \brief
* CYW20829 family HAL triggers header
*
********************************************************************************
* \copyright
* (c) (2016-2023), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
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

#if (defined(CY_DEVICE_CYW20829) && (CY_SYSLIB_GET_SILICON_REV_ID == CY_SYSLIB_20829B0_SILICON_REV))
#include "triggers/cyhal_triggers_cyw20829.h"

const uint16_t cyhal_sources_per_mux[15] =
{
    26, 54, 54, 46, 64, 3, 19, 2, 3, 3, 4, 5, 1, 1, 2, 
};

const bool cyhal_is_mux_1to1[15] =
{
    false, false, false, false, false, false, false, false, false, false, true, true, true, true, true, 
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux0_sources[26] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN0,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN1,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN2,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN3,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN4,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN5,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN6,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN7,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DC,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DATA,
    _CYHAL_TRIGGER_TDM_TR_TX_REQ0,
    _CYHAL_TRIGGER_TDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ1,
    _CYHAL_TRIGGER_CRYPTO_TR_TRNG_BITSTREAM,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux1_sources[54] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT4,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT5,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT6,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT7,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0262,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1262,
    _CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB0_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB0_TR_RX_REQ,
    _CYHAL_TRIGGER_CRYPTO_TR_TRNG_BITSTREAM,
    _CYHAL_TRIGGER_SCB1_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB1_TR_RX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB2_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_RX_REQ,
    _CYHAL_TRIGGER_SMIF_TR_TX_REQ,
    _CYHAL_TRIGGER_SMIF_TR_RX_REQ,
    _CYHAL_TRIGGER_TDM_TR_TX_REQ0,
    _CYHAL_TRIGGER_TDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ1,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ_ALL,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN0,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN1,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN2,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN3,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DC,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DATA,
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0,
    _CYHAL_TRIGGER_BTSS_TR_TX_START,
    _CYHAL_TRIGGER_BTSS_TR_RX_PACKET_SYNC,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux2_sources[54] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT8,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT9,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT10,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT11,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT12,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT13,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT14,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT15,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0262,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1262,
    _CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB0_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB0_TR_RX_REQ,
    _CYHAL_TRIGGER_CRYPTO_TR_TRNG_BITSTREAM,
    _CYHAL_TRIGGER_SCB1_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB1_TR_RX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB2_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_RX_REQ,
    _CYHAL_TRIGGER_SMIF_TR_TX_REQ,
    _CYHAL_TRIGGER_SMIF_TR_RX_REQ,
    _CYHAL_TRIGGER_TDM_TR_TX_REQ0,
    _CYHAL_TRIGGER_TDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ1,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ_ALL,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN4,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN5,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN6,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN7,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DC,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DATA,
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0,
    _CYHAL_TRIGGER_BTSS_TR_TX_START,
    _CYHAL_TRIGGER_BTSS_TR_RX_PACKET_SYNC,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux3_sources[46] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT4,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT5,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT6,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT7,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0262,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1262,
    _CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB0_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB0_TR_RX_REQ,
    _CYHAL_TRIGGER_CRYPTO_TR_TRNG_BITSTREAM,
    _CYHAL_TRIGGER_SCB1_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB1_TR_RX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB2_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_RX_REQ,
    _CYHAL_TRIGGER_TDM_TR_TX_REQ0,
    _CYHAL_TRIGGER_TDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ1,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ_ALL,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DC,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DATA,
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux4_sources[64] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT1,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT2,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT3,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT4,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT5,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT6,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT7,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT8,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT9,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT10,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT11,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT12,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT13,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT14,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT15,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0262,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1262,
    _CYHAL_TRIGGER_SCB0_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB0_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB0_TR_RX_REQ,
    _CYHAL_TRIGGER_CRYPTO_TR_TRNG_BITSTREAM,
    _CYHAL_TRIGGER_SCB1_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB1_TR_RX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_I2C_SCL_FILTERED,
    _CYHAL_TRIGGER_SCB2_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_RX_REQ,
    _CYHAL_TRIGGER_SMIF_TR_TX_REQ,
    _CYHAL_TRIGGER_SMIF_TR_RX_REQ,
    _CYHAL_TRIGGER_TDM_TR_TX_REQ0,
    _CYHAL_TRIGGER_TDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ1,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ_ALL,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN0,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN1,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN2,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN3,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN4,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN5,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN6,
    _CYHAL_TRIGGER_IOSS_PERI_TR_IO_INPUT_IN7,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DC,
    _CYHAL_TRIGGER_ADCMIC_TR_ADCMIC_DATA,
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux5_sources[3] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT0,
    _CYHAL_TRIGGER_CPUSS_CTI_TR_OUT1,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux6_sources[19] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT00,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT10,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT01,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT11,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1256,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1257,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1258,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1259,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1260,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1261,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT0262,
    _CYHAL_TRIGGER_TCPWM0_TR_OUT1262,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux7_sources[2] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_CANFD0_TR_TMP_RTP_OUT0,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux8_sources[3] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_SCB0_TR_TX_REQ,
    _CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_REQ0,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux9_sources[3] =
{
    _CYHAL_TRIGGER_CPUSS_ZERO,
    _CYHAL_TRIGGER_SCB0_TR_RX_REQ,
    _CYHAL_TRIGGER_CANFD0_TR_FIFO00,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux10_sources[4] =
{
    _CYHAL_TRIGGER_SCB1_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB1_TR_RX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_TX_REQ,
    _CYHAL_TRIGGER_SCB2_TR_RX_REQ,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux11_sources[5] =
{
    _CYHAL_TRIGGER_TDM_TR_TX_REQ0,
    _CYHAL_TRIGGER_TDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ0,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ1,
    _CYHAL_TRIGGER_PDM_TR_RX_REQ_ALL,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux12_sources[1] =
{
    _CYHAL_TRIGGER_CANFD0_TR_FIFO10,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux13_sources[1] =
{
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT8,
};

const _cyhal_trigger_source_cyw20829_t cyhal_mux14_sources[2] =
{
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT9,
    _CYHAL_TRIGGER_CPUSS_DW0_TR_OUT10,
};

const _cyhal_trigger_source_cyw20829_t* cyhal_mux_to_sources[15] =
{
    cyhal_mux0_sources, 
    cyhal_mux1_sources, 
    cyhal_mux2_sources, 
    cyhal_mux3_sources, 
    cyhal_mux4_sources, 
    cyhal_mux5_sources, 
    cyhal_mux6_sources, 
    cyhal_mux7_sources, 
    cyhal_mux8_sources, 
    cyhal_mux9_sources, 
    cyhal_mux10_sources, 
    cyhal_mux11_sources, 
    cyhal_mux12_sources, 
    cyhal_mux13_sources, 
    cyhal_mux14_sources, 
};

const uint8_t cyhal_dest_to_mux[59] =
{
    131, /* CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_ACK0 */
    7, /* CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN0 */
    4, /* CYHAL_TRIGGER_CPUSS_CTI_TR_IN0 */
    4, /* CYHAL_TRIGGER_CPUSS_CTI_TR_IN1 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN0 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN1 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN2 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN3 */
    8, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN4 */
    9, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN5 */
    128, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN6 */
    128, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN7 */
    128, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN8 */
    128, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN9 */
    129, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN10 */
    129, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN11 */
    129, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN12 */
    129, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN13 */
    129, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN14 */
    130, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN15 */
    3, /* CYHAL_TRIGGER_IOSS_PERI_TR_IO_OUTPUT_OUT0 */
    3, /* CYHAL_TRIGGER_IOSS_PERI_TR_IO_OUTPUT_OUT1 */
    132, /* CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER0 */
    132, /* CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER1 */
    6, /* CYHAL_TRIGGER_PDM_TR_ACTIVATE0 */
    6, /* CYHAL_TRIGGER_PDM_TR_ACTIVATE1 */
    5, /* CYHAL_TRIGGER_PDM_TR_DBG_FREEZE */
    5, /* CYHAL_TRIGGER_PERI_TR_DBG_FREEZE */
    4, /* CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_MCWDT0 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN0 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN1 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN2 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN3 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN4 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN5 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN6 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN7 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN8 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN9 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN10 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN11 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN12 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN13 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN14 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN15 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN16 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN17 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN18 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN19 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN20 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN21 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN22 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN23 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN24 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN25 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN26 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN27 */
    5, /* CYHAL_TRIGGER_TCPWM0_TR_DEBUG_FREEZE */
    5, /* CYHAL_TRIGGER_TDM_TR_DBG_FREEZE */
};

const uint8_t cyhal_mux_dest_index[59] =
{
    0, /* CYHAL_TRIGGER_CANFD0_TR_DBG_DMA_ACK0 */
    0, /* CYHAL_TRIGGER_CANFD0_TR_EVT_SWT_IN0 */
    0, /* CYHAL_TRIGGER_CPUSS_CTI_TR_IN0 */
    1, /* CYHAL_TRIGGER_CPUSS_CTI_TR_IN1 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN0 */
    1, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN1 */
    2, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN2 */
    3, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN3 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN4 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN5 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN6 */
    1, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN7 */
    2, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN8 */
    3, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN9 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN10 */
    1, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN11 */
    2, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN12 */
    3, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN13 */
    4, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN14 */
    0, /* CYHAL_TRIGGER_CPUSS_DW0_TR_IN15 */
    0, /* CYHAL_TRIGGER_IOSS_PERI_TR_IO_OUTPUT_OUT0 */
    1, /* CYHAL_TRIGGER_IOSS_PERI_TR_IO_OUTPUT_OUT1 */
    0, /* CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER0 */
    1, /* CYHAL_TRIGGER_LIN0_TR_CMD_TX_HEADER1 */
    0, /* CYHAL_TRIGGER_PDM_TR_ACTIVATE0 */
    1, /* CYHAL_TRIGGER_PDM_TR_ACTIVATE1 */
    1, /* CYHAL_TRIGGER_PDM_TR_DBG_FREEZE */
    0, /* CYHAL_TRIGGER_PERI_TR_DBG_FREEZE */
    3, /* CYHAL_TRIGGER_SRSS_TR_DEBUG_FREEZE_MCWDT0 */
    0, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN0 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN1 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN2 */
    3, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN3 */
    4, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN4 */
    5, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN5 */
    6, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN6 */
    7, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN7 */
    8, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN8 */
    9, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN9 */
    10, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN10 */
    11, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN11 */
    12, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN12 */
    13, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN13 */
    0, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN14 */
    1, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN15 */
    2, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN16 */
    3, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN17 */
    4, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN18 */
    5, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN19 */
    6, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN20 */
    7, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN21 */
    8, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN22 */
    9, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN23 */
    10, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN24 */
    11, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN25 */
    12, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN26 */
    13, /* CYHAL_TRIGGER_TCPWM0_TR_ALL_CNT_IN27 */
    3, /* CYHAL_TRIGGER_TCPWM0_TR_DEBUG_FREEZE */
    2, /* CYHAL_TRIGGER_TDM_TR_DBG_FREEZE */
};

#endif /* CY_DEVICE_CYW20829 */
