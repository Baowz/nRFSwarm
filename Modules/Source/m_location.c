#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "m_motor.h"
#include "d_encoder2.h"
#include "m_location.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"
#include "nrf_delay.h"

#define PI 3.141592654

//uint32_t angle = 0;
//int32_t xdirection;
//int32_t ydirection;
    
    uint32_t leftencodervalue;
    uint32_t rightencodervalue;
    uint32_t oldleftencodervalue;
    uint32_t oldrightencodervalue;
    uint32_t leftdifference;
    uint32_t rightdifference;
    uint32_t difference;
    int32_t tempangle;
    int32_t tempxlocation;
    int32_t tempylocation;



void location_service(motor_direction_t *selectdirection, encoder_ticks_t *encodercounter, location_angle_t *location_and_angle)
{

    double mathtest;
    double degreetoradian;

    leftencodervalue = (uint32_t)encodercounter->leftmotorticks;
    rightencodervalue = (uint32_t)encodercounter->rightmotorticks;

    //Possible to use switch case?
    switch (selectdirection->direction)
    {
        //Full stop
        case 0:
        oldleftencodervalue = leftencodervalue;
        oldrightencodervalue = rightencodervalue;
       
            break;

        //Forward
        case 1:


        //Calculate position
        if ((leftencodervalue != oldleftencodervalue) && (rightencodervalue != oldrightencodervalue))
        {
        leftdifference = leftencodervalue - oldleftencodervalue;
        rightdifference = rightencodervalue - oldrightencodervalue;
        difference = (leftdifference + rightdifference)/2;
        oldleftencodervalue = leftencodervalue;
        oldrightencodervalue = rightencodervalue;
        
        tempangle = location_and_angle->angle;
        degreetoradian = tempangle;
        degreetoradian = (degreetoradian* PI)/180;
        tempxlocation = (difference/ticksconfig.ticks_per_mm) * cos(degreetoradian);
        tempylocation = (difference/ticksconfig.ticks_per_mm) * sin(degreetoradian);
        location_and_angle->xlocation = location_and_angle->xlocation + tempxlocation;
        location_and_angle->ylocation = location_and_angle->ylocation + tempylocation;


        NRF_LOG_INFO("Mathtest says  %d .", mathtest);
        NRF_LOG_INFO("tempangle is  %d .", tempangle);
        NRF_LOG_INFO("degreetoradian is  %d .", degreetoradian);
        NRF_LOG_INFO("tempxlocation says  %d .", tempylocation);
        NRF_LOG_INFO("tempxlocation says  %d .", tempxlocation);
        }

            break;
        
        //Reverse
        case 2:
        if ((leftencodervalue != oldleftencodervalue) && (rightencodervalue != oldrightencodervalue))
        {
        leftdifference = leftencodervalue - oldleftencodervalue;
        rightdifference = rightencodervalue - oldrightencodervalue;
        difference = (leftdifference + rightdifference)/2;
        oldleftencodervalue = leftencodervalue;
        oldrightencodervalue = rightencodervalue;      
        tempangle = location_and_angle->angle;
        degreetoradian = tempangle;
        degreetoradian = (degreetoradian* PI)/180;
        tempxlocation = (difference/ticksconfig.ticks_per_mm) * cos(degreetoradian);
        tempylocation = (difference/ticksconfig.ticks_per_mm) * sin(degreetoradian);
        location_and_angle->xlocation = location_and_angle->xlocation - tempxlocation;
        location_and_angle->ylocation = location_and_angle->ylocation - tempylocation;
        }
            break;

        //Turn CW
        case 3:
        if ((leftencodervalue != oldleftencodervalue) && (rightencodervalue != oldrightencodervalue))
        {
        leftdifference = leftencodervalue - oldleftencodervalue;
        rightdifference = rightencodervalue - oldrightencodervalue;
        difference = (leftdifference + rightdifference)/2;
        oldleftencodervalue = leftencodervalue;
        oldrightencodervalue = rightencodervalue;
        tempangle = location_and_angle->angle;
        tempangle = tempangle - (difference/ticksconfig.ticks_per_degree);
        //tempangle = tempangle - difference;
        //NRF_LOG_INFO("tempangle - difference is %d .", tempangle);
        if (tempangle > 360)
        {
        tempangle = tempangle - 360;
        }
        if (tempangle < 0)
        {
        tempangle = tempangle + 360;
        }
        location_and_angle->angle = tempangle;
        }


            break;
        
        //Turn CCW
        case 4:
        if ((leftencodervalue != oldleftencodervalue) && (rightencodervalue != oldrightencodervalue))
        {
        leftdifference = leftencodervalue - oldleftencodervalue;
        rightdifference = rightencodervalue - oldrightencodervalue;
        difference = (leftdifference + rightdifference)/2;
        oldleftencodervalue = leftencodervalue;
        oldrightencodervalue = rightencodervalue; 
        tempangle = location_and_angle->angle;
        //NRF_LOG_INFO("tempangle is %d .", tempangle);
        //tempangle = tempangle - (difference/ticksconfig.ticks_per_degree);
        tempangle = tempangle + difference;
        //NRF_LOG_INFO("tempangle - difference is %d .", tempangle);
        if (tempangle > 360)
        {
        tempangle = tempangle - 360;
        }
        if (tempangle < 0)
        {
        tempangle = tempangle + 360;
        }
        location_and_angle->angle = tempangle;
        }
            break;

        default:
            // No implementation needed.
            break;

    }
    

}
