/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#include <soc/gpe.h>
#include <soc/gpio.h>

/* MAX98357A SD_MODE */
#define GPIO_SPEAKER_MAXIM_AMP_SDMODE	GPP_B2

/* EC in RW */
#define GPIO_EC_IN_RW		GPP_C6

/* BIOS Flash Write Protect */
#define GPIO_PCH_WP		GPP_C23

/* Memory configuration board straps */
#define GPIO_MEM_CONFIG_0	GPP_C12
#define GPIO_MEM_CONFIG_1	GPP_C13
#define GPIO_MEM_CONFIG_2	GPP_C14
#define GPIO_MEM_CONFIG_3	GPP_C15

/* EC wake is LAN_WAKE# which is a special DeepSX wake pin */
#define GPE_EC_WAKE		GPE0_LAN_WAK

/* GPP_B16 is WLAN_WAKE. GPP_B group is routed to DW0 in the GPE0 block */
#define GPE_WLAN_WAKE		GPE0_DW0_16

/* GPP_B5 is TOUCHPAD WAKE. GPP_B group is routed to DW0 in the GPE0 block */
#define GPE_TOUCHPAD_WAKE       GPE0_DW0_05

/* Input device interrupt configuration */
#define TOUCHPAD_INT_L		GPP_B3_IRQ
#define TOUCHSCREEN_INT_L	GPP_E7_IRQ
#define MIC_INT_L		GPP_F10_IRQ

/* GPP_E16 is EC_SCI_L. GPP_E group is routed to DW2 in the GPE0 block */
#define EC_SCI_GPI		GPE0_DW2_16
#define EC_SMI_GPI		GPP_E15

#ifndef __ACPI__
/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
/* EC_PCH_RCIN */	PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1),
/* LPC_LAD_0 */		PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1),
/* LPC_LAD_1 */		PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1),
/* LPC_LAD_2 */		PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1),
/* LPC_LAD_3 */		PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1),
/* LPC_FRAME */		PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
/* LPC_SERIRQ */	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
/* PIRQA# */		PAD_NC(GPP_A7, NONE),
/* LPC_CLKRUN */	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
/* EC_LPC_CLK */	PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1),
/* PCH_LPC_CLK */	PAD_NC(GPP_A10, NONE),
/* EC_HID_INT */	PAD_NC(GPP_A11, NONE),
/* ISH_KB_PROX_INT */	PAD_NC(GPP_A12, NONE),
/* PCH_SUSPWRACB */	PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),
/* PM_SUS_STAT */	PAD_NC(GPP_A14, NONE),
/* PCH_SUSACK */	PAD_CFG_NF(GPP_A15, NONE, DEEP, NF1),
/* SD_1P8_SEL */	PAD_NC(GPP_A16, NONE),
/* SD_PWR_EN */		PAD_NC(GPP_A17, NONE),
/* ACCEL INTERRUPT */	PAD_NC(GPP_A18, NONE),
/* ISH_GP1 */		PAD_NC(GPP_A19, NONE),
/* GYRO_DRDY */		PAD_NC(GPP_A20, NONE),
/* FLIP_ACCEL_INT */	PAD_NC(GPP_A21, NONE),
/* GYRO_INT */		PAD_NC(GPP_A22, NONE),
/* ISH_GP5 */		PAD_NC(GPP_A23, NONE),
/* CORE_VID0 */		PAD_NC(GPP_B0, NONE),
/* CORE_VID1 */		PAD_NC(GPP_B1, NONE),
/* HSJ_MIC_DET */	PAD_CFG_GPO(GPP_B2, 0, DEEP),
/* TRACKPAD_INT */	PAD_CFG_GPI_APIC_HIGH(GPP_B3, NONE, PLTRST),
/* BT_RF_KILL */	PAD_NC(GPP_B4, NONE),
/* SRCCLKREQ0# */	PAD_CFG_GPI_SCI(GPP_B5, NONE, DEEP, EDGE_SINGLE, INVERT), /* TOUCHPAD WAKE */
/* WIFI_CLK_REQ */	PAD_CFG_NF(GPP_B6, NONE, DEEP, NF1),
/* KEPLR_CLK_REQ */	PAD_NC(GPP_B7, NONE),
/* AUDIO_INT_WAK */	PAD_CFG_GPI_SCI(GPP_B8, NONE, DEEP, EDGE_SINGLE, INVERT),
/* SSD_CLK_REQ */	PAD_NC(GPP_B9, NONE),
/* SRCCLKREQ5# */	PAD_NC(GPP_B10, NONE),
/* MPHY_EXT_PWR_GATE */ PAD_NC(GPP_B11, NONE),
/* PM_SLP_S0 */		PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
/* PCH_PLT_RST */	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
/* PCH_BUZZER */	PAD_CFG_GPO(GPP_B14, 0, DEEP),
/* GSPI0_CS# */		PAD_NC(GPP_B15, NONE),
/* WLAN_PCIE_WAKE */	PAD_CFG_GPI_SCI(GPP_B16, NONE, DEEP, EDGE_SINGLE, INVERT),
/* SSD_PCIE_WAKE */	PAD_NC(GPP_B17, NONE),
/* GSPI0_MOSI */	PAD_NC(GPP_B18, NONE),
/* CCODEC_SPI_CS */	PAD_NC(GPP_B19, NONE),
/* CODEC_SPI_CLK */	PAD_NC(GPP_B20, NONE),
/* CODEC_SPI_MISO */	PAD_NC(GPP_B21, NONE),
/* CODEC_SPI_MOSI */	PAD_NC(GPP_B22, NONE),
/* SM1ALERT# */		PAD_NC(GPP_B23, NONE),
/* SMB_CLK */		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),
/* SMB_DATA */		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),
/* SMBALERT# */		PAD_CFG_GPO(GPP_C2, 0, DEEP),
/* M2_WWAN_PWREN */	PAD_NC(GPP_C3, NONE),
/* SML0DATA */		PAD_NC(GPP_C4, NONE),
/* SML0ALERT# */	PAD_NC(GPP_C5, NONE),
/* EC_IN_RW */		PAD_CFG_GPI_GPIO_DRIVER(GPP_C6, NONE, DEEP),
/* USB_CTL */		PAD_NC(GPP_C7, NONE),
/* UART0_RXD */		PAD_NC(GPP_C8, NONE),
/* UART0_TXD */		PAD_NC(GPP_C9, NONE),
/* NFC_RST* */		PAD_NC(GPP_C10, NONE),
/* EN_PP3300_KEPLER */	PAD_NC(GPP_C11, NONE),
/* PCH_MEM_CFG0 */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C12, NONE, DEEP),
/* PCH_MEM_CFG1 */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C13, NONE, DEEP),
/* PCH_MEM_CFG2 */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C14, NONE, DEEP),
/* PCH_MEM_CFG3 */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C15, NONE, DEEP),
/* I2C0_SDA */		PAD_CFG_NF(GPP_C16, UP_5K, DEEP, NF1),
/* I2C0_SCL */		PAD_CFG_NF(GPP_C17, UP_5K, DEEP, NF1),
/* I2C1_SDA */		PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1),
/* I2C1_SCL */		PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1),
/* GD_UART2_RXD */	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
/* GD_UART2_TXD */	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
/* TCH_PNL_PWREN */	PAD_CFG_GPO(GPP_C22, 1, DEEP),
/* SPI_WP_STATUS */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C23, UP_20K, DEEP),
/* ITCH_SPI_CS */	PAD_NC(GPP_D0, NONE),
/* ITCH_SPI_CLK */	PAD_NC(GPP_D1, NONE),
/* ITCH_SPI_MISO_1 */	PAD_NC(GPP_D2, NONE),
/* ITCH_SPI_MISO_0 */	PAD_NC(GPP_D3, NONE),
/* CAM_FLASH_STROBE */	PAD_NC(GPP_D4, NONE),
/* EN_PP3300_DX_EMMC */ PAD_NC(GPP_D5, NONE),
/* EN_PP1800_DX_EMMC */ PAD_NC(GPP_D6, NONE),
/* SH_I2C1_SDA */	PAD_NC(GPP_D7, NONE),
/* SH_I2C1_SCL */	PAD_NC(GPP_D8, NONE),
/* ISH_SPI_CSB */	PAD_NC(GPP_D9, NONE),
/* USB_A0_ILIM_SEL */	PAD_CFG_GPO(GPP_D10, 0, DEEP),
/* USB_A1_ILIM_SEL */	PAD_CFG_GPO(GPP_D11, 0, DEEP),
/* EN_PP3300_DX_CAM */	PAD_NC(GPP_D12, NONE),
/* EN_PP1800_DX_AUDIO */PAD_CFG_GPO(GPP_D13, 1, DEEP),
/* ISH_UART0_TXD */	PAD_NC(GPP_D14, NONE),
/* ISH_UART0_RTS */	PAD_NC(GPP_D15, NONE),
/* ISH_UART0_CTS */	PAD_NC(GPP_D16, NONE),
/* DMIC_CLK_1 */	PAD_CFG_NF(GPP_D17, NONE, DEEP, NF1),
/* DMIC_DATA_1 */	PAD_CFG_NF(GPP_D18, NONE, DEEP, NF1),
/* DMIC_CLK_0 */	PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
/* DMIC_DATA_0 */	PAD_CFG_NF(GPP_D20, NONE, DEEP, NF1),
/* ITCH_SPI_D2 */	PAD_NC(GPP_D21, NONE),
/* ITCH_SPI_D3 */	PAD_NC(GPP_D22, NONE),
/* I2S_MCLK */		PAD_CFG_NF(GPP_D23, NONE, DEEP, NF1),
/* SPI_TPM_IRQ */	PAD_CFG_GPI_APIC_HIGH(GPP_E0, NONE, PLTRST),
/* SATAXPCIE1 */	PAD_NC(GPP_E1, NONE),
/* SSD_PEDET */		PAD_NC(GPP_E2, NONE),
/* CPU_GP0 */		PAD_NC(GPP_E3, NONE),
/* SSD_SATA_DEVSLP */	PAD_NC(GPP_E4, NONE),
/* SATA_DEVSLP1 */	PAD_NC(GPP_E5, NONE),
/* SATA_DEVSLP2 */	PAD_NC(GPP_E6, NONE),
/* TCH_PNL_INTR* */	PAD_CFG_GPI_APIC_HIGH(GPP_E7, NONE, PLTRST),
/* SATALED# */		PAD_NC(GPP_E8, NONE),
/* USB2_OC_0 */		PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1),
/* USB2_OC_1 */		PAD_CFG_NF(GPP_E10, NONE, DEEP, NF1),
/* USB2_OC_2 */		PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1),
/* USB2_OC_3 */		PAD_CFG_NF(GPP_E12, NONE, DEEP, NF1),
/* DDI1_HPD */		PAD_CFG_NF(GPP_E13, NONE, DEEP, NF1),
/* DDI2_HPD */		PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
/* EC_SMI */		PAD_CFG_GPI_SMI(GPP_E15, NONE, DEEP, EDGE_SINGLE, INVERT),
/* EC_SCI */		PAD_CFG_GPI_SCI(GPP_E16, NONE, DEEP, EDGE_SINGLE, INVERT),
/* EDP_HPD */		PAD_CFG_NF(GPP_E17, NONE, DEEP, NF1),
/* DDPB_CTRLCLK */	PAD_CFG_NF(GPP_E18, NONE, DEEP, NF1),
/* DDPB_CTRLDATA */	PAD_CFG_NF(GPP_E19, NONE, DEEP, NF1),
/* DDPC_CTRLCLK */	PAD_CFG_NF(GPP_E20, NONE, DEEP, NF1),
/* DDPC_CTRLDATA */	PAD_CFG_NF(GPP_E21, NONE, DEEP, NF1),
/* DDPD_CTRLCLK */	PAD_NC(GPP_E22, NONE),
/* TCH_PNL_RST */	PAD_CFG_GPO(GPP_E23, 1, DEEP),
/* I2S2_SCLK */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F0, NONE, DEEP),
/* I2S2_SFRM */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F1, NONE, DEEP),
/* I2S2_TXD */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F2, NONE, DEEP),
/* I2S2_RXD */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F3, NONE, DEEP),
/* I2C2_SDA */		PAD_CFG_NF(GPP_F4, NONE, DEEP, NF1),
/* I2C2_SCL */		PAD_CFG_NF(GPP_F5, NONE, DEEP, NF1),
/* I2C3_SDA */		PAD_NC(GPP_F6, NONE),
/* I2C3_SCL */		PAD_NC(GPP_F7, NONE),
/* I2C4_SDA */		PAD_CFG_NF_1V8(GPP_F8, NONE, DEEP, NF1),
/* I2C4_SCL */		PAD_CFG_NF_1V8(GPP_F9, NONE, DEEP, NF1),
/* AUDIO_IRQ */		PAD_CFG_GPI_APIC_HIGH(GPP_F10, NONE, PLTRST),
/* I2C5_SCL */		PAD_NC(GPP_F11, NONE),
/* EMMC_CMD */		PAD_CFG_NF(GPP_F12, NONE, DEEP, NF1),
/* EMMC_DATA0 */	PAD_CFG_NF(GPP_F13, NONE, DEEP, NF1),
/* EMMC_DATA1 */	PAD_CFG_NF(GPP_F14, NONE, DEEP, NF1),
/* EMMC_DATA2 */	PAD_CFG_NF(GPP_F15, NONE, DEEP, NF1),
/* EMMC_DATA3 */	PAD_CFG_NF(GPP_F16, NONE, DEEP, NF1),
/* EMMC_DATA4 */	PAD_CFG_NF(GPP_F17, NONE, DEEP, NF1),
/* EMMC_DATA5 */	PAD_CFG_NF(GPP_F18, NONE, DEEP, NF1),
/* EMMC_DATA6 */	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1),
/* EMMC_DATA7 */	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1),
/* EMMC_RCLK */		PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1),
/* EMMC_CLK */		PAD_CFG_NF(GPP_F22, NONE, DEEP, NF1),
/* BOOT_BEEP */		PAD_CFG_GPO(GPP_F23, 0, DEEP),
/* SD_CMD */		PAD_NC(GPP_G0, NONE),
/* SD_DATA0 */		PAD_NC(GPP_G1, NONE),
/* SD_DATA1 */		PAD_NC(GPP_G2, NONE),
/* SD_DATA2 */		PAD_NC(GPP_G3, NONE),
/* SD_DATA3 */		PAD_NC(GPP_G4, NONE),
/* SD_CD# */		PAD_NC(GPP_G5, NONE),
/* SD_CLK */		PAD_NC(GPP_G6, NONE),
/* SD_WP */		PAD_NC(GPP_G7, NONE),
/* PCH_BATLOW */	PAD_CFG_NF(GPD0, NONE, DEEP, NF1),
/* EC_PCH_ACPRESENT */	PAD_CFG_NF(GPD1, NONE, DEEP, NF1),
/* EC_PCH_WAKE */	PAD_CFG_NF(GPD2, NONE, DEEP, NF1),
/* EC_PCH_PWRBTN */	PAD_CFG_NF(GPD3, NONE, DEEP, NF1),
/* PM_SLP_S3# */	PAD_CFG_NF(GPD4, NONE, DEEP, NF1),
/* PM_SLP_S4# */	PAD_CFG_NF(GPD5, NONE, DEEP, NF1),
/* PM_SLP_SA# */	PAD_CFG_NF(GPD6, NONE, DEEP, NF1),
/* GPD7 */		PAD_NC(GPD7, NONE),
/* PM_SUSCLK */		PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
/* PCH_SLP_WLAN# */	PAD_NC(GPD9, NONE),
/* PM_SLP_S5# */	PAD_NC(GPD10, NONE),
/* LANPHYC */		PAD_NC(GPD11, NONE),
};

/* Early pad configuration in romstage. */
static const struct pad_config early_gpio_table[] = {
/* SRCCLKREQ2# */	PAD_CFG_NF(GPP_B7, NONE, DEEP, NF1), /* KEPLER */
/* UART0_CTS# */	PAD_CFG_GPO(GPP_C11, 0, DEEP), /* EN_PP3300_KEPLER */
/* SPI_WP_STATUS */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C23, UP_20K, DEEP),
/* GD_UART2_RXD */	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
/* GD_UART2_TXD */	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
};

#endif

#endif
