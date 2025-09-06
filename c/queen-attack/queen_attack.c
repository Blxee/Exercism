#include "queen_attack.h"

uint8_t diff(int a, int b)
{
  int result = a - b;

  if (result < 0)
    result = -result;
  return (result);
}

attack_status_t can_attack(position_t q1, position_t q2)
{
  uint8_t arr[4] = {q1.row, q1.column, q2.row, q2.column};
  for (int i = 0; i < 4; i++)
    if (arr[i] >= 8)
      return (INVALID_POSITION);
  
  if (q1.row == q2.row && q1.column == q2.column)
    return (INVALID_POSITION);
  uint8_t diff_row = diff(q1.row, q2.row);
  uint8_t diff_col = diff(q1.column, q2.column);

  return (!diff_row || !diff_col || diff_row == diff_col);
}
