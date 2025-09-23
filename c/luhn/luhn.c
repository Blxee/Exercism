#include "luhn.h"

bool luhn(const char *num)
{
	int sum = 0;
	int len = strlen(num);
	int i = len - 1;
	bool x2 = false;
	int digits_found = 0;
	int digit;

	while (i >= 0)
	{
		if (isdigit(num[i]))
		{
			digit = num[i] - '0';
			if (x2)
				digit *= 2;
			if (digit > 9)
				digit -= 9;
			sum += digit;
			x2 = !x2;
			digits_found++;
		}
		else if (num[i] != ' ')
			return (false);
		i--;
	}
	return (digits_found > 1 && sum % 10 == 0);
}
