#include <stdbool.h>
#include <stdint.h>

#include "nrf_gpio.h"
#include "vl53l0x_api.h"
#include "app_tof.h"
#include "nrf_log.h"

static VL53L0X_Dev_t  tof_sensor_1;
static VL53L0X_Dev_t  tof_sensor_2;
static VL53L0X_Dev_t  tof_sensor_3;
static VL53L0X_Dev_t  tof_sensor_4;

static VL53L0X_DeviceInfo_t tof_info_1;
static VL53L0X_DeviceInfo_t tof_info_2;
static VL53L0X_DeviceInfo_t tof_info_3;
static VL53L0X_DeviceInfo_t tof_info_4;

void app_tof_get_range(VL53L0X_RangingMeasurementData_t *RangingMeasurementData, uint8_t sensor)
{
  switch(sensor) {
    case 1:
      VL53L0X_PerformSingleRangingMeasurement(&tof_sensor_1, RangingMeasurementData);
    break;
    case 2:
      VL53L0X_PerformSingleRangingMeasurement(&tof_sensor_2, RangingMeasurementData);
    break;
    case 3:
      VL53L0X_PerformSingleRangingMeasurement(&tof_sensor_3, RangingMeasurementData);
    break;
    case 4:
      VL53L0X_PerformSingleRangingMeasurement(&tof_sensor_4, RangingMeasurementData);
    break;
  }
}

void app_tof_setAddress(VL53L0X_Dev_t * device, uint8_t newAddr)
{
  newAddr &= 0x7F;

  VL53L0X_SetDeviceAddress(device, newAddr * 2); // 7-8bit TODO: Check this.

  device->I2cDevAddr = newAddr;
}

void init_sensor(VL53L0X_Dev_t* device, VL53L0X_DeviceInfo_t* info, uint8_t i2cAddr)
{
  uint32_t  refSpadCount;
  uint8_t   isApertureSpads;
  uint8_t   VhvSettings;
  uint8_t   PhaseCal;

  VL53L0X_DataInit(device);

  if(i2cAddr != 0x29)
    VL53L0X_SetDeviceAddress(device, i2cAddr);

  VL53L0X_GetDeviceInfo(device, info);

  VL53L0X_StaticInit(device);

  VL53L0X_PerformRefSpadManagement(device, &refSpadCount, &isApertureSpads); // TODO: Add status check to each of these funcitons

  VL53L0X_PerformRefCalibration(device, &VhvSettings, &PhaseCal);

  VL53L0X_SetDeviceMode(device, VL53L0X_DEVICEMODE_SINGLE_RANGING);

  VL53L0X_SetLimitCheckEnable(device, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);

  VL53L0X_SetLimitCheckEnable(device, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);

  VL53L0X_SetLimitCheckEnable(device, VL53L0X_CHECKENABLE_RANGE_IGNORE_THRESHOLD, 1);

  VL53L0X_SetLimitCheckValue(device, VL53L0X_CHECKENABLE_RANGE_IGNORE_THRESHOLD, (FixPoint1616_t)( 1.5 * 0.023 * 65536));
}


void app_tof_init(void)
{
  // Initialize Comms

  tof_sensor_1.I2cDevAddr = VL53L0X_I2C_ADDR_1;
  tof_sensor_2.I2cDevAddr = VL53L0X_I2C_ADDR_1;
  tof_sensor_3.I2cDevAddr = VL53L0X_I2C_ADDR_1;
  tof_sensor_4.I2cDevAddr = VL53L0X_I2C_ADDR_1;

  tof_sensor_1.comms_type = 1;
  tof_sensor_2.comms_type = 1;
  tof_sensor_3.comms_type = 1;
  tof_sensor_4.comms_type = 1;

  tof_sensor_1.comms_speed_khz = 400;
  tof_sensor_2.comms_speed_khz = 400;
  tof_sensor_3.comms_speed_khz = 400;
  tof_sensor_4.comms_speed_khz = 400;


  VL53L0X_i2c_init();

  // Pin configuration

  nrf_gpio_cfg_output(XSHUT_PIN_1);
  nrf_gpio_cfg_output(XSHUT_PIN_2);
  nrf_gpio_cfg_output(XSHUT_PIN_3);
  nrf_gpio_cfg_output(XSHUT_PIN_4);

  nrf_gpio_pin_clear(XSHUT_PIN_1); // Put all sensors into shutdown
  nrf_gpio_pin_clear(XSHUT_PIN_2);
  nrf_gpio_pin_clear(XSHUT_PIN_3);
  nrf_gpio_pin_clear(XSHUT_PIN_4);


  // Init sensor 1

  nrf_gpio_pin_set(XSHUT_PIN_1); // Wake up sensor 1
  init_sensor(&tof_sensor_1, &tof_info_1, VL53L0X_I2C_ADDR_1);

  // Init sensor 2

  nrf_gpio_pin_set(XSHUT_PIN_2); // Wake up sensor 2
  init_sensor(&tof_sensor_2, &tof_info_2, VL53L0X_I2C_ADDR_2);

  // Init sensor 3

  nrf_gpio_pin_set(XSHUT_PIN_3); // Wake up sensor 3
  init_sensor(&tof_sensor_3, &tof_info_3, VL53L0X_I2C_ADDR_3);

  // Init sensor 4

  nrf_gpio_pin_set(XSHUT_PIN_4); // Wake up sensor 4
  init_sensor(&tof_sensor_4, &tof_info_4, VL53L0X_I2C_ADDR_4);

  NRF_LOG_RAW_INFO("[SUCCESS] Light Detection and Ranging system operative. (LIDAR)")
}
