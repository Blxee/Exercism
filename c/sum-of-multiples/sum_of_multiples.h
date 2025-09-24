#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stddef.h>
#include <stdbool.h>

bool is_dup(const unsigned int *factors, unsigned int len, unsigned int factor);
unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit);

#endif
