#include "lecturetitle.h"

int main ()
{
	LectureTitle title("C++", "White belt", "4th");

	LectureTitle title1 = {"C++", "White belt", "4th"};

	LectureTitle title2 = {{"C++"}, {"White belt"}, {"4th"}};

	LectureTitle title3(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);

	return 0;
}
