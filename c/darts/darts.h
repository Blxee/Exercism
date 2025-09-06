#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>

#define SQR(i) ((i) * (i))

#define CIRCLE_OUTER (10)
#define CIRCLE_MIDDLE (5)
#define CIRCLE_INNER (1)

typedef struct {
  float x;
  float y;
} coordinate_t;

uint8_t score(coordinate_t position);

#endif
