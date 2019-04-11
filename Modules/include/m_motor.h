#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "nrf_gpio.h"
#include "nrf_drv_pwm.h"




// Define Pin for PWM motor control
#define PWM_PIN_0               NRF_GPIO_PIN_MAP(0,03)    // Pin P0.04 Selected
//#define PWM_PIN_0               NRF_GPIO_PIN_MAP(0,13)    // Switch to led 
#define PWM_PIN_1               NRF_GPIO_PIN_MAP(0,04)    // Pin P0.04 Selected
#define MOTOR_PIN_OA            NRF_GPIO_PIN_MAP(0,28)    // Pin P0.04 Selected
#define MOTOR_PIN_OB            NRF_GPIO_PIN_MAP(0,29)    // Pin P0.04 Selected
#define MOTOR_PIN_1A            NRF_GPIO_PIN_MAP(0,30)    // Pin P0.04 Selected
#define MOTOR_PIN_1B            NRF_GPIO_PIN_MAP(0,31)    // Pin P0.04 Selected

//#define LED_1          NRF_GPIO_PIN_MAP(0,13)
#define LED_3          NRF_GPIO_PIN_MAP(0,15)
#define LED_4          NRF_GPIO_PIN_MAP(0,16)



typedef struct
{
  bool motor0forward; 
  bool motor1forward;
}motor_direction_t;

typedef struct
{
  uint16_t speedA; 
  uint16_t speedB;
}motor_speed_t;

void motor_direction(motor_direction_t *direction);
void motor_speed(motor_speed_t *speed);
void init_motor_pwm(void);

void motor_run(void);