#include "palindrome_products.h"

product_t *get_palindrome_product(int from, int to)
{
  product_t *result = malloc(sizeof(*result));
  int i, j, n;

  result->smallest = INT_MAX;
  result->largest = INT_MIN;
  for (i = from; i <= to; i++)
  {
    for (j = from; j <= to; j++)
    {
      if (i == j)
        continue ;
      n = i * j;
      if (is_palindrome(n))
      {
        if (n < result->smallest)
        {
          result->smallest = n;
          // set factors
        }
        if (n > result->largest)
        {
          result->largest = n;
          // set factors
        }
      }
    }
  }
  return (result);
}

bool is_palindrome(int n)
{
  int s = 1;
  int e = 1;

  while (n / e * 10)
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
