#include "grains.h"

uint64_t square(uint8_t index)
{
  uint64_t result = 1;

  if (index == 0 || index > 64)
    return (0);
  result <<= index - 1;
  return (result);
}

uint64_t total(void)
{
  return (~0ull);
}
