#include <iostream>
#include "movestring.h"

int main ()
{
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);

	for (auto i : destination)
		cout << i;

	return 0;
}
