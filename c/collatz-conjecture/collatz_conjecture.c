#include "collatz_conjecture.h"

int steps(int start)
{
  int i = 0;
  
  if (start <= 0)
    return (ERROR_VALUE);
  while (start != 1)
  {
    if (start & 1)
      start = start * 3 + 1;
    else
      start /= 2;
    i++;
  }
  return (i);
}
