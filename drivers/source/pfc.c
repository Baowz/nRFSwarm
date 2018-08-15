#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "pfc.h"
#include "pid.h"
#include "nrf_log.h"

static PID_t PID_signal_field;
static PID_t PID_heading_field;
static PID_t PID_obstacle_field_one;
static PID_t PID_obstacle_field_two;
static PID_t PID_obstacle_field_three;
static PID_t PID_obstacle_field_four;


// Initialization of the three PID-controllers.

void potential_field_controller_init(void)
{
    PID_signal_field.set_point  = 0;
    PID_signal_field.error      = 0;
    PID_signal_field.last_error = 0;
    PID_signal_field.kp         = KP_SIGNAL_FIELD;
    PID_signal_field.ki         = KI_SIGNAL_FIELD;
    PID_signal_field.kd         = KD_SIGNAL_FIELD;
    PID_signal_field.i_lb       = PID_LOWER_INTEGRATION_LIMIT;
    PID_signal_field.i_ub       = PID_UPPER_INTEGRATION_LIMIT;

    PID_heading_field.set_point  = 0;
    PID_heading_field.error      = 0;
    PID_heading_field.last_error = 0;
    PID_heading_field.kp         = KP_HEADING_FIELD;
    PID_heading_field.ki         = KI_HEADING_FIELD;
    PID_heading_field.kd         = KD_HEADING_FIELD;
    PID_heading_field.i_lb       = PID_LOWER_INTEGRATION_LIMIT;
    PID_heading_field.i_ub       = PID_UPPER_INTEGRATION_LIMIT;

    PID_obstacle_field_one.set_point  = 0;
    PID_obstacle_field_one.error      = 0;
    PID_obstacle_field_one.last_error = 0;
    PID_obstacle_field_one.kp         = KP_OBSTACLE_FIELD_ONE;
    PID_obstacle_field_one.ki         = KI_OBSTACLE_FIELD_ONE;
    PID_obstacle_field_one.kd         = KD_OBSTACLE_FIELD_ONE;
    PID_obstacle_field_one.i_lb       = PID_LOWER_INTEGRATION_LIMIT;
    PID_obstacle_field_one.i_ub       = PID_UPPER_INTEGRATION_LIMIT;

    PID_obstacle_field_two.set_point  = 0;
    PID_obstacle_field_two.error      = 0;
    PID_obstacle_field_two.last_error = 0;
    PID_obstacle_field_two.kp         = KP_OBSTACLE_FIELD_TWO;
    PID_obstacle_field_two.ki         = KI_OBSTACLE_FIELD_TWO;
    PID_obstacle_field_two.kd         = KD_OBSTACLE_FIELD_TWO;
    PID_obstacle_field_two.i_lb       = PID_LOWER_INTEGRATION_LIMIT;
    PID_obstacle_field_two.i_ub       = PID_UPPER_INTEGRATION_LIMIT;

    PID_obstacle_field_three.set_point  = 0;
    PID_obstacle_field_three.error      = 0;
    PID_obstacle_field_three.last_error = 0;
    PID_obstacle_field_three.kp         = KP_OBSTACLE_FIELD_THREE;
    PID_obstacle_field_three.ki         = KI_OBSTACLE_FIELD_THREE;
    PID_obstacle_field_three.kd         = KD_OBSTACLE_FIELD_THREE;
    PID_obstacle_field_three.i_lb       = PID_LOWER_INTEGRATION_LIMIT;
    PID_obstacle_field_three.i_ub       = PID_UPPER_INTEGRATION_LIMIT;

    PID_obstacle_field_four.set_point  = 0;
    PID_obstacle_field_four.error      = 0;
    PID_obstacle_field_four.last_error = 0;
    PID_obstacle_field_four.kp         = KP_OBSTACLE_FIELD_FOUR;
    PID_obstacle_field_four.ki         = KI_OBSTACLE_FIELD_FOUR;
    PID_obstacle_field_four.kd         = KD_OBSTACLE_FIELD_FOUR;
    PID_obstacle_field_four.i_lb       = PID_LOWER_INTEGRATION_LIMIT;
    PID_obstacle_field_four.i_ub       = PID_UPPER_INTEGRATION_LIMIT;

    NRF_LOG_RAW_INFO("[SUCCESS] Potential Field Controller initiated. \n");
}

// Potential field for the RSSI signal strength.

float compute_potential_field_signal_strength(int8_t RSSI)
{
  if(RSSI < MINIMUM_SIGNAL_STRENGTH)
    return K_SIGNAL_STRENGTH*( 1/(100 + RSSI) - 1/(100 + MINIMUM_SIGNAL_STRENGTH));
  else if(RSSI >= MINIMUM_SIGNAL_STRENGTH && RSSI <= MAXIMUM_SIGNAL_STRENGTH)
    return 0;
  else if(RSSI > MAXIMUM_SIGNAL_STRENGTH)
    return K_SIGNAL_STRENGTH*((1/RSSI) - (1/MAXIMUM_SIGNAL_STRENGTH));
}

// Potential field for the heading direction.

float compute_potential_field_heading(float heading, float heading_ref)
{
  if(heading - heading_ref <= PI)
    return K_HEADING*(heading - heading_ref);
  else if (heading - heading_ref > PI)
    return -K_HEADING*((heading - PI) - heading_ref);
}

// Potential field for the obstacle avoidance procedure.

float compute_potential_field_obstacle(float measurement)
{
  if(measurement <= 20)
    measurement = 20;

  if(measurement < OBSTACLE_CUTOFF_DISTANCE)
    return K_OBSTACLE*(1.0f/measurement - 1.0f/OBSTACLE_CUTOFF_DISTANCE)*(1.0f/measurement - 1.0f/OBSTACLE_CUTOFF_DISTANCE) + 5;
  if(measurement >= OBSTACLE_CUTOFF_DISTANCE)
    return 0;
}

// PFC and PID controller computations. Formatted to be sent to the motor output.

void update_pfc_controller(motor_t *motor, int8_t RSSI, float heading, float heading_ref, float *measurement, float *speed, float dt, int16_t *analytical_data)
{
    static float signal_field_scalar      =  0;
    static float heading_field_scalar     =  0;
    static float obstacle_field_scalar[4] = {0};
    static float obstacle_bleeding_coef   =  100;

    static float signal_output            =  0;
    static float heading_output           =  0;
    static float obstacle_output[4]       = {0};
    static float controller_output[2]     = {0};

    // Compute scalar value of potential fields

    if(!(RSSI == -100))
      signal_field_scalar    = 0; //compute_potential_field_signal_strength(RSSI);
    heading_field_scalar     = 0; //compute_potential_field_heading(heading, heading_ref);

    obstacle_field_scalar[0] = compute_potential_field_obstacle(measurement[0]);
    obstacle_field_scalar[1] = compute_potential_field_obstacle(measurement[1]);
    obstacle_field_scalar[2] = compute_potential_field_obstacle(measurement[2]);
    obstacle_field_scalar[3] = compute_potential_field_obstacle(measurement[3]);

    // Compute output from PID controller

    signal_output      = 0; //update_PID(&PID_signal_field, signal_field_scalar, dt);
    heading_output     = 0; //update_PID(&PID_heading_field, heading_field_scalar, dt);

    // To avoid jumping back and forth should the forward and backward output from sensor 1 and 3 be 0 if the measurement ranges are too close

    obstacle_output[0] = update_PID(&PID_obstacle_field_one,   obstacle_field_scalar[0], dt);
    obstacle_output[1] = update_PID(&PID_obstacle_field_two,   obstacle_field_scalar[1], dt);
    obstacle_output[2] = update_PID(&PID_obstacle_field_three, obstacle_field_scalar[2], dt);
    obstacle_output[3] = update_PID(&PID_obstacle_field_four,  obstacle_field_scalar[3], dt);

    // Output computed controller signals

    controller_output[0] = -speed[0] + signal_output // + heading_output
                         - (5.0f * obstacle_output[0]) - obstacle_output[1] + obstacle_output[2] + obstacle_output[3];
    controller_output[1] = -speed[1] + signal_output // - heading_output
                         - obstacle_output[0] + obstacle_output[1] + obstacle_output[2] - obstacle_output[3]; //TODO: Test this

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

    // Physical offset fix

    motor->output_motor_a = MOTOR_OFFSET_LEFT*motor->output_motor_a;
    motor->output_motor_b = MOTOR_OFFSET_RIGHT*motor->output_motor_b;

    analytical_data[0]   = signal_output;
    analytical_data[1]   = obstacle_output[0];
    analytical_data[2]   = obstacle_output[1];
    analytical_data[3]   = obstacle_output[2];
    analytical_data[4]   = obstacle_output[3];
}
