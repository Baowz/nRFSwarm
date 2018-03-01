#include "vl53l0x_def.h"

#include "motor.h"
#include "app_mpu.h"

typedef struct{
////// General states //////
uint8_t mac_adress[6];
bool RSSI;
bool voltage;

bool interrupt_flag;

////// States for peripheral units /////
// Motor states
motor_t motor;

// States for MPU-9250
static float angle_measurement[3];
float accel[3];

// States for VL53L0X LIDAR-system
static VL53L0X_RangingMeasurementData_t lidarOne;
static VL53L0X_RangingMeasurementData_t lidarTwo;
static VL53L0X_RangingMeasurementData_t lidarThree;
static VL53L0X_RangingMeasurementData_t lidarFour;

// States for RGB LEDs

uint8_t led_one_red;
uint8_t led_one_green;
uint8_t led_one_blue;

uint8_t led_two_red;
uint8_t led_two_green;
uint8_t led_two_blue;

}state_machine_t
