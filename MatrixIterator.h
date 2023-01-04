#include "Matrix.h"

template <typename T>
class MatrixIterator
{
public:
  MatrixIterator(T* curr_elem, Matrix<T>* matrix)
  {
  elem = curr_elem;
  list = matrix->data;
  length = matrix->height * matrix->width;
  };

  void Start()
  {
  elem = &list[0];
  };
  void Forward()
  {
  if (elem < &list[length])
    elem = elem + 1;
  };
  T& Item()
  {
  return *elem;
  };
  bool Valid()
  {
  return elem < &list[length] && elem >= &list[0];
  };
public:
  T* elem;
  T* list;
  int length;
};