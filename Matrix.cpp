#include "Matrix.h"
#include <iostream>

template <typename T>
Matrix<T>:: Matrix()
  : height(2), width(2)
{
  data = new T[height * width];
}

template <typename T>
Matrix<T>:: Matrix(const int &y, const int &x)
  : height(y), width(x)
{
  data = new T[height * width];
}

template <typename T>
Matrix<T>:: Matrix(const Matrix<T> &x)
  : height(x.height), width(x.width), data(new T[height*width])
{
  for(int i = 0; i < width * height; ++i) {
    data[i] = x.data[i];
  }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const double &x) const
{
  Matrix<T> temp = *this;
  temp += x;

  return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &x) const
{
  Matrix<T> temp = *this;
  temp += x;

  return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const double &x) const
{
  Matrix<T> temp = *this;
  temp -= x;

  return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &x) const
{
  Matrix<T> temp = *this;
  temp -= x;

  return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const double &x) const
{
  Matrix<T> temp = *this;
  temp *= x;

  return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &x) const
{
  Matrix<T> temp = *this;
  temp *= x;

  return temp;
}

template <typename T>
const T* Matrix<T>:: operator[](const int& x) const
{
  return &data[x * width];
}

template <typename T>
T* Matrix<T>:: operator[](const int& x)
{
  return &data[x * width];
}

template <typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T> &x)
{
  if (&x == this)
  {
    return *this;
  }
  else 
  {
  height = x.height;
  width = x.width;
  data = new T[height * width];

  for (int i = 0; i < width * height; ++i)
  {
    data[i] = x.data[i];
  }
  
  return *this;
  }
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const double &x) 
{
  for (int i = 0; i < height * width; ++i)
  {
    data[i] += x;
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &x) 
{
  if (x.height != height || x.width != width)
  {
    throw "You cannot sum different-sized matrices!";
  }

  for (int i = 0; i < height * width; ++i)
  {
    data[i] += x.data[i];
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const double &x)
{
  for (int i = 0; i < height * width; ++i)
  {
    data[i] -= x;
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &x)
{
  if (x.height != height || x.width != width)
  {
    throw "You cannot substract different-sized matrices!";
  }

  for (int i = 0; i < height * width; ++i)
  {
    data[i] -= x.data[i];
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const double &x)
{
  for (int i = 0; i < height * width; ++i)
  {
    data[i] *= x;
  }

  return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T> &x)
{
  if (x.height != width)
  {
    throw "You cannot multiply different-sized matrices!";
  }
  
  double* new_data = new T[height * x.width];

  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < x.width; ++j)
    {
      for (int k = 0; k < width; ++k)
      {
        new_data[i * x.width + j] += data[i * width + k] * x.data[k * x.width + j];
      }
    }
  }

  delete[] data;

  data = new_data;
  width = x.width;

  return *this;
}

template <typename T>
bool Matrix<T>::operator== (const Matrix<T>& x) const
{
  if (x.height != height || x.width != width)
  {
    return false;
  }

  for (int i = 0; i < width * height; ++i)
  {
    if (x.data[i] != data[i])
    {
      return false;
    }
  }

  return true;
}

template <typename T>
bool Matrix<T>::operator!= (const Matrix<T>& x) const
{
  return !(*this == x);
}

template <typename T>
std::istream& operator>> (std::istream& stream, Matrix<T>& x)
{
  stream >> x.height;
  stream >> x.width;
  
  for (int i = 0; i < x.height * x.width; ++i)
  {
    stream >> x.data[i];
  }

  return stream;
}

template <typename T>
std::ostream& operator<< (std::ostream& stream, const Matrix<T>& x)
{
  for (int i = 0; i < x.height; ++i)
  {
    for (int j = 0; j < x.width; ++j)
    {
      stream << x.data[x.width * i + j] << ' ';
    }
    stream << '\n';
  }

  return stream;
}

template <typename T>
Matrix<T>:: ~Matrix()
{
  delete[] data;
}