#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "nrf_gpio.h"
//#include "nrf_drv_pwm.h"
#include "nrfx_pwm.h"
#include "nrf_pwm.h"





// Define Pin for PWM motor control
#define PWM_PIN_A               NRF_GPIO_PIN_MAP(0,03)    // Pin P0.04 Selected
//#define PWM_PIN_0               NRF_GPIO_PIN_MAP(0,13)    // Switch to led
#define PWM_PIN_B               NRF_GPIO_PIN_MAP(0,04)    // Pin P0.04 Selected
#define MOTOR_PIN_A1            NRF_GPIO_PIN_MAP(0,28)    // Pin P0.04 Selected
#define MOTOR_PIN_A2            NRF_GPIO_PIN_MAP(0,29)    // Pin P0.04 Selected
#define MOTOR_PIN_B1            NRF_GPIO_PIN_MAP(0,30)    // Pin P0.04 Selected
#define MOTOR_PIN_B2            NRF_GPIO_PIN_MAP(0,31)    // Pin P0.04 Selected

//#define LED_1          NRF_GPIO_PIN_MAP(0,13)
#define LED_3          NRF_GPIO_PIN_MAP(0,15)
#define LED_4          NRF_GPIO_PIN_MAP(0,16)


//Select direction
// Stop
// 1 Forward
// 2 Reverse
// 3 Turn CW
// 4 Turn CCW
typedef struct
{
  int direction;
}motor_direction_t;

typedef struct
{
  uint16_t speedA;
  uint16_t speedB;
}motor_speed_t;


//Initial motor direction and speed
 static motor_direction_t selectdirection =
 {
 .direction = 0,
 };

 static motor_speed_t speed =
 {
 .speedA = 0,
 .speedB = 0,
 };

void motor_direction(motor_direction_t *direction);
void motor_speed(motor_speed_t *speed);
void init_motor_pwm(void);

void motor_run(void);



//Example main
// int main(void)
// {

//         //Create struct named motors and insert values
//     init_motor_pwm();
    
//     static motor_direction_t direction =
//     {
//     .motor0forward = 0,
//     .motor1forward = 1
//     };

//     static motor_speed_t speed =
//     {
//     .speedA = 100,
//     .speedB = 20,
//     };

//     for (;;) // Neverending loop
//    {      
//       motor_direction(&direction);
//       motor_speed(&speed);
//       motor_run();
  
//    }
// }