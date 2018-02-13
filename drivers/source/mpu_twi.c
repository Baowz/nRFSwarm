#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "nrf_drv_twi.h"
#include "app_error.h"
#include "app_util_platform.h"
#include "nrf_log.h"

#include "mpu_twi.h"

const nrf_drv_twi_t twi = NRF_DRV_TWI_INSTANCE(0);

void twi_init()
{
    ret_code_t err_code;

    const nrf_drv_twi_config_t twi_config = {
       .scl                = MPU_SCL_PIN,
       .sda                = MPU_SDA_PIN,
       .frequency          = NRF_TWI_FREQ_100K,
       .interrupt_priority = APP_IRQ_PRIORITY_LOW,
       .clear_bus_init     = false
    };

    err_code = nrf_drv_twi_init(&twi, &twi_config, NULL, NULL);
    APP_ERROR_CHECK(err_code);

    nrf_drv_twi_enable(&twi);

	  NRF_LOG_RAW_INFO("[SUCCESS] MPU TWI enabled. \n");
}

uint8_t twi_write(uint8_t slave_addr, uint8_t reg_addr, uint8_t length, uint8_t* data)
{
  static uint8_t merge_array[32] = {0};

	uint32_t err_code;
	uint8_t i;

	merge_array[0] = reg_addr;

	for(i = 0; i < length; i++)
	{
		merge_array[i+1] = data[i];
	}

	err_code = nrf_drv_twi_tx(&twi, slave_addr, merge_array, length+1, false);
  APP_ERROR_CHECK(err_code);

  return 0;
}

uint8_t twi_read(uint8_t slave_addr, uint8_t reg_addr, uint8_t length, uint8_t* data)
{
	uint32_t err_code;
    err_code = nrf_drv_twi_tx(&twi, slave_addr, &reg_addr, 1, false);
    APP_ERROR_CHECK(err_code);

    err_code = nrf_drv_twi_rx(&twi, slave_addr, data, length);
    APP_ERROR_CHECK(err_code);

  return 0;
}
