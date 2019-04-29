#include <stdint.h>
#include <stdbool.h>

#define LPS22HB_ADDR (0xB8 >> 1)
#define LPS22HB_CHIPID 0b10111100

static bool LPS22HB_chipfound = false;