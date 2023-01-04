#include <iostream>

template <typename T>
class Matrix
{
public:
  Matrix();
  Matrix(const int &y, const int &x);
  Matrix(const Matrix<T> &x);

  Matrix<T> operator+ (const double &x) const;
  Matrix<T> operator+ (const Matrix<T> &x) const;
  Matrix<T> operator- (const double &x) const;
  Matrix<T> operator- (const Matrix<T> &x) const;
  Matrix<T> operator* (const double &x) const;
  Matrix<T> operator* (const Matrix<T> &x) const;
  const T* operator[] (const int &x) const;
  T* operator[] (const int &x);
  Matrix<T>& operator= (const Matrix<T> &x);
  Matrix<T>& operator+= (const double &x);
  Matrix<T>& operator+= (const Matrix<T> &x);
  Matrix<T>& operator-= (const double &x);
  Matrix<T>& operator-= (const Matrix<T> &x);
  Matrix<T>& operator*= (const double &x);
  Matrix<T>& operator*= (const Matrix<T> &x);
  bool operator== (const Matrix<T>& x) const;
  bool operator!= (const Matrix<T>& x) const;
  friend std::istream& operator>> (std::istream& stream, Matrix<T>& x);
  friend std::ostream& operator<< (std::ostream& stream, const Matrix<T>& x);

  ~Matrix();

public:
  int height, width;
  T* data;
};