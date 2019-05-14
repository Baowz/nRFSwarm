#include <stdbool.h>
#include <stdint.h>

#include "app_timer.h"
#include "nrfx_clock.h"
#include "nrfx_pwm.h"
#include "boards.h"
#include "d_swarm_board.h"
#include "app_error.h"

#include "m_status_led.h"
#include "config.h"


static nrf_pwm_values_individual_t duty_cycle;

nrfx_pwm_t m_pwm1 = NRFX_PWM_INSTANCE(1);

nrfx_pwm_config_t const status_led_config = {
    .output_pins = {
        STATUS_LED_R_PIN | NRFX_PWM_PIN_INVERTED, // channel 0
        STATUS_LED_G_PIN | NRFX_PWM_PIN_INVERTED, // channel 1
        STATUS_LED_B_PIN | NRFX_PWM_PIN_INVERTED, // channel 2
        NRFX_PWM_PIN_NOT_USED                     // channel 3

    },
    .irq_priority = APP_IRQ_PRIORITY_LOWEST,
    .base_clock = STATUS_LED_PWM_CLOCK_SPEED,
    .count_mode = NRF_PWM_MODE_UP,
    .top_value = STATUS_LED_PWM_TOP_VALUE,
    .load_mode = NRF_PWM_LOAD_INDIVIDUAL,
    .step_mode = NRF_PWM_STEP_AUTO};

nrf_pwm_values_individual_t seq_values = {
    0,
    0,
    0,
    0};

nrf_pwm_sequence_t const seq =
    {
        .values.p_individual = &seq_values,
        .length = NRF_PWM_VALUES_LENGTH(seq_values),
        .repeats = 0,
        .end_delay = 0};

void status_led_init(void)
{
    APP_ERROR_CHECK(nrfx_clock_init(NULL));
    nrfx_clock_lfclk_start();

    APP_ERROR_CHECK(nrfx_pwm_init(&m_pwm1, &status_led_config, NULL));

    nrfx_pwm_simple_playback(&m_pwm1, &seq, 1, NRFX_PWM_FLAG_LOOP);

#if DUAL_CHIP_ENABLE
#if SECONDARY_CHIP
    APP_ERROR_CHECK(nrfx_pwm_init(&m_pwm2, &optn_status_led_config, NULL));

    nrfx_pwm_simple_playback(&m_pwm2, &optn_seq, 1, NRFX_PWM_FLAG_LOOP);
#endif
#endif
}

void change_color(uint8_t _r, uint8_t _g, uint8_t _b)
{
    change_duty_cycle(_r, _g, _b, &seq_values);
}

void change_duty_cycle(uint8_t _duty_cycle_r,
                       uint8_t _duty_cycle_g,
                       uint8_t _duty_cycle_b,
                       nrf_pwm_values_individual_t *_seq_values)
{
    _seq_values->channel_0 = _duty_cycle_r;
    _seq_values->channel_1 = _duty_cycle_g;
    _seq_values->channel_2 = _duty_cycle_b;
}

void status_led_mode(uint8_t _led_mode)
{
    switch (_led_mode)
    {
    case 0:
        change_color(100, 0, 0);
        break;
    case 1:
        change_color(50, 50, 0);
        break;
    case 2:
        change_color(0, 100, 0);
        break;
    case 3:
        change_color(0, 50, 50);
        break;
    case 4:
        change_color(0, 0, 100);
        break;
    default:
        break;
    }
}

#if SECONDARY_CHIP

static nrf_pwm_values_individual_t optn_duty_cycle;

nrfx_pwm_t m_pwm2 = NRFX_PWM_INSTANCE(2);

nrfx_pwm_config_t const optn_status_led_config = {
    .output_pins = {
        OPTN_STATUS_LED_R_PIN | NRFX_PWM_PIN_INVERTED, // channel 0
        OPTN_STATUS_LED_G_PIN | NRFX_PWM_PIN_INVERTED, // channel 1
        OPTN_STATUS_LED_B_PIN | NRFX_PWM_PIN_INVERTED, // channel 2
        NRFX_PWM_PIN_NOT_USED                          // channel 3

    },
    .irq_priority = APP_IRQ_PRIORITY_LOWEST,
    .base_clock = STATUS_LED_PWM_CLOCK_SPEED,
    .count_mode = NRF_PWM_MODE_UP,
    .top_value = STATUS_LED_PWM_TOP_VALUE,
    .load_mode = NRF_PWM_LOAD_INDIVIDUAL,
    .step_mode = NRF_PWM_STEP_AUTO};

nrf_pwm_values_individual_t optn_seq_values = {
    0,
    0,
    0,
    0};

nrf_pwm_sequence_t const optn_seq =
    {
        .values.p_individual = &optn_seq_values,
        .length = NRF_PWM_VALUES_LENGTH(optn_seq_values),
        .repeats = 0,
        .end_delay = 0};

void optn_change_color(uint8_t _r, uint8_t _g, uint8_t _b)
{
    change_duty_cycle(_r, _g, _b, &optn_seq_values);
}

void optn_status_led_mode(uint8_t _led_mode)
{
    switch (_led_mode)
    {
    case 0:
        change_color(100, 0, 0);
        break;
    case 1:
        change_color(50, 50, 0);
        break;
    case 2:
        change_color(0, 100, 0);
        break;
    case 3:
        change_color(0, 50, 50);
        break;
    case 4:
        change_color(0, 0, 100);
        break;
    default:
        break;
    }
}

#endif