#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
void print(const vector<int>& v) {
  for (const int& i : v) {
    cout << i << " ";
  }
}

int main() {
  int range_length;
  cin >> range_length;
  vector<int> permutation(range_length);

  // iota             -> http://ru.cppreference.com/w/cpp/algorithm/iota
  // «аполн€ет диапазон последовательно возрастающими значени€ми
  iota(permutation.begin(), permutation.end(), 1);

  // reverse          -> http://ru.cppreference.com/w/cpp/algorithm/reverse
  // ћен€ет пор€док следовани€ элементов в диапазоне на противоположный
  reverse(permutation.begin(), permutation.end());

  // prev_permutation ->
  //     http://ru.cppreference.com/w/cpp/algorithm/prev_permutation
  // ѕреобразует диапазон в предыдущую (лексикографически) перестановку,
  // если она существует, и возвращает true,
  // иначе (если не существует) - в последнюю (наибольшую) и возвращает false
  do {
    for (int num : permutation) {
      cout << num << ' ';
    }
    cout << endl;
  } while (prev_permutation(permutation.begin(), permutation.end()));

  return 0;
  //int n; 
  //cin >> n;
  //vector<int> v;
  //for (int i = 1; i <= n; ++i) {
  //  v.push_back(i);
  //}
  //sort(v.rbegin(), v.rend());
  //print(v);
  //cout << endl;
  //while (prev_permutation(v.begin(), v.end())) {
  //  print(v);
  //  cout << endl;
  //}

  //return 0;
}