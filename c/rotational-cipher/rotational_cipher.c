#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
	int len = strlen(text);
	char *cipher = malloc(len + 1);
	int i;

	i = 0;
	while (i < len)
	{
		if (isalpha(text[i]))
		{
			if (islower(text[i]))
				cipher[i] = (text[i] - 'a' + shift_key) % 26 + 'a';
			else
				cipher[i] = (text[i] - 'A' + shift_key) % 26 + 'A';
		}
		else
			cipher[i] = text[i];
		i++;
	}
	cipher[len] = '\0';
	return (cipher);
}
