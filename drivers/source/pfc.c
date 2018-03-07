#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pfc.h"
#include "pid.h"
#include "nrf_log.h"

static PID_t PID_obstacle_field;

void potential_field_controller_init(void)
{
    PID_obstacle_field.set_point  = 0;
    PID_obstacle_field.error      = 0;
    PID_obstacle_field.last_error = 0;
    PID_obstacle_field.kp         = KP_OBSTACLE_FIELD;
    PID_obstacle_field.ki         = KI_OBSTACLE_FIELD;
    PID_obstacle_field.kd         = KD_OBSTACLE_FIELD;
    PID_obstacle_field.i_lb       = PID_LOWER_INTEGRATION_LIMIT;
    PID_obstacle_field.i_ub       = PID_UPPER_INTEGRATION_LIMIT;

		NRF_LOG_RAW_INFO("Potential Field Controller initiated. \n");
}

float compute_potential_field_obstacle(float measurement)
{
  if(measurement < OBSTACLE_CUTOFF_DISTANCE)
    return K_OBSTACLE*(1.0f/measurement - 1.0f/OBSTACLE_CUTOFF_DISTANCE)*(1.0f/measurement - 1.0f/OBSTACLE_CUTOFF_DISTANCE);
  if(measurement >= OBSTACLE_CUTOFF_DISTANCE)
    return 0;
}

void update_pfc_controller(motor_t *motor, float *measurement, float dt)
{
    static float obstacle_field_scalar[4] = {0};
    static float obstacle_output[4]       = {0};
    static float controller_output[2]     = {0};

    // Compute scalar value of potential fields

    obstacle_field_scalar[0] = compute_potential_field_obstacle(measurement[0]);
    obstacle_field_scalar[1] = compute_potential_field_obstacle(measurement[1]);
    obstacle_field_scalar[2] = compute_potential_field_obstacle(measurement[2]);
    obstacle_field_scalar[3] = compute_potential_field_obstacle(measurement[3]);

    // Compute output from PID controller
    obstacle_output[0] = update_PID(&PID_obstacle_field, obstacle_field_scalar[0], dt);
    obstacle_output[1] = 0.5f*update_PID(&PID_obstacle_field, obstacle_field_scalar[1], dt);
    obstacle_output[2] = update_PID(&PID_obstacle_field, obstacle_field_scalar[2], dt);
    obstacle_output[3] = 0.5f*update_PID(&PID_obstacle_field, obstacle_field_scalar[3], dt);

    // Output computed controller signals

    controller_output[0] = -obstacle_output[0] - obstacle_output[1] + obstacle_output[2] + obstacle_output[3];
    controller_output[1] = -obstacle_output[0] + obstacle_output[1] + obstacle_output[2] - obstacle_output[3]; //TODO: Test this

    // Make controller output compatible with motor domain

    // Motor A
    if(controller_output[0] < 0)
    {
      motor->direction_motor_a = false;
      motor->output_motor_a    = -controller_output[0];
    }
    else
    {
      motor->direction_motor_a = true;
      motor->output_motor_a    = controller_output[0];
    }

    // Motor B
    if(controller_output[1] < 0)
    {
      motor->direction_motor_b = false;
      motor->output_motor_b    = -controller_output[1];
    }
    else
    {
      motor->direction_motor_b = true;
      motor->output_motor_b    = controller_output[1];
    }

    //Setting top value for PWM-signals
    if(motor->output_motor_a > PWM_TOP_VALUE)
    {
      motor->output_motor_a = PWM_TOP_VALUE;
    }

    if(motor->output_motor_b > PWM_TOP_VALUE)
    {
      motor->output_motor_b = PWM_TOP_VALUE;
    }
}
