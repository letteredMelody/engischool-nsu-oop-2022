#include <iostream>
#include "Date.h"

int main()
{
  Date base;
  Date string("31 12 2022");
  Date date(1, 1, 2022);

  string += 1;
  date -= 1;

  Date leap(28, 2, 2024);
  Date not_leap(28, 2, 2023);
  
  ++leap;
  not_leap++;
  leap--;
  --not_leap;

  std::cout << (leap == not_leap) << '\n';
  std::cout << (leap != not_leap) << '\n';
  std::cout << (leap > not_leap) << '\n';
  std::cout << (leap < not_leap) << '\n';

  Date input;

  std::cin >> input;

  Date::PrintString(input);

  return 0;
}
