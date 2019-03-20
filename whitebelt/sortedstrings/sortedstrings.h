#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
	  stringsVec.push_back(s);
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
	  sort(begin(stringsVec), end(stringsVec));

	  return stringsVec;
  }
private:
  // приватные поля
  vector<string> stringsVec;
};
