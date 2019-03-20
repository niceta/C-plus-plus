#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
  auto negative = find_if(numbers.begin(), numbers.end(),
    [] (int n) { return n < 0; });
  if (negative != numbers.end()) {
    auto it = negative;
    while (it != numbers.begin()) {
      --it;
      cout << *it << " ";
    }
  }
  else {
    for (auto it = numbers.rbegin(); it != numbers.rend(); it++) {
      cout << *it << " ";
    }
  }
  cout << endl;
}

int main() {
  PrintVectorPart({ 6, 1, 8, -5, 4 });
  PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
  PrintVectorPart({ 6, 1, 8, 5, 4 });
  return 0;
}