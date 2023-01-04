#include "MatrixIterator.h"

#include <iostream>

int main()
{
  Matrix<float> check(3, 4);

  for (int i = 0; i < 12; ++i)
  {
    check.data[i] = 1./(i + 1);
  }
  
  std::cout << check;

  MatrixIterator<float> iter(&check.data[0], &check);

  for (iter.Start(); iter.Valid(); iter.Forward())
  {
    std::cout << iter.Item() << " ";
  }
}