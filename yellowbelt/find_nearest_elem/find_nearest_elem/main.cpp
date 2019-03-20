#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
  auto first_not_less = lower_bound(numbers.begin(), numbers.end(), border);
  if (first_not_less == numbers.begin()) {
    return first_not_less;
  }
  auto last_less = prev(first_not_less);
  if (first_not_less == numbers.end()) {
    return last_less;
  }

  bool is_less = (border - *last_less <= *first_not_less - border);
  return is_less ? last_less : first_not_less;
}

int main() {
  set<int> numbers = { 1, 4, 6 };
  cout <<
    *FindNearestElement(numbers, 0) << " " <<
    *FindNearestElement(numbers, 3) << " " <<
    *FindNearestElement(numbers, 5) << " " <<
    *FindNearestElement(numbers, 6) << " " <<
    *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}