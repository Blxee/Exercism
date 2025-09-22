#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size)
{
	struct tm *date;

	(void)size;
	input += 1000000000;
	date = gmtime(&input);
	sprintf(output, "%d%02d-%02d-%02d %02d:%02d:%02d",
			date->tm_year / 100 == 1 ? 20 : 19,
			date->tm_year % 100,
			date->tm_mon + 1,
			date->tm_mday,
			date->tm_hour,
			date->tm_min,
			date->tm_sec);
}
