#include "darts.h"

uint8_t score(coordinate_t position)
{
  float radius = SQR(position.x) + SQR(position.y);

  if (radius <= SQR(CIRCLE_INNER))
    return (10);
  else if (radius <= SQR(CIRCLE_MIDDLE))
    return (5);
  else if (radius <= SQR(CIRCLE_OUTER))
    return (1);
  return (0);
}
