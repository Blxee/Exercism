#include "binary.h"

int convert(const char *input)
{
	int num;

	num = 0;
	while (*input)
	{
		num <<= 1;
		if (*input != '0' && *input != '1')
			return (INVALID);
		if (*input == '1')
			num |= 1;
		input++;
	}
	return (num);
}
