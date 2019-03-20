#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
/*
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
  auto it_begin = lower_bound(range_begin, range_end, prefix, 
    [] (const string& l, char c) { return l[0] < c; });
  auto it_end = lower_bound(range_begin, range_end, static_cast<char>(prefix + 1),
    [] (const string& l, char c) { return l[0] < c; });
  return make_pair(it_begin, it_end);
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
  auto it_begin = lower_bound(range_begin, range_end, prefix,
    [] (const string& l, const string& r) { return l < r; });
  string s = prefix;
  size_t i = s.size() - 1;
  s[i]++;
  
  auto it_end = lower_bound(range_begin, range_end, s,
    [] (const string& l, const string& r) { return l < r; });
  return make_pair(it_begin, it_end);
}
*/
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
  RandomIt range_begin, RandomIt range_end, char prefix) {

  // ��� ������, ������������ � '<prefix>', ������ ��� ����� ������ "<prefix>"
  auto left = lower_bound(range_begin, range_end, string(1, prefix));

  // �������� ��������� � �������� ������.
  // �� �������, ���� prefix = 'z':
  // � ���� ������ �� ������� ��������� �� 'z' ������ � ������� ��������
  char next_prefix = static_cast<char>(prefix + 1);

  // ������ "<next_prefix>" � ������ ��������� �����
  // �������� ������ ������� ������
  // ��������� �����, ����������� � '<prefix>'
  auto right = lower_bound(range_begin, range_end, string(1, next_prefix));

  return { left, right };
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
  RandomIt range_begin, RandomIt range_end, string prefix) {

  // ��� ������, ������������ � prefix, ������ ��� ����� ������ "<prefix>"
  auto left = lower_bound(range_begin, range_end, prefix);

  // �������� ������, ������� � ������ ��������� ����� ��������
  // ������ ������� ������ ��������� �����, ������������ � prefix
  string upper_bound = prefix;
  ++upper_bound[upper_bound.size() - 1];

  // ������ ����������� �����, �� ������� upper_bound,
  // ����������� �������� ������ �������������
  auto right = lower_bound(range_begin, range_end, upper_bound);

  return { left, right };
}
int main() {
  const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

  const auto mo_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
  for (auto it = mo_result.first; it != mo_result.second; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  const auto mt_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
  cout << (mt_result.first - begin(sorted_strings)) << " " <<
    (mt_result.second - begin(sorted_strings)) << endl;

  const auto na_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
  cout << (na_result.first - begin(sorted_strings)) << " " <<
    (na_result.second - begin(sorted_strings)) << endl;

  return 0;
}