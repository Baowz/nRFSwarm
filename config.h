/**
 *
 */


#define DUAL_CHIP_ENABLE true // enable dual chip

#if DUAL_CHIP_ENABLE
    #define SECONDERY_CHIP false
#endif


/**
 *  uncomment the defines under to change the default settings
 *  for the clock speed and top value for pwm used in the status leds
 */
//#define STATUS_LED_PWM_TOP_VALUE 200
//#define STATUS_LED_PWM_CLOCK_SPEED NRF_PWM_CLK_250kHz
