#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "nrf_drv_saadc.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "batt_meas.h"

static const nrf_drv_timer_t m_timer = NRF_DRV_TIMER_INSTANCE(4);
static nrf_saadc_value_t     m_buffer_pool[2][SAMPLES_IN_BUFFER];
static nrf_ppi_channel_t     m_ppi_channel;
static uint32_t              m_adc_evt_counter;

static batt_mon_cb_t saadc_cb;


static void timer_handler(nrf_timer_event_t event_type, void * p_context)
{

}


static void saadc_sampling_event_init(void)
{
    ret_code_t err_code;

    err_code = nrf_drv_ppi_init();
    APP_ERROR_CHECK(err_code);

    nrf_drv_timer_config_t timer_cfg = NRF_DRV_TIMER_DEFAULT_CONFIG;
    timer_cfg.bit_width = NRF_TIMER_BIT_WIDTH_32;
    err_code = nrf_drv_timer_init(&m_timer, &timer_cfg, timer_handler);
    APP_ERROR_CHECK(err_code);

    /* setup m_timer for compare event every COMPARE_EVT_MS ms */
    uint32_t ticks = nrf_drv_timer_ms_to_ticks(&m_timer, COMPARE_EVT_MS);
    nrf_drv_timer_extended_compare(&m_timer,
                                   NRF_TIMER_CC_CHANNEL0,
                                   ticks,
                                   NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK,
                                   false);
    nrf_drv_timer_enable(&m_timer);

    uint32_t timer_compare_event_addr = nrf_drv_timer_compare_event_address_get(&m_timer,
                                                                                NRF_TIMER_CC_CHANNEL0);
    uint32_t saadc_sample_task_addr   = nrf_drv_saadc_sample_task_get();

    /* setup ppi channel so that timer compare event is triggering sample task in SAADC */
    err_code = nrf_drv_ppi_channel_alloc(&m_ppi_channel);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_ppi_channel_assign(m_ppi_channel,
                                          timer_compare_event_addr,
                                          saadc_sample_task_addr);
    APP_ERROR_CHECK(err_code);
}


static void saadc_sampling_event_enable(void)
{
    ret_code_t err_code = nrf_drv_ppi_channel_enable(m_ppi_channel);

    APP_ERROR_CHECK(err_code);
}


static void saadc_callback(nrf_drv_saadc_evt_t const * p_event)
{
    if (p_event->type == NRF_DRV_SAADC_EVT_DONE)
    {
        uint32_t sum = 0;
        float average = 0;
        float meas_voltage;
        float batt_voltage;

        ret_code_t err_code;

        err_code = nrf_drv_saadc_buffer_convert(p_event->data.done.p_buffer, SAMPLES_IN_BUFFER);
        APP_ERROR_CHECK(err_code);

        int i;
        //NRF_LOG_INFO("ADC event number: %d", (int)m_adc_evt_counter);

        for (i = 0; i < SAMPLES_IN_BUFFER; i++)
        {
            sum += p_event->data.done.p_buffer[i];
            //NRF_LOG_INFO("%d", p_event->data.done.p_buffer[i]);
        }
        m_adc_evt_counter++;

        average = (float)((float)sum / (float)SAMPLES_IN_BUFFER); 				 // Average value from the buffer
        //NRF_LOG_INFO("Average: "NRF_LOG_FLOAT_MARKER"", NRF_LOG_FLOAT(average));

        meas_voltage = average / (((1.0f / 6.0f) / 0.6f) * ((float)(1 << 10)));  // average val from buf / (saadc gain / saadc internal voltage ref) * resolution in bits
        batt_voltage = meas_voltage * VOLTAGE_DIV_COEFF;
        //NRF_LOG_INFO("Average buf val: "NRF_LOG_FLOAT_MARKER" Battery voltage: "NRF_LOG_FLOAT_MARKER"", NRF_LOG_FLOAT(average), NRF_LOG_FLOAT(batt_voltage));

        saadc_cb(batt_voltage);
    }
}


static void saadc_init(batt_mon_cb_t callback)
{
    ret_code_t err_code;
    saadc_cb = callback;

    nrf_saadc_channel_config_t channel_config =
    NRF_DRV_SAADC_DEFAULT_CHANNEL_CONFIG_SE(NRF_SAADC_INPUT_AIN6);          // Input on analog pin 6 (P0.30)

    err_code = nrf_drv_saadc_init(NULL, saadc_callback);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_saadc_channel_init(0, &channel_config);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_saadc_buffer_convert(m_buffer_pool[0], SAMPLES_IN_BUFFER);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_saadc_buffer_convert(m_buffer_pool[1], SAMPLES_IN_BUFFER);
    APP_ERROR_CHECK(err_code);
}


void batt_mon_enable(batt_mon_cb_t callback)
{
    saadc_init(callback);
    saadc_sampling_event_init();
    saadc_sampling_event_enable();

    //nrf_gpio_cfg_output(BATT_MON_EN); // Configure pin BATT_MON_EN as output
    //nrf_gpio_pin_set(BATT_MON_EN); // Set pin BATT_MON_EN high, enabling battery monitoring

    NRF_LOG_RAW_INFO("[SUCCESS] Battery monitoring enabled. \n")
}
