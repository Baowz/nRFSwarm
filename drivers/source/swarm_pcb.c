#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "app_error.h"
#include "app_util_platform.h"
#include "nrf_log.h"
#include "nrf_drv_pwm.h"

#include "swarm_pcb.h"
#include "nrf_gpio.h"

static nrf_drv_pwm_t rgb_one_pwm = NRF_DRV_PWM_INSTANCE(1);
static nrf_drv_pwm_t rgb_two_pwm = NRF_DRV_PWM_INSTANCE(2);
static nrf_pwm_values_individual_t led_one_pwm_values;
static nrf_pwm_values_individual_t led_two_pwm_values;

static void pwm_event_handler(nrf_drv_pwm_evt_type_t event_type)
{

}

void rgb_update_led_color(uint8_t led, uint16_t red, uint16_t green, uint16_t blue)
{
  if (led == 1)
  {
    led_one_pwm_values.channel_0 = red;
    led_one_pwm_values.channel_1 = green;
    led_one_pwm_values.channel_2 = blue;

    nrf_pwm_sequence_t const led_one_seq =
    {
      .values.p_individual = &led_one_pwm_values,
      .length          		 = NRF_PWM_VALUES_LENGTH(led_one_pwm_values),
      .repeats         		 = 0,
      .end_delay       		 = 0,
    };

    nrf_drv_pwm_simple_playback(&rgb_one_pwm, &led_one_seq, 1, NRF_DRV_PWM_FLAG_LOOP);
  }
  else if (led == 2)
  {
    led_two_pwm_values.channel_0 = red;
    led_two_pwm_values.channel_1 = green;
    led_two_pwm_values.channel_2 = blue;

    nrf_pwm_sequence_t const led_two_seq =
    {
      .values.p_individual = &led_two_pwm_values,
      .length          		 = NRF_PWM_VALUES_LENGTH(led_two_pwm_values),
      .repeats         		 = 0,
      .end_delay       		 = 0,
    };

    nrf_drv_pwm_simple_playback(&rgb_two_pwm, &led_two_seq, 1, NRF_DRV_PWM_FLAG_LOOP);
  }
}

void rgb_led_init(void)
{
  ret_code_t err_code;
  nrf_drv_pwm_config_t const pwm_one_config =
  {
    .output_pins =
      {
        LED_ONE_R_PIN,
        LED_ONE_G_PIN,
        LED_ONE_B_PIN,
        NRF_DRV_PWM_PIN_NOT_USED,
      },
      .base_clock  = NRF_PWM_CLK_16MHz,
      .count_mode  = NRF_PWM_MODE_UP,
      .top_value   = PWM_TOP_VALUE,
      .load_mode   = NRF_PWM_LOAD_INDIVIDUAL,
      .step_mode   = NRF_PWM_STEP_AUTO
  };

  nrf_drv_pwm_config_t const pwm_two_config =
  {
    .output_pins =
      {
        LED_TWO_R_PIN,
        LED_TWO_G_PIN,
        LED_TWO_B_PIN,
        NRF_DRV_PWM_PIN_NOT_USED,
      },
      .base_clock  = NRF_PWM_CLK_16MHz,
      .count_mode  = NRF_PWM_MODE_UP,
      .top_value   = PWM_TOP_VALUE,
      .load_mode   = NRF_PWM_LOAD_INDIVIDUAL,
      .step_mode   = NRF_PWM_STEP_AUTO
  };

  err_code = nrf_drv_pwm_init(&rgb_one_pwm, &pwm_one_config, pwm_event_handler);
  APP_ERROR_CHECK(err_code);

  err_code = nrf_drv_pwm_init(&rgb_two_pwm, &pwm_two_config, pwm_event_handler);
  APP_ERROR_CHECK(err_code);

  rgb_update_led_color(1, RGB_ONE_DEFAULT_RED, RGB_ONE_DEFAULT_GREEN, RGB_ONE_DEFAULT_BLUE);
  rgb_update_led_color(2, RGB_TWO_DEFAULT_RED, RGB_TWO_DEFAULT_GREEN, RGB_TWO_DEFAULT_BLUE);
}

void pcb_peripherals_init(void)
{
  rgb_led_init();

  nrf_gpio_cfg_output(GPIO_PIN_ONE);
  nrf_gpio_cfg_output(GPIO_PIN_TWO);
  nrf_gpio_cfg_output(GPIO_PIN_THREE);
  nrf_gpio_cfg_output(GPIO_PIN_FOUR);

  nrf_gpio_pin_clear(GPIO_PIN_ONE);
  nrf_gpio_pin_clear(GPIO_PIN_TWO);
  nrf_gpio_pin_clear(GPIO_PIN_THREE);
  nrf_gpio_pin_clear(GPIO_PIN_FOUR);


  NRF_LOG_RAW_INFO("[SUCCESS] RGB LED PWM initiated, GPIO ready. \n")

}
