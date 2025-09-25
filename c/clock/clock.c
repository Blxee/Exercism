#include "clock.h"

int clock_hour(clock_t clock)
{
	char digit1 = clock.text[0] - '0';
	char digit2 = clock.text[1] - '0';

	return (digit1 * 10 + digit2);
}

int clock_minute(clock_t clock)
{
	char digit1 = clock.text[3] - '0';
	char digit2 = clock.text[4] - '0';

	return (digit1 * 10 + digit2);
}

clock_t clock_create(int hour, int minute)
{
	clock_t clock;

	hour += minute / 60;
	minute %= 60;
	if (minute < 0)
	{
		hour--;
		minute = 60 + minute;
	}
	hour %= 24;
	if (hour < 0)
		hour = 24 + hour;

	sprintf(clock.text, "%c%c:%c%c",
			hour / 10 + '0',
			hour % 10 + '0',
			minute / 10 + '0',
			minute % 10 + '0');

	return (clock);
}

clock_t clock_add(clock_t clock, int minute_add)
{
	return (clock_create(clock_hour(clock), clock_minute(clock) + minute_add));
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
	return (clock_create(clock_hour(clock), clock_minute(clock) - minute_subtract));
}

bool clock_is_equal(clock_t a, clock_t b)
{
	a = clock_create(clock_hour(a), clock_minute(a));
	b = clock_create(clock_hour(b), clock_minute(b));

	return (strcmp(a.text, b.text) == 0);
}
