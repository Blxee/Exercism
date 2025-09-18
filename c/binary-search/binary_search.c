#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
	int sp;
	int ep;
	int mid;

	sp = 0;
	ep = length - 1;

	while (sp <= ep)
	{
		mid = (sp + ep) / 2;
		if (arr[mid] < value)
			sp = mid + 1;
		else if (arr[mid] > value)
			ep = mid - 1;
		else
			return (arr + mid);
	}
	return (NULL);
}
