#pragma once
#include <stdexcept>
#include <string>
#include <tuple>
#include <iostream>
#include <iomanip>
#include <sstream>

class Date {
public:
  Date(int y, int m, int d);
  int getDay() const;
  int getMonth() const;
  int getYear() const;
private:
  int y_;
  int m_;
  int d_;
};

bool operator==(const Date& lhs, const Date& rhs);
bool operator<(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);

Date ParseDate(std::istream& date_stream);