#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "d_encoder.h"
#include "m_motor.h"
#include "m_motor.c"


void count_ticks(ENCODERA_LEFT, ENCODERA_RIGHT,motor_direction_t *direction) {
    int MOTORA_TICKS = 0;
    int MOTORB_TICKS = 0;
    if (direction->motor0forward){
        if(nrf_gpio_sense_high(ENCODERA_LEFT)){
            MOTORA_TICKS++;
        }
     }
     else {
        if(nrf_gpio_sense_high(ENCODERA_LEFT)){
            MOTORA_TICKS--;
        }
     }
     if (direction->motor1forward){
        if(nrf_gpio_sense_high(ENCODERA_RIGHT)){
            MOTORB_TICKS++;
        }
     }
     else {
        if(nrf_gpio_sense_high(ENCODERA_RIGHT)){
            MOTORB_TICKS--;
     }
return(MOTORA_TICKS, MOTORB_TICKS);
};