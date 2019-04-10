#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "min_max.h"

float check_lower_upper_range(float value, float lower, float upper)
{
  if(value >= upper)
    value = upper;
  else if(value <= lower)
    value = lower;

  return value;
}

uint32_t min(uint32_t a, uint32_t b)
{
  if (a <= b)
    return a;
  else
    return b;
}

uint32_t max(uint32_t a, uint32_t b)
{
  if (a >= b)
    return a;
  else
    return b;
}