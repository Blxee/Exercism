#include "palindrome_products.h"
#include <stdlib.h>

product_t *get_palindrome_product(int from, int to)
{
  product_t *result = malloc(sizeof(*result));
  int i, j, n;

  result->smallest = INT_MAX;
  result->largest = INT_MIN;
  result->factors_sm = malloc(sizeof(factor_t));
  result->factors_lg = malloc(sizeof(factor_t));
  result->factors_sm->next = NULL;
  result->factors_lg->next = NULL;
  if (from > to)
  {
    sprintf(result->error, "invalid input: min is %d and max is %d", from, to);
    return (result);
  }
  for (i = from; i <= to; i++)
  {
    for (j = from; j <= to; j++)
    {
      n = i * j;
      if (is_palindrome(n))
      {
        if (n < result->smallest)
        {
          result->smallest = n;
          result->factors_sm->factor_a = i;
          result->factors_sm->factor_b = j;
        }
        else if (n == result->smallest)
          append_factor(&(result->factors_sm), i, j);
        if (n > result->largest)
        {
          result->largest = n;
          result->factors_lg->factor_a = i;
          result->factors_lg->factor_b = j;
        }
        else if (n == result->largest)
          append_factor(&(result->factors_lg), i, j);
      }
    }
  }
  if (result->smallest == INT_MAX)
    sprintf(result->error, "no palindrome with factors in the range %d to %d", from, to);
  return (result);
}

bool is_palindrome(int n)
{
  int s = 1;
  int e = 1;

  while (n / (e * 10))
    e *= 10;
  while (e > s)
  {
    if (n / s % 10 != n / e % 10)
      return (false);
    s *= 10;
    e /= 10;
  }
  return (true);
}

void free_product(product_t *p)
{
  factor_t *fact;
  factor_t *pre_fact;
  
  fact = p->factors_sm;
  while (fact)
  {
    pre_fact = fact;
    fact = fact->next;
    free(pre_fact);
  }
  fact = p->factors_lg;
  while (fact)
  {
    pre_fact = fact;
    fact = fact->next;
    free(pre_fact);
  }
  free(p);
}

void append_factor(factor_t **factor, int a, int b)
{
  while (*factor)
    factor = &((*factor)->next);
  *factor = malloc(sizeof(factor_t));
  (*factor)->factor_a = a;
  (*factor)->factor_b = b;
  (*factor)->next = NULL;
}
