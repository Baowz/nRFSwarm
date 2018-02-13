#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "nrf_drv_pwm.h"
#include "nrf_gpio.h"
#include "nrf_log.h"

#include "motor.h"

static nrf_drv_pwm_t motor_pwm = NRF_DRV_PWM_INSTANCE(0);
static nrf_pwm_values_individual_t pwm_values;

static void pwm_event_handler(nrf_drv_pwm_evt_type_t event_type)
{

}

void motor_pwm_init(void)
{
  ret_code_t err_code;
  nrf_drv_pwm_config_t const pwm_config =
  {
    .output_pins =
      {
        MOTOR_A_PWM_OUTPUT_PIN, // Motor A PWM output
        MOTOR_B_PWM_OUTPUT_PIN, // Motor B PWM output
        NRF_DRV_PWM_PIN_NOT_USED,
        NRF_DRV_PWM_PIN_NOT_USED,
      },
      .base_clock  = NRF_PWM_CLK_16MHz,
      .count_mode  = NRF_PWM_MODE_UP,
      .top_value   = PWM_TOP_VALUE,
      .load_mode   = NRF_PWM_LOAD_INDIVIDUAL,
      .step_mode   = NRF_PWM_STEP_AUTO
  };

  nrf_gpio_cfg_output(MOTOR_AIN1);
  nrf_gpio_cfg_output(MOTOR_AIN2);
  nrf_gpio_cfg_output(MOTOR_BIN1);
  nrf_gpio_cfg_output(MOTOR_BIN2);

  err_code = nrf_drv_pwm_init(&motor_pwm, &pwm_config, pwm_event_handler);
  APP_ERROR_CHECK(err_code);

  pwm_values.channel_0 = 0; // Initial values for the PWM channels
  pwm_values.channel_1 = 0;
  pwm_values.channel_2 = 0;
  pwm_values.channel_3 = 0;

	NRF_LOG_RAW_INFO("[SUCCESS] Motor PWM initiated. \n");
}

void motor_start_pwm_sequence(void)
{
  nrf_pwm_sequence_t const seq =
  {
    .values.p_individual = &pwm_values,
    .length          		 = NRF_PWM_VALUES_LENGTH(pwm_values),
    .repeats         		 = 0,
    .end_delay       		 = 0,
  };

	#if PRINT_PWM
		NRF_LOG_RAW_INFO("PWM values updated. PWMA: %d - PWMB: %d \n", pwm_values.channel_0, pwm_values.channel_1);
  #endif
	nrf_drv_pwm_simple_playback(&motor_pwm, &seq, 1, NRF_DRV_PWM_FLAG_LOOP);
}

void motor_logic(motor_t *motor)
{
  if(motor->direction_motor_a)
  {
    nrf_gpio_pin_clear(MOTOR_AIN1);
    nrf_gpio_pin_set(MOTOR_AIN2);
  }
  else
  {
    nrf_gpio_pin_set(MOTOR_AIN1);
    nrf_gpio_pin_clear(MOTOR_AIN2);
  }

  if(motor->direction_motor_b)
  {
    nrf_gpio_pin_set(MOTOR_BIN1);
    nrf_gpio_pin_clear(MOTOR_BIN2);
  }
  else
  {
    nrf_gpio_pin_clear(MOTOR_BIN1);
    nrf_gpio_pin_set(MOTOR_BIN2);
  }
}

void update_motor_values(motor_t *motor)
{
  // Update motor directions

  motor_logic(motor);

  // Update outputted pwm values

  pwm_values.channel_0 = PWM_TOP_VALUE - (uint16_t)motor->output_motor_a;
  pwm_values.channel_1 = PWM_TOP_VALUE - (uint16_t)motor->output_motor_b;

  motor_start_pwm_sequence();
}
