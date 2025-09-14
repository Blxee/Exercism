#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

#define ARR_LEN(arr) ((int)(sizeof(arr) / sizeof(arr[0])))
bool is_pangram(const char *sentence);

#endif
