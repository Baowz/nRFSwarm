/**
 *
 *
 *
 *
 *
 *
 *
 */
#include "nrf_gpio.h"

#include "config.h"
/*
//////////////PIN MAP/////////////////////////////
#if SECONDARY_CHIP
/////////SECONDARY CHIP PIN MAP///////////////////
#define SYSTEM_RESET_PIN                NRF_GPIO_PIN_MAP(0, 18)

#define STATUS_LED_R_PIN                NRF_GPIO_PIN_MAP(0, 13)
#define STATUS_LED_G_PIN                NRF_GPIO_PIN_MAP(0, 17)
#define STATUS_LED_B_PIN                NRF_GPIO_PIN_MAP(0, 15)

#define OPTN_STATUS_LED_R_PIN           NRF_GPIO_PIN_MAP(0, 20)
#define OPTN_STATUS_LED_G_PIN           NRF_GPIO_PIN_MAP(0, 24)
#define OPTN_STATUS_LED_B_PIN           NRF_GPIO_PIN_MAP(0, 22)

#define GPIO_1_HEADER_PIN               NRF_GPIO_PIN_MAP(1, 09)
#define GPIO_2_HEADER_PIN               NRF_GPIO_PIN_MAP(0, 06)
#define GPIO_3_HEADER_PIN               NRF_GPIO_PIN_MAP(0, 26)
#define GPIO_4_HEADER_PIN               NRF_GPIO_PIN_MAP(0, 08)
#define GPIO_5_HEADER_PIN               NRF_GPIO_PIN_MAP(0, 04)
#define GPIO_6_HEADER_PIN               NRF_GPIO_PIN_MAP(0, 30)

#define GPIO_7_HEADER_PIN               NRF_GPIO_PIN_MAP(0, 31)
#define GPIO_8_HEADER_PIN               NRF_GPIO_PIN_MAP(1, 05)
#define GPIO_9_HEADER_PIN               NRF_GPIO_PIN_MAP(0, 29)
#define GPIO_10_HEADER_PIN              NRF_GPIO_PIN_MAP(1, 03)
#define GPIO_11_HEADER_PIN              NRF_GPIO_PIN_MAP(0, 02)
#define GPIO_12_HEADER_PIN              NRF_GPIO_PIN_MAP(1, 07)

#define MOD_SCL_SCK_PIN                 NRF_GPIO_PIN_MAP(1, 00)
#define MOD_SDA_MOSI_PIN                NRF_GPIO_PIN_MAP(0, 23)
#define MOD_MISO_PIN                    NRF_GPIO_PIN_MAP(0, 25)
#define MOD_CS_1_PIN                    NRF_GPIO_PIN_MAP(1, 04)
#define MOD_CS_2_PIN                    NRF_GPIO_PIN_MAP(1, 06)
#define MOD_CS_3_PIN                    NRF_GPIO_PIN_MAP(1, 01)
#define MOD_CS_4_PIN                    NRF_GPIO_PIN_MAP(1, 11)
#define MOD_CS_5_PIN                    NRF_GPIO_PIN_MAP(0, 27)
#define MOD_CS_6_PIN                    NRF_GPIO_PIN_MAP(0, 05)
#define MOD_CS_7_PIN                    NRF_GPIO_PIN_MAP(0, 07)
#define MOD_CS_8_PIN                    NRF_GPIO_PIN_MAP(1, 02)

#define UART_RX_PIN                     NRF_GPIO_PIN_MAP(0, 21)
#define UART_TX_PIN                     NRF_GPIO_PIN_MAP(0, 16)
#define UART_CTS_PIN                    NRF_GPIO_PIN_MAP(0, 19)
#define UART_RTS_PIN                    NRF_GPIO_PIN_MAP(0, 14)

#define SHLD_SCL_SCK_PIN                NRF_GPIO_PIN_MAP(1, 10)
#define SHLD_SDA_MOSI_PIN               NRF_GPIO_PIN_MAP(1, 14)
#define SHLD_MISO_PIN                   NRF_GPIO_PIN_MAP(1, 12)
#define SHLD_CS_1_PIN                   NRF_GPIO_PIN_MAP(1, 13)
#define SHLD_LED_1_PIN                  NRF_GPIO_PIN_MAP(0, 03)
#define SHLD_CS_2_PIN                   NRF_GPIO_PIN_MAP(0, 28)
#define SHLD_LED_2_PIN                  NRF_GPIO_PIN_MAP(0, 12)

#define SDA_PIN                         NRF_GPIO_PIN_MAP(1, 08)
#define SCL_PIN                         NRF_GPIO_PIN_MAP(0, 11)
//////////////////////////////////////////////////
#else
///////////PRIMARY CHIP PIN MAP///////////////////
#define LED_MATRIX_SDB_PIN              NRF_GPIO_PIN_MAP(0, 19)
#define LED_MATRIX_IICRST_PIN           NRF_GPIO_PIN_MAP(0, 31)

#define SCL_PIN                         NRF_GPIO_PIN_MAP(0, 14)
#define SDA_PIN                         NRF_GPIO_PIN_MAP(0, 16)
#define SENSOR_CHIP_SELECT_PIN          NRF_GPIO_PIN_MAP(0, 30)

#define MOTOR_ENCODER_A1_PIN            NRF_GPIO_PIN_MAP(0, 24)
#define MOTOR_ENCODER_A2_PIN            NRF_GPIO_PIN_MAP(1, 11)
#define MOTOR_ENCODER_B1_PIN            NRF_GPIO_PIN_MAP(0, 21)
#define MOTOR_ENCODER_B2_PIN            NRF_GPIO_PIN_MAP(0, 04)

#define MOTOR_STBY_PIN                  NRF_GPIO_PIN_MAP(1, 06)
#define MOTOR_A_IN_1_PIN                NRF_GPIO_PIN_MAP(0, 22)
#define MOTOR_A_IN_2_PIN                NRF_GPIO_PIN_MAP(1, 10)
#define MOTOR_B_IN_1_PIN                NRF_GPIO_PIN_MAP(1, 04)
#define MOTOR_B_IN_2_PIN                NRF_GPIO_PIN_MAP(1, 03)
#define MOTOR_A_PWM_PIN                 NRF_GPIO_PIN_MAP(0, 25)
#define MOTOR_B_PWM_PIN                 NRF_GPIO_PIN_MAP(1, 00)

#define BAT_CHARGE_STAT_PIN             NRF_GPIO_PIN_MAP(1, 01)
#define BAT_MON_ENABLE_PIN              NRF_GPIO_PIN_MAP(0, 23)
#define BAT_MON_PIN                     NRF_GPIO_PIN_MAP(0, 28)

#define STATUS_LED_R_PIN                NRF_GPIO_PIN_MAP(0, 13)
#define STATUS_LED_B_PIN                NRF_GPIO_PIN_MAP(0, 15)
#define STATUS_LED_G_PIN                NRF_GPIO_PIN_MAP(0, 17)

#define USB_CONNECT_PIN                 NRF_GPIO_PIN_MAP(0, 02)

#define SYSTEM_RESET_PIN                NRF_GPIO_PIN_MAP(0, 18)

#define MOD_SCL_SCK_PIN                 NRF_GPIO_PIN_MAP(0, 07)
#define MOD_SDA_MOSI_PIN                NRF_GPIO_PIN_MAP(0, 05)
#define MOD_MISO_PIN                    NRF_GPIO_PIN_MAP(0, 27)
#define MOD_CS_1_PIN                    NRF_GPIO_PIN_MAP(1, 15)
#define MOD_CS_2_PIN                    NRF_GPIO_PIN_MAP(0, 29)
#define MOD_CS_3_PIN                    NRF_GPIO_PIN_MAP(0, 20)
#define MOD_CS_4_PIN                    NRF_GPIO_PIN_MAP(0, 03)
#define MOD_CS_5_PIN                    NRF_GPIO_PIN_MAP(1, 05)
#define MOD_CS_6_PIN                    NRF_GPIO_PIN_MAP(1, 07)
#define MOD_CS_7_PIN                    NRF_GPIO_PIN_MAP(1, 02)
#define MOD_CS_8_PIN                    NRF_GPIO_PIN_MAP(1, 14)

#define UART_RX_PIN                     NRF_GPIO_PIN_MAP(0, 11)
#define UART_TX_PIN                     NRF_GPIO_PIN_MAP(1, 09)
#define UART_CTS_PIN                    NRF_GPIO_PIN_MAP(0, 12)
#define UART_RTS_PIN                    NRF_GPIO_PIN_MAP(1, 08)

#define SHLD_SCL_SCK_PIN                NRF_GPIO_PIN_MAP(0, 06)
#define SHLD_SDA_MOSI_PIN               NRF_GPIO_PIN_MAP(0, 26)
#define SHLD_MISO_PIN                   NRF_GPIO_PIN_MAP(0, 08)
#define SHLD_CS_1_PIN                   NRF_GPIO_PIN_MAP(1, 13)
#define SHLD_LED_1_PIN                  NRF_GPIO_PIN_MAP(1, 12)
//////////////////////////////////////////////////
#endif
*/

#if SECONDARY_CHIP
#define GPIO_1_PIN NRF_GPIO_PIN_MAP(1,14)
#define GPIO_2_PIN NRF_GPIO_PIN_MAP(0,03)
#define GPIO_3_PIN NRF_GPIO_PIN_MAP(1,12)
#define GPIO_4_PIN NRF_GPIO_PIN_MAP(1,11)
#else
#define GPIO_1_PIN NRF_GPIO_PIN_MAP(1,14)
#define GPIO_2_PIN NRF_GPIO_PIN_MAP(0,03)
#define GPIO_3_PIN NRF_GPIO_PIN_MAP(1,12)
#define GPIO_4_PIN NRF_GPIO_PIN_MAP(1,11)

#define EX_MOD_SCL_PIN NRF_GPIO_PIN_MAP(0,04)
#define EX_MOD_SDA_MOSI_PIN NRF_GPIO_PIN_MAP(0,05)
#define EX_MOD_MISO_PIN NRF_GPIO_PIN_MAP(0,07)
#define EX_MOD_CS_1_PIN NRF_GPIO_PIN_MAP(1,08)
#define EX_MOD_CS_2_PIN NRF_GPIO_PIN_MAP(1,10)
#define EX_MOD_CS_3_PIN NRF_GPIO_PIN_MAP(1,00)
#define EX_MOD_CS_4_PIN NRF_GPIO_PIN_MAP(0,11)

#define MPU_MISO_PIN NRF_GPIO_PIN_MAP(0,12)
#define MPU_SCL_PIN NRF_GPIO_PIN_MAP(1,04)
#define MPU_INT_PIN NRF_GPIO_PIN_MAP(1,06)
#define MPU_SDA_MOSI_PIN NRF_GPIO_PIN_MAP(1,02)

#define MOTOR_AIN_1_PIN NRF_GPIO_PIN_MAP(0,19)
#define MOTOR_AIN_2_PIN NRF_GPIO_PIN_MAP(0,16)
#define MOTOR_BIN_1_PIN NRF_GPIO_PIN_MAP(0,21)
#define MOTOR_BIN_2_PIN NRF_GPIO_PIN_MAP(0,23)
#define MOTOR_PWM_A_PIN NRF_GPIO_PIN_MAP(0,14)
#define MOTOR_PWM_B_PIN NRF_GPIO_PIN_MAP(0,25)

#define STATUS_LED_R_PIN NRF_GPIO_PIN_MAP(0, 13)
#define STATUS_LED_G_PIN NRF_GPIO_PIN_MAP(0, 17)
#define STATUS_LED_B_PIN NRF_GPIO_PIN_MAP(0, 15)

#define OPTN_STATUS_LED_R_PIN NRF_GPIO_PIN_MAP(0, 20)
#define OPTN_STATUS_LED_G_PIN NRF_GPIO_PIN_MAP(0, 24)
#define OPTN_STATUS_LED_B_PIN NRF_GPIO_PIN_MAP(0, 22)

#define BAT_MON_ENABLE_PIN NRF_GPIO_PIN_MAP(0,28)
#define BAT_STAT_PIN NRF_GPIO_PIN_MAP(0,30)
#define BAT_CHG_STAT_PIN NRF_GPIO_PIN_MAP(0,31)

#define UART_RX_PIN NRF_GPIO_PIN_MAP(1,01)
#define UART_TX_PIN NRF_GPIO_PIN_MAP(1,03)
#define UART_CTS_PIN NRF_GPIO_PIN_MAP(1,05)
#define UART_RTS_PIN NRF_GPIO_PIN_MAP(1,07)

#endif
