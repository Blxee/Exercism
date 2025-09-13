#include "raindrops.h"

void convert(char result[], int drops)
{
	const int MAP_KEYS[] = {3, 5, 7};
	const char *MAP_VALS[] = { "Pling", "Plang", "Plong" };
	int i;
	int offset;

	offset = 0;
	i = 0;
	while (i < (int)(sizeof(MAP_KEYS) / sizeof(*MAP_KEYS)))
	{
		if (drops % MAP_KEYS[i] == 0)
		{
			sprintf(result + offset, "%s", MAP_VALS[i]);
			offset += 5;
		}
		i++;
	}
	if (result[0] == '\0')
		sprintf(result, "%d", drops);
}
