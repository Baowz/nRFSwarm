#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "nrfx_pwm.h"
#include "m_motor.h"
#include "nrf_gpio.h"

#include "app_error.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"


//

//



static nrfx_pwm_t MOTOR_PWM = NRFX_PWM_INSTANCE(0);     //Start motor pwm instance

static void pwm_event_handler(nrfx_pwm_evt_type_t event_type);

//Create struct named motor and insert values
    motor_values_t motors =
    {
    .motor0throttle = 20,
    .motor1throttle = 20,

    .motor0forward = 1,
    .motor1forward = 1
    };

  static nrf_pwm_values_individual_t Throttle_values; // Struct for Throttle Values
  //nrf_pwm_values_individual_t Throttle_values =
  //{
  //.channel_0 = motors.motor0throttle,
  //.channel_1 = motors.motor1throttle,
  //.channel_0 = 0,
  //.channel_0 = 0,
  //};

      nrf_pwm_sequence_t const seq =
    {
        .values.p_individual = &Throttle_values,
        .length          = NRF_PWM_VALUES_LENGTH(Throttle_values),
        .repeats         = 0,
        .end_delay       = 0
    };

void init_motor_pwm(void)
{
    NRF_LOG_INFO("Motor PWM Initalizing");



    nrfx_pwm_config_t const motor_pwm_config =
    {
        .output_pins =
        {
            PWM_PIN_0 | NRFX_PWM_PIN_INVERTED,  // Motor 0
            PWM_PIN_1 | NRFX_PWM_PIN_INVERTED,  // Motor 1
            NRFX_PWM_PIN_NOT_USED,              // Channel 2 Not in use
            NRFX_PWM_PIN_NOT_USED               // Channel 3 Not in use
        },
        .irq_priority = APP_IRQ_PRIORITY_LOWEST,
        .base_clock   = PWM_PRESCALER_PRESCALER_DIV_8, // 2MHz
        .count_mode   = PWM_MODE_UPDOWN_Up,             // Up counter, edge-aligned PWM duty cycle
        .top_value    = 100,                             //  2Mhz / 100 = 20kHz
        .load_mode    = PWM_DECODER_LOAD_Individual,
        .step_mode    = PWM_DECODER_MODE_RefreshCount
    };
    APP_ERROR_CHECK(nrfx_pwm_init(&MOTOR_PWM, &motor_pwm_config, NULL));

    Throttle_values.channel_0 = 0;
    Throttle_values.channel_1 = 0;
    Throttle_values.channel_2 = 0;
    Throttle_values.channel_3 = 0;

    nrf_gpio_cfg_output(MOTOR_PIN_OA);
    nrf_gpio_cfg_output(MOTOR_PIN_OB);
    nrf_gpio_cfg_output(MOTOR_PIN_1A);
    nrf_gpio_cfg_output(MOTOR_PIN_1B);
}

void MOTOR_DIRECTION(motor_values_t *motors)
{
     if (motors->motor0forward){
       nrf_gpio_pin_set(MOTOR_PIN_OA);
       nrf_gpio_pin_clear(MOTOR_PIN_OB);
     }
     else {
       nrf_gpio_pin_set(MOTOR_PIN_OA);
       nrf_gpio_pin_clear(MOTOR_PIN_OB);
     }
     if (motors->motor1forward){
       nrf_gpio_pin_set(MOTOR_PIN_1A);
       nrf_gpio_pin_clear(MOTOR_PIN_1B);
     }
     else {
       nrf_gpio_pin_set(MOTOR_PIN_1A);
       nrf_gpio_pin_clear(MOTOR_PIN_1B);
     }
}

int main(void)
{
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    init_motor_pwm();
   
  



   

    for (;;) // Neverending loop
   {
      nrfx_pwm_simple_playback(&MOTOR_PWM, &seq, 1, NRFX_PWM_FLAG_STOP);
        // Wait for an event.
        //__WFE();

        // Clear the event register.
        //__SEV();
        //__WFE();

     //   NRF_LOG_FLUSH();
   }
}