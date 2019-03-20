#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{
	ifstream input("input.txt");

	if (input.is_open()) {
		int numrows;
		int numcols;
		input >> numrows >> numcols;
		for (int i = 0; i < numrows; ++i) {
			int temp;
			const int w = 10;
			for (int j = 0; j < numcols - 1; ++j) {
				input >> temp;
				input.ignore(1);
				cout << setw(w) << temp << ' ';
			}
			input >> temp;
			cout << setw(w) << temp;
			if (i != numrows - 1)
				cout << endl;
		}
	}
	return 0;
}
