#include "isogram.h"

bool is_isogram(const char phrase[])
{
	bool char_appearance[26] = {0};
	int i;

	if (!phrase)
		return (false);
	i = 0;
	while (phrase[i])
	{
		if (phrase[i] >= 'a' && phrase[i] <= 'z')
		{
			if (char_appearance[phrase[i] - 'a'])
				return (false);
			else
				char_appearance[phrase[i] - 'a'] = true;
		}
		else if (phrase[i] >= 'A' && phrase[i] <= 'Z')
		{
			if (char_appearance[phrase[i] - 'A'])
				return (false);
			else
				char_appearance[phrase[i] - 'A'] = true;
		}
		i++;
	}
	return (true);
}
