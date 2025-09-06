#include "leap.h"

bool leap_year(int year)
{
  bool div4 = year % 4 == 0;
  bool div100 = year % 100 == 0;
  bool div400 = year % 400 == 0;

  return div4 && (!div100 || div400);
}
