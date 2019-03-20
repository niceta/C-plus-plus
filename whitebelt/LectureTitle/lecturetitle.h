#include <string>
using namespace std;

struct Week {
	explicit Week (string w) {
		value = w;
	}

	string value;
};
struct Course {
	explicit Course (string c) {
		value = c;
	}

	string value;
};
struct Specialization {
	explicit Specialization (string s) {
		value = s;
	}

	string value;
};

struct LectureTitle {
	LectureTitle(Specialization s, Course c, Week w) {
		specialization = s.value;
		course = c.value;
		week = w.value;
	}

	string specialization;
	string course;
	string week;
};
