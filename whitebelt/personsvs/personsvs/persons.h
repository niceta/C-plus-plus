#include <vector>
#include <string>
#include <map>

using namespace std;

struct personData
{
	string first_name;
	string last_name;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		// �������� ���� ��������� ����� �� first_name � ��� year
		personHistory[year].first_name = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		// �������� ���� ��������� ������� �� last_name � ��� year
		personHistory[year].last_name = last_name;
	}
	string GetFullName(int year) {
		// �������� ��� � ������� �� ��������� �� ����� ���� year
		string first_name = "";
		string last_name  = "";

		for (const auto &item : personHistory) {
			if (year < item.first)
				break;

			if (item.second.first_name != "")
				first_name = item.second.first_name;
			if (item.second.last_name != "")
				last_name = item.second.last_name;
			//if (item.first >= year)
				//break;
		}

		string result = first_name + " " + last_name;
		if (first_name == "" && last_name == "")
			result = "Incognito";
		else if (first_name == "")
			result = last_name + " with unknown first name";
		else if (last_name == "")
			result = first_name + " with unknown last name";

		return result;
	}
private:
	// ��������� ����
	map<int, personData> personHistory;
};