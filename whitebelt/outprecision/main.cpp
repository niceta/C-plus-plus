#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	const string path = "input.txt";

	ifstream input(path);

	if (input.is_open())
	{
		string line;
		cout << fixed << setprecision(3);

		while (!input.eof())
		{
			int numlines;
			int numcols;
			input >> numlines;
			input >> numcols;
			cout << numlines << numcols;
		}
	}
	return 0;
}
