#include "date.h"

Date::Date(int y, int m, int d) 
    : d_(d), m_(m), y_(y) {}

int Date::getDay() const {
  return d_;
}

int Date::getMonth() const {
  return m_;
}

int Date::getYear() const {
  return y_;
}
// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs) {
  int y = lhs.getYear();
  int m = lhs.getMonth();
  int d = lhs.getDay();

  int y2 = rhs.getYear();
  int m2 = rhs.getMonth();
  int d2 = rhs.getDay();
  return std::tie(y, m, d) < std::tie(y2, m2, d2);
}

std::ostream& operator<<(std::ostream& stream, const Date& date) {
  stream << std::setw(4) << std::setfill('0') << date.getYear() <<
    "-" << std::setw(2) << std::setfill('0') << date.getMonth() <<
    "-" << std::setw(2) << std::setfill('0') << date.getDay();
  return stream;
}

Date ParseDate(std::istream& date_stream) {
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);
  ok = ok && (date_stream.peek() == '-');
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);
  ok = ok && date_stream.eof();

  date_stream.ignore(1);

  return Date(year, month, day);
}

bool operator==(const Date & lhs, const Date & rhs) {
  int y = lhs.getYear();
  int m = lhs.getMonth();
  int d = lhs.getDay();
  int y2 = rhs.getYear();
  int m2 = rhs.getMonth();
  int d2 = rhs.getDay();
  return std::tie(y, m, d) == std::tie(y2, m2, d2);
}
