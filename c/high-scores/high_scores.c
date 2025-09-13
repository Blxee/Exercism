#include "high_scores.h"
///
/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{
	return (scores[scores_len - 1]);
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
	int32_t highest;
	size_t i;

	highest = 0;
	i = 0;
	while (i < scores_len)
	{
		if (scores[i] > highest)
			highest = scores[i];
		i++;
	}
	return (highest);
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
	int32_t *scores_cpy;
	size_t i;
	size_t j;
	int32_t tmp;

	scores_cpy = malloc(scores_len * sizeof(int32_t));
	memcpy(scores_cpy, scores, scores_len * sizeof(int32_t));

	i = 0;
	while (i < scores_len)
	{
		j = 0;
		while (j < scores_len - i - 1)
		{
			if (scores_cpy[j] < scores_cpy[j + 1])
			{
				tmp = scores_cpy[j];
				scores_cpy[j] = scores_cpy[j + 1];
				scores_cpy[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 3 && i < scores_len)
	{
		output[i] = scores_cpy[i];
		i++;
	}
	free(scores_cpy);
	return (i);
}
