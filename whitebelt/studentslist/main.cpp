#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct student {
	string fname;
	string lname;

	int day;
	int month;
	int year;
};

int main ()
{
	int studentsNum;
	cin >> studentsNum;

	vector<student> students(studentsNum);

	for (auto &s : students) {
		cin >> s.fname;
		cin >> s.lname;
		cin >> s.day;
		cin >> s.month;
		cin >> s.year;
	}

	int numReq;
	cin >> numReq;

	for (int i = 0; i < numReq; ++i) {
		string command;
		int K;
		cin >> command >> K;

		if (command == "name" && K > 0 && K <= studentsNum) {
			cout << students[K - 1].fname << ' ' << students[K - 1].lname << endl;
		}
		else if (command == "date" && K > 0 && K <= studentsNum) {
			cout << students[K - 1].day << '.' << students[K - 1].month << '.' <<
					students[K - 1].year << endl;
		}
		else
			cout << "bad request" << endl;
	}

	return 0;
}
