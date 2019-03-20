#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<string> SplitIntoWords(const string& s) {
  vector<string> v = {};
  auto it = s.begin();
  while (it != s.end()) {
    auto temp_it = find(it, s.end(), ' ');
    v.push_back( { it, temp_it } );
    it = temp_it;
    if (it != s.end()) ++it;
  }
  return v;
}
void print(const vector<int>& v) {
  for (const auto& i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> v = { 1, 2, 3, 4, 5 };
  set<int> s;
  
  
  is_permutation(s.begin(), s.end(), v.begin());
  is_permutation(v.begin(), v.end(), v.begin());
  partial_sum(s.begin(), s.end(), back_inserter(v));
  partial_sum(s.begin(), s.end(), v.begin());
  /*string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  */
  return 0;
}