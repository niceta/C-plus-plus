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
	  if (personHistory.count(year) == 0)
	  {
		  bool isLess = true;
		  for (const auto& i : personHistory)
			  if (year > i.first)
			  {
				  isLess = false;
				  break;
			  }

		  if (isLess)
			  return "Incognito";
		  else
		  {
			  string firstName = getLastFirstName(year);
			  string lastName  = getLastLastName(year);

			  if (firstName == "" && lastName != "")
				  return lastName + " with unknown first name";
			  if (lastName == "" && firstName != "")
				  return firstName + " with unknown last name";
		  }
	  }
	  else
	  {
		  if (personHistory[year].first_name != "" && personHistory[year].last_name != "")
			  return personHistory[year].first_name + " " + personHistory[year].last_name;

		  if (personHistory[year].first_name == "")
		  {
			  personHistory[year].first_name = getLastFirstName(year);
			  if (personHistory[year].first_name == "")
				  return personHistory[year].last_name + " with unknown first name";
		  }
		  else if (personHistory[year].last_name == "")
		  {
			  personHistory[year].last_name = getLastLastName(year);
			  if (personHistory[year].last_name == "")
			  				  return personHistory[year].first_name + " with unknown last name";
		  }
	  }
  }
private:
  // ��������� ����
  string getLastFirstName(int year) {
	  string result;
	  for (const auto &i : personHistory)
	  {
		  if (i.second.first_name != "")
			  result = i.second.first_name;
		  if (i.first >= year)
		  {
			  personHistory[year].first_name = result;
			  break;
		  }
	  }
	  return result;
  }

  string getLastLastName(int year) {
	  string result;
	  	  for (const auto &i : personHistory)
	  	  {
	  		  if (i.second.last_name != "")
	  		  	  result = i.second.last_name;
	  		  if (i.first >= year)
	  		  {
	  			  personHistory[year].last_name = result;
	  			  break;
	  		  }
	  	  }
	  	  return result;
  }

  map<int, personData> personHistory;
};
