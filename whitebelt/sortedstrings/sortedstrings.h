#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    // �������� ������ s � �����
	  stringsVec.push_back(s);
  }
  vector<string> GetSortedStrings() {
    // �������� ����� �� ���� ����������� ����� � ��������������� �������
	  sort(begin(stringsVec), end(stringsVec));

	  return stringsVec;
  }
private:
  // ��������� ����
  vector<string> stringsVec;
};
