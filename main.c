// nRF Swarm rev 0.1 by Henrik Malvik Halvorsen - Master's project

#include <stdbool.h>
#include <stdint.h>

#include "nrf.h"
#include "nordic_common.h"
#include "boards.h"
#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_delay.h"

#include "motor.h"
#include "twi.h"
#include "app_mpu.h"
#include "real_time_clock.h"
#include "swarm_pcb.h"
#include "spi.h"
#include "batt_meas.h"

#define PRINT_MEASURED_VOLTAGE 1

#define ALGORITHM_INTERVAL_MS   1000
#define BOOT_DELAY_MS           100

/**
 * @brief Function for application main entry.
 */

 static const nrf_drv_timer_t application_timer = NRF_DRV_TIMER_INSTANCE(1); // Main timer
 static nrf_drv_timer_t rtc_timer = NRF_DRV_TIMER_INSTANCE(2); // Timer used for real time sensitive data

// Init function for logging of data

void log_init(void)
{
    ret_code_t err_code = NRF_LOG_INIT(NULL);
    APP_ERROR_CHECK(err_code);

    NRF_LOG_DEFAULT_BACKENDS_INIT();
}

// Event handler for the main timer

void timer_event_handler(nrf_timer_event_t event_type, void* p_context)
{
  static float angle_measurement[3] = {0};
  static float accel[3] = {0};
  static motor_t motor;

  app_mpu_get_angles(angle_measurement, accel);
  update_motor_values(&motor);
}

//Init function for initiation of the main timer.

void timer_init()
{
    uint32_t err_code;
    uint32_t time_ticks;

    static nrf_drv_timer_config_t timer_cfg =
    {
        .frequency = NRF_TIMER_FREQ_16MHz,
        .mode      = NRF_TIMER_MODE_TIMER,
        .bit_width = NRF_TIMER_BIT_WIDTH_32,
        .interrupt_priority = 3
    };
    err_code = nrf_drv_timer_init(&application_timer, &timer_cfg, timer_event_handler);
    APP_ERROR_CHECK(err_code);

    time_ticks = nrf_drv_timer_ms_to_ticks(&application_timer, ALGORITHM_INTERVAL_MS);

    nrf_drv_timer_extended_compare(&application_timer, NRF_TIMER_CC_CHANNEL0, time_ticks, NRF_TIMER_SHORT_COMPARE0_CLEAR_MASK, true);

    nrf_drv_timer_enable(&application_timer);

    NRF_LOG_RAW_INFO("[SUCCESS] Main timer enabled. \n");
}

// Callback function in order to read battery voltage

void batt_callback(float voltage)
{
    /*if(voltage < VOLTAGE_LEVEL_CUTOFF)
    {
		uint32_t err_code;

		low_voltage = true;				// low_voltage flag has no function at this moment, uncomment this comment if that changes.
		err_code = sd_power_system_off();
		APP_ERROR_CHECK(err_code);      //put nRF52 in sleep mode / power off
  }*/
	#if PRINT_MEASURED_VOLTAGE
          NRF_LOG_RAW_INFO("Measured voltage: "NRF_LOG_FLOAT_MARKER" V\r\n", NRF_LOG_FLOAT(voltage));
	#endif
}

////////////////////////////////////////////////////////////////////
/////////////////////////// Main ///////////////////////////////////
////////////////////////////////////////////////////////////////////

int main(void)
{
  log_init();

  NRF_LOG_RAW_INFO("\n \n nRF Swarm revision 0.1 online. \n \n");
  NRF_LOG_RAW_INFO("Initializing all systems in %d ms. \n", BOOT_DELAY_MS);

  nrf_delay_ms(BOOT_DELAY_MS); // Delay must be here since the MPU-9250 needs a small time interval in order to be ready for TWI-communication.

  // Initialization

  pcb_peripherals_init(); // Initializes RGB LEDs and GPIO

  rtc_init(&rtc_timer); // Real time clock used for configuration and timing of the MPU 9250 and additional real time sensitive data
  spi_init(); // Initialize serial peripheral interface for shield and sensory communication.
  twi_init(); // Initialize two wire interface used to communicate with the MPU 9250.
  app_mpu_init(); // Initialize MPU 9250, flashing DMP firmware to the unit.

  batt_mon_enable(batt_callback); // Battery voltage monitoring.
  motor_pwm_init(); // PWM used to control the motors of the vessel.
  timer_init(); // Main timer used to run the swarm algorithm

  NRF_LOG_RAW_INFO("All systems online. \n");

  rgb_update_led_color(1,0,0,255);

    while (true)
    {
      NRF_LOG_PROCESS();
    }
}
/** @} */
