#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "motor.h"

#define PI 3.1415926535897f

// Physical constants

#define MOTOR_OFFSET_LEFT 1.0f
#define MOTOR_OFFSET_RIGHT 1.0f

// PFC VALUES

#define K_SIGNAL_STRENGTH     100.0f
#define K_HEADING             0.0f
#define K_OBSTACLE            10000.0f

// PID VALUES

#define KP_SIGNAL_FIELD 120.0f
#define KD_SIGNAL_FIELD 0.0f
#define KI_SIGNAL_FIELD 15.0f

#define KP_HEADING_FIELD 1.0f
#define KD_HEADING_FIELD 0.0f
#define KI_HEADING_FIELD 0.0f

#define KP_OBSTACLE_FIELD_ONE 135.0f
#define KD_OBSTACLE_FIELD_ONE 27.0f
#define KI_OBSTACLE_FIELD_ONE 0.0f

#define KP_OBSTACLE_FIELD_TWO 40.0f
#define KD_OBSTACLE_FIELD_TWO 10.0f
#define KI_OBSTACLE_FIELD_TWO 0.0f

#define KP_OBSTACLE_FIELD_THREE 150.0f
#define KD_OBSTACLE_FIELD_THREE 30.0f
#define KI_OBSTACLE_FIELD_THREE 0.0f

#define KP_OBSTACLE_FIELD_FOUR 40.0f
#define KD_OBSTACLE_FIELD_FOUR 10.0f
#define KI_OBSTACLE_FIELD_FOUR 0.0f


#define PID_LOWER_INTEGRATION_LIMIT -500.0f
#define PID_UPPER_INTEGRATION_LIMIT 500.0f

// Upper and lower bound values for PFC

#define MINIMUM_SIGNAL_STRENGTH   -55.0f // abs(dBM)
#define MAXIMUM_SIGNAL_STRENGTH   -50.0f // abs(dBM)
#define OBSTACLE_CUTOFF_DISTANCE  500.0f

// Prototypes for functions used in source files:

void potential_field_controller_init(void);
void update_pfc_controller(motor_t *motor, int8_t RSSI, float heading, float heading_ref, float *measurement, float *speed, float dt, int16_t *analytical_data);
