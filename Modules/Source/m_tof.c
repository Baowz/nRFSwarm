#include <stdbool.h>
#include <stdint.h>

#include "nrf_delay.h"
#include "d_swarm_board.h"

#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
#include "vl53l0x_i2c_platform.h"


#include "m_tof.h"

static VL53L0X_Dev_t tof_sensor_1;
static VL53L0X_Dev_t tof_sensor_2;
static VL53L0X_Dev_t tof_sensor_3;
static VL53L0X_Dev_t tof_sensor_4;
static VL53L0X_Dev_t tof_sensor_5;
static VL53L0X_Dev_t tof_sensor_6;
static VL53L0X_Dev_t tof_sensor_7;
static VL53L0X_Dev_t tof_sensor_8;

static VL53L0X_DeviceInfo_t tof_info_1;
static VL53L0X_DeviceInfo_t tof_info_2;
static VL53L0X_DeviceInfo_t tof_info_3;
static VL53L0X_DeviceInfo_t tof_info_4;
static VL53L0X_DeviceInfo_t tof_info_5;
static VL53L0X_DeviceInfo_t tof_info_6;
static VL53L0X_DeviceInfo_t tof_info_7;
static VL53L0X_DeviceInfo_t tof_info_8;

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
/*
void app_tof_get_range_all(VL53L0X_RangingMeasurementData_t *sensor_one, VL53L0X_RangingMeasurementData_t *sensor_two, VL53L0X_RangingMeasurementData_t *sensor_three, VL53L0X_RangingMeasurementData_t *sensor_four, float *range_array)
{
  app_tof_get_range(sensor_one, 1);
  app_tof_get_range(sensor_two, 2);
  app_tof_get_range(sensor_three, 3);
  app_tof_get_range(sensor_four, 4);

  range_array[0] = (float)sensor_one->RangeMilliMeter;
  range_array[1] = (float)sensor_two->RangeMilliMeter;
  range_array[2] = (float)sensor_three->RangeMilliMeter;
  range_array[3] = (float)sensor_four->RangeMilliMeter;

  // Compute indicator value for nearest obstacle, to be indicated on LED 2.
  float red_obstacle_value_percentage   = (float)(((min(min(min(sensor_one->RangeMilliMeter, sensor_two->RangeMilliMeter), sensor_three->RangeMilliMeter), sensor_four->RangeMilliMeter))-20.0f)/(RED_INDICATION_RANGE)); // 100% if no obstacle within range
  float green_obstacle_value_percentage = (float)(((min(min(min(sensor_one->RangeMilliMeter, sensor_two->RangeMilliMeter), sensor_three->RangeMilliMeter), sensor_four->RangeMilliMeter))-20.0f)/(GREEN_INDICATION_RANGE)); // 100% if no obstacle within range

  uint16_t red_obstacle_value    = (uint16_t)(1000.0f * (1.0f - check_lower_upper_range(red_obstacle_value_percentage, 0.0f, 1.0f)));
  uint16_t green_obstacle_value  = (uint16_t)(1000.0f * (1.0f - check_lower_upper_range(green_obstacle_value_percentage, 0.0f, 1.0f)));

  //TODO: Move this somewhere else to ensure modularity
  rgb_update_led_color(2, red_obstacle_value, green_obstacle_value - red_obstacle_value, 0);
}*/

void tof_setAddress(VL53L0X_Dev_t *device, uint8_t newAddr)
{
    newAddr &= 0x7F;

    VL53L0X_SetDeviceAddress(device, newAddr * 2); // 7->8 bit

    device->I2cDevAddr = newAddr;
}

void init_sensor(VL53L0X_Dev_t *device, VL53L0X_DeviceInfo_t *info, uint8_t i2cAddr)
{
    uint32_t refSpadCount;
    uint8_t isApertureSpads;
    uint8_t VhvSettings;
    uint8_t PhaseCal;

    VL53L0X_DataInit(device);

    if (i2cAddr != 0x29)
    {
        tof_setAddress(device, i2cAddr);
    }
    VL53L0X_GetDeviceInfo(device, info);

    VL53L0X_StaticInit(device);

    VL53L0X_PerformRefSpadManagement(device, &refSpadCount, &isApertureSpads); // TODO: Add status check to each of these funcitons

    VL53L0X_PerformRefCalibration(device, &VhvSettings, &PhaseCal);

    VL53L0X_SetDeviceMode(device, VL53L0X_DEVICEMODE_SINGLE_RANGING);

    VL53L0X_SetLimitCheckEnable(device, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);

    VL53L0X_SetLimitCheckEnable(device, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);

    VL53L0X_SetLimitCheckEnable(device, VL53L0X_CHECKENABLE_RANGE_IGNORE_THRESHOLD, 1);

    VL53L0X_SetLimitCheckValue(device, VL53L0X_CHECKENABLE_RANGE_IGNORE_THRESHOLD, (FixPoint1616_t)(1.5 * 0.023 * 65536));
}

void tof_init(void)
{
    VL53L0X_Dev_t sensor[] = {tof_sensor_1,
                              tof_sensor_2,
                              tof_sensor_3,
                              tof_sensor_4,
                              tof_sensor_5,
                              tof_sensor_6,
                              tof_sensor_7,
                              tof_sensor_8};

    uint8_t sensor_xshut[] = {XSHUT_PIN_1,
                              XSHUT_PIN_2,
                              XSHUT_PIN_3,
                              XSHUT_PIN_4,
                              XSHUT_PIN_5,
                              XSHUT_PIN_6,
                              XSHUT_PIN_7,
                              XSHUT_PIN_8};

    uint8_t sensor_addr[] = {VL53L0X_TWI_ADDRESS_1,
                             VL53L0X_TWI_ADDRESS_2,
                             VL53L0X_TWI_ADDRESS_3,
                             VL53L0X_TWI_ADDRESS_4,
                             VL53L0X_TWI_ADDRESS_5,
                             VL53L0X_TWI_ADDRESS_6,
                             VL53L0X_TWI_ADDRESS_7,
                             VL53L0X_TWI_ADDRESS_8};

    VL53L0X_DeviceInfo_t sensor_info[] = {tof_info_1,
                                          tof_info_2,
                                          tof_info_3,
                                          tof_info_4,
                                          tof_info_5,
                                          tof_info_6,
                                          tof_info_7,
                                          tof_info_8};

    for (uint8_t i = 0; i < TOF_NUMBER_OF_SENSORS; i++)
    {
        sensor[i].I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
        sensor[i].comms_type = 1;
        sensor[i].comms_speed_khz = 400;
    }

    for (uint8_t i = 0; i < TOF_NUMBER_OF_SENSORS; i++)
    {
        nrf_gpio_cfg_output(sensor_xshut[i]);
        nrf_gpio_pin_clear(sensor_xshut[i]);
    }

    VL53L0X_i2c_init();

    for (uint8_t i = 0; i < TOF_NUMBER_OF_SENSORS; i++)
    {
        nrf_gpio_pin_set(sensor_xshut[i]); // Wake up sensor
        nrf_delay_ms(WAKE_UP_TIME);
        init_sensor(&sensor[i], &sensor_info[i], sensor_addr[i]);
    }

    /*
    //BACKUP
    tof_sensor_1.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
    tof_sensor_2.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
    tof_sensor_3.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
    tof_sensor_4.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
    tof_sensor_5.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
    tof_sensor_6.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
    tof_sensor_7.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;
    tof_sensor_8.I2cDevAddr = VL53L0X_TWI_ADDRESS_DEFAULT;

    tof_sensor_1.comms_type = 1;
    tof_sensor_2.comms_type = 1;
    tof_sensor_3.comms_type = 1;
    tof_sensor_4.comms_type = 1;
    tof_sensor_5.comms_type = 1;
    tof_sensor_6.comms_type = 1;
    tof_sensor_7.comms_type = 1;
    tof_sensor_8.comms_type = 1;

    tof_sensor_1.comms_speed_khz = 400;
    tof_sensor_2.comms_speed_khz = 400;
    tof_sensor_3.comms_speed_khz = 400;
    tof_sensor_4.comms_speed_khz = 400;
    tof_sensor_5.comms_speed_khz = 400;
    tof_sensor_6.comms_speed_khz = 400;
    tof_sensor_7.comms_speed_khz = 400;
    tof_sensor_8.comms_speed_khz = 400;

    nrf_gpio_cfg_output(XSHUT_PIN_1);
    nrf_gpio_cfg_output(XSHUT_PIN_2);
    nrf_gpio_cfg_output(XSHUT_PIN_3);
    nrf_gpio_cfg_output(XSHUT_PIN_4);
    nrf_gpio_cfg_output(XSHUT_PIN_5);
    nrf_gpio_cfg_output(XSHUT_PIN_6);
    nrf_gpio_cfg_output(XSHUT_PIN_7);
    nrf_gpio_cfg_output(XSHUT_PIN_8);

    // Put all sensors into shutdown
    nrf_gpio_pin_clear(XSHUT_PIN_1);
    nrf_gpio_pin_clear(XSHUT_PIN_2);
    nrf_gpio_pin_clear(XSHUT_PIN_3);
    nrf_gpio_pin_clear(XSHUT_PIN_4);
    nrf_gpio_pin_clear(XSHUT_PIN_5);
    nrf_gpio_pin_clear(XSHUT_PIN_6);
    nrf_gpio_pin_clear(XSHUT_PIN_7);
    nrf_gpio_pin_clear(XSHUT_PIN_8);

    VL53L0X_i2c_init();

    // Init sensor 1
    nrf_gpio_pin_set(XSHUT_PIN_1); // Wake up sensor 1
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_1, &tof_info_1, VL53L0X_TWI_ADDRESS_1);

    // Init sensor 2
    nrf_gpio_pin_set(XSHUT_PIN_2); // Wake up sensor 2
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_2, &tof_info_2, VL53L0X_TWI_ADDRESS_2);

    // Init sensor 3
    nrf_gpio_pin_set(XSHUT_PIN_3); // Wake up sensor 3
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_3, &tof_info_3, VL53L0X_TWI_ADDRESS_3);

    // Init sensor 4
    nrf_gpio_pin_set(XSHUT_PIN_4); // Wake up sensor 4
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_4, &tof_info_4, VL53L0X_TWI_ADDRESS_4);

    // Init sensor 5
    nrf_gpio_pin_set(XSHUT_PIN_5); // Wake up sensor 5
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_5, &tof_info_5, VL53L0X_TWI_ADDRESS_5);

    // Init sensor 6
    nrf_gpio_pin_set(XSHUT_PIN_6); // Wake up sensor 6
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_6, &tof_info_6, VL53L0X_TWI_ADDRESS_6);

    // Init sensor 7
    nrf_gpio_pin_set(XSHUT_PIN_7); // Wake up sensor 7
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_7, &tof_info_7, VL53L0X_TWI_ADDRESS_7);

    // Init sensor 8
    nrf_gpio_pin_set(XSHUT_PIN_8); // Wake up sensor 8
    nrf_delay_ms(WAKE_UP_TIME);
    init_sensor(&tof_sensor_8, &tof_info_8, VL53L0X_TWI_ADDRESS_8);*/
}