#include <stdbool.h>
#include <stdint.h>
#include <string.h>
//#include "d_swarm_board.h"

typedef struct
{
  uint32_t ticks_per_mm;
  uint32_t ticks_per_degree;
}number_of_ticks_config_t;

typedef struct
{
  uint32_t angle;
  int32_t xlocation;
  int32_t ylocation;
}location_angle_t;

//Start angle and position
static location_angle_t location_and_angle =
{
  .angle = 45,
  .xlocation = 0,
  .ylocation = 0,
};

//Configure how many encoder ticks will happen for 1mm and for 1 degree
static number_of_ticks_config_t ticksconfig =
{
  .ticks_per_mm = 1,
  .ticks_per_degree = 1,
};

void location_service(motor_direction_t *selectdirection, encoder_ticks_t *encodercounter, location_angle_t *location_and_angle);