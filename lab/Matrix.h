#include <iostream>

class Matrix
{
public:
  Matrix();
  Matrix(const int &y, const int &x);
  Matrix(const Matrix &x);

  Matrix operator+ (const double &x) const;
  Matrix operator+ (const Matrix &x) const;
  Matrix operator- (const double &x) const;
  Matrix operator- (const Matrix &x) const;
  Matrix operator* (const double &x) const;
  Matrix operator* (const Matrix &x) const;
  const double* operator[] (const int &x) const;
  double* operator[] (const int &x);
  Matrix& operator= (const Matrix &x);
  Matrix& operator+= (const double &x);
  Matrix& operator+= (const Matrix &x);
  Matrix& operator-= (const double &x);
  Matrix& operator-= (const Matrix &x);
  Matrix& operator*= (const double &x);
  Matrix& operator*= (const Matrix &x);
  bool operator== (const Matrix& x) const;
  bool operator!= (const Matrix& x) const;
  friend std::istream& operator>> (std::istream& stream, Matrix& x);
  friend std::ostream& operator<< (std::ostream& stream, const Matrix& x);

  ~Matrix();

public:
  int height, width;
  double* data;
};