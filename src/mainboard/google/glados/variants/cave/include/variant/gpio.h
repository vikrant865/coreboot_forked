/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MAINBOARD_GPIO_H
#define MAINBOARD_GPIO_H

#include <soc/gpe.h>
#include <soc/gpio.h>

/* MAX98357A SD_MODE */
#define GPIO_SPEAKER_MAXIM_AMP_SDMODE	GPP_E3

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
#define GPE_TOUCHPAD_WAKE	GPE0_DW0_05

/* Input device interrupt configuration */
#define TOUCHPAD_INT_L		GPP_B3_IRQ
#define TOUCHSCREEN_INT_L	GPP_E7_IRQ
#define MIC_INT_L		GPP_F10_IRQ

/* GPP_E16 is EC_SCI_L. GPP_E group is routed to DW2 in the GPE0 block */
#define EC_SCI_GPI		GPE0_DW2_16
#define EC_SMI_GPI		GPP_E15

/* Power rail control signals. */
#define EN_PP3300_KEPLER	GPP_C11
#define EN_PP3300_DX_TOUCH	GPP_C22
#define EN_PP3300_DX_EMMC	GPP_D5
#define EN_PP1800_DX_EMMC	GPP_D6
#define EN_PP3300_DX_CAM	GPP_D12

/* SD controller needs additional card detect GPIO to support RTD3 */
#define GPIO_SD_CARD_DETECT	GPP_A7

#ifndef __ACPI__
/* Pad configuration in ramstage. */
static const struct pad_config gpio_table[] = {
/* RCIN# */		PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1),
/* LAD0 */		PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1),
/* LAD1 */		PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1),
/* LAD2 */		PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1),
/* LAD3 */		PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1),
/* LFRAME# */		PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1),
/* SERIRQ */		PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1),
/* SD_CD_INT_L */	PAD_CFG_GPI_GPIO_DRIVER(GPP_A7, UP_20K, DEEP),
/* CLKRUN# */		PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1),
/* CLKOUT_LPC0 */	PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1),
/* CLKOUT_LPC1 */	PAD_NC(GPP_A10, NONE),
/* PME# */		PAD_NC(GPP_A11, NONE),
/* BM_BUSY# */		PAD_NC(GPP_A12, NONE),
/* SUSWARN# */		PAD_CFG_NF(GPP_A13, NONE, DEEP, NF1),
/* SUS_STAT# */		PAD_CFG_NF(GPP_A14, NONE, DEEP, NF1),
/* SUSACK# */		PAD_CFG_NF(GPP_A15, NONE, DEEP, NF1),
/* SD_1P8_SEL */	PAD_CFG_NF(GPP_A16, NONE, DEEP, NF1),
/* SD_PWR_EN# */	PAD_CFG_NF(GPP_A17, NONE, DEEP, NF1),
/* ISH_GP0 */		PAD_NC(GPP_A18, NONE),
/* ISH_GP1 */		PAD_NC(GPP_A19, NONE),
/* ISH_GP2 */		PAD_NC(GPP_A20, NONE),
/* ISH_GP3 */		PAD_NC(GPP_A21, NONE),
/* ISH_GP4 */		PAD_NC(GPP_A22, NONE),
/* ISH_GP5 */		PAD_NC(GPP_A23, NONE),
/* CORE_VID0 */		PAD_NC(GPP_B0, NONE),
/* CORE_VID1 */		PAD_NC(GPP_B1, NONE),
/* VRALERT# */		PAD_NC(GPP_B2, NONE),
/* CPU_GP2 */		PAD_CFG_GPI_APIC_HIGH(GPP_B3, NONE, PLTRST), /* TRACKPAD */
/* CPU_GP3 */		PAD_NC(GPP_B4, NONE),
/* SRCCLKREQ0# */	PAD_CFG_GPI_SCI(GPP_B5, NONE, DEEP, EDGE_SINGLE, INVERT), /* TRACKPAD WAKE */
/* SRCCLKREQ1# */	PAD_CFG_NF(GPP_B6, NONE, DEEP, NF1), /* WLAN */
/* SRCCLKREQ2# */	PAD_NC(GPP_B7, NONE),
/* SRCCLKREQ3# */	PAD_NC(GPP_B8, NONE),
/* SRCCLKREQ4# */	PAD_NC(GPP_B9, NONE),
/* SRCCLKREQ5# */	PAD_NC(GPP_B10, NONE),
/* EXT_PWR_GATE# */	PAD_CFG_NF(GPP_B11, NONE, DEEP, NF1),
/* SLP_S0# */		PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1),
/* PLTRST# */		PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),
/* SPKR */		PAD_NC(GPP_B14, NONE),
/* GSPI0_CS# */		PAD_NC(GPP_B15, NONE),
/* GSPI0_CLK */		PAD_CFG_GPI_SCI(GPP_B16, NONE, DEEP, EDGE_SINGLE, INVERT), /* WLAN WAKE */
/* GSPI0_MISO */	PAD_NC(GPP_B17, NONE),
/* GSPI0_MOSI */	PAD_NC(GPP_B18, NONE),
/* GSPI1_CS# */		PAD_NC(GPP_B19, NONE),
/* GSPI1_CLK */		PAD_NC(GPP_B20, NONE),
/* GSPI1_MISO */	PAD_NC(GPP_B21, NONE),
/* GSPI1_MOSI */	PAD_NC(GPP_B22, NONE),
/* SM1ALERT# */		PAD_CFG_GPO(GPP_B23, 0, DEEP),
/* SMBCLK */		PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1), /* XDP */
/* SMBDATA */		PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1), /* XDP */
/* SMBALERT# */		PAD_NC(GPP_C2, NONE),
/* SML0CLK */		PAD_CFG_GPI_GPIO_DRIVER(GPP_C3, NONE, DEEP),
/* SML0DATA */		PAD_CFG_GPI_GPIO_DRIVER(GPP_C4, NONE, DEEP),
/* SML0ALERT# */	PAD_CFG_GPO(GPP_C5, 0, DEEP),
/* SM1CLK */		PAD_CFG_GPI_GPIO_DRIVER(GPP_C6, UP_20K, DEEP), /* EC_IN_RW */
/* SM1DATA */		PAD_CFG_GPI_GPIO_DRIVER(GPP_C7, NONE, DEEP),
/* UART0_RXD */		PAD_NC(GPP_C8, NONE),
/* UART0_TXD */		PAD_NC(GPP_C9, NONE),
/* UART0_RTS# */	PAD_NC(GPP_C10, NONE),
/* UART0_CTS# */	PAD_NC(GPP_C11, NONE),
/* UART1_RXD */		PAD_CFG_GPI_GPIO_DRIVER(GPP_C12, NONE, DEEP), /* MEM_CONFIG[0] */
/* UART1_TXD */		PAD_CFG_GPI_GPIO_DRIVER(GPP_C13, NONE, DEEP), /* MEM_CONFIG[1] */
/* UART1_RTS# */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C14, NONE, DEEP), /* MEM_CONFIG[2] */
/* UART1_CTS# */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C15, NONE, DEEP), /* MEM_CONFIG[3] */
/* I2C0_SDA */		PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1), /* TOUCHSCREEN */
/* I2C0_SCL */		PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1), /* TOUCHSCREEN */
/* I2C1_SDA */		PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1), /* TRACKPAD */
/* I2C1_SCL */		PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1), /* TRACKPAD */
/* UART2_RXD */		PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1), /* SERVO */
/* UART2_TXD */		PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1), /* SERVO */
/* UART2_RTS# */	PAD_CFG_GPO(GPP_C22, 1, DEEP), /* EN_PP3300_DX_TOUCH */
/* UART2_CTS# */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C23, UP_20K, DEEP), /* PCH_WP */
/* SPI1_CS# */		PAD_NC(GPP_D0, NONE),
/* SPI1_CLK */		PAD_NC(GPP_D1, NONE),
/* SPI1_MISO */		PAD_NC(GPP_D2, NONE),
/* SPI1_MOSI */		PAD_NC(GPP_D3, NONE),
/* FASHTRIG */		PAD_NC(GPP_D4, NONE),
/* ISH_I2C0_SDA */	PAD_CFG_GPO(GPP_D5, 1, DEEP), /* EN_PP3300_DX_EMMC */
/* ISH_I2C0_SCL */	PAD_CFG_GPO(GPP_D6, 1, DEEP), /* EN_PP1800_DX_EMMC */
/* ISH_I2C1_SDA */	PAD_NC(GPP_D7, NONE),
/* ISH_I2C1_SCL */	PAD_NC(GPP_D8, NONE),
			PAD_NC(GPP_D9, NONE),
			PAD_NC(GPP_D10, NONE),
			PAD_NC(GPP_D11, NONE),
			PAD_CFG_GPO(GPP_D12, 1, DEEP), /* EN_PP3300_DX_CAM */
/* ISH_UART0_RXD */	PAD_NC(GPP_D13, NONE),
/* ISH_UART0_TXD */	PAD_NC(GPP_D14, NONE),
/* ISH_UART0_RTS# */	PAD_NC(GPP_D15, NONE),
/* ISH_UART0_CTS# */	PAD_NC(GPP_D16, NONE),
/* DMIC_CLK1 */		PAD_NC(GPP_D17, NONE),
/* DMIC_DATA1 */	PAD_NC(GPP_D18, NONE),
/* DMIC_CLK0 */		PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
/* DMIC_DATA0 */	PAD_CFG_NF(GPP_D20, NONE, DEEP, NF1),
/* TS_SPI_IO2 */	PAD_NC(GPP_D21, NONE),
/* TS_SPI_IO3 */	PAD_NC(GPP_D22, NONE),
/* I2S_MCLK */		PAD_CFG_NF(GPP_D23, NONE, DEEP, NF1),
/* SATAXPCI0 */		PAD_CFG_GPI_APIC_HIGH(GPP_E0, NONE, PLTRST), /* TPM_PIRQ_L */
/* SATAXPCIE1 */	PAD_NC(GPP_E1, NONE),
/* SATAXPCIE2 */	PAD_NC(GPP_E2, NONE),
/* CPU_GP0 */		PAD_CFG_GPI_GPIO_DRIVER(GPP_E3, NONE, DEEP), /* AUDIO_DB_ID */
/* SATA_DEVSLP0 */	PAD_CFG_GPO(GPP_E4, 1, DEEP), /* TOUCH_RESET */
/* SATA_DEVSLP1 */	PAD_NC(GPP_E5, NONE),
/* SATA_DEVSLP2 */	PAD_NC(GPP_E6, NONE),
/* CPU_GP1 */		PAD_CFG_GPI_APIC_HIGH(GPP_E7, NONE, PLTRST), /* TOUCHSCREEN */
/* SATALED# */		PAD_NC(GPP_E8, NONE),
/* USB2_OCO# */		PAD_NC(GPP_E9, NONE),
/* USB2_OC1# */		PAD_NC(GPP_E10, NONE),
/* USB2_OC2# */		PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1),
/* USB2_OC3# */		PAD_CFG_NF(GPP_E12, NONE, DEEP, NF1),
/* DDPB_HPD0 */		PAD_CFG_NF(GPP_E13, NONE, DEEP, NF1),
/* DDPC_HPD1 */		PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),
/* DDPD_HPD2 */		PAD_CFG_GPI_SMI(GPP_E15, NONE, DEEP, EDGE_SINGLE, INVERT), /* EC_SMI_L */
/* DDPE_HPD3 */		PAD_CFG_GPI_SCI(GPP_E16, NONE, DEEP, EDGE_SINGLE, INVERT), /* EC_SCI_L */
/* EDP_HPD */		PAD_CFG_NF(GPP_E17, NONE, DEEP, NF1),
/* DDPB_CTRLCLK */	PAD_NC(GPP_E18, NONE),
/* DDPB_CTRLDATA */	PAD_CFG_NF(GPP_E19, NONE, DEEP, NF1),
/* DDPC_CTRLCLK */	PAD_NC(GPP_E20, NONE),
/* DDPC_CTRLDATA */	PAD_CFG_NF(GPP_E21, NONE, DEEP, NF1),
			PAD_NC(GPP_E22, NONE),
			PAD_NC(GPP_E23, NONE),
/*
 * The next 4 pads are for bit banging the amplifiers. They are connected
 * together with i2s0 signals. For default behavior of i2s make these
 * gpio inupts.
 */
/* I2S2_SCLK */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F0, NONE, DEEP),
/* I2S2_SFRM */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F1, NONE, DEEP),
/* I2S2_TXD */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F2, NONE, DEEP),
/* I2S2_RXD */		PAD_CFG_GPI_GPIO_DRIVER(GPP_F3, NONE, DEEP),
/* I2C2_SDA */		PAD_NC(GPP_F4, NONE),
/* I2C2_SCL */		PAD_NC(GPP_F5, NONE),
/* I2C3_SDA */		PAD_NC(GPP_F6, NONE),
/* I2C3_SCL */		PAD_NC(GPP_F7, NONE),
/* I2C4_SDA */		PAD_CFG_NF(GPP_F8, NONE, DEEP, NF1), /* Amplifiers */
/* I2C4_SCL */		PAD_CFG_NF(GPP_F9, NONE, DEEP, NF1), /* Amplifiers */
/* I2C5_SDA */		PAD_CFG_GPI_APIC_HIGH(GPP_F10, NONE, PLTRST), /* MIC_INT_L */
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
/* BOOT_BEEP */		PAD_CFG_GPO(GPP_F23, 1, DEEP),
/* SD_CMD */		PAD_CFG_NF(GPP_G0, NONE, DEEP, NF1),
/* SD_DATA0 */		PAD_CFG_NF(GPP_G1, NONE, DEEP, NF1),
/* SD_DATA1 */		PAD_CFG_NF(GPP_G2, NONE, DEEP, NF1),
/* SD_DATA2 */		PAD_CFG_NF(GPP_G3, NONE, DEEP, NF1),
/* SD_DATA3 */		PAD_CFG_NF(GPP_G4, NONE, DEEP, NF1),
/* SD_CD# */		PAD_CFG_NF(GPP_G5, NONE, DEEP, NF1),
/* SD_CLK */		PAD_CFG_NF(GPP_G6, NONE, DEEP, NF1),
/* SD_WP */		PAD_CFG_NF(GPP_G7, DN_20K, DEEP, NF1),
/* BATLOW# */		PAD_CFG_NF(GPD0, NONE, DEEP, NF1),
/* ACPRESENT */		PAD_CFG_NF(GPD1, NONE, DEEP, NF1),
/* LAN_WAKE# */		PAD_CFG_NF(GPD2, UP_20K, DEEP, NF1), /* EC_PCH_WAKE_L */
/* PWRBTN# */		PAD_CFG_NF(GPD3, UP_20K, DEEP, NF1),
/* SLP_S3# */		PAD_CFG_NF(GPD4, UP_20K, DEEP, NF1),
/* SLP_S4# */		PAD_CFG_NF(GPD5, UP_20K, DEEP, NF1),
/* SLP_A# */		PAD_CFG_NF(GPD6, UP_20K, DEEP, NF1),
			PAD_NC(GPD7, NONE),
/* SUSCLK */		PAD_CFG_NF(GPD8, NONE, DEEP, NF1),
/* SLP_WLAN# */		PAD_NC(GPD9, NONE),
/* SLP_S5# */		PAD_CFG_NF(GPD10, UP_20K, DEEP, NF1),
/* LANPHYC */		PAD_NC(GPD11, NONE),
};

/* Early pad configuration in romstage. */
static const struct pad_config early_gpio_table[] = {
/* UART2_CTS# */	PAD_CFG_GPI_GPIO_DRIVER(GPP_C23, UP_20K, DEEP), /* PCH_WP */
/* GD_UART2_RXD */	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),
/* GD_UART2_TXD */	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),
};

#endif

#endif
