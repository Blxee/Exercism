#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
	size_t len = 0;
	size_t i;
	size_t j;

	i = 2;
	while (i <= limit)
	{
		j = 0;
		while (j < len)
		{
			if (i % primes[j] == 0)
				goto jump;
			j++;
		}
		primes[len++] = i;
		if (len == max_primes)
			return (len);
jump:
		i++;
	}
	return (len);
}
