#include "allergies.h"


bool is_allergic_to(const allergen_t allergen, const int score)
{
	return (score & 1 << allergen);
}

allergen_list_t get_allergens(const int score)
{
	allergen_list_t allergies = (allergen_list_t){0};
	int i = 0;

	while (i < ALLERGEN_COUNT)
	{
		allergies.allergens[i] = score & 1 << i;
		allergies.count += allergies.allergens[i];
		i++;
	}
	return (allergies);
}
