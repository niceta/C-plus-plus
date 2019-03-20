#include <vector>
#include <string>
#include <map>

using namespace std;

class Person {
public:
	Person(const string &fname, const string &lname, int yb) {
		first_names[yb] = fname;
		last_names[yb] = lname;
		_year_of_birth = yb;
	}
	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		//personHistory[year].first_name = first_name;
		if (year < _year_of_birth)
			return;
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		//personHistory[year].last_name = last_name;
		if (year < _year_of_birth)
			return;
		last_names[year] = last_name;
	}
	string GetFullName(int year) const {
		// получить имя и фамилию по состоянию на конец года year
		if (year < _year_of_birth)
			return "No person";

		string first_name = GetNameByYear(first_names, year);
		string last_name = GetNameByYear(last_names, year);

		string result = first_name + " " + last_name;

		if (first_name == "" && last_name == "")
			result = "Incognito";
		else if (first_name == "")
			result = last_name + " with unknown first name";
		else if (last_name == "")
			result = first_name + " with unknown last name";

		return result;
	}
	string GetFullNameWithHistory (int year) const {
		// получить все имена и фамилии по состоянию на конец года year
		if (year < _year_of_birth)
			return "No person";

		string result = "";

		vector<string> resVecFNames = GetHistoryByYear(first_names, year);
		vector<string> resVecLNames = GetHistoryByYear(last_names, year);

		if (resVecFNames.size() == 0 && resVecLNames.size() == 0)
			result = "Incognito";
		else if (resVecFNames.size() == 0) {
			result += resVecLNames[0];
			MakeResultString(resVecLNames, result);
			result += " with unknown first name";
		}
		else if (resVecLNames.size() == 0) {
			result += resVecFNames[0];
			MakeResultString(resVecFNames, result);
			result += " with unknown last name";
		}
		else {
			result = resVecFNames[0];
			MakeResultString(resVecFNames, result);

			result += " " + resVecLNames[0];
			MakeResultString(resVecLNames, result);
		}

		return result;
	}
private:
	// приватные поля
	//map<int, personData> personHistory;

	string GetNameByYear(const map<int, string> &names, int year) const {
		string result = "";

		for (const auto &i : names) {
			if (i.first <= year)
				result = i.second;
			else
				break;
		}

		return result;
	}

	vector<string> GetHistoryByYear(const map<int, string> &names, int year) const {
		vector<string> temp;
		temp.push_back("");
		int i = 0;
		for (const auto &item : names) {
			if (item.first <= year && item.second != temp[i]) {
				temp.push_back(item.second);
				++i;
			}
			else
				break;
		}

		vector<string> result;
		for (int j = temp.size() - 1; j > 0; --j)
			result.push_back(temp[j]);

		return result;
	}

	void MakeResultString(const vector<string> &names, string &result) const {
		if (names.size() > 1)
			result += " (";
		else if (names.size() == 1) {
			//result += " ";
			return;
		}

		for (size_t i = 1; i < names.size(); ++i) {
			if (i != names.size() - 1)
				result += names[i] + ", ";
			else
				result += names[i] + ")";
		}
	}
	map<int, string> first_names;
	map<int, string> last_names;

	int _year_of_birth;
};