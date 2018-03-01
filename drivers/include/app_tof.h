#include <stdbool.h>
#include <stdint.h>

#include "vl53l0x_api.h"
#include "pca10056.h"

#define WAKE_UP_TIME             300

#define VL53L0X_I2C_DEFAULT_ADDR 0x29

#define VL53L0X_I2C_ADDR_1       0x32
#define VL53L0X_I2C_ADDR_2       0x31
#define VL53L0X_I2C_ADDR_3       0x30
#define VL53L0X_I2C_ADDR_4       0x29

#define XSHUT_PIN_1     NRF_GPIO_PIN_MAP(1,8)
#define XSHUT_PIN_2     NRF_GPIO_PIN_MAP(1,10)
#define XSHUT_PIN_3     NRF_GPIO_PIN_MAP(1,0)
#define XSHUT_PIN_4     NRF_GPIO_PIN_MAP(0,11)

// Prototypes for externally used functions

void app_tof_init(void);
void app_tof_get_range(VL53L0X_RangingMeasurementData_t *RangingMeasurementData, uint8_t sensor);
void app_tof_get_range_all(VL53L0VL53L0X_RangingMeasurementData_t *sensor_one, VL53L0VL53L0X_RangingMeasurementData_t *sensor_two, VL53L0VL53L0X_RangingMeasurementData_t *sensor_three, VL53L0VL53L0X_RangingMeasurementData_t *sensor_four);
