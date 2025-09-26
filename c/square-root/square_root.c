#include "square_root.h"


uint16 find_square(uint16 n, uint16 i, uint16 j)
{
	uint16 m;

	if (i >= j)
		return (i);
	m = (i + j) / 2;
	if (m * m < n)
		return (find_square(n, m + 1, j));
	else if (m * m > n)
		return (find_square(n, i, m - 1));
	else
		return (m);
}

uint16 square_root(uint16 n)
{
	return (find_square(n, 0, n));
}
