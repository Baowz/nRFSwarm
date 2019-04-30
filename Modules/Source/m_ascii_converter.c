#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "ascii_converter.h"

// This code presumes that all data to be transformed in-between hex and ASCII are only the characters 0-9 and A-F.

uint8_t hex_to_ascii_number_table[] = {0x30, 0x31, 0x31, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46};

uint16_t hex_array_to_ascii(char *hex_array, uint8_t *ascii_array)
{
  static uint16_t size = 0;
  for(uint8_t i = 1; i <= 6; i = i + 1) // TODO: 6 can't be hardcoded (Upper limit of i). Currently sizeof(hex_array) gives 4.. why?
    {
      ascii_array[size] = hex_to_ascii_number_table[hex_array[6 - i] >> 4];
      size++;
      ascii_array[size] = hex_to_ascii_number_table[hex_array[6 - i] & 0x0F];
      size++;
    }
  return size;
}