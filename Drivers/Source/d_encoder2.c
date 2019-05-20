#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "nrfx_gpiote.h"
#include "d_encoder2.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"


//Code that runs when encoder interrupt triggers, encodercounter wont increase unless functions is in main
//void encoderintnerrupt(nrfx_gpiote_pin_t input,  nrf_gpiote_polarity_t action)
//{
//
//    if(input == encoderA_left)
//    {
//        
//        encodercounter.leftmotorticks++;
//        NRF_LOG_INFO("Left press");
//        //nrf_gpio_pin_set(LED_1);
//        
//     }
//    else if(input == encoderA_right)
//    {   
//        encodercounter.rightmotorticks++;
//        NRF_LOG_INFO("right press");
//    }
//}


//Configure interrupt for Encoders  
void gpio_init(void)
{
    ret_code_t err_code;

    err_code = nrfx_gpiote_init();
    APP_ERROR_CHECK(err_code);
    //Input config
    //Settings for using buttons on DK, check for what works with real encoder
    //nrfx_gpiote_in_config_t encoder_interrupt = NRFX_GPIOTE_CONFIG_IN_SENSE_TOGGLE(true);
    nrfx_gpiote_in_config_t encoder_interrupt = NRFX_GPIOTE_CONFIG_IN_SENSE_LOTOHI(true);
    encoder_interrupt.pull = NRF_GPIO_PIN_PULLUP;

    //Init left encoder pin
    err_code = nrfx_gpiote_in_init(encoderA_left, &encoder_interrupt, encoderintnerrupt);
    APP_ERROR_CHECK(err_code);
    //Init right encoder pin
    err_code = nrfx_gpiote_in_init(encoderA_right, &encoder_interrupt, encoderintnerrupt);
    APP_ERROR_CHECK(err_code);
    //Enable events
    nrfx_gpiote_in_event_enable(encoderA_left, true);
    nrfx_gpiote_in_event_enable(encoderA_right, true);
}