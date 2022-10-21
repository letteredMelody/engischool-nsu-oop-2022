#include <iostream>
#include "Date.h"

constexpr int Date::amount[12];
constexpr char Date::stringMonth[12][4];

bool isLeap (int year)
{
  return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

Date:: Date()
  : day(1), month(0), year(0)
{
}

Date:: Date(const std::string &x)
  : Date()
{
  int m;
  std::stringstream(x) >> day >> m >> year;
  month = m - 1;
}

Date:: Date(const int &x, const int &y, const int &z)
  : day(x), month(y - 1), year(z)
{
}

Date:: Date(const Date& x)
  : day(x.day), month(x.month), year(x.year)
{
}

Date Date::operator+ (const int& x) const
{
  Date temp = *this;
  temp += x;

  return temp;
}

Date Date::operator- (const int& x) const
{
  Date temp = *this;
  temp -= x;

  return temp;
}

Date& Date::operator+= (const int& x) 
{

  int days = day + x, months = month, years = year;
  
  for (; days > amount[months] + (isLeap(years) && months == 1); months = (months + 1) % 12)
  {
    if (months == 11)
    {
      years += 1;
    }
    days -= amount[months] + (isLeap(years) && months == 1);
  }
  
  return *this;
}

Date& Date::operator-= (const int& x)
{
  int days = day - x, months = month, years = year;
  
  for (months = (12 + months - 1) % 12; days <= 0; months = (12 + months - 1) % 12)
  {
    if (months == 11)
    {
      years -= 1;
    }
    days += amount[months] + (isLeap(years) && months == 1);
  }

  return *this;
}

Date& Date::operator++ ()
{
  *this += 1;

  return *this;
}

Date Date::operator++ (int)
{
  Date temp = *this;

  ++*this;

  return temp;
}

Date& Date::operator-- ()
{
  *this -= 1;

  return *this;
}

Date Date::operator-- (int)
{
  Date temp = *this;

  --*this;

  return temp;
}

bool Date::operator== (const Date& x) const
{
  return day == x.day && month == x.month && year == x.year;
}

bool Date::operator!= (const Date& x) const
{
  return !(*this == x);
}

bool Date::operator< (const Date& x) const
{
  return year < x.year || month < x.month || day < x.day;
}

bool Date::operator> (const Date& x) const
{
  return *this != x && !(*this < x);
}

bool Date::operator<= (const Date& x) const
{
  return !(*this > x);
}

bool Date::operator>= (const Date& x) const
{
  return !(*this < x);
}

std::istream& operator>> (std::istream& stream, Date& x)
{
  int month;
  stream >> x.day >> month >> x.year;
  x.month = month - 1;

  return stream;
}

std::ostream& operator<< (std::ostream& stream, const Date& x)
{
  stream << x.day << ' ' << x.month + 1 << ' ' << x.year;
  
  return stream;
}

void Date::PrintString (const Date& x)
{
  std::cout << x.day << ' ' << stringMonth[x.month] << ' ' << x.year;
}
