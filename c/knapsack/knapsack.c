#include "knapsack.h"

static unsigned int g_maximum_weight;
static const item_t *g_items;
static size_t g_item_count;

unsigned int recursive_find(int offset, unsigned int weight)
{
	unsigned int i;
	unsigned int val;
	unsigned int max;

	val = 0;
	max = 0;
	i = offset;
	while (i < g_item_count)
	{
		if (weight + g_items[i].weight > g_maximum_weight)
		{
			i++;
			continue;
		}
		val = g_items[i].value;
		val += recursive_find(i + 1, weight + g_items[i].weight);
		if (val > max)
			max = val;
		i++;
	}
	return (max);
}

unsigned int maximum_value(const unsigned int maximum_weight, const item_t *const items, size_t item_count)
{
	g_maximum_weight = maximum_weight;
	g_items = items;
	g_item_count = item_count;
	return (recursive_find(0, 0));
}
