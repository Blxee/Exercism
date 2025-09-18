#include "armstrong_numbers.h"

int ft_pow(int n, int p)
{
	int res;

	res = 1;
	while (p > 0)
	{
		res *= n;
		p--;
	}
	return (res);
}

bool is_armstrong_number(int candidate)
{
	int len;
	int sum;
	int num;

	len = 0;
	while (candidate / ft_pow(10, len))
		len++;

	sum = 0;
	num = candidate;
	while (num)
	{
		sum += ft_pow(num % 10, len);
		num /= 10;
	}
	return (candidate == sum);
}
