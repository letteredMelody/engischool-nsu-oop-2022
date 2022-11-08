#include "Matrix.h"
#include <iostream>

Matrix:: Matrix()
  : height(2), width(2)
{
  data = new double[height * width];
}

Matrix:: Matrix(const int &y, const int &x)
  : height(y), width(x)
{
  data = new double[height * width];
}

Matrix:: Matrix(const Matrix &x)
  : height(x.height), width(x.width), data(new double[height*width])
{
  for(int i = 0; i < width * height; ++i) {
    data[i] = x.data[i];
  }
}

Matrix Matrix::operator+(const double &x) const
{
  Matrix temp = *this;
  temp += x;

  return temp;
}

Matrix Matrix::operator+(const Matrix &x) const
{
  Matrix temp = *this;
  temp += x;

  return temp;
}

Matrix Matrix::operator-(const double &x) const
{
  Matrix temp = *this;
  temp -= x;

  return temp;
}

Matrix Matrix::operator-(const Matrix &x) const
{
  Matrix temp = *this;
  temp -= x;

  return temp;
}

Matrix Matrix::operator*(const double &x) const
{
  Matrix temp = *this;
  temp *= x;

  return temp;
}

Matrix Matrix::operator*(const Matrix &x) const
{
  Matrix temp = *this;
  temp *= x;

  return temp;
}

const double* Matrix:: operator[](const int& x) const
{
  return &data[x * width];
}

double* Matrix:: operator[](const int& x)
{
  return &data[x * width];
}

Matrix& Matrix::operator= (const Matrix &x)
{
  if (&x == this)
  {
    return *this;
  }
  else 
  {
  height = x.height;
  width = x.width;
  data = new double[height * width];

  for (int i = 0; i < width * height; ++i)
  {
    data[i] = x.data[i];
  }
  
  return *this;
  }
}

Matrix& Matrix::operator+=(const double &x) 
{
  for (int i = 0; i < height * width; ++i)
  {
    data[i] += x;
  }

  return *this;
}

Matrix& Matrix::operator+=(const Matrix &x) 
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

Matrix& Matrix::operator-=(const double &x)
{
  for (int i = 0; i < height * width; ++i)
  {
    data[i] -= x;
  }

  return *this;
}

Matrix& Matrix::operator-=(const Matrix &x)
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

Matrix& Matrix::operator*=(const double &x)
{
  for (int i = 0; i < height * width; ++i)
  {
    data[i] *= x;
  }

  return *this;
}

Matrix& Matrix::operator*=(const Matrix &x)
{
  if (x.height != width)
  {
    throw "You cannot multiply different-sized matrices!";
  }
  
  double* new_data = new double[height * x.width];

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

bool Matrix::operator== (const Matrix& x) const
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

bool Matrix::operator!= (const Matrix& x) const
{
  return !(*this == x);
}

std::istream& operator>> (std::istream& stream, Matrix& x)
{
  stream >> x.height;
  stream >> x.width;
  
  for (int i = 0; i < x.height * x.width; ++i)
  {
    stream >> x.data[i];
  }

  return stream;
}

std::ostream& operator<< (std::ostream& stream, const Matrix& x)
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

Matrix:: ~Matrix()
{
  delete[] data;
}