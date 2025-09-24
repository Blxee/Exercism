#include "sum_of_multiples.h"

bool is_dup(const unsigned int *factors, unsigned int len, unsigned int factor)
{
	unsigned int i = 0;

	while (i < len)
	{
		if (factor % factors[i] == 0)
			return (true);
		i++;
	}
	return (false);
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
	unsigned int sum = 0;
	unsigned int factor;
	unsigned int i = 0;

	while (i < number_of_factors)
	{
		factor = factors[i];
		while (factor && factor < limit)
		{
			if (!is_dup(factors, i, factor))
				sum += factor;
			factor += factors[i];
		}
		i++;
	}
	return (sum);
}
