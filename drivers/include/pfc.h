#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "motor.h"

// PFC VALUES

#define K_OBSTACLE  1000000.0f

// PID VALUES

#define KP_OBSTACLE_FIELD 1.0f
#define KD_OBSTACLE_FIELD 0.0f
#define KI_OBSTACLE_FIELD 0.0f

#define PID_LOWER_INTEGRATION_LIMIT -4000.0f
#define PID_UPPER_INTEGRATION_LIMIT 4000.0f

#define OBSTACLE_CUTOFF_DISTANCE  500.0f

// Prototypes for functions used in source files:

void potential_field_controller_init(void);
void update_pfc_controller(motor_t *motor, float *measurement, float dt);
