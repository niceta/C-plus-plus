#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{
	const string inpath = "input.txt";
	const string outpath = "output.txt";

	ifstream input(inpath);

	if (input.is_open()) {
		string line;
		ofstream output(outpath);
		while (getline(input, line)) {
			output << line << endl;
		}
	}

	return 0;
}
