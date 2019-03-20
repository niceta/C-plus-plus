#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <exception>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
// –еализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	Date() {};
	Date(int y, int m, int d) { 
		_year = y;
		_month = m;
		_day = d;
	}
	int GetYear()  const { return _year;  }
	int GetMonth() const { return _month; }
	int GetDay()   const { return _day;   }
	void SetYear(int y)  { _year = y;     }
	void SetMonth(int m) { _month = m;    }
	void SetDay(int d)	 { _day = d;      }
private:
	int _year;
	int _month;
	int _day;
};

void EnsureNextSymbolAndSkip(stringstream &stream, const string &s) {
	if (stream.peek() != '-') {
		throw runtime_error("Wrong date format: " + s);
	}
	stream.ignore(1);
}

Date ParseDate(const string &s) {
	stringstream stream(s);
	int y, m, d;
	string tail;

	stream >> y; 
	if (y < 0 || y > 9999) {
		throw runtime_error("Wrong date format: " + s);
	}
	EnsureNextSymbolAndSkip(stream, s);
	
	stream >> m;
	if (m < 1 || m > 12) {
		throw runtime_error("Month value is invalid: " + to_string(m));
	}
	EnsureNextSymbolAndSkip(stream, s);

	stream >> d;
	if (d < 1 || d > 31) {
		throw runtime_error("Day value is invalid: " + to_string(d));
	}

	stream >> tail;
	if (tail != "") {
		throw runtime_error("Wrong date format: " + s);
	}

	return { y, m, d };
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == lhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		}
		else {
			return lhs.GetMonth() < rhs.GetMonth();
		}
	}
	else {
		return lhs.GetYear() < rhs.GetYear();
	}
}

ostream& operator<<(ostream &stream, const Date &date) {
	stream << setw(4) << setfill('0') << date.GetYear()  << '-';
	stream << setw(2) << setfill('0') << date.GetMonth() << '-';
	stream << setw(2) << setfill('0') << date.GetDay();

	return stream;
}

istream& operator>>(istream &stream, Date &date) {
	string	sDate;
	
	stream >> sDate; 
	
	date = ParseDate(sDate);
	return stream;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (data.count(date) > 0 && data.at(date).count(event) > 0) {
			data.at(date).erase(event);
			return true;
		}
		else {
			return false;
		}
	}
	int  DeleteDate(const Date& date) {
		if (data.count(date) > 0) {
			const int res = data.at(date).size();
			data.at(date).clear();
			return res;
		}
		else {
			return 0;
		}
	}

	set<string>/* ??? */ Find(const Date& date) const {
		set<string> result;
		if (data.count(date) > 0) {
			result = data.at(date);
		}
		return result;
	}

	void Print() const {
		for (const auto &item : data) {
			for (const auto &event : item.second) {
				cout << item.first << ' ' << event << endl;
			}
		}
	}
private:
	map<Date, set<string>> data;
};

int main() {
	Database db;

	string command;
	// —читайте команды с потока ввода и обработайте каждую
	while (getline(cin, command)) {
		stringstream stream(command);
		string code;
		stream >> code;
		if (code == "Add") {
			Date date;
			string event;
			try {
				stream >> date >> event;
				if (event == "")
					return 0;
			}
			catch (exception &ex) {
				cout << ex.what() << endl;
				continue;
			}

			db.AddEvent(date, event);
		}

		else if (code == "Del") {
			Date date;
			string event;
			try {
				stream >> date >> event;
				if (event != "") {
					if (db.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					}
					else {
						cout << "Event not found" << endl;
					}
				}
				else {
					int n = db.DeleteDate(date);
					cout << "Deleted " << n << " events" << endl;
				}
			}
			catch (exception &ex) {
				cout << ex.what() << endl;
				continue;
			}
		}

		else if (code == "Find") {
			Date date;
			try {
				stream >> date;
				set<string> events = db.Find(date);
				for (const auto &event : events) {
					cout << event << endl;
				}
			} 
			catch (exception &ex) {
				cout << ex.what() << endl;
			}
		}

		else if (code == "Print") {
			db.Print();
		}
		else if (code != "") {
			cout << "Unknown command: " << code << endl;
		}
	}

	return 0;
}