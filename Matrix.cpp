#include <iostream>
#include "Matrix.h"

template <typename T>
Matrix<T> Matrix<T>::operator+ (const int& x) const
{   
  int width = this->width, height = this->height;
  T* data = this->data;

  for (int i = 0; i < width * height; ++i)
  {
    data[i] += x;
  }

  return { height, width, data };
}

template <typename T>
Matrix<T> Matrix<T>::operator+ (const Matrix& x) const
{   
  int width = this->width, height = this->height;
  T* data = this->data;

  if (height != x.height || width != x.width)
  {
    throw "You cannot sum different sized matrices!";
  }
  else
  {
    for (int i = 0; i < height * width; ++i)
    {
      data[i] += x.data[i];
    }
  }

  return { height, width, data };
}

template <typename T>
Matrix<T> Matrix<T>::operator- (const int& x) const
{
  int width = this->width, height = this->height;
  T* data = this->data;

  for (int i = 0; i < width * height; ++i)
  {
    data[i] -= x;
  }

  return { height, width, data };
}

template <typename T>
Matrix<T> Matrix<T>::operator- (const Matrix& x) const
{
  int width = this->width, height = this->height;
  T* data = this->data;

  if (height != x.height || width != x.width)
  {
    throw "You cannot substract different sized matrices!";
  }
  else
  {
    for (int i = 0; i < height * width; ++i)
    {
      data[i] -= x.data[i];
    }
  }

  return { height, width, data };
}

template <typename T>
Matrix<T> Matrix<T>::operator* (const int& x) const
{
  int width = this->width, height = this->height;
  T* data = this->data;

  for (int i = 0; i < width * height; ++i)
  {
    data[i] *= x;
  }

  return { height, width, data };
}

template <typename T>
Matrix<double> Matrix<T>::operator* (const double& x) const
{
  int width = this->width, height = this->height;
  T* data = this->data;

  for (int i = 0; i < width * height; ++i)
  {
    data[i] *= x;
  }

  return { height, width, data };
}

template <typename T>
Matrix<T> Matrix<T>::operator* (const Matrix& x) const
{
  int width = this->width, height = this->height;
  T* data = this->data;

  if (height != x.height || width != x.width)
  {
    throw "You cannot multiply different sized matrices!";
  }
  else
  {
    for (int i = 0; i < height * width; ++i)
    {
      data[i] *= x.data[i];
    }
  }

  return { height, width, data };
}

template <typename T>
T* Matrix<T>::operator[] (const int& x) const
{
  T* row = new T[this->width];

  for (int i = width * (x - 1); i < width * x; ++i)
  {
    row[i - width * (x - 1)] = this->data[i];
  }

  return row;
}

template <typename T>
Matrix<T> Matrix<T>::operator= (const Matrix& x)
{
  this->data = x.data;
  this->height = x.height;
  this->width = x.width;

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+= (const int& x)
{
  *this = *this + x;

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+= (const Matrix& x)
{
  *this = *this + x;

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-= (const int& x)
{
  *this = *this - x;

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-= (const Matrix& x)
{
  *this = *this - x;

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*= (const int& x)
{
  *this = *this * x;

  return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*= (const Matrix& x)
{
  *this = *this * x;

  return *this;
}

template <typename T>
Matrix<double> Matrix<T>::operator*= (const double& x) 
{
  *this = *this * x;

  return *this;
}

template <typename T>
bool Matrix<T>::operator== (const Matrix& x) const
{
  if (this->height != x.height || this->width != x.width)
  {
    return false;
  }
  else 
  {
    for (int i = 0; i < this->height * this->width; ++i)
    {
      if (this->data[i] != x.data[i])
      {
        return false;
      }
    }
  }

  return true;
}