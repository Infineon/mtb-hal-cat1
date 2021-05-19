/***************************************************************************//**
* \file cyhal_mxs28playermcuss_128_tqfp.h
*
* \brief
* MXS28PLAYERMCUSS device GPIO HAL header for 128-TQFP package
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

#ifndef _CYHAL_MXS28PLAYERMCUSS_128_TQFP_H_
#define _CYHAL_MXS28PLAYERMCUSS_128_TQFP_H_

#include "cyhal_hw_resources.h"

/**
 * \addtogroup group_hal_impl_pin_package_mxs28playermcuss_128_tqfp MXS28PLAYERMCUSS 128-TQFP
 * \ingroup group_hal_impl_pin_package
 * \{
 * Pin definitions and connections specific to the MXS28PLAYERMCUSS 128-TQFP package.
 */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/** Gets a pin definition from the provided port and pin numbers */
#define CYHAL_GET_GPIO(port, pin)   ((((uint8_t)(port)) << 3U) + ((uint8_t)(pin)))

/** Macro that, given a gpio, will extract the pin number */
#define CYHAL_GET_PIN(pin)          ((uint8_t)(((uint8_t)pin) & 0x07U))
/** Macro that, given a gpio, will extract the port number */
#define CYHAL_GET_PORT(pin)         ((uint8_t)((((uint8_t)pin) >> 3U) & 0x1FU))

/** Definitions for all of the pins that are bonded out on in the 128-TQFP package for the MXS28PLAYERMCUSS series. */
typedef enum {
    NC = 0xFF, //!< No Connect/Invalid Pin

    P0_0 = CYHAL_GET_GPIO(CYHAL_PORT_0, 0), //!< Port 0 Pin 0
    P0_1 = CYHAL_GET_GPIO(CYHAL_PORT_0, 1), //!< Port 0 Pin 1
    P0_2 = CYHAL_GET_GPIO(CYHAL_PORT_0, 2), //!< Port 0 Pin 2
    P0_3 = CYHAL_GET_GPIO(CYHAL_PORT_0, 3), //!< Port 0 Pin 3
    P0_4 = CYHAL_GET_GPIO(CYHAL_PORT_0, 4), //!< Port 0 Pin 4
    P0_5 = CYHAL_GET_GPIO(CYHAL_PORT_0, 5), //!< Port 0 Pin 5

    P2_0 = CYHAL_GET_GPIO(CYHAL_PORT_2, 0), //!< Port 2 Pin 0
    P2_1 = CYHAL_GET_GPIO(CYHAL_PORT_2, 1), //!< Port 2 Pin 1
    P2_2 = CYHAL_GET_GPIO(CYHAL_PORT_2, 2), //!< Port 2 Pin 2
    P2_3 = CYHAL_GET_GPIO(CYHAL_PORT_2, 3), //!< Port 2 Pin 3
    P2_4 = CYHAL_GET_GPIO(CYHAL_PORT_2, 4), //!< Port 2 Pin 4
    P2_5 = CYHAL_GET_GPIO(CYHAL_PORT_2, 5), //!< Port 2 Pin 5

    P4_0 = CYHAL_GET_GPIO(CYHAL_PORT_4, 0), //!< Port 4 Pin 0
    P4_1 = CYHAL_GET_GPIO(CYHAL_PORT_4, 1), //!< Port 4 Pin 1
    P4_2 = CYHAL_GET_GPIO(CYHAL_PORT_4, 2), //!< Port 4 Pin 2
    P4_3 = CYHAL_GET_GPIO(CYHAL_PORT_4, 3), //!< Port 4 Pin 3

    P5_6 = CYHAL_GET_GPIO(CYHAL_PORT_5, 6), //!< Port 5 Pin 6
    P5_7 = CYHAL_GET_GPIO(CYHAL_PORT_5, 7), //!< Port 5 Pin 7

    P6_0 = CYHAL_GET_GPIO(CYHAL_PORT_6, 0), //!< Port 6 Pin 0
    P6_1 = CYHAL_GET_GPIO(CYHAL_PORT_6, 1), //!< Port 6 Pin 1
    P6_2 = CYHAL_GET_GPIO(CYHAL_PORT_6, 2), //!< Port 6 Pin 2
    P6_3 = CYHAL_GET_GPIO(CYHAL_PORT_6, 3), //!< Port 6 Pin 3
    P6_4 = CYHAL_GET_GPIO(CYHAL_PORT_6, 4), //!< Port 6 Pin 4
    P6_5 = CYHAL_GET_GPIO(CYHAL_PORT_6, 5), //!< Port 6 Pin 5
    P6_6 = CYHAL_GET_GPIO(CYHAL_PORT_6, 6), //!< Port 6 Pin 6
    P6_7 = CYHAL_GET_GPIO(CYHAL_PORT_6, 7), //!< Port 6 Pin 7

    P7_0 = CYHAL_GET_GPIO(CYHAL_PORT_7, 0), //!< Port 7 Pin 0
    P7_1 = CYHAL_GET_GPIO(CYHAL_PORT_7, 1), //!< Port 7 Pin 1
    P7_2 = CYHAL_GET_GPIO(CYHAL_PORT_7, 2), //!< Port 7 Pin 2
    P7_3 = CYHAL_GET_GPIO(CYHAL_PORT_7, 3), //!< Port 7 Pin 3
    P7_4 = CYHAL_GET_GPIO(CYHAL_PORT_7, 4), //!< Port 7 Pin 4
    P7_5 = CYHAL_GET_GPIO(CYHAL_PORT_7, 5), //!< Port 7 Pin 5
    P7_6 = CYHAL_GET_GPIO(CYHAL_PORT_7, 6), //!< Port 7 Pin 6
    P7_7 = CYHAL_GET_GPIO(CYHAL_PORT_7, 7), //!< Port 7 Pin 7

    P8_0 = CYHAL_GET_GPIO(CYHAL_PORT_8, 0), //!< Port 8 Pin 0
    P8_1 = CYHAL_GET_GPIO(CYHAL_PORT_8, 1), //!< Port 8 Pin 1
    P8_2 = CYHAL_GET_GPIO(CYHAL_PORT_8, 2), //!< Port 8 Pin 2
    P8_3 = CYHAL_GET_GPIO(CYHAL_PORT_8, 3), //!< Port 8 Pin 3

    P9_0 = CYHAL_GET_GPIO(CYHAL_PORT_9, 0), //!< Port 9 Pin 0
    P9_1 = CYHAL_GET_GPIO(CYHAL_PORT_9, 1), //!< Port 9 Pin 1
    P9_2 = CYHAL_GET_GPIO(CYHAL_PORT_9, 2), //!< Port 9 Pin 2
    P9_3 = CYHAL_GET_GPIO(CYHAL_PORT_9, 3), //!< Port 9 Pin 3

    P10_0 = CYHAL_GET_GPIO(CYHAL_PORT_10, 0), //!< Port 10 Pin 0
    P10_1 = CYHAL_GET_GPIO(CYHAL_PORT_10, 1), //!< Port 10 Pin 1
    P10_2 = CYHAL_GET_GPIO(CYHAL_PORT_10, 2), //!< Port 10 Pin 2
    P10_3 = CYHAL_GET_GPIO(CYHAL_PORT_10, 3), //!< Port 10 Pin 3

    P11_0 = CYHAL_GET_GPIO(CYHAL_PORT_11, 0), //!< Port 11 Pin 0
    P11_1 = CYHAL_GET_GPIO(CYHAL_PORT_11, 1), //!< Port 11 Pin 1
    P11_2 = CYHAL_GET_GPIO(CYHAL_PORT_11, 2), //!< Port 11 Pin 2
    P11_3 = CYHAL_GET_GPIO(CYHAL_PORT_11, 3), //!< Port 11 Pin 3
    P11_4 = CYHAL_GET_GPIO(CYHAL_PORT_11, 4), //!< Port 11 Pin 4
    P11_5 = CYHAL_GET_GPIO(CYHAL_PORT_11, 5), //!< Port 11 Pin 5
    P11_6 = CYHAL_GET_GPIO(CYHAL_PORT_11, 6), //!< Port 11 Pin 6
    P11_7 = CYHAL_GET_GPIO(CYHAL_PORT_11, 7), //!< Port 11 Pin 7

    P12_0 = CYHAL_GET_GPIO(CYHAL_PORT_12, 0), //!< Port 12 Pin 0
    P12_1 = CYHAL_GET_GPIO(CYHAL_PORT_12, 1), //!< Port 12 Pin 1
    P12_2 = CYHAL_GET_GPIO(CYHAL_PORT_12, 2), //!< Port 12 Pin 2
    P12_3 = CYHAL_GET_GPIO(CYHAL_PORT_12, 3), //!< Port 12 Pin 3
    P12_4 = CYHAL_GET_GPIO(CYHAL_PORT_12, 4), //!< Port 12 Pin 4
    P12_5 = CYHAL_GET_GPIO(CYHAL_PORT_12, 5), //!< Port 12 Pin 5
    P12_6 = CYHAL_GET_GPIO(CYHAL_PORT_12, 6), //!< Port 12 Pin 6
    P12_7 = CYHAL_GET_GPIO(CYHAL_PORT_12, 7), //!< Port 12 Pin 7

    P13_0 = CYHAL_GET_GPIO(CYHAL_PORT_13, 0), //!< Port 13 Pin 0
    P13_1 = CYHAL_GET_GPIO(CYHAL_PORT_13, 1), //!< Port 13 Pin 1
    P13_2 = CYHAL_GET_GPIO(CYHAL_PORT_13, 2), //!< Port 13 Pin 2
    P13_3 = CYHAL_GET_GPIO(CYHAL_PORT_13, 3), //!< Port 13 Pin 3
    P13_4 = CYHAL_GET_GPIO(CYHAL_PORT_13, 4), //!< Port 13 Pin 4
    P13_5 = CYHAL_GET_GPIO(CYHAL_PORT_13, 5), //!< Port 13 Pin 5
    P13_6 = CYHAL_GET_GPIO(CYHAL_PORT_13, 6), //!< Port 13 Pin 6
    P13_7 = CYHAL_GET_GPIO(CYHAL_PORT_13, 7), //!< Port 13 Pin 7

    P15_0 = CYHAL_GET_GPIO(CYHAL_PORT_15, 0), //!< Port 15 Pin 0
    P15_1 = CYHAL_GET_GPIO(CYHAL_PORT_15, 1), //!< Port 15 Pin 1
    P15_2 = CYHAL_GET_GPIO(CYHAL_PORT_15, 2), //!< Port 15 Pin 2
    P15_3 = CYHAL_GET_GPIO(CYHAL_PORT_15, 3), //!< Port 15 Pin 3
    P15_4 = CYHAL_GET_GPIO(CYHAL_PORT_15, 4), //!< Port 15 Pin 4
    P15_5 = CYHAL_GET_GPIO(CYHAL_PORT_15, 5), //!< Port 15 Pin 5
    P15_6 = CYHAL_GET_GPIO(CYHAL_PORT_15, 6), //!< Port 15 Pin 6
    P15_7 = CYHAL_GET_GPIO(CYHAL_PORT_15, 7), //!< Port 15 Pin 7

    P16_0 = CYHAL_GET_GPIO(CYHAL_PORT_16, 0), //!< Port 16 Pin 0
    P16_1 = CYHAL_GET_GPIO(CYHAL_PORT_16, 1), //!< Port 16 Pin 1
    P16_2 = CYHAL_GET_GPIO(CYHAL_PORT_16, 2), //!< Port 16 Pin 2
    P16_3 = CYHAL_GET_GPIO(CYHAL_PORT_16, 3), //!< Port 16 Pin 3
    P16_4 = CYHAL_GET_GPIO(CYHAL_PORT_16, 4), //!< Port 16 Pin 4
    P16_5 = CYHAL_GET_GPIO(CYHAL_PORT_16, 5), //!< Port 16 Pin 5
} cyhal_gpio_mxs28playermcuss_128_tqfp_t;

/** Create generic name for the series/package specific type. */
typedef cyhal_gpio_mxs28playermcuss_128_tqfp_t cyhal_gpio_t;

/* Connection type definition */
/** Represents an association between a pin and a resource */
typedef struct
{
    const cyhal_resource_inst_t  *inst;      //!< The associated resource instance
    cyhal_gpio_t                 pin;        //!< The GPIO pin
    uint8_t                      drive_mode; //!< The DriveMode configuration value
    en_hsiom_sel_t               hsiom;      //!< The HSIOM configuration value
} cyhal_resource_pin_mapping_t;

/* Pin connections */
/** Indicates that a pin map exists for bless_ext_lna_rx_ctl*/
#define CYHAL_PIN_MAP_BLESS_EXT_LNA_RX_CTL
/** List of valid pin to peripheral connections for the bless_ext_lna_rx_ctl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_ext_lna_rx_ctl[1];
/** Indicates that a pin map exists for bless_ext_pa_lna_chip_en*/
#define CYHAL_PIN_MAP_BLESS_EXT_PA_LNA_CHIP_EN
/** List of valid pin to peripheral connections for the bless_ext_pa_lna_chip_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_ext_pa_lna_chip_en[1];
/** Indicates that a pin map exists for bless_ext_pa_tx_ctl*/
#define CYHAL_PIN_MAP_BLESS_EXT_PA_TX_CTL
/** List of valid pin to peripheral connections for the bless_ext_pa_tx_ctl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_ext_pa_tx_ctl[1];
/** Indicates that a pin map exists for bless_mxd_act_bpktctl*/
#define CYHAL_PIN_MAP_BLESS_MXD_ACT_BPKTCTL
/** List of valid pin to peripheral connections for the bless_mxd_act_bpktctl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_bpktctl[1];
/** Indicates that a pin map exists for bless_mxd_act_dbus_rx_en*/
#define CYHAL_PIN_MAP_BLESS_MXD_ACT_DBUS_RX_EN
/** List of valid pin to peripheral connections for the bless_mxd_act_dbus_rx_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_dbus_rx_en[1];
/** Indicates that a pin map exists for bless_mxd_act_dbus_tx_en*/
#define CYHAL_PIN_MAP_BLESS_MXD_ACT_DBUS_TX_EN
/** List of valid pin to peripheral connections for the bless_mxd_act_dbus_tx_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_dbus_tx_en[1];
/** Indicates that a pin map exists for bless_mxd_act_txd_rxd*/
#define CYHAL_PIN_MAP_BLESS_MXD_ACT_TXD_RXD
/** List of valid pin to peripheral connections for the bless_mxd_act_txd_rxd signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_txd_rxd[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_act_ldo_en*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_ACT_LDO_EN
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_act_ldo_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_act_ldo_en[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_buck_en*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_BUCK_EN
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_buck_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_buck_en[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_clk_en*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_CLK_EN
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_clk_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_clk_en[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_dig_ldo_en*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_DIG_LDO_EN
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_dig_ldo_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_dig_ldo_en[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_isolate_n*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_ISOLATE_N
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_isolate_n signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_isolate_n[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_mxd_clk_out*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_MXD_CLK_OUT
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_mxd_clk_out signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_mxd_clk_out[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_rcb_clk*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_RCB_CLK
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_rcb_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_rcb_clk[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_rcb_data*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_RCB_DATA
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_rcb_data signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_rcb_data[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_rcb_le*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_RCB_LE
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_rcb_le signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_rcb_le[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_reset_n*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_RESET_N
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_reset_n signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_reset_n[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_ret_ldo_ol_hv*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_RET_LDO_OL_HV
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_ret_ldo_ol_hv signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_ret_ldo_ol_hv[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_ret_switch_hv*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_RET_SWITCH_HV
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_ret_switch_hv signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_ret_switch_hv[1];
/** Indicates that a pin map exists for bless_mxd_dpslp_xtal_en*/
#define CYHAL_PIN_MAP_BLESS_MXD_DPSLP_XTAL_EN
/** List of valid pin to peripheral connections for the bless_mxd_dpslp_xtal_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_xtal_en[1];
/** Indicates that a pin map exists for eth_eth_tsu_timer_cmp_val*/
#define CYHAL_PIN_MAP_ETH_ETH_TSU_TIMER_CMP_VAL
/** List of valid pin to peripheral connections for the eth_eth_tsu_timer_cmp_val signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_eth_tsu_timer_cmp_val[1];
/** Indicates that a pin map exists for eth_mdc*/
#define CYHAL_PIN_MAP_ETH_MDC
/** List of valid pin to peripheral connections for the eth_mdc signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_mdc[1];
/** Indicates that a pin map exists for eth_mdio*/
#define CYHAL_PIN_MAP_ETH_MDIO
/** List of valid pin to peripheral connections for the eth_mdio signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_mdio[1];
/** Indicates that a pin map exists for eth_ref_clk*/
#define CYHAL_PIN_MAP_ETH_REF_CLK
/** List of valid pin to peripheral connections for the eth_ref_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_ref_clk[1];
/** Indicates that a pin map exists for eth_rx_ctl*/
#define CYHAL_PIN_MAP_ETH_RX_CTL
/** List of valid pin to peripheral connections for the eth_rx_ctl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_rx_ctl[1];
/** Indicates that a pin map exists for eth_rx_er*/
#define CYHAL_PIN_MAP_ETH_RX_ER
/** List of valid pin to peripheral connections for the eth_rx_er signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_rx_er[1];
/** Indicates that a pin map exists for eth_rxd*/
#define CYHAL_PIN_MAP_ETH_RXD
/** List of valid pin to peripheral connections for the eth_rxd signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_rxd[2];
/** Indicates that a pin map exists for eth_tx_clk*/
#define CYHAL_PIN_MAP_ETH_TX_CLK
/** List of valid pin to peripheral connections for the eth_tx_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_tx_clk[1];
/** Indicates that a pin map exists for eth_tx_ctl*/
#define CYHAL_PIN_MAP_ETH_TX_CTL
/** List of valid pin to peripheral connections for the eth_tx_ctl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_tx_ctl[1];
/** Indicates that a pin map exists for eth_txd*/
#define CYHAL_PIN_MAP_ETH_TXD
/** List of valid pin to peripheral connections for the eth_txd signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_txd[2];
/** Indicates that a pin map exists for i3c_i3c_scl*/
#define CYHAL_PIN_MAP_I3C_I3C_SCL
/** List of valid pin to peripheral connections for the i3c_i3c_scl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_i3c_i3c_scl[1];
/** Indicates that a pin map exists for i3c_i3c_sda*/
#define CYHAL_PIN_MAP_I3C_I3C_SDA
/** List of valid pin to peripheral connections for the i3c_i3c_sda signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_i3c_i3c_sda[1];
/** Indicates that a pin map exists for i3c_i3c_sda_pullup_en*/
#define CYHAL_PIN_MAP_I3C_I3C_SDA_PULLUP_EN
/** List of valid pin to peripheral connections for the i3c_i3c_sda_pullup_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_i3c_i3c_sda_pullup_en[2];
/** Indicates that a pin map exists for pdm_pdm_clk*/
#define CYHAL_PIN_MAP_PDM_PDM_CLK
/** List of valid pin to peripheral connections for the pdm_pdm_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_pdm_pdm_clk[5];
/** Indicates that a pin map exists for pdm_pdm_data*/
#define CYHAL_PIN_MAP_PDM_PDM_DATA
/** List of valid pin to peripheral connections for the pdm_pdm_data signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_pdm_pdm_data[5];
/** Indicates that a pin map exists for peri_tr_io_input*/
#define CYHAL_PIN_MAP_PERI_TR_IO_INPUT
/** List of valid pin to peripheral connections for the peri_tr_io_input signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_input[28];
/** Indicates that a pin map exists for peri_tr_io_output*/
#define CYHAL_PIN_MAP_PERI_TR_IO_OUTPUT
/** List of valid pin to peripheral connections for the peri_tr_io_output signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_output[6];
/** Indicates that a pin map exists for scb_i2c_scl*/
#define CYHAL_PIN_MAP_SCB_I2C_SCL
/** List of valid pin to peripheral connections for the scb_i2c_scl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_scl[14];
/** Indicates that a pin map exists for scb_i2c_sda*/
#define CYHAL_PIN_MAP_SCB_I2C_SDA
/** List of valid pin to peripheral connections for the scb_i2c_sda signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_sda[14];
/** Indicates that a pin map exists for scb_spi_m_clk*/
#define CYHAL_PIN_MAP_SCB_SPI_M_CLK
/** List of valid pin to peripheral connections for the scb_spi_m_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_clk[14];
/** Indicates that a pin map exists for scb_spi_m_miso*/
#define CYHAL_PIN_MAP_SCB_SPI_M_MISO
/** List of valid pin to peripheral connections for the scb_spi_m_miso signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_miso[14];
/** Indicates that a pin map exists for scb_spi_m_mosi*/
#define CYHAL_PIN_MAP_SCB_SPI_M_MOSI
/** List of valid pin to peripheral connections for the scb_spi_m_mosi signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_mosi[14];
/** Indicates that a pin map exists for scb_spi_m_select0*/
#define CYHAL_PIN_MAP_SCB_SPI_M_SELECT0
/** List of valid pin to peripheral connections for the scb_spi_m_select0 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select0[14];
/** Indicates that a pin map exists for scb_spi_m_select1*/
#define CYHAL_PIN_MAP_SCB_SPI_M_SELECT1
/** List of valid pin to peripheral connections for the scb_spi_m_select1 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select1[7];
/** Indicates that a pin map exists for scb_spi_m_select2*/
#define CYHAL_PIN_MAP_SCB_SPI_M_SELECT2
/** List of valid pin to peripheral connections for the scb_spi_m_select2 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select2[7];
/** Indicates that a pin map exists for scb_spi_m_select3*/
#define CYHAL_PIN_MAP_SCB_SPI_M_SELECT3
/** List of valid pin to peripheral connections for the scb_spi_m_select3 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select3[4];
/** Indicates that a pin map exists for scb_spi_s_clk*/
#define CYHAL_PIN_MAP_SCB_SPI_S_CLK
/** List of valid pin to peripheral connections for the scb_spi_s_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_clk[14];
/** Indicates that a pin map exists for scb_spi_s_miso*/
#define CYHAL_PIN_MAP_SCB_SPI_S_MISO
/** List of valid pin to peripheral connections for the scb_spi_s_miso signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_miso[14];
/** Indicates that a pin map exists for scb_spi_s_mosi*/
#define CYHAL_PIN_MAP_SCB_SPI_S_MOSI
/** List of valid pin to peripheral connections for the scb_spi_s_mosi signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_mosi[14];
/** Indicates that a pin map exists for scb_spi_s_select0*/
#define CYHAL_PIN_MAP_SCB_SPI_S_SELECT0
/** List of valid pin to peripheral connections for the scb_spi_s_select0 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select0[14];
/** Indicates that a pin map exists for scb_spi_s_select1*/
#define CYHAL_PIN_MAP_SCB_SPI_S_SELECT1
/** List of valid pin to peripheral connections for the scb_spi_s_select1 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select1[7];
/** Indicates that a pin map exists for scb_spi_s_select2*/
#define CYHAL_PIN_MAP_SCB_SPI_S_SELECT2
/** List of valid pin to peripheral connections for the scb_spi_s_select2 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select2[7];
/** Indicates that a pin map exists for scb_spi_s_select3*/
#define CYHAL_PIN_MAP_SCB_SPI_S_SELECT3
/** List of valid pin to peripheral connections for the scb_spi_s_select3 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select3[4];
/** Indicates that a pin map exists for scb_uart_cts*/
#define CYHAL_PIN_MAP_SCB_UART_CTS
/** List of valid pin to peripheral connections for the scb_uart_cts signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_cts[12];
/** Indicates that a pin map exists for scb_uart_rts*/
#define CYHAL_PIN_MAP_SCB_UART_RTS
/** List of valid pin to peripheral connections for the scb_uart_rts signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rts[12];
/** Indicates that a pin map exists for scb_uart_rx*/
#define CYHAL_PIN_MAP_SCB_UART_RX
/** List of valid pin to peripheral connections for the scb_uart_rx signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rx[12];
/** Indicates that a pin map exists for scb_uart_tx*/
#define CYHAL_PIN_MAP_SCB_UART_TX
/** List of valid pin to peripheral connections for the scb_uart_tx signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_tx[12];
/** Indicates that a pin map exists for sdhc_card_cmd*/
#define CYHAL_PIN_MAP_SDHC_CARD_CMD
/** List of valid pin to peripheral connections for the sdhc_card_cmd signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_cmd[1];
/** Indicates that a pin map exists for sdhc_card_dat_3to0*/
#define CYHAL_PIN_MAP_SDHC_CARD_DAT_3TO0
/** List of valid pin to peripheral connections for the sdhc_card_dat_3to0 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_dat_3to0[4];
/** Indicates that a pin map exists for sdhc_card_dat_7to4*/
#define CYHAL_PIN_MAP_SDHC_CARD_DAT_7TO4
/** List of valid pin to peripheral connections for the sdhc_card_dat_7to4 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_dat_7to4[4];
/** Indicates that a pin map exists for sdhc_card_detect_n*/
#define CYHAL_PIN_MAP_SDHC_CARD_DETECT_N
/** List of valid pin to peripheral connections for the sdhc_card_detect_n signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_detect_n[1];
/** Indicates that a pin map exists for sdhc_card_emmc_reset_n*/
#define CYHAL_PIN_MAP_SDHC_CARD_EMMC_RESET_N
/** List of valid pin to peripheral connections for the sdhc_card_emmc_reset_n signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_emmc_reset_n[1];
/** Indicates that a pin map exists for sdhc_card_if_pwr_en*/
#define CYHAL_PIN_MAP_SDHC_CARD_IF_PWR_EN
/** List of valid pin to peripheral connections for the sdhc_card_if_pwr_en signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_if_pwr_en[1];
/** Indicates that a pin map exists for sdhc_card_mech_write_prot*/
#define CYHAL_PIN_MAP_SDHC_CARD_MECH_WRITE_PROT
/** List of valid pin to peripheral connections for the sdhc_card_mech_write_prot signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_mech_write_prot[1];
/** Indicates that a pin map exists for sdhc_clk_card*/
#define CYHAL_PIN_MAP_SDHC_CLK_CARD
/** List of valid pin to peripheral connections for the sdhc_clk_card signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_clk_card[1];
/** Indicates that a pin map exists for sdhc_io_volt_sel*/
#define CYHAL_PIN_MAP_SDHC_IO_VOLT_SEL
/** List of valid pin to peripheral connections for the sdhc_io_volt_sel signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_io_volt_sel[1];
/** Indicates that a pin map exists for sdhc_led_ctrl*/
#define CYHAL_PIN_MAP_SDHC_LED_CTRL
/** List of valid pin to peripheral connections for the sdhc_led_ctrl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_led_ctrl[1];
/** Indicates that a pin map exists for sdiodev_sdio_clk*/
#define CYHAL_PIN_MAP_SDIODEV_SDIO_CLK
/** List of valid pin to peripheral connections for the sdiodev_sdio_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdiodev_sdio_clk[1];
/** Indicates that a pin map exists for sdiodev_sdio_cmd*/
#define CYHAL_PIN_MAP_SDIODEV_SDIO_CMD
/** List of valid pin to peripheral connections for the sdiodev_sdio_cmd signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdiodev_sdio_cmd[1];
/** Indicates that a pin map exists for sdiodev_sdio_data*/
#define CYHAL_PIN_MAP_SDIODEV_SDIO_DATA
/** List of valid pin to peripheral connections for the sdiodev_sdio_data signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_sdiodev_sdio_data[4];
/** Indicates that a pin map exists for smif_spi_clk*/
#define CYHAL_PIN_MAP_SMIF_SPI_CLK
/** List of valid pin to peripheral connections for the smif_spi_clk signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_clk[1];
/** Indicates that a pin map exists for smif_spi_data0*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA0
/** List of valid pin to peripheral connections for the smif_spi_data0 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data0[1];
/** Indicates that a pin map exists for smif_spi_data1*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA1
/** List of valid pin to peripheral connections for the smif_spi_data1 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data1[1];
/** Indicates that a pin map exists for smif_spi_data2*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA2
/** List of valid pin to peripheral connections for the smif_spi_data2 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data2[1];
/** Indicates that a pin map exists for smif_spi_data3*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA3
/** List of valid pin to peripheral connections for the smif_spi_data3 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data3[1];
/** Indicates that a pin map exists for smif_spi_data4*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA4
/** List of valid pin to peripheral connections for the smif_spi_data4 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data4[1];
/** Indicates that a pin map exists for smif_spi_data5*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA5
/** List of valid pin to peripheral connections for the smif_spi_data5 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data5[1];
/** Indicates that a pin map exists for smif_spi_data6*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA6
/** List of valid pin to peripheral connections for the smif_spi_data6 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data6[1];
/** Indicates that a pin map exists for smif_spi_data7*/
#define CYHAL_PIN_MAP_SMIF_SPI_DATA7
/** List of valid pin to peripheral connections for the smif_spi_data7 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data7[1];
/** Indicates that a pin map exists for smif_spi_rwds*/
#define CYHAL_PIN_MAP_SMIF_SPI_RWDS
/** List of valid pin to peripheral connections for the smif_spi_rwds signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_rwds[1];
/** Indicates that a pin map exists for smif_spi_select0*/
#define CYHAL_PIN_MAP_SMIF_SPI_SELECT0
/** List of valid pin to peripheral connections for the smif_spi_select0 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select0[1];
/** Indicates that a pin map exists for smif_spi_select1*/
#define CYHAL_PIN_MAP_SMIF_SPI_SELECT1
/** List of valid pin to peripheral connections for the smif_spi_select1 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select1[1];
/** Indicates that a pin map exists for smif_spi_select2*/
#define CYHAL_PIN_MAP_SMIF_SPI_SELECT2
/** List of valid pin to peripheral connections for the smif_spi_select2 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select2[1];
/** Indicates that a pin map exists for smif_spi_select3*/
#define CYHAL_PIN_MAP_SMIF_SPI_SELECT3
/** List of valid pin to peripheral connections for the smif_spi_select3 signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select3[1];
/** Indicates that a pin map exists for tcpwm_line*/
#define CYHAL_PIN_MAP_TCPWM_LINE
/** List of valid pin to peripheral connections for the tcpwm_line signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line[84];
/** Indicates that a pin map exists for tcpwm_line_compl*/
#define CYHAL_PIN_MAP_TCPWM_LINE_COMPL
/** List of valid pin to peripheral connections for the tcpwm_line_compl signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line_compl[84];
/** Indicates that a pin map exists for tdm_tdm_rx_fsync*/
#define CYHAL_PIN_MAP_TDM_TDM_RX_FSYNC
/** List of valid pin to peripheral connections for the tdm_tdm_rx_fsync signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_fsync[3];
/** Indicates that a pin map exists for tdm_tdm_rx_mck*/
#define CYHAL_PIN_MAP_TDM_TDM_RX_MCK
/** List of valid pin to peripheral connections for the tdm_tdm_rx_mck signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_mck[3];
/** Indicates that a pin map exists for tdm_tdm_rx_sck*/
#define CYHAL_PIN_MAP_TDM_TDM_RX_SCK
/** List of valid pin to peripheral connections for the tdm_tdm_rx_sck signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_sck[3];
/** Indicates that a pin map exists for tdm_tdm_rx_sd*/
#define CYHAL_PIN_MAP_TDM_TDM_RX_SD
/** List of valid pin to peripheral connections for the tdm_tdm_rx_sd signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_sd[3];
/** Indicates that a pin map exists for tdm_tdm_tx_fsync*/
#define CYHAL_PIN_MAP_TDM_TDM_TX_FSYNC
/** List of valid pin to peripheral connections for the tdm_tdm_tx_fsync signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_fsync[3];
/** Indicates that a pin map exists for tdm_tdm_tx_mck*/
#define CYHAL_PIN_MAP_TDM_TDM_TX_MCK
/** List of valid pin to peripheral connections for the tdm_tdm_tx_mck signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_mck[3];
/** Indicates that a pin map exists for tdm_tdm_tx_sck*/
#define CYHAL_PIN_MAP_TDM_TDM_TX_SCK
/** List of valid pin to peripheral connections for the tdm_tdm_tx_sck signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_sck[3];
/** Indicates that a pin map exists for tdm_tdm_tx_sd*/
#define CYHAL_PIN_MAP_TDM_TDM_TX_SD
/** List of valid pin to peripheral connections for the tdm_tdm_tx_sd signal. */
extern const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_sd[3];

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/** \} group_hal_impl_pin_package */

#endif /* _CYHAL_MXS28PLAYERMCUSS_128_TQFP_H_ */


/* [] END OF FILE */
