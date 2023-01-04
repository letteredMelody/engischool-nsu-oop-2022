#include "Matrix.h"
#include <iostream>

int main()
{
  Matrix<int> base;
  Matrix<float> size(3, 4);

  for (int i = 0; i < 12; ++i)
  {
    size.data[i] = i;
  }
  
  std::cout << size;
  
  base[0][0] = 1;
  base += 1;
  
  Matrix<int> second = base;
  base += second;
  
  base *= 0.5;

  std::cout << base;
  
  std::cout << (base == second) << '\n';
  std::cout << (base != second) << '\n';
  
  Matrix<int> input;
  
  std::cin >> input;
  std::cout << input;
}