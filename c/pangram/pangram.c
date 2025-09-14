#include "pangram.h"

bool is_pangram(const char *sentence)
{
	int chars[26] = {0};
	int i;

	if (!sentence)
		return (false);
	i = 0;
	while (sentence[i])
	{
		if (sentence[i] >= 'a' && sentence[i] <= 'z')
			chars[sentence[i] - 'a'] += 1;
		if (sentence[i] >= 'A' && sentence[i] <= 'Z')
			chars[sentence[i] - 'A'] += 1;
		i++;
	}
	i = 0;
	while (i < ARR_LEN(chars))
	{
		if (chars[i] == 0)
			return (false);
		i++;
	}
	return (true);
}
