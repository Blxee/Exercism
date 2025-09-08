#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
  int i;

  if (strlen(lhs) != strlen(rhs))
    return (-1);
  i = 0;
  while (*lhs && *rhs)
  {
    if (*lhs != *rhs)
      i++;
    lhs++;
    rhs++;
  }
  return (i);
}
