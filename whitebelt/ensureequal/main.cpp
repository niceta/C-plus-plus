#include <iostream>
#include <exception>

using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		throw runtime_error(left + " != " + right);
	}
}

/*int main ()
{
	try {
		EnsureEqual("left", "lef");
	}
	catch (exception &ex) {
		cout << ex.what() << endl;
	}
	return 0;
}*/
