#include <stdbool.h>
#include <stdint.h>

#include "d_swarm_board.h"
#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
#include "nrf_delay.h"

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

void tof_get_range(VL53L0X_RangingMeasurementData_t *RangingMeasurementData, VL53L0X_Dev_t *sensor)
{
    VL53L0X_PerformSingleRangingMeasurement(&sensor, RangingMeasurementData);
}

void tof_get_range_all()
{
}

void tof_setAddress(VL53L0X_Dev_t *device, uint8_t newAddr)
{
    newAddr &= 0x7F;

    VL53L0X_SetDeviceAddress(device, newAddr * 2); // 7-8bit

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

void tof_init()
{
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
    nrf_gpio_pin_clear(XSHUT_PIN_1);
    nrf_gpio_pin_clear(XSHUT_PIN_2);
    nrf_gpio_pin_clear(XSHUT_PIN_3);
    nrf_gpio_pin_clear(XSHUT_PIN_4);

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
    init_sensor(&tof_sensor_8, &tof_info_8, VL53L0X_TWI_ADDRESS_8);
}