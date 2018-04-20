#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "motor.h"

#define PI 3.1415926535897f

// PFC VALUES

#define K_SIGNAL_STRENGTH    1000000.0f
#define K_HEADING            1000000.0f
#define K_OBSTACLE           1000000.0f

// PID VALUES

#define KP_SIGNAL_FIELD 1.0f
#define KD_SIGNAL_FIELD 0.0f
#define KI_SIGNAL_FIELD 0.0f

#define KP_HEADING_FIELD 1.0f
#define KD_HEADING_FIELD 0.0f
#define KI_HEADING_FIELD 0.0f

#define KP_OBSTACLE_FIELD 1.0f
#define KD_OBSTACLE_FIELD 0.0f
#define KI_OBSTACLE_FIELD 0.0f

#define PID_LOWER_INTEGRATION_LIMIT -4000.0f
#define PID_UPPER_INTEGRATION_LIMIT 4000.0f

// Upper and lower bound values for PFC

#define MINIMUM_SIGNAL_STRENGTH   -50.0f // abs(dBM)
#define MAXIMUM_SIGNAL_STRENGTH   -40.0f // abs(dBM)
#define OBSTACLE_CUTOFF_DISTANCE  1000.0f

// Prototypes for functions used in source files:

void potential_field_controller_init(void);
void update_pfc_controller(motor_t *motor, int8_t RSSI, float heading, float heading_ref, float *measurement, float speed, float dt);
