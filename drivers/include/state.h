#include "vl53l0x_def.h"
#include "motor.h"

// Print state values, they are not mutually exclusive

#define PRINT_STATE_MAC_ADDRESS           0
#define PRINT_STATE_ANGLE_VALUES          1
#define PRINT_STATE_ACCELEROMETER_VALUES  0
#define PRINT_STATE_RANGE_MEASUREMENT     1
#define PRINT_STATE_RSSI_VALUE            1
#define PRINT_STATE_LED_VALUE             0
#define PRINT_STATE_VOLTAGE_VALUE         1


// Struct for states used in this project, bar from MQTT-states
typedef struct{
////// General states //////
char mac_address[6];
int8_t RSSI;
float voltage;

bool interrupt_flag;

////// States for peripheral units /////
// Motor states
motor_t motor;

// States for MPU-9250
float angle_measurement[3];
float accel[3];

// States for VL53L0X LIDAR-system
VL53L0X_RangingMeasurementData_t lidarOne;
VL53L0X_RangingMeasurementData_t lidarTwo;
VL53L0X_RangingMeasurementData_t lidarThree;
VL53L0X_RangingMeasurementData_t lidarFour;

// States for RGB LEDs

uint16_t led_one_red;
uint16_t led_one_green;
uint16_t led_one_blue;

uint16_t led_two_red;
uint16_t led_two_green;
uint16_t led_two_blue;

}state_machine_t;
