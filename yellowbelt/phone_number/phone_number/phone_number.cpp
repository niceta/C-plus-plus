#include "phone_number.h"
#include <sstream>
#include <exception>
#include <algorithm>
/*
size_t find_defis(const string& s) {
  size_t i = s.find('-');
  if (i == string::npos) {
    throw invalid_argument("wrong format: can't find the first '-'!");
  }
  return i;
}
*/

PhoneNumber::PhoneNumber(const string & international_number)
{
  istringstream is(international_number);

  char sign = is.get();
  getline(is, country_code_, '-');
  getline(is, city_code_, '-');
  getline(is, local_number_);

  if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
    throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + international_number);
  }
  /*
  if (international_number[0] != '+') {
    throw invalid_argument("first symbol is not '+'!");
  }

  size_t index_first = find_defis(international_number);

  country_code_ = international_number.substr(1, index_first - 1);
  if (country_code_.empty()) {
    throw invalid_argument("wrong format: country code is empty");
  }

  string city_string = international_number.substr(index_first + 1);
  size_t index_second = find_defis(city_string);

  city_code_ = city_string.substr(0, index_second);
  if (city_code_.empty()) {
    throw invalid_argument("wrong format: city code is empty");
  }

  local_number_ = city_string.substr(index_second + 1);
  if (local_number_.empty()) {
    throw invalid_argument("wrong format: local number is empty");
  }*/
}

string PhoneNumber::GetCountryCode() const
{
  return country_code_;
}

string PhoneNumber::GetCityCode() const
{
  return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
  return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
  string result = "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
  return result;
}
