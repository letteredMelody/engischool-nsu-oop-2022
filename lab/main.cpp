#include "Matrix.h"
#include <iostream>

int main()
{
  Matrix base;
  Matrix size(3, 4);
  Matrix cnst(4, 3);

  for (int i = 0; i < 12; ++i)
  {
    size.data[i] = i;
    // cnst.data[i] = i;
  }
  
  std::cout << size;
//   std::cout << cnst;
  
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      cnst[i][j]++;
    }
  }
  
  std::cout << cnst;
  
  size *= cnst;
  
  std::cout << size;
  
  base[0][0] = 1;
  base += 1;
  
  Matrix second = base;
  base += second;
  
  base *= 0.5;

  // std::cout << base;
  
  // std::cout << (base == second) << '\n';
  // std::cout << (base != second) << '\n';
  
  Matrix input;
  
  // std::cin >> input;
  // std::cout << input;
}