#include "reverse_string.h"

char *reverse(const char *value)
{
	int len;
	char *result;
	int i;
	int j;

	len = 0;
	while (value[len])
		len++;

	result = malloc(len + 1);

	i = 0;
	j = len - 1;

	while (i <= j)
	{
		result[i] = value[j];
		result[j] = value[i];
		i++;
		j--;
	}

	result[len] = '\0';

	return (result);
}
