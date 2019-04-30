/**
 *
 */
#include <stdbool.h>

#define DUAL_CHIP_ENABLE true
#define SECONDARY_CHIP_MODE false

#define STATUS_LED_PWM_TOP_VALUE STATUS_LED_PWM_TOP_VALUE_DEFAULT
#define STATUS_LED_PWM_CLOCK_SPEED STATUS_LED_PWM_CLOCK_SPEED_DEFAULT

#define BMX160_ENABLE true
#define LPS22HB_ENABLE true


////////////////////////////////////////////////////////////////
////////// DO NOT CHANGE SETTING UNDER THIS LINE////////////////
////////////////////////////////////////////////////////////////

#define SECONDARY_CHIP_DEFAULT_CONFIG false

#if DUAL_CHIP_ENABLE
    #define SECONDARY_CHIP SECONDARY_CHIP_MODE
#else
    #define SECONDARY_CHIP SECONDARY_CHIP_DEFAULT_CONFIG
#endif

#define STATUS_LED_PWM_TOP_VALUE_DEFAULT 200

#define STATUS_LED_PWM_CLOCK_SPEED_DEFAULT NRF_PWM_CLK_250kHz