#include <string>
#include <sstream>

class Date
{
public:
  Date();
  Date(const std::string &x);
  Date(const int &x, const int &y, const int &z);
  Date(const Date& x);

  Date operator+ (const int& x) const;
  Date operator- (const int& x) const;
  Date& operator= (const Date& x) = default;
  Date& operator+= (const int& x);
  Date& operator-= (const int& x);
  Date& operator++ ();
  Date operator++ (int);
  Date& operator-- ();
  Date operator-- (int);
  bool operator== (const Date& x) const;
  bool operator!= (const Date& x) const;
  bool operator< (const Date& x) const;
  bool operator> (const Date& x) const;
  bool operator<= (const Date& x) const;
  bool operator>= (const Date& x) const;
  friend std::istream& operator>> (std::istream& stream, Date& x);
  friend std::ostream& operator<< (std::ostream& stream, const Date& x);

  static void PrintString (const Date& x);

private:
  int day, month, year;
  static constexpr int amount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  static constexpr char stringMonth[12][4] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "dec"};
};

