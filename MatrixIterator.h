#include "Matrix.h"

template <typename T>
class MatrixIterator
{
public:
  MatrixIterator(T*, Matrix<T>*);

  void Start();
  void Forward();
  T& Item();
  bool Valid();
public:
  T* elem;
  Matrix<T>* list;
  int length;
};

////////////////////////////////////////////

template <typename T>
MatrixIterator<T>:: MatrixIterator(T* curr_elem, Matrix<T>* matrix)
{
  elem = curr_elem;
  list = matrix->data;
  length = matrix->height * matrix->width;
}

template <typename T>
void MatrixIterator<T>:: Start()
{
  elem = &list[0];
}

template <typename T>
void MatrixIterator<T>:: Forward()
{
  if (elem < &list[length])
    elem = elem + 1;
}

template <typename T>
T& MatrixIterator<T>:: Item()
{
  return *elem;
}

template <typename T>
bool MatrixIterator<T>:: Valid()
{
  return elem < &list[length] && elem >= &list[0];
}