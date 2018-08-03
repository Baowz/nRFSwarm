#include <stdint.h>
#include <stdbool.h>
#include "beeclust.h"

bool beeclust_check(float delta_time, bool stop_motors, float light_percentage)
{
 static float wait_time = 0;
 static float delay_time = 0;
 static bool delay_pause = 0;

 // If the vessel was recently paused, cooldown for being paused again.
 if(delay_pause)
 {
   delay_time -= delta_time; // Decrement cooldown time
   if(delay_time <= 0)
   {
     // Stop cooldown
     delay_time = 0;
     delay_pause = 0;
   }
   return 0;
 }
 else
 {
    // First perform a check if the motors should be stopped or initiated
   if(stop_motors == 0)
   {
     if(light_percentage >= MAX_LIGHT_VALUE)
     {
       // Motors are stopped
       wait_time = (light_percentage - MAX_LIGHT_VALUE)/2.0f;
       delay_time = 5.0f/(light_percentage - MAX_LIGHT_VALUE);
       return 1;
     }
     else
     {
       // Motors are not stopped
       return 0;
     }
   }

  else if(stop_motors == 1)
    {
      // Count down for restart
      wait_time -= delta_time;
      if(wait_time <= 0)
      {
        //Restart motors, stop countdown
        wait_time = 0;
        delay_pause = 1;
        return 0;
      }
      else
      {
        // Continue countdown
        return 1;
      }
    }
  }
}
