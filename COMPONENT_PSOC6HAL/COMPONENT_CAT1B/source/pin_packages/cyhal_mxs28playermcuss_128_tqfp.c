/***************************************************************************//**
* \file cyhal_mxs28playermcuss_128_tqfp.c
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

#include "cy_device_headers.h"
#include "cyhal_hw_types.h"

#if defined(_GPIO_MXS28PLAYERMCUSS_128_TQFP_H_)
#include "pin_packages/cyhal_mxs28playermcuss_128_tqfp.h"

/* Hardware Blocks */
static const cyhal_resource_inst_t CYHAL_BLESS_0 = { CYHAL_RSC_BLESS, 0, 0 };
static const cyhal_resource_inst_t CYHAL_ETH_0 = { CYHAL_RSC_ETH, 0, 0 };
static const cyhal_resource_inst_t CYHAL_I3C_0 = { CYHAL_RSC_I3C, 0, 0 };
static const cyhal_resource_inst_t CYHAL_PDM_0_0 = { CYHAL_RSC_PDM, 0, 0 };
static const cyhal_resource_inst_t CYHAL_PDM_0_1 = { CYHAL_RSC_PDM, 0, 1 };
static const cyhal_resource_inst_t CYHAL_PDM_0_2 = { CYHAL_RSC_PDM, 0, 2 };
static const cyhal_resource_inst_t CYHAL_SCB_0 = { CYHAL_RSC_SCB, 0, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_1 = { CYHAL_RSC_SCB, 1, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_2 = { CYHAL_RSC_SCB, 2, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_3 = { CYHAL_RSC_SCB, 3, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_4 = { CYHAL_RSC_SCB, 4, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_5 = { CYHAL_RSC_SCB, 5, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_6 = { CYHAL_RSC_SCB, 6, 0 };
static const cyhal_resource_inst_t CYHAL_SCB_7 = { CYHAL_RSC_SCB, 7, 0 };
static const cyhal_resource_inst_t CYHAL_SDHC_1 = { CYHAL_RSC_SDHC, 1, 0 };
static const cyhal_resource_inst_t CYHAL_SDIODEV_0 = { CYHAL_RSC_SDIODEV, 0, 0 };
static const cyhal_resource_inst_t CYHAL_SMIF_0 = { CYHAL_RSC_SMIF, 0, 0 };
static const cyhal_resource_inst_t CYHAL_TCPWM_0_0 = { CYHAL_RSC_TCPWM, 0, 0 };
static const cyhal_resource_inst_t CYHAL_TCPWM_0_1 = { CYHAL_RSC_TCPWM, 0, 1 };
static const cyhal_resource_inst_t CYHAL_TCPWM_0_2 = { CYHAL_RSC_TCPWM, 0, 2 };
static const cyhal_resource_inst_t CYHAL_TCPWM_0_3 = { CYHAL_RSC_TCPWM, 0, 3 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_0 = { CYHAL_RSC_TCPWM, 1, 0 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_1 = { CYHAL_RSC_TCPWM, 1, 1 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_10 = { CYHAL_RSC_TCPWM, 1, 10 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_11 = { CYHAL_RSC_TCPWM, 1, 11 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_12 = { CYHAL_RSC_TCPWM, 1, 12 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_13 = { CYHAL_RSC_TCPWM, 1, 13 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_14 = { CYHAL_RSC_TCPWM, 1, 14 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_15 = { CYHAL_RSC_TCPWM, 1, 15 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_2 = { CYHAL_RSC_TCPWM, 1, 2 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_3 = { CYHAL_RSC_TCPWM, 1, 3 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_4 = { CYHAL_RSC_TCPWM, 1, 4 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_5 = { CYHAL_RSC_TCPWM, 1, 5 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_6 = { CYHAL_RSC_TCPWM, 1, 6 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_7 = { CYHAL_RSC_TCPWM, 1, 7 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_8 = { CYHAL_RSC_TCPWM, 1, 8 };
static const cyhal_resource_inst_t CYHAL_TCPWM_1_9 = { CYHAL_RSC_TCPWM, 1, 9 };
static const cyhal_resource_inst_t CYHAL_TDM_0 = { CYHAL_RSC_TDM, 0, 0 };

/* Pin connections */
/* Connections for: bless_ext_lna_rx_ctl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_ext_lna_rx_ctl[1] = {
    {&CYHAL_BLESS_0, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_BLESS_EXT_LNA_RX_CTL},
};

/* Connections for: bless_ext_pa_lna_chip_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_ext_pa_lna_chip_en[1] = {
    {&CYHAL_BLESS_0, P5_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_7_BLESS_EXT_PA_LNA_CHIP_EN},
};

/* Connections for: bless_ext_pa_tx_ctl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_ext_pa_tx_ctl[1] = {
    {&CYHAL_BLESS_0, P5_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_6_BLESS_EXT_PA_TX_CTL},
};

/* Connections for: bless_mxd_act_bpktctl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_bpktctl[1] = {
    {&CYHAL_BLESS_0, P16_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_3_BLESS_MXD_ACT_BPKTCTL},
};

/* Connections for: bless_mxd_act_dbus_rx_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_dbus_rx_en[1] = {
    {&CYHAL_BLESS_0, P16_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_1_BLESS_MXD_ACT_DBUS_RX_EN},
};

/* Connections for: bless_mxd_act_dbus_tx_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_dbus_tx_en[1] = {
    {&CYHAL_BLESS_0, P16_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_2_BLESS_MXD_ACT_DBUS_TX_EN},
};

/* Connections for: bless_mxd_act_txd_rxd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_act_txd_rxd[1] = {
    {&CYHAL_BLESS_0, P16_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_4_BLESS_MXD_ACT_TXD_RXD},
};

/* Connections for: bless_mxd_dpslp_act_ldo_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_act_ldo_en[1] = {
    {&CYHAL_BLESS_0, P15_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_6_BLESS_MXD_DPSLP_ACT_LDO_EN},
};

/* Connections for: bless_mxd_dpslp_buck_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_buck_en[1] = {
    {&CYHAL_BLESS_0, P15_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_2_BLESS_MXD_DPSLP_BUCK_EN},
};

/* Connections for: bless_mxd_dpslp_clk_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_clk_en[1] = {
    {&CYHAL_BLESS_0, P15_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_4_BLESS_MXD_DPSLP_CLK_EN},
};

/* Connections for: bless_mxd_dpslp_dig_ldo_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_dig_ldo_en[1] = {
    {&CYHAL_BLESS_0, P16_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_0_BLESS_MXD_DPSLP_DIG_LDO_EN},
};

/* Connections for: bless_mxd_dpslp_isolate_n */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_isolate_n[1] = {
    {&CYHAL_BLESS_0, P15_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_5_BLESS_MXD_DPSLP_ISOLATE_N},
};

/* Connections for: bless_mxd_dpslp_mxd_clk_out */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_mxd_clk_out[1] = {
    {&CYHAL_BLESS_0, P4_3, (uint8_t)CY_GPIO_DM_HIGHZ, P4_3_BLESS_MXD_DPSLP_MXD_CLK_OUT},
};

/* Connections for: bless_mxd_dpslp_rcb_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_rcb_clk[1] = {
    {&CYHAL_BLESS_0, P4_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_0_BLESS_MXD_DPSLP_RCB_CLK},
};

/* Connections for: bless_mxd_dpslp_rcb_data */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_rcb_data[1] = {
    {&CYHAL_BLESS_0, P16_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_5_BLESS_MXD_DPSLP_RCB_DATA},
};

/* Connections for: bless_mxd_dpslp_rcb_le */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_rcb_le[1] = {
    {&CYHAL_BLESS_0, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_BLESS_MXD_DPSLP_RCB_LE},
};

/* Connections for: bless_mxd_dpslp_reset_n */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_reset_n[1] = {
    {&CYHAL_BLESS_0, P15_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_3_BLESS_MXD_DPSLP_RESET_N},
};

/* Connections for: bless_mxd_dpslp_ret_ldo_ol_hv */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_ret_ldo_ol_hv[1] = {
    {&CYHAL_BLESS_0, P15_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_1_BLESS_MXD_DPSLP_RET_LDO_OL_HV},
};

/* Connections for: bless_mxd_dpslp_ret_switch_hv */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_ret_switch_hv[1] = {
    {&CYHAL_BLESS_0, P15_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_0_BLESS_MXD_DPSLP_RET_SWITCH_HV},
};

/* Connections for: bless_mxd_dpslp_xtal_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_bless_mxd_dpslp_xtal_en[1] = {
    {&CYHAL_BLESS_0, P15_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_7_BLESS_MXD_DPSLP_XTAL_EN},
};

/* Connections for: eth_eth_tsu_timer_cmp_val */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_eth_tsu_timer_cmp_val[1] = {
    {&CYHAL_ETH_0, P12_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_4_ETH0_ETH_TSU_TIMER_CMP_VAL},
};

/* Connections for: eth_mdc */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_mdc[1] = {
    {&CYHAL_ETH_0, P12_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_6_ETH0_MDC},
};

/* Connections for: eth_mdio */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_mdio[1] = {
    {&CYHAL_ETH_0, P12_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_7_ETH0_MDIO},
};

/* Connections for: eth_ref_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_ref_clk[1] = {
    {&CYHAL_ETH_0, P13_7, (uint8_t)CY_GPIO_DM_HIGHZ, P13_7_ETH0_REF_CLK},
};

/* Connections for: eth_rx_ctl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_rx_ctl[1] = {
    {&CYHAL_ETH_0, P2_0, (uint8_t)CY_GPIO_DM_HIGHZ, P2_0_ETH0_RX_CTL},
};

/* Connections for: eth_rx_er */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_rx_er[1] = {
    {&CYHAL_ETH_0, P12_3, (uint8_t)CY_GPIO_DM_HIGHZ, P12_3_ETH0_RX_ER},
};

/* Connections for: eth_rxd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_rxd[2] = {
    {&CYHAL_ETH_0, P2_1, (uint8_t)CY_GPIO_DM_HIGHZ, P2_1_ETH0_RXD0},
    {&CYHAL_ETH_0, P2_2, (uint8_t)CY_GPIO_DM_HIGHZ, P2_2_ETH0_RXD1},
};

/* Connections for: eth_tx_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_tx_clk[1] = {
    {&CYHAL_ETH_0, P13_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_7_ETH0_TX_CLK},
};

/* Connections for: eth_tx_ctl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_tx_ctl[1] = {
    {&CYHAL_ETH_0, P2_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_5_ETH0_TX_CTL},
};

/* Connections for: eth_txd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_eth_txd[2] = {
    {&CYHAL_ETH_0, P2_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_3_ETH0_TXD0},
    {&CYHAL_ETH_0, P2_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_4_ETH0_TXD1},
};

/* Connections for: i3c_i3c_scl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_i3c_i3c_scl[1] = {
    {&CYHAL_I3C_0, P11_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P11_0_I3C_I3C_SCL},
};

/* Connections for: i3c_i3c_sda */
const cyhal_resource_pin_mapping_t cyhal_pin_map_i3c_i3c_sda[1] = {
    {&CYHAL_I3C_0, P11_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P11_1_I3C_I3C_SDA},
};

/* Connections for: i3c_i3c_sda_pullup_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_i3c_i3c_sda_pullup_en[2] = {
    {&CYHAL_I3C_0, P9_3, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P9_3_I3C_I3C_SDA_PULLUP_EN},
    {&CYHAL_I3C_0, P10_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P10_1_I3C_I3C_SDA_PULLUP_EN},
};

/* Connections for: pdm_pdm_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pdm_pdm_clk[5] = {
    {&CYHAL_PDM_0_1, P2_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_0_PDM_PDM_CLK1},
    {&CYHAL_PDM_0_1, P5_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_6_PDM_PDM_CLK1},
    {&CYHAL_PDM_0_0, P6_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_2_PDM_PDM_CLK0},
    {&CYHAL_PDM_0_0, P12_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_6_PDM_PDM_CLK0},
    {&CYHAL_PDM_0_2, P15_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_0_PDM_PDM_CLK2},
};

/* Connections for: pdm_pdm_data */
const cyhal_resource_pin_mapping_t cyhal_pin_map_pdm_pdm_data[5] = {
    {&CYHAL_PDM_0_1, P2_1, (uint8_t)CY_GPIO_DM_HIGHZ, P2_1_PDM_PDM_DATA1},
    {&CYHAL_PDM_0_1, P5_7, (uint8_t)CY_GPIO_DM_HIGHZ, P5_7_PDM_PDM_DATA1},
    {&CYHAL_PDM_0_0, P6_3, (uint8_t)CY_GPIO_DM_HIGHZ, P6_3_PDM_PDM_DATA0},
    {&CYHAL_PDM_0_0, P12_7, (uint8_t)CY_GPIO_DM_HIGHZ, P12_7_PDM_PDM_DATA0},
    {&CYHAL_PDM_0_2, P15_1, (uint8_t)CY_GPIO_DM_HIGHZ, P15_1_PDM_PDM_DATA2},
};

/* Connections for: peri_tr_io_input */
/* Since the GPIO pin is already specified there is no need to specify a particular resource for every entry.
   Instead set the resource_inst field to the index of the input or output trigger line. */
const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_input[28] = {
    {(cyhal_resource_inst_t*)0, P0_0, (uint8_t)CY_GPIO_DM_HIGHZ, P0_0_PERI_TR_IO_INPUT0},
    {(cyhal_resource_inst_t*)1, P0_1, (uint8_t)CY_GPIO_DM_HIGHZ, P0_1_PERI_TR_IO_INPUT1},
    {(cyhal_resource_inst_t*)2, P0_2, (uint8_t)CY_GPIO_DM_HIGHZ, P0_2_PERI_TR_IO_INPUT2},
    {(cyhal_resource_inst_t*)3, P0_3, (uint8_t)CY_GPIO_DM_HIGHZ, P0_3_PERI_TR_IO_INPUT3},
    {(cyhal_resource_inst_t*)4, P2_0, (uint8_t)CY_GPIO_DM_HIGHZ, P2_0_PERI_TR_IO_INPUT4},
    {(cyhal_resource_inst_t*)5, P2_1, (uint8_t)CY_GPIO_DM_HIGHZ, P2_1_PERI_TR_IO_INPUT5},
    {(cyhal_resource_inst_t*)8, P4_0, (uint8_t)CY_GPIO_DM_HIGHZ, P4_0_PERI_TR_IO_INPUT8},
    {(cyhal_resource_inst_t*)9, P4_1, (uint8_t)CY_GPIO_DM_HIGHZ, P4_1_PERI_TR_IO_INPUT9},
    {(cyhal_resource_inst_t*)10, P5_6, (uint8_t)CY_GPIO_DM_HIGHZ, P5_6_PERI_TR_IO_INPUT10},
    {(cyhal_resource_inst_t*)11, P5_7, (uint8_t)CY_GPIO_DM_HIGHZ, P5_7_PERI_TR_IO_INPUT11},
    {(cyhal_resource_inst_t*)12, P6_4, (uint8_t)CY_GPIO_DM_HIGHZ, P6_4_PERI_TR_IO_INPUT12},
    {(cyhal_resource_inst_t*)13, P6_5, (uint8_t)CY_GPIO_DM_HIGHZ, P6_5_PERI_TR_IO_INPUT13},
    {(cyhal_resource_inst_t*)14, P7_0, (uint8_t)CY_GPIO_DM_HIGHZ, P7_0_PERI_TR_IO_INPUT14},
    {(cyhal_resource_inst_t*)15, P7_1, (uint8_t)CY_GPIO_DM_HIGHZ, P7_1_PERI_TR_IO_INPUT15},
    {(cyhal_resource_inst_t*)16, P8_0, (uint8_t)CY_GPIO_DM_HIGHZ, P8_0_PERI_TR_IO_INPUT16},
    {(cyhal_resource_inst_t*)17, P8_1, (uint8_t)CY_GPIO_DM_HIGHZ, P8_1_PERI_TR_IO_INPUT17},
    {(cyhal_resource_inst_t*)18, P9_0, (uint8_t)CY_GPIO_DM_HIGHZ, P9_0_PERI_TR_IO_INPUT18},
    {(cyhal_resource_inst_t*)19, P9_1, (uint8_t)CY_GPIO_DM_HIGHZ, P9_1_PERI_TR_IO_INPUT19},
    {(cyhal_resource_inst_t*)20, P10_0, (uint8_t)CY_GPIO_DM_HIGHZ, P10_0_PERI_TR_IO_INPUT20},
    {(cyhal_resource_inst_t*)21, P10_1, (uint8_t)CY_GPIO_DM_HIGHZ, P10_1_PERI_TR_IO_INPUT21},
    {(cyhal_resource_inst_t*)22, P11_0, (uint8_t)CY_GPIO_DM_HIGHZ, P11_0_PERI_TR_IO_INPUT22},
    {(cyhal_resource_inst_t*)23, P11_1, (uint8_t)CY_GPIO_DM_HIGHZ, P11_1_PERI_TR_IO_INPUT23},
    {(cyhal_resource_inst_t*)24, P12_0, (uint8_t)CY_GPIO_DM_HIGHZ, P12_0_PERI_TR_IO_INPUT24},
    {(cyhal_resource_inst_t*)25, P12_1, (uint8_t)CY_GPIO_DM_HIGHZ, P12_1_PERI_TR_IO_INPUT25},
    {(cyhal_resource_inst_t*)26, P13_0, (uint8_t)CY_GPIO_DM_HIGHZ, P13_0_PERI_TR_IO_INPUT26},
    {(cyhal_resource_inst_t*)27, P13_1, (uint8_t)CY_GPIO_DM_HIGHZ, P13_1_PERI_TR_IO_INPUT27},
    {(cyhal_resource_inst_t*)6, P16_2, (uint8_t)CY_GPIO_DM_HIGHZ, P16_2_PERI_TR_IO_INPUT6},
    {(cyhal_resource_inst_t*)7, P16_3, (uint8_t)CY_GPIO_DM_HIGHZ, P16_3_PERI_TR_IO_INPUT7},
};

/* Connections for: peri_tr_io_output */
/* Since the GPIO pin is already specified there is no need to specify a particular resource for every entry.
   Instead set the resource_inst field to the index of the input or output trigger line. */
const cyhal_resource_pin_mapping_t cyhal_pin_map_peri_tr_io_output[6] = {
    {(cyhal_resource_inst_t*)0, P0_4, (uint8_t)CY_GPIO_DM_HIGHZ, P0_4_PERI_TR_IO_OUTPUT0},
    {(cyhal_resource_inst_t*)1, P0_5, (uint8_t)CY_GPIO_DM_HIGHZ, P0_5_PERI_TR_IO_OUTPUT1},
    {(cyhal_resource_inst_t*)0, P6_4, (uint8_t)CY_GPIO_DM_HIGHZ, P6_4_PERI_TR_IO_OUTPUT0},
    {(cyhal_resource_inst_t*)1, P6_5, (uint8_t)CY_GPIO_DM_HIGHZ, P6_5_PERI_TR_IO_OUTPUT1},
    {(cyhal_resource_inst_t*)0, P11_3, (uint8_t)CY_GPIO_DM_HIGHZ, P11_3_PERI_TR_IO_OUTPUT0},
    {(cyhal_resource_inst_t*)1, P11_4, (uint8_t)CY_GPIO_DM_HIGHZ, P11_4_PERI_TR_IO_OUTPUT1},
};

/* Connections for: scb_i2c_scl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_scl[14] = {
    {&CYHAL_SCB_0, P0_2, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P0_2_SCB0_I2C_SCL},
    {&CYHAL_SCB_1, P2_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P2_0_SCB1_I2C_SCL},
    {&CYHAL_SCB_7, P4_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P4_0_SCB7_I2C_SCL},
    {&CYHAL_SCB_3, P6_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P6_0_SCB3_I2C_SCL},
    {&CYHAL_SCB_6, P6_4, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P6_4_SCB6_I2C_SCL},
    {&CYHAL_SCB_4, P7_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P7_0_SCB4_I2C_SCL},
    {&CYHAL_SCB_4, P8_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P8_0_SCB4_I2C_SCL},
    {&CYHAL_SCB_2, P9_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P9_0_SCB2_I2C_SCL},
    {&CYHAL_SCB_1, P10_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P10_0_SCB1_I2C_SCL},
    {&CYHAL_SCB_5, P11_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P11_0_SCB5_I2C_SCL},
    {&CYHAL_SCB_6, P12_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P12_0_SCB6_I2C_SCL},
    {&CYHAL_SCB_6, P13_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P13_0_SCB6_I2C_SCL},
    {&CYHAL_SCB_5, P15_2, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P15_2_SCB5_I2C_SCL},
    {&CYHAL_SCB_0, P16_0, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P16_0_SCB0_I2C_SCL},
};

/* Connections for: scb_i2c_sda */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_i2c_sda[14] = {
    {&CYHAL_SCB_0, P0_3, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P0_3_SCB0_I2C_SDA},
    {&CYHAL_SCB_1, P2_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P2_1_SCB1_I2C_SDA},
    {&CYHAL_SCB_7, P4_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P4_1_SCB7_I2C_SDA},
    {&CYHAL_SCB_3, P6_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P6_1_SCB3_I2C_SDA},
    {&CYHAL_SCB_6, P6_5, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P6_5_SCB6_I2C_SDA},
    {&CYHAL_SCB_4, P7_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P7_1_SCB4_I2C_SDA},
    {&CYHAL_SCB_4, P8_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P8_1_SCB4_I2C_SDA},
    {&CYHAL_SCB_2, P9_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P9_1_SCB2_I2C_SDA},
    {&CYHAL_SCB_1, P10_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P10_1_SCB1_I2C_SDA},
    {&CYHAL_SCB_5, P11_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P11_1_SCB5_I2C_SDA},
    {&CYHAL_SCB_6, P12_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P12_1_SCB6_I2C_SDA},
    {&CYHAL_SCB_6, P13_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P13_1_SCB6_I2C_SDA},
    {&CYHAL_SCB_5, P15_3, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P15_3_SCB5_I2C_SDA},
    {&CYHAL_SCB_0, P16_1, (uint8_t)CY_GPIO_DM_OD_DRIVESLOW, P16_1_SCB0_I2C_SDA},
};

/* Connections for: scb_spi_m_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_clk[14] = {
    {&CYHAL_SCB_0, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_SCB0_SPI_CLK},
    {&CYHAL_SCB_1, P2_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_2_SCB1_SPI_CLK},
    {&CYHAL_SCB_7, P4_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_2_SCB7_SPI_CLK},
    {&CYHAL_SCB_3, P6_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_2_SCB3_SPI_CLK},
    {&CYHAL_SCB_6, P6_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_6_SCB6_SPI_CLK},
    {&CYHAL_SCB_4, P7_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_2_SCB4_SPI_CLK},
    {&CYHAL_SCB_4, P8_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_2_SCB4_SPI_CLK},
    {&CYHAL_SCB_2, P9_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_2_SCB2_SPI_CLK},
    {&CYHAL_SCB_1, P10_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_2_SCB1_SPI_CLK},
    {&CYHAL_SCB_5, P11_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_2_SCB5_SPI_CLK},
    {&CYHAL_SCB_6, P12_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_2_SCB6_SPI_CLK},
    {&CYHAL_SCB_6, P13_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_2_SCB6_SPI_CLK},
    {&CYHAL_SCB_5, P15_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_4_SCB5_SPI_CLK},
    {&CYHAL_SCB_0, P16_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_2_SCB0_SPI_CLK},
};

/* Connections for: scb_spi_m_miso */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_miso[14] = {
    {&CYHAL_SCB_0, P0_3, (uint8_t)CY_GPIO_DM_HIGHZ, P0_3_SCB0_SPI_MISO},
    {&CYHAL_SCB_1, P2_1, (uint8_t)CY_GPIO_DM_HIGHZ, P2_1_SCB1_SPI_MISO},
    {&CYHAL_SCB_7, P4_1, (uint8_t)CY_GPIO_DM_HIGHZ, P4_1_SCB7_SPI_MISO},
    {&CYHAL_SCB_3, P6_1, (uint8_t)CY_GPIO_DM_HIGHZ, P6_1_SCB3_SPI_MISO},
    {&CYHAL_SCB_6, P6_5, (uint8_t)CY_GPIO_DM_HIGHZ, P6_5_SCB6_SPI_MISO},
    {&CYHAL_SCB_4, P7_1, (uint8_t)CY_GPIO_DM_HIGHZ, P7_1_SCB4_SPI_MISO},
    {&CYHAL_SCB_4, P8_1, (uint8_t)CY_GPIO_DM_HIGHZ, P8_1_SCB4_SPI_MISO},
    {&CYHAL_SCB_2, P9_1, (uint8_t)CY_GPIO_DM_HIGHZ, P9_1_SCB2_SPI_MISO},
    {&CYHAL_SCB_1, P10_1, (uint8_t)CY_GPIO_DM_HIGHZ, P10_1_SCB1_SPI_MISO},
    {&CYHAL_SCB_5, P11_1, (uint8_t)CY_GPIO_DM_HIGHZ, P11_1_SCB5_SPI_MISO},
    {&CYHAL_SCB_6, P12_1, (uint8_t)CY_GPIO_DM_HIGHZ, P12_1_SCB6_SPI_MISO},
    {&CYHAL_SCB_6, P13_1, (uint8_t)CY_GPIO_DM_HIGHZ, P13_1_SCB6_SPI_MISO},
    {&CYHAL_SCB_5, P15_3, (uint8_t)CY_GPIO_DM_HIGHZ, P15_3_SCB5_SPI_MISO},
    {&CYHAL_SCB_0, P16_1, (uint8_t)CY_GPIO_DM_HIGHZ, P16_1_SCB0_SPI_MISO},
};

/* Connections for: scb_spi_m_mosi */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_mosi[14] = {
    {&CYHAL_SCB_0, P0_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_2_SCB0_SPI_MOSI},
    {&CYHAL_SCB_1, P2_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_0_SCB1_SPI_MOSI},
    {&CYHAL_SCB_7, P4_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_0_SCB7_SPI_MOSI},
    {&CYHAL_SCB_3, P6_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_0_SCB3_SPI_MOSI},
    {&CYHAL_SCB_6, P6_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_4_SCB6_SPI_MOSI},
    {&CYHAL_SCB_4, P7_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_0_SCB4_SPI_MOSI},
    {&CYHAL_SCB_4, P8_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_0_SCB4_SPI_MOSI},
    {&CYHAL_SCB_2, P9_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_0_SCB2_SPI_MOSI},
    {&CYHAL_SCB_1, P10_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_0_SCB1_SPI_MOSI},
    {&CYHAL_SCB_5, P11_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_0_SCB5_SPI_MOSI},
    {&CYHAL_SCB_6, P12_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_0_SCB6_SPI_MOSI},
    {&CYHAL_SCB_6, P13_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_0_SCB6_SPI_MOSI},
    {&CYHAL_SCB_5, P15_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_2_SCB5_SPI_MOSI},
    {&CYHAL_SCB_0, P16_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_0_SCB0_SPI_MOSI},
};

/* Connections for: scb_spi_m_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select0[14] = {
    {&CYHAL_SCB_0, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_SCB0_SPI_SELECT0},
    {&CYHAL_SCB_1, P2_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_3_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_7, P4_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_3_SCB7_SPI_SELECT0},
    {&CYHAL_SCB_3, P6_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_3_SCB3_SPI_SELECT0},
    {&CYHAL_SCB_6, P6_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_7_SCB6_SPI_SELECT0},
    {&CYHAL_SCB_4, P7_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_3_SCB4_SPI_SELECT0},
    {&CYHAL_SCB_4, P8_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_3_SCB4_SPI_SELECT0},
    {&CYHAL_SCB_2, P9_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_3_SCB2_SPI_SELECT0},
    {&CYHAL_SCB_1, P10_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_3_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_5, P11_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_3_SCB5_SPI_SELECT0},
    {&CYHAL_SCB_6, P12_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_3_SCB6_SPI_SELECT0},
    {&CYHAL_SCB_6, P13_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_3_SCB6_SPI_SELECT0},
    {&CYHAL_SCB_5, P15_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_5_SCB5_SPI_SELECT0},
    {&CYHAL_SCB_0, P16_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_3_SCB0_SPI_SELECT0},
};

/* Connections for: scb_spi_m_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select1[7] = {
    {&CYHAL_SCB_0, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_SCB0_SPI_SELECT1},
    {&CYHAL_SCB_1, P2_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_4_SCB1_SPI_SELECT1},
    {&CYHAL_SCB_4, P7_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_4_SCB4_SPI_SELECT1},
    {&CYHAL_SCB_5, P11_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_4_SCB5_SPI_SELECT1},
    {&CYHAL_SCB_6, P12_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_4_SCB6_SPI_SELECT1},
    {&CYHAL_SCB_6, P13_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_4_SCB6_SPI_SELECT1},
    {&CYHAL_SCB_0, P16_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_4_SCB0_SPI_SELECT1},
};

/* Connections for: scb_spi_m_select2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select2[7] = {
    {&CYHAL_SCB_0, P0_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_1_SCB0_SPI_SELECT2},
    {&CYHAL_SCB_1, P2_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_5_SCB1_SPI_SELECT2},
    {&CYHAL_SCB_4, P7_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_5_SCB4_SPI_SELECT2},
    {&CYHAL_SCB_5, P11_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_5_SCB5_SPI_SELECT2},
    {&CYHAL_SCB_6, P12_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_5_SCB6_SPI_SELECT2},
    {&CYHAL_SCB_6, P13_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_5_SCB6_SPI_SELECT2},
    {&CYHAL_SCB_0, P16_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_5_SCB0_SPI_SELECT2},
};

/* Connections for: scb_spi_m_select3 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_m_select3[4] = {
    {&CYHAL_SCB_4, P7_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_6_SCB4_SPI_SELECT3},
    {&CYHAL_SCB_5, P11_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_6_SCB5_SPI_SELECT3},
    {&CYHAL_SCB_6, P12_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_6_SCB6_SPI_SELECT3},
    {&CYHAL_SCB_6, P13_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_6_SCB6_SPI_SELECT3},
};

/* Connections for: scb_spi_s_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_clk[14] = {
    {&CYHAL_SCB_0, P0_4, (uint8_t)CY_GPIO_DM_HIGHZ, P0_4_SCB0_SPI_CLK},
    {&CYHAL_SCB_1, P2_2, (uint8_t)CY_GPIO_DM_HIGHZ, P2_2_SCB1_SPI_CLK},
    {&CYHAL_SCB_7, P4_2, (uint8_t)CY_GPIO_DM_HIGHZ, P4_2_SCB7_SPI_CLK},
    {&CYHAL_SCB_3, P6_2, (uint8_t)CY_GPIO_DM_HIGHZ, P6_2_SCB3_SPI_CLK},
    {&CYHAL_SCB_6, P6_6, (uint8_t)CY_GPIO_DM_HIGHZ, P6_6_SCB6_SPI_CLK},
    {&CYHAL_SCB_4, P7_2, (uint8_t)CY_GPIO_DM_HIGHZ, P7_2_SCB4_SPI_CLK},
    {&CYHAL_SCB_4, P8_2, (uint8_t)CY_GPIO_DM_HIGHZ, P8_2_SCB4_SPI_CLK},
    {&CYHAL_SCB_2, P9_2, (uint8_t)CY_GPIO_DM_HIGHZ, P9_2_SCB2_SPI_CLK},
    {&CYHAL_SCB_1, P10_2, (uint8_t)CY_GPIO_DM_HIGHZ, P10_2_SCB1_SPI_CLK},
    {&CYHAL_SCB_5, P11_2, (uint8_t)CY_GPIO_DM_HIGHZ, P11_2_SCB5_SPI_CLK},
    {&CYHAL_SCB_6, P12_2, (uint8_t)CY_GPIO_DM_HIGHZ, P12_2_SCB6_SPI_CLK},
    {&CYHAL_SCB_6, P13_2, (uint8_t)CY_GPIO_DM_HIGHZ, P13_2_SCB6_SPI_CLK},
    {&CYHAL_SCB_5, P15_4, (uint8_t)CY_GPIO_DM_HIGHZ, P15_4_SCB5_SPI_CLK},
    {&CYHAL_SCB_0, P16_2, (uint8_t)CY_GPIO_DM_HIGHZ, P16_2_SCB0_SPI_CLK},
};

/* Connections for: scb_spi_s_miso */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_miso[14] = {
    {&CYHAL_SCB_0, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_SCB0_SPI_MISO},
    {&CYHAL_SCB_1, P2_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_1_SCB1_SPI_MISO},
    {&CYHAL_SCB_7, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_SCB7_SPI_MISO},
    {&CYHAL_SCB_3, P6_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_1_SCB3_SPI_MISO},
    {&CYHAL_SCB_6, P6_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_5_SCB6_SPI_MISO},
    {&CYHAL_SCB_4, P7_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_1_SCB4_SPI_MISO},
    {&CYHAL_SCB_4, P8_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_1_SCB4_SPI_MISO},
    {&CYHAL_SCB_2, P9_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_1_SCB2_SPI_MISO},
    {&CYHAL_SCB_1, P10_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_1_SCB1_SPI_MISO},
    {&CYHAL_SCB_5, P11_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_1_SCB5_SPI_MISO},
    {&CYHAL_SCB_6, P12_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_1_SCB6_SPI_MISO},
    {&CYHAL_SCB_6, P13_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_1_SCB6_SPI_MISO},
    {&CYHAL_SCB_5, P15_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_3_SCB5_SPI_MISO},
    {&CYHAL_SCB_0, P16_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_1_SCB0_SPI_MISO},
};

/* Connections for: scb_spi_s_mosi */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_mosi[14] = {
    {&CYHAL_SCB_0, P0_2, (uint8_t)CY_GPIO_DM_HIGHZ, P0_2_SCB0_SPI_MOSI},
    {&CYHAL_SCB_1, P2_0, (uint8_t)CY_GPIO_DM_HIGHZ, P2_0_SCB1_SPI_MOSI},
    {&CYHAL_SCB_7, P4_0, (uint8_t)CY_GPIO_DM_HIGHZ, P4_0_SCB7_SPI_MOSI},
    {&CYHAL_SCB_3, P6_0, (uint8_t)CY_GPIO_DM_HIGHZ, P6_0_SCB3_SPI_MOSI},
    {&CYHAL_SCB_6, P6_4, (uint8_t)CY_GPIO_DM_HIGHZ, P6_4_SCB6_SPI_MOSI},
    {&CYHAL_SCB_4, P7_0, (uint8_t)CY_GPIO_DM_HIGHZ, P7_0_SCB4_SPI_MOSI},
    {&CYHAL_SCB_4, P8_0, (uint8_t)CY_GPIO_DM_HIGHZ, P8_0_SCB4_SPI_MOSI},
    {&CYHAL_SCB_2, P9_0, (uint8_t)CY_GPIO_DM_HIGHZ, P9_0_SCB2_SPI_MOSI},
    {&CYHAL_SCB_1, P10_0, (uint8_t)CY_GPIO_DM_HIGHZ, P10_0_SCB1_SPI_MOSI},
    {&CYHAL_SCB_5, P11_0, (uint8_t)CY_GPIO_DM_HIGHZ, P11_0_SCB5_SPI_MOSI},
    {&CYHAL_SCB_6, P12_0, (uint8_t)CY_GPIO_DM_HIGHZ, P12_0_SCB6_SPI_MOSI},
    {&CYHAL_SCB_6, P13_0, (uint8_t)CY_GPIO_DM_HIGHZ, P13_0_SCB6_SPI_MOSI},
    {&CYHAL_SCB_5, P15_2, (uint8_t)CY_GPIO_DM_HIGHZ, P15_2_SCB5_SPI_MOSI},
    {&CYHAL_SCB_0, P16_0, (uint8_t)CY_GPIO_DM_HIGHZ, P16_0_SCB0_SPI_MOSI},
};

/* Connections for: scb_spi_s_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select0[14] = {
    {&CYHAL_SCB_0, P0_5, (uint8_t)CY_GPIO_DM_HIGHZ, P0_5_SCB0_SPI_SELECT0},
    {&CYHAL_SCB_1, P2_3, (uint8_t)CY_GPIO_DM_HIGHZ, P2_3_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_7, P4_3, (uint8_t)CY_GPIO_DM_HIGHZ, P4_3_SCB7_SPI_SELECT0},
    {&CYHAL_SCB_3, P6_3, (uint8_t)CY_GPIO_DM_HIGHZ, P6_3_SCB3_SPI_SELECT0},
    {&CYHAL_SCB_6, P6_7, (uint8_t)CY_GPIO_DM_HIGHZ, P6_7_SCB6_SPI_SELECT0},
    {&CYHAL_SCB_4, P7_3, (uint8_t)CY_GPIO_DM_HIGHZ, P7_3_SCB4_SPI_SELECT0},
    {&CYHAL_SCB_4, P8_3, (uint8_t)CY_GPIO_DM_HIGHZ, P8_3_SCB4_SPI_SELECT0},
    {&CYHAL_SCB_2, P9_3, (uint8_t)CY_GPIO_DM_HIGHZ, P9_3_SCB2_SPI_SELECT0},
    {&CYHAL_SCB_1, P10_3, (uint8_t)CY_GPIO_DM_HIGHZ, P10_3_SCB1_SPI_SELECT0},
    {&CYHAL_SCB_5, P11_3, (uint8_t)CY_GPIO_DM_HIGHZ, P11_3_SCB5_SPI_SELECT0},
    {&CYHAL_SCB_6, P12_3, (uint8_t)CY_GPIO_DM_HIGHZ, P12_3_SCB6_SPI_SELECT0},
    {&CYHAL_SCB_6, P13_3, (uint8_t)CY_GPIO_DM_HIGHZ, P13_3_SCB6_SPI_SELECT0},
    {&CYHAL_SCB_5, P15_5, (uint8_t)CY_GPIO_DM_HIGHZ, P15_5_SCB5_SPI_SELECT0},
    {&CYHAL_SCB_0, P16_3, (uint8_t)CY_GPIO_DM_HIGHZ, P16_3_SCB0_SPI_SELECT0},
};

/* Connections for: scb_spi_s_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select1[7] = {
    {&CYHAL_SCB_0, P0_0, (uint8_t)CY_GPIO_DM_HIGHZ, P0_0_SCB0_SPI_SELECT1},
    {&CYHAL_SCB_1, P2_4, (uint8_t)CY_GPIO_DM_HIGHZ, P2_4_SCB1_SPI_SELECT1},
    {&CYHAL_SCB_4, P7_4, (uint8_t)CY_GPIO_DM_HIGHZ, P7_4_SCB4_SPI_SELECT1},
    {&CYHAL_SCB_5, P11_4, (uint8_t)CY_GPIO_DM_HIGHZ, P11_4_SCB5_SPI_SELECT1},
    {&CYHAL_SCB_6, P12_4, (uint8_t)CY_GPIO_DM_HIGHZ, P12_4_SCB6_SPI_SELECT1},
    {&CYHAL_SCB_6, P13_4, (uint8_t)CY_GPIO_DM_HIGHZ, P13_4_SCB6_SPI_SELECT1},
    {&CYHAL_SCB_0, P16_4, (uint8_t)CY_GPIO_DM_HIGHZ, P16_4_SCB0_SPI_SELECT1},
};

/* Connections for: scb_spi_s_select2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select2[7] = {
    {&CYHAL_SCB_0, P0_1, (uint8_t)CY_GPIO_DM_HIGHZ, P0_1_SCB0_SPI_SELECT2},
    {&CYHAL_SCB_1, P2_5, (uint8_t)CY_GPIO_DM_HIGHZ, P2_5_SCB1_SPI_SELECT2},
    {&CYHAL_SCB_4, P7_5, (uint8_t)CY_GPIO_DM_HIGHZ, P7_5_SCB4_SPI_SELECT2},
    {&CYHAL_SCB_5, P11_5, (uint8_t)CY_GPIO_DM_HIGHZ, P11_5_SCB5_SPI_SELECT2},
    {&CYHAL_SCB_6, P12_5, (uint8_t)CY_GPIO_DM_HIGHZ, P12_5_SCB6_SPI_SELECT2},
    {&CYHAL_SCB_6, P13_5, (uint8_t)CY_GPIO_DM_HIGHZ, P13_5_SCB6_SPI_SELECT2},
    {&CYHAL_SCB_0, P16_5, (uint8_t)CY_GPIO_DM_HIGHZ, P16_5_SCB0_SPI_SELECT2},
};

/* Connections for: scb_spi_s_select3 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_spi_s_select3[4] = {
    {&CYHAL_SCB_4, P7_6, (uint8_t)CY_GPIO_DM_HIGHZ, P7_6_SCB4_SPI_SELECT3},
    {&CYHAL_SCB_5, P11_6, (uint8_t)CY_GPIO_DM_HIGHZ, P11_6_SCB5_SPI_SELECT3},
    {&CYHAL_SCB_6, P12_6, (uint8_t)CY_GPIO_DM_HIGHZ, P12_6_SCB6_SPI_SELECT3},
    {&CYHAL_SCB_6, P13_6, (uint8_t)CY_GPIO_DM_HIGHZ, P13_6_SCB6_SPI_SELECT3},
};

/* Connections for: scb_uart_cts */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_cts[12] = {
    {&CYHAL_SCB_1, P2_3, (uint8_t)CY_GPIO_DM_HIGHZ, P2_3_SCB1_UART_CTS},
    {&CYHAL_SCB_7, P4_3, (uint8_t)CY_GPIO_DM_HIGHZ, P4_3_SCB7_UART_CTS},
    {&CYHAL_SCB_3, P6_3, (uint8_t)CY_GPIO_DM_HIGHZ, P6_3_SCB3_UART_CTS},
    {&CYHAL_SCB_6, P6_7, (uint8_t)CY_GPIO_DM_HIGHZ, P6_7_SCB6_UART_CTS},
    {&CYHAL_SCB_4, P7_3, (uint8_t)CY_GPIO_DM_HIGHZ, P7_3_SCB4_UART_CTS},
    {&CYHAL_SCB_4, P8_3, (uint8_t)CY_GPIO_DM_HIGHZ, P8_3_SCB4_UART_CTS},
    {&CYHAL_SCB_2, P9_3, (uint8_t)CY_GPIO_DM_HIGHZ, P9_3_SCB2_UART_CTS},
    {&CYHAL_SCB_1, P10_3, (uint8_t)CY_GPIO_DM_HIGHZ, P10_3_SCB1_UART_CTS},
    {&CYHAL_SCB_5, P11_3, (uint8_t)CY_GPIO_DM_HIGHZ, P11_3_SCB5_UART_CTS},
    {&CYHAL_SCB_6, P12_3, (uint8_t)CY_GPIO_DM_HIGHZ, P12_3_SCB6_UART_CTS},
    {&CYHAL_SCB_6, P13_3, (uint8_t)CY_GPIO_DM_HIGHZ, P13_3_SCB6_UART_CTS},
    {&CYHAL_SCB_5, P15_5, (uint8_t)CY_GPIO_DM_HIGHZ, P15_5_SCB5_UART_CTS},
};

/* Connections for: scb_uart_rts */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rts[12] = {
    {&CYHAL_SCB_1, P2_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_2_SCB1_UART_RTS},
    {&CYHAL_SCB_7, P4_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_2_SCB7_UART_RTS},
    {&CYHAL_SCB_3, P6_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_2_SCB3_UART_RTS},
    {&CYHAL_SCB_6, P6_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_6_SCB6_UART_RTS},
    {&CYHAL_SCB_4, P7_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_2_SCB4_UART_RTS},
    {&CYHAL_SCB_4, P8_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_2_SCB4_UART_RTS},
    {&CYHAL_SCB_2, P9_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_2_SCB2_UART_RTS},
    {&CYHAL_SCB_1, P10_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_2_SCB1_UART_RTS},
    {&CYHAL_SCB_5, P11_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_2_SCB5_UART_RTS},
    {&CYHAL_SCB_6, P12_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_2_SCB6_UART_RTS},
    {&CYHAL_SCB_6, P13_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_2_SCB6_UART_RTS},
    {&CYHAL_SCB_5, P15_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_4_SCB5_UART_RTS},
};

/* Connections for: scb_uart_rx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_rx[12] = {
    {&CYHAL_SCB_1, P2_0, (uint8_t)CY_GPIO_DM_HIGHZ, P2_0_SCB1_UART_RX},
    {&CYHAL_SCB_7, P4_0, (uint8_t)CY_GPIO_DM_HIGHZ, P4_0_SCB7_UART_RX},
    {&CYHAL_SCB_3, P6_0, (uint8_t)CY_GPIO_DM_HIGHZ, P6_0_SCB3_UART_RX},
    {&CYHAL_SCB_6, P6_4, (uint8_t)CY_GPIO_DM_HIGHZ, P6_4_SCB6_UART_RX},
    {&CYHAL_SCB_4, P7_0, (uint8_t)CY_GPIO_DM_HIGHZ, P7_0_SCB4_UART_RX},
    {&CYHAL_SCB_4, P8_0, (uint8_t)CY_GPIO_DM_HIGHZ, P8_0_SCB4_UART_RX},
    {&CYHAL_SCB_2, P9_0, (uint8_t)CY_GPIO_DM_HIGHZ, P9_0_SCB2_UART_RX},
    {&CYHAL_SCB_1, P10_0, (uint8_t)CY_GPIO_DM_HIGHZ, P10_0_SCB1_UART_RX},
    {&CYHAL_SCB_5, P11_0, (uint8_t)CY_GPIO_DM_HIGHZ, P11_0_SCB5_UART_RX},
    {&CYHAL_SCB_6, P12_0, (uint8_t)CY_GPIO_DM_HIGHZ, P12_0_SCB6_UART_RX},
    {&CYHAL_SCB_6, P13_0, (uint8_t)CY_GPIO_DM_HIGHZ, P13_0_SCB6_UART_RX},
    {&CYHAL_SCB_5, P15_2, (uint8_t)CY_GPIO_DM_HIGHZ, P15_2_SCB5_UART_RX},
};

/* Connections for: scb_uart_tx */
const cyhal_resource_pin_mapping_t cyhal_pin_map_scb_uart_tx[12] = {
    {&CYHAL_SCB_1, P2_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_1_SCB1_UART_TX},
    {&CYHAL_SCB_7, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_SCB7_UART_TX},
    {&CYHAL_SCB_3, P6_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_1_SCB3_UART_TX},
    {&CYHAL_SCB_6, P6_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_5_SCB6_UART_TX},
    {&CYHAL_SCB_4, P7_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_1_SCB4_UART_TX},
    {&CYHAL_SCB_4, P8_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_1_SCB4_UART_TX},
    {&CYHAL_SCB_2, P9_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_1_SCB2_UART_TX},
    {&CYHAL_SCB_1, P10_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_1_SCB1_UART_TX},
    {&CYHAL_SCB_5, P11_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_1_SCB5_UART_TX},
    {&CYHAL_SCB_6, P12_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_1_SCB6_UART_TX},
    {&CYHAL_SCB_6, P13_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_1_SCB6_UART_TX},
    {&CYHAL_SCB_5, P15_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_3_SCB5_UART_TX},
};

/* Connections for: sdhc_card_cmd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_cmd[1] = {
    {&CYHAL_SDHC_1, P12_1, (uint8_t)CY_GPIO_DM_STRONG, P12_1_SDHC1_CARD_CMD},
};

/* Connections for: sdhc_card_dat_3to0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_dat_3to0[4] = {
    {&CYHAL_SDHC_1, P12_2, (uint8_t)CY_GPIO_DM_STRONG, P12_2_SDHC1_CARD_DAT_3TO00},
    {&CYHAL_SDHC_1, P12_3, (uint8_t)CY_GPIO_DM_STRONG, P12_3_SDHC1_CARD_DAT_3TO01},
    {&CYHAL_SDHC_1, P12_4, (uint8_t)CY_GPIO_DM_STRONG, P12_4_SDHC1_CARD_DAT_3TO02},
    {&CYHAL_SDHC_1, P12_5, (uint8_t)CY_GPIO_DM_STRONG, P12_5_SDHC1_CARD_DAT_3TO03},
};

/* Connections for: sdhc_card_dat_7to4 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_dat_7to4[4] = {
    {&CYHAL_SDHC_1, P13_4, (uint8_t)CY_GPIO_DM_STRONG, P13_4_SDHC1_CARD_DAT_7TO40},
    {&CYHAL_SDHC_1, P13_5, (uint8_t)CY_GPIO_DM_STRONG, P13_5_SDHC1_CARD_DAT_7TO41},
    {&CYHAL_SDHC_1, P13_6, (uint8_t)CY_GPIO_DM_STRONG, P13_6_SDHC1_CARD_DAT_7TO42},
    {&CYHAL_SDHC_1, P13_7, (uint8_t)CY_GPIO_DM_STRONG, P13_7_SDHC1_CARD_DAT_7TO43},
};

/* Connections for: sdhc_card_detect_n */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_detect_n[1] = {
    {&CYHAL_SDHC_1, P12_7, (uint8_t)CY_GPIO_DM_HIGHZ, P12_7_SDHC1_CARD_DETECT_N},
};

/* Connections for: sdhc_card_emmc_reset_n */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_emmc_reset_n[1] = {
    {&CYHAL_SDHC_1, P12_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_6_SDHC1_CARD_EMMC_RESET_N},
};

/* Connections for: sdhc_card_if_pwr_en */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_if_pwr_en[1] = {
    {&CYHAL_SDHC_1, P13_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_2_SDHC1_CARD_IF_PWR_EN},
};

/* Connections for: sdhc_card_mech_write_prot */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_card_mech_write_prot[1] = {
    {&CYHAL_SDHC_1, P13_0, (uint8_t)CY_GPIO_DM_HIGHZ, P13_0_SDHC1_CARD_MECH_WRITE_PROT},
};

/* Connections for: sdhc_clk_card */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_clk_card[1] = {
    {&CYHAL_SDHC_1, P12_0, (uint8_t)CY_GPIO_DM_STRONG, P12_0_SDHC1_CLK_CARD},
};

/* Connections for: sdhc_io_volt_sel */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_io_volt_sel[1] = {
    {&CYHAL_SDHC_1, P13_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_3_SDHC1_IO_VOLT_SEL},
};

/* Connections for: sdhc_led_ctrl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdhc_led_ctrl[1] = {
    {&CYHAL_SDHC_1, P13_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_1_SDHC1_LED_CTRL},
};

/* Connections for: sdiodev_sdio_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdiodev_sdio_clk[1] = {
    {&CYHAL_SDIODEV_0, P2_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_5_SDIODEV0_SDIO_CLK},
};

/* Connections for: sdiodev_sdio_cmd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdiodev_sdio_cmd[1] = {
    {&CYHAL_SDIODEV_0, P2_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_4_SDIODEV0_SDIO_CMD},
};

/* Connections for: sdiodev_sdio_data */
const cyhal_resource_pin_mapping_t cyhal_pin_map_sdiodev_sdio_data[4] = {
    {&CYHAL_SDIODEV_0, P2_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_0_SDIODEV0_SDIO_DATA0},
    {&CYHAL_SDIODEV_0, P2_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_1_SDIODEV0_SDIO_DATA1},
    {&CYHAL_SDIODEV_0, P2_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_2_SDIODEV0_SDIO_DATA2},
    {&CYHAL_SDIODEV_0, P2_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_3_SDIODEV0_SDIO_DATA3},
};

/* Connections for: smif_spi_clk */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_clk[1] = {
    {&CYHAL_SMIF_0, P11_7, (uint8_t)CY_GPIO_DM_STRONG, P11_7_SMIF_SPIHB_CLK},
};

/* Connections for: smif_spi_data0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data0[1] = {
    {&CYHAL_SMIF_0, P11_6, (uint8_t)CY_GPIO_DM_STRONG, P11_6_SMIF_SPIHB_DATA0},
};

/* Connections for: smif_spi_data1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data1[1] = {
    {&CYHAL_SMIF_0, P11_5, (uint8_t)CY_GPIO_DM_STRONG, P11_5_SMIF_SPIHB_DATA1},
};

/* Connections for: smif_spi_data2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data2[1] = {
    {&CYHAL_SMIF_0, P11_4, (uint8_t)CY_GPIO_DM_STRONG, P11_4_SMIF_SPIHB_DATA2},
};

/* Connections for: smif_spi_data3 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data3[1] = {
    {&CYHAL_SMIF_0, P11_3, (uint8_t)CY_GPIO_DM_STRONG, P11_3_SMIF_SPIHB_DATA3},
};

/* Connections for: smif_spi_data4 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data4[1] = {
    {&CYHAL_SMIF_0, P12_0, (uint8_t)CY_GPIO_DM_STRONG, P12_0_SMIF_SPIHB_DATA4},
};

/* Connections for: smif_spi_data5 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data5[1] = {
    {&CYHAL_SMIF_0, P12_1, (uint8_t)CY_GPIO_DM_STRONG, P12_1_SMIF_SPIHB_DATA5},
};

/* Connections for: smif_spi_data6 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data6[1] = {
    {&CYHAL_SMIF_0, P12_2, (uint8_t)CY_GPIO_DM_STRONG, P12_2_SMIF_SPIHB_DATA6},
};

/* Connections for: smif_spi_data7 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_data7[1] = {
    {&CYHAL_SMIF_0, P12_3, (uint8_t)CY_GPIO_DM_STRONG, P12_3_SMIF_SPIHB_DATA7},
};

/* Connections for: smif_spi_rwds */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_rwds[1] = {
    {&CYHAL_SMIF_0, P12_5, (uint8_t)CY_GPIO_DM_STRONG, P12_5_SMIF_SPIHB_RWDS},
};

/* Connections for: smif_spi_select0 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select0[1] = {
    {&CYHAL_SMIF_0, P11_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_2_SMIF_SPIHB_SELECT0},
};

/* Connections for: smif_spi_select1 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select1[1] = {
    {&CYHAL_SMIF_0, P11_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_1_SMIF_SPIHB_SELECT1},
};

/* Connections for: smif_spi_select2 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select2[1] = {
    {&CYHAL_SMIF_0, P11_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_0_SMIF_SPIHB_SELECT2},
};

/* Connections for: smif_spi_select3 */
const cyhal_resource_pin_mapping_t cyhal_pin_map_smif_spi_select3[1] = {
    {&CYHAL_SMIF_0, P12_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_4_SMIF_SPIHB_SELECT3},
};

/* Connections for: tcpwm_line */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line[84] = {
    {&CYHAL_TCPWM_0_0, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_0, P0_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_0_TCPWM1_LINE0},
    {&CYHAL_TCPWM_0_1, P0_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_2_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_1, P0_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_2_TCPWM1_LINE1},
    {&CYHAL_TCPWM_0_2, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_2, P0_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_4_TCPWM1_LINE2},
    {&CYHAL_TCPWM_0_3, P2_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_0_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_7, P2_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_0_TCPWM1_LINE7},
    {&CYHAL_TCPWM_0_0, P2_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_2_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_8, P2_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_2_TCPWM1_LINE8},
    {&CYHAL_TCPWM_0_1, P2_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_4_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_9, P2_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_4_TCPWM1_LINE9},
    {&CYHAL_TCPWM_0_2, P4_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_0_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_10, P4_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_0_TCPWM1_LINE10},
    {&CYHAL_TCPWM_0_3, P4_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_2_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_11, P4_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_2_TCPWM1_LINE11},
    {&CYHAL_TCPWM_0_0, P5_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_6_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_12, P5_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_6_TCPWM1_LINE12},
    {&CYHAL_TCPWM_0_1, P6_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_0_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_13, P6_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_0_TCPWM1_LINE13},
    {&CYHAL_TCPWM_0_2, P6_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_2_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_14, P6_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_2_TCPWM1_LINE14},
    {&CYHAL_TCPWM_0_3, P6_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_4_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_15, P6_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_4_TCPWM1_LINE15},
    {&CYHAL_TCPWM_0_0, P6_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_6_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_0, P6_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_6_TCPWM1_LINE0},
    {&CYHAL_TCPWM_0_1, P7_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_0_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_1, P7_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_0_TCPWM1_LINE1},
    {&CYHAL_TCPWM_0_2, P7_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_2_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_2, P7_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_2_TCPWM1_LINE2},
    {&CYHAL_TCPWM_0_3, P7_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_4_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_3, P7_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_4_TCPWM1_LINE3},
    {&CYHAL_TCPWM_0_0, P7_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_6_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_4, P7_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_6_TCPWM1_LINE4},
    {&CYHAL_TCPWM_0_1, P8_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_0_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_5, P8_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_0_TCPWM1_LINE5},
    {&CYHAL_TCPWM_0_2, P8_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_2_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_6, P8_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_2_TCPWM1_LINE6},
    {&CYHAL_TCPWM_0_3, P9_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_0_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_7, P9_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_0_TCPWM1_LINE7},
    {&CYHAL_TCPWM_0_0, P9_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_2_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_8, P9_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_2_TCPWM1_LINE8},
    {&CYHAL_TCPWM_0_1, P10_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_0_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_9, P10_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_0_TCPWM1_LINE9},
    {&CYHAL_TCPWM_0_2, P10_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_2_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_10, P10_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_2_TCPWM1_LINE10},
    {&CYHAL_TCPWM_0_3, P11_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_0_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_11, P11_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_0_TCPWM1_LINE11},
    {&CYHAL_TCPWM_0_0, P11_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_2_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_12, P11_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_2_TCPWM1_LINE12},
    {&CYHAL_TCPWM_0_1, P11_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_4_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_13, P11_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_4_TCPWM1_LINE13},
    {&CYHAL_TCPWM_0_2, P11_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_6_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_14, P11_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_6_TCPWM1_LINE14},
    {&CYHAL_TCPWM_0_3, P12_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_0_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_15, P12_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_0_TCPWM1_LINE15},
    {&CYHAL_TCPWM_0_0, P12_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_2_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_0, P12_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_2_TCPWM1_LINE0},
    {&CYHAL_TCPWM_0_1, P12_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_4_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_1, P12_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_4_TCPWM1_LINE1},
    {&CYHAL_TCPWM_0_2, P12_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_6_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_2, P12_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_6_TCPWM1_LINE2},
    {&CYHAL_TCPWM_0_3, P13_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_0_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_3, P13_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_0_TCPWM1_LINE3},
    {&CYHAL_TCPWM_0_0, P13_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_2_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_4, P13_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_2_TCPWM1_LINE4},
    {&CYHAL_TCPWM_0_1, P13_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_4_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_5, P13_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_4_TCPWM1_LINE5},
    {&CYHAL_TCPWM_0_2, P13_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_6_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_6, P13_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_6_TCPWM1_LINE6},
    {&CYHAL_TCPWM_0_3, P15_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_0_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_3, P15_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_0_TCPWM1_LINE3},
    {&CYHAL_TCPWM_0_0, P15_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_2_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_4, P15_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_2_TCPWM1_LINE4},
    {&CYHAL_TCPWM_0_1, P15_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_4_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_5, P15_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_4_TCPWM1_LINE5},
    {&CYHAL_TCPWM_0_2, P15_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_6_TCPWM0_LINE2},
    {&CYHAL_TCPWM_1_6, P15_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_6_TCPWM1_LINE6},
    {&CYHAL_TCPWM_0_3, P16_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_0_TCPWM0_LINE3},
    {&CYHAL_TCPWM_1_7, P16_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_0_TCPWM1_LINE7},
    {&CYHAL_TCPWM_0_0, P16_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_2_TCPWM0_LINE0},
    {&CYHAL_TCPWM_1_8, P16_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_2_TCPWM1_LINE8},
    {&CYHAL_TCPWM_0_1, P16_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_4_TCPWM0_LINE1},
    {&CYHAL_TCPWM_1_9, P16_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_4_TCPWM1_LINE9},
};

/* Connections for: tcpwm_line_compl */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tcpwm_line_compl[84] = {
    {&CYHAL_TCPWM_0_0, P0_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_1_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_0, P0_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_1_TCPWM1_LINE_COMPL0},
    {&CYHAL_TCPWM_0_1, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_1, P0_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_3_TCPWM1_LINE_COMPL1},
    {&CYHAL_TCPWM_0_2, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_2, P0_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P0_5_TCPWM1_LINE_COMPL2},
    {&CYHAL_TCPWM_0_3, P2_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_1_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_7, P2_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_1_TCPWM1_LINE_COMPL7},
    {&CYHAL_TCPWM_0_0, P2_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_3_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_8, P2_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_3_TCPWM1_LINE_COMPL8},
    {&CYHAL_TCPWM_0_1, P2_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_5_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_9, P2_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P2_5_TCPWM1_LINE_COMPL9},
    {&CYHAL_TCPWM_0_2, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_10, P4_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_1_TCPWM1_LINE_COMPL10},
    {&CYHAL_TCPWM_0_3, P4_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_3_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_11, P4_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P4_3_TCPWM1_LINE_COMPL11},
    {&CYHAL_TCPWM_0_0, P5_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_7_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_12, P5_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P5_7_TCPWM1_LINE_COMPL12},
    {&CYHAL_TCPWM_0_1, P6_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_1_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_13, P6_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_1_TCPWM1_LINE_COMPL13},
    {&CYHAL_TCPWM_0_2, P6_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_3_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_14, P6_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_3_TCPWM1_LINE_COMPL14},
    {&CYHAL_TCPWM_0_3, P6_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_5_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_15, P6_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_5_TCPWM1_LINE_COMPL15},
    {&CYHAL_TCPWM_0_0, P6_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_7_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_0, P6_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P6_7_TCPWM1_LINE_COMPL0},
    {&CYHAL_TCPWM_0_1, P7_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_1_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_1, P7_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_1_TCPWM1_LINE_COMPL1},
    {&CYHAL_TCPWM_0_2, P7_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_3_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_2, P7_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_3_TCPWM1_LINE_COMPL2},
    {&CYHAL_TCPWM_0_3, P7_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_5_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_3, P7_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_5_TCPWM1_LINE_COMPL3},
    {&CYHAL_TCPWM_0_0, P7_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_7_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_4, P7_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P7_7_TCPWM1_LINE_COMPL4},
    {&CYHAL_TCPWM_0_1, P8_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_1_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_5, P8_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_1_TCPWM1_LINE_COMPL5},
    {&CYHAL_TCPWM_0_2, P8_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_3_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_6, P8_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_3_TCPWM1_LINE_COMPL6},
    {&CYHAL_TCPWM_0_3, P9_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_1_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_7, P9_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_1_TCPWM1_LINE_COMPL7},
    {&CYHAL_TCPWM_0_0, P9_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_3_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_8, P9_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_3_TCPWM1_LINE_COMPL8},
    {&CYHAL_TCPWM_0_1, P10_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_1_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_9, P10_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_1_TCPWM1_LINE_COMPL9},
    {&CYHAL_TCPWM_0_2, P10_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_3_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_10, P10_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P10_3_TCPWM1_LINE_COMPL10},
    {&CYHAL_TCPWM_0_3, P11_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_1_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_11, P11_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_1_TCPWM1_LINE_COMPL11},
    {&CYHAL_TCPWM_0_0, P11_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_3_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_12, P11_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_3_TCPWM1_LINE_COMPL12},
    {&CYHAL_TCPWM_0_1, P11_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_5_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_13, P11_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_5_TCPWM1_LINE_COMPL13},
    {&CYHAL_TCPWM_0_2, P11_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_7_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_14, P11_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P11_7_TCPWM1_LINE_COMPL14},
    {&CYHAL_TCPWM_0_3, P12_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_1_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_15, P12_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_1_TCPWM1_LINE_COMPL15},
    {&CYHAL_TCPWM_0_0, P12_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_3_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_0, P12_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_3_TCPWM1_LINE_COMPL0},
    {&CYHAL_TCPWM_0_1, P12_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_5_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_1, P12_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_5_TCPWM1_LINE_COMPL1},
    {&CYHAL_TCPWM_0_2, P12_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_7_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_2, P12_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P12_7_TCPWM1_LINE_COMPL2},
    {&CYHAL_TCPWM_0_3, P13_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_1_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_3, P13_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_1_TCPWM1_LINE_COMPL3},
    {&CYHAL_TCPWM_0_0, P13_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_3_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_4, P13_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_3_TCPWM1_LINE_COMPL4},
    {&CYHAL_TCPWM_0_1, P13_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_5_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_5, P13_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_5_TCPWM1_LINE_COMPL5},
    {&CYHAL_TCPWM_0_2, P13_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_7_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_6, P13_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_7_TCPWM1_LINE_COMPL6},
    {&CYHAL_TCPWM_0_3, P15_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_1_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_3, P15_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_1_TCPWM1_LINE_COMPL3},
    {&CYHAL_TCPWM_0_0, P15_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_3_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_4, P15_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_3_TCPWM1_LINE_COMPL4},
    {&CYHAL_TCPWM_0_1, P15_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_5_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_5, P15_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_5_TCPWM1_LINE_COMPL5},
    {&CYHAL_TCPWM_0_2, P15_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_7_TCPWM0_LINE_COMPL2},
    {&CYHAL_TCPWM_1_6, P15_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_7_TCPWM1_LINE_COMPL6},
    {&CYHAL_TCPWM_0_3, P16_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_1_TCPWM0_LINE_COMPL3},
    {&CYHAL_TCPWM_1_7, P16_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_1_TCPWM1_LINE_COMPL7},
    {&CYHAL_TCPWM_0_0, P16_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_3_TCPWM0_LINE_COMPL0},
    {&CYHAL_TCPWM_1_8, P16_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_3_TCPWM1_LINE_COMPL8},
    {&CYHAL_TCPWM_0_1, P16_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_5_TCPWM0_LINE_COMPL1},
    {&CYHAL_TCPWM_1_9, P16_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_5_TCPWM1_LINE_COMPL9},
};

/* Connections for: tdm_tdm_rx_fsync */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_fsync[3] = {
    {&CYHAL_TDM_0, P9_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_1_TDM_TDM_RX_FSYNC0},
    {&CYHAL_TDM_0, P13_5, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_5_TDM_TDM_RX_FSYNC1},
    {&CYHAL_TDM_0, P16_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_3_TDM_TDM_RX_FSYNC1},
};

/* Connections for: tdm_tdm_rx_mck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_mck[3] = {
    {&CYHAL_TDM_0, P8_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_0_TDM_TDM_RX_MCK0},
    {&CYHAL_TDM_0, P13_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_0_TDM_TDM_RX_MCK1},
    {&CYHAL_TDM_0, P15_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_6_TDM_TDM_RX_MCK1},
};

/* Connections for: tdm_tdm_rx_sck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_sck[3] = {
    {&CYHAL_TDM_0, P9_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P9_0_TDM_TDM_RX_SCK0},
    {&CYHAL_TDM_0, P13_4, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_4_TDM_TDM_RX_SCK1},
    {&CYHAL_TDM_0, P16_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_2_TDM_TDM_RX_SCK1},
};

/* Connections for: tdm_tdm_rx_sd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_rx_sd[3] = {
    {&CYHAL_TDM_0, P9_2, (uint8_t)CY_GPIO_DM_HIGHZ, P9_2_TDM_TDM_RX_SD0},
    {&CYHAL_TDM_0, P13_6, (uint8_t)CY_GPIO_DM_HIGHZ, P13_6_TDM_TDM_RX_SD1},
    {&CYHAL_TDM_0, P16_4, (uint8_t)CY_GPIO_DM_HIGHZ, P16_4_TDM_TDM_RX_SD1},
};

/* Connections for: tdm_tdm_tx_fsync */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_fsync[3] = {
    {&CYHAL_TDM_0, P8_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_2_TDM_TDM_TX_FSYNC0},
    {&CYHAL_TDM_0, P13_2, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_2_TDM_TDM_TX_FSYNC1},
    {&CYHAL_TDM_0, P16_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_0_TDM_TDM_TX_FSYNC1},
};

/* Connections for: tdm_tdm_tx_mck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_mck[3] = {
    {&CYHAL_TDM_0, P8_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_0_TDM_TDM_TX_MCK0},
    {&CYHAL_TDM_0, P13_0, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_0_TDM_TDM_TX_MCK1},
    {&CYHAL_TDM_0, P15_6, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_6_TDM_TDM_TX_MCK1},
};

/* Connections for: tdm_tdm_tx_sck */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_sck[3] = {
    {&CYHAL_TDM_0, P8_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_1_TDM_TDM_TX_SCK0},
    {&CYHAL_TDM_0, P13_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_1_TDM_TDM_TX_SCK1},
    {&CYHAL_TDM_0, P15_7, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P15_7_TDM_TDM_TX_SCK1},
};

/* Connections for: tdm_tdm_tx_sd */
const cyhal_resource_pin_mapping_t cyhal_pin_map_tdm_tdm_tx_sd[3] = {
    {&CYHAL_TDM_0, P8_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P8_3_TDM_TDM_TX_SD0},
    {&CYHAL_TDM_0, P13_3, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P13_3_TDM_TDM_TX_SD1},
    {&CYHAL_TDM_0, P16_1, (uint8_t)CY_GPIO_DM_STRONG_IN_OFF, P16_1_TDM_TDM_TX_SD1},
};

#endif
