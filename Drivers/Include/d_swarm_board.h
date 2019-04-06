/**
 *
 *
 *
 *
 *
 *
 *
 */
#include "config.h"

#define NRF_GPIO_PIN_MAP(port, pin) ((port << 5) | (pin & 0x1F))

//////////////PIN MAP///////////////////////////
#if DUAL_CHIP_ENABLE
#if SECONDARY_CHIP
/////////SECONDARY CHIP PIN MAP////////////////////
#define SYSTEM_RESET_PIN                NRF_GPIO_PIN_MAP(0, 18)
#define STATUS_LED_1_R_PIN              NRF_GPIO_PIN_MAP(0, 13)
#define STATUS_LED_1_G_PIN              NRF_GPIO_PIN_MAP(0, 17)
#define STATUS_LED_1_B_PIN              NRF_GPIO_PIN_MAP(0, 15)
#define STATUS_LED_2_R_PIN              NRF_GPIO_PIN_MAP(0, 20)
#define STATUS_LED_2_G_PIN              NRF_GPIO_PIN_MAP(0, 24)
#define STATUS_LED_2_B_PIN              NRF_GPIO_PIN_MAP(0, 22)
#define SHLD_HEADER_1_STATUS_LED_PIN    NRF_GPIO_PIN_MAP(0, 03)
#define SHLD_HEADER_2_STATUS_LED_PIN    NRF_GPIO_PIN_MAP(0, 12)
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
//////////////////////////////////////////////////
#else
///////////PRIMARY CHIP PIN MAP////////////////////
#define LED_MATRIX_SDB_PIN              NRF_GPIO_PIN_MAP(0, 14)
#define LED_MATRIX_IICRST_PIN           NRF_GPIO_PIN_MAP(0, 02)
#define MOTOR_ENCODER_A1_PIN            NRF_GPIO_PIN_MAP(0, 11)
#define MOTOR_ENCODER_A2_PIN            NRF_GPIO_PIN_MAP(0, 29)
#define MOTOR_ENCODER_B1_PIN            NRF_GPIO_PIN_MAP(0, 12)
#define MOTOR_ENCODER_B2_PIN            NRF_GPIO_PIN_MAP(0, 03)
#define MOTOR_STBY_PIN                  NRF_GPIO_PIN_MAP(1, 06)
#define MOTOR_A_IN_1_PIN                NRF_GPIO_PIN_MAP(0, 20)
#define MOTOR_A_IN_2_PIN                NRF_GPIO_PIN_MAP(1, 10)
#define MOTOR_B_IN_1_PIN                NRF_GPIO_PIN_MAP(1, 04)
#define MOTOR_B_IN_2_PIN                NRF_GPIO_PIN_MAP(1, 03)
#define MOTOR_A_PWM_PIN                 NRF_GPIO_PIN_MAP(0, 23)
#define MOTOR_B_PWM_PIN                 NRF_GPIO_PIN_MAP(0, 25)
#define BAT_CHARGE_STAT_PIN             NRF_GPIO_PIN_MAP(1, 01)
#define BAT_MON_ENABLE_PIN              NRF_GPIO_PIN_MAP(1, 14)
#define BAT_MON_PIN                     NRF_GPIO_PIN_MAP(0, 05)
#define STATUS_LED_R_PIN                NRF_GPIO_PIN_MAP(0, 13)
#define STATUS_LED_B_PIN                NRF_GPIO_PIN_MAP(0, 15)
#define STATUS_LED_G_PIN                NRF_GPIO_PIN_MAP(0, 17)
#define SENSOR_CHIP_SELECT_PIN          NRF_GPIO_PIN_MAP(1, 08)
#define USB_CONNECT_PIN                 NRF_GPIO_PIN_MAP(0, 31)
#define SYSTEM_RESET_PIN                NRF_GPIO_PIN_MAP(0, 18)
//////////////////////////////////////////////////
#endif
#else
/////////////SINGLE CHIP PIN MAP///////////////////
#define LED_MATRIX_SDB_PIN              NRF_GPIO_PIN_MAP(0, 14)
#define LED_MATRIX_IICRST_PIN           NRF_GPIO_PIN_MAP(0, 02)
#define MOTOR_ENCODER_A1_PIN            NRF_GPIO_PIN_MAP(0, 11)
#define MOTOR_ENCODER_A2_PIN            NRF_GPIO_PIN_MAP(0, 29)
#define MOTOR_ENCODER_B1_PIN            NRF_GPIO_PIN_MAP(0, 12)
#define MOTOR_ENCODER_B2_PIN            NRF_GPIO_PIN_MAP(0, 03)
#define MOTOR_STBY_PIN                  NRF_GPIO_PIN_MAP(1, 06)
#define MOTOR_A_IN_1_PIN                NRF_GPIO_PIN_MAP(0, 20)
#define MOTOR_A_IN_2_PIN                NRF_GPIO_PIN_MAP(1, 10)
#define MOTOR_B_IN_1_PIN                NRF_GPIO_PIN_MAP(1, 04)
#define MOTOR_B_IN_2_PIN                NRF_GPIO_PIN_MAP(1, 03)
#define MOTOR_A_PWM_PIN                 NRF_GPIO_PIN_MAP(0, 23)
#define MOTOR_B_PWM_PIN                 NRF_GPIO_PIN_MAP(0, 25)
#define BAT_CHARGE_STAT_PIN             NRF_GPIO_PIN_MAP(1, 01)
#define BAT_MON_ENABLE_PIN              NRF_GPIO_PIN_MAP(1, 14)
#define BAT_MON_PIN                     NRF_GPIO_PIN_MAP(0, 05)
#define STATUS_LED_R_PIN                NRF_GPIO_PIN_MAP(0, 13)
#define STATUS_LED_B_PIN                NRF_GPIO_PIN_MAP(0, 15)
#define STATUS_LED_G_PIN                NRF_GPIO_PIN_MAP(0, 17)
#define SENSOR_CHIP_SELECT_PIN          NRF_GPIO_PIN_MAP(1, 08)
#define USB_CONNECT_PIN                 NRF_GPIO_PIN_MAP(0, 31)
#define SYSTEM_RESET_PIN                NRF_GPIO_PIN_MAP(0, 18)
//////////////////////////////////////////////////
#endif