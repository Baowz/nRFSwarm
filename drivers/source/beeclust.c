#include <stdint.h>
#include <stdbool.h>
#include "beeclust.h"
#include "nrf_log.h"

static float light_optimum = MIN_LIGHT_VALUE;
static float wait_time = 0;
static float delay_time = 0;
static bool  delay_pause = 0;
static bool bee_search = 0;

static pub_cb_t beeclust_pub_data;

// Moving average update of beeclust optimum
void beeclust_update_optimum(float new_data)
{
  static float light_vault[10];
  static uint8_t update_counter = 0;
  float sum = 0;

  if(new_data <= MIN_LIGHT_VALUE)
    return;

  update_counter++;

  if(update_counter >= 10)
    update_counter = 10;

  // Moving average optimum calculation

  for(uint8_t i = 0; i < 9; i++)
  {
    light_vault[i] = light_vault[i+1];
  }

  light_vault[9] = new_data;

  for(uint8_t k = 0; k < update_counter; k++)
  {
    sum += light_vault[9-k];
  }

  light_optimum = sum / update_counter;

  if(light_optimum >= 90.0f)
  {
    light_optimum = 90.0f;
  }
}

void beeclust_reset_all(void)
{
  light_optimum = MIN_LIGHT_VALUE;
  wait_time = 0;
  delay_time = 0;
  delay_pause = 0;
}

void beeclust_data_update(uint8_t data)
{
  switch(data)
  {
    case BEECLUST_RESET:
      NRF_LOG_RAW_INFO("Resetting BEECLUST. \n", data);
      beeclust_reset_all();
      break;
    case START_SEARCH:
      NRF_LOG_RAW_INFO("Starting BEECLUST search. \n", data);
      bee_search = true;
      break;
    case STOP_SEARCH:
      NRF_LOG_RAW_INFO("Pausing BEECLUST search. \n", data);
      bee_search = false;
      break;
    default:
      beeclust_update_optimum((float)data);
      break;
  }
}

// Classic beeclust, check light value and perform necessary stop/halt action or reinitiate motors
bool beeclust_check(float delta_time, bool stop_motors, float light_percentage)
{
 if(!bee_search)
  return 1;

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
     if(light_percentage >= light_optimum + LIGHT_TOLERANCE)
     {
       // Motors are stopped
       wait_time = (light_percentage - MIN_LIGHT_VALUE)/2.0f;
       delay_time = 10.0f/(light_percentage - MIN_LIGHT_VALUE);
       beeclust_update_optimum(light_percentage);
       beeclust_pub_data((uint8_t)light_percentage);
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
      // Check if light has moved
      if(light_percentage < (light_optimum / 2))
      {
        beeclust_reset_all();
        beeclust_pub_data(BEECLUST_RESET);
        return 0;
      }
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

// Initialize the BEECLUST search.

void beeclust_init(pub_cb_t publish_callback)
{
  beeclust_pub_data = publish_callback;
  bee_search = true;
}
