#include "dnd_character.h"

int ability(void)
{
	int score;
	int i;
	int dice;
	int smallest;

	srand(time(NULL));
	score = 0;
	smallest = 7;
	i = 0;
	while (i < 4)
	{
		dice = rand() % 6 + 1;
		score += dice;
		if (dice < smallest)
			smallest = dice;
		i++;
	}
	score -= smallest;
	return (score);
}

int modifier(int score)
{
	return ((int)floor(((double)score - 10.) / 2.));
}

dnd_character_t make_dnd_character(void)
{
	dnd_character_t character;

	character = (dnd_character_t) {
		.strength = ability(),
		.dexterity = ability(),
		.constitution = ability(),
		.intelligence = ability(),
		.wisdom = ability(),
		.charisma = ability(),
	};
	character.hitpoints = 10 + modifier(character.constitution);
	return (character);
}
