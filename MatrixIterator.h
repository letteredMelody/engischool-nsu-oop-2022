#include <Matrix.h>

template <typename T>
class MatrixIterator
{
public:
  MatrixIterator(T*, Matrix<T>*)
public:
  T* elem;
  Matrix<T>* matrix;
};