#include <stdio.h>
#include <string.h>
#include "nrf_drv_pwm.h"
#include "nrfx_pwm.h"
#include "app_util_platform.h"
#include "app_error.h"
#include "boards.h"
#include "bsp.h"
#include "app_timer.h"
#include "nrf_drv_clock.h"
#include "nrf_gpio.h"
#include "nrfx_gpiote.h"


#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

static nrfx_pwm_t MOTOR_PWM = NRFX_PWM_INSTANCE(0);

static void pwm_event_handler(nrfx_pwm_evt_type_t event_type)
{
}

void MOTOR_INIT(void)
{
    NRF_LOG_INFO("Motor Driver");



    nrfx_pwm_config_t const Motor_config =
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
    APP_ERROR_CHECK(nrfx_pwm_config_t(&MOTOR_PWM, &Motor_config, pwm_event_handler));

    Throttle_values.channel_0 = 0;
    Throttle_values.channel_1 = 0;
    Throttle_values.channel_2 = 0;
    Throttle_values.channel_3 = 0;

    nrf_gpio_cfg_pin_output(Motor_PIN_OA);
    nrf_gpio_cfg_pin_output(Motor_PIN_OB);
    nrf_gpio_cfg_pin_output(Motor_PIN_1A);
    nrf_gpio_cfg_pin_output(Motor_PIN_1B);
}
void MOTOR_RUN(void)
{
     if motor_values.motor0dir == FORWARD{
       nrf_gpio_pin_set(MOTOR_PIN_OA);
       nrf_gpio_pin_clear(MOTOR_PIN_OB);
     }
     else {
       nrf_gpio_pin_set(MOTOR_PIN_OA);
       nrf_gpio_pin_clear(MOTOR_PIN_OB);
     }
     if motor_values.motor1dir == FORWARD{
       nrf_gpio_pin_set(MOTOR_PIN_1A);
       nrf_gpio_pin_clear(MOTOR_PIN_1B);
     }
     else {
       nrf_gpio_pin_set(MOTOR_PIN_1A);
       nrf_gpio_pin_clear(MOTOR_PIN_1B);
     }
    static nrf_pwm_values_individual_t Throttle_values[] =
    {
        motor_values_t.motor0throttle,
        motor_values_t.motor1throttle,
        0,
        0

    };
    nrf_pwm_sequence_t const seq =
    {
        .values.p_individual = &Throttle_values,
        .length          = NRF_PWM_VALUES_LENGTH(Throttle_values),
        .repeats         = 0,
        .end_delay       = 0
    };
}


}

int main(void)
{
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    init_bsp();

    NRF_LOG_INFO("PWM example started.");

    motor_values motors
    {
    uint8_t motor0throttle = 20;
    uint8_t motor1throttle = 20;

    char motor0dir = FORWARD;
    char motor1dir = FORWARD;
    };


    demo1();

    for (;;)
    {
        // Wait for an event.
        __WFE();

        // Clear the event register.
        __SEV();
        __WFE();

        NRF_LOG_FLUSH();
    }
}


/** @} */
