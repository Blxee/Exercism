#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
	struct tm *date;

	(void)size;
	input += 1000000000;
	date = gmtime(&input);
	strftime(output, size, "%Y-%m-%d %H:%M:%S", date);
}
