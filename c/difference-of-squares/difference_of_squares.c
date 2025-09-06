#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number)
{
  unsigned int sum = 0;

  while (number) {
    sum += number * number;
    number--;
  }
  return (sum);
}

unsigned int square_of_sum(unsigned int number)
{
  unsigned int sum = 0;

  while (number)
  {
    sum += number;
    number--;
  }
  sum *= sum;
  return (sum);
}

unsigned int difference_of_squares(unsigned int number)
{
  return (square_of_sum(number) - sum_of_squares(number));
}
