#include "perfect_numbers.h"

kind classify_number(int n)
{
	unsigned int num;
	unsigned int fact_sum;
	unsigned int i;

	if (n <= 0)
		return (ERROR);
	num = (unsigned int)n;
	fact_sum = 0;
	i = 1;
	while (i < num)
	{
		if (num % i == 0)
			fact_sum += i;
		i++;
	}
	if (fact_sum < num)
		return (DEFICIENT_NUMBER);
	if (fact_sum == num)
		return (PERFECT_NUMBER);
	else
		return (ABUNDANT_NUMBER);
}
