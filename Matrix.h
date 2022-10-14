
template <typename T>
class Matrix
{
  public:
    Matrix()
      : height(2), width(2)
    {
    }

    Matrix(const int& y, const int& x)
      : height(y), width(x)
    {
    }

    Matrix(const Matrix& m)
      : height(m.height), width(m.width), data(m.data)
    {
    }

    Matrix operator+ (const int& x) const;
    Matrix operator+ (const Matrix& x) const;
    Matrix operator- (const int& x) const;
    Matrix operator- (const Matrix& x) const;
    Matrix operator* (const int& x) const;
    Matrix<double> operator* (const double& x) const;
    Matrix operator* (const Matrix& x) const;
    T* operator[] (const int& x) const;
    Matrix operator= (const Matrix& x);
    Matrix operator+= (const int& x); 
    Matrix operator+= (const Matrix& x);
    Matrix operator-= (const int& x);
    Matrix operator-= (const Matrix& x);
    Matrix operator*= (const int& x);
    Matrix<double> operator*= (const double& x);
    Matrix operator*= (const Matrix& x);
    bool operator== (const Matrix& x) const;
    bool operator!= (const Matrix& x) const;

  private:
    int height;
    int width;
    T* data = new T[height * width];
};