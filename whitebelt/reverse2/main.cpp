#include <iostream>
#include "reversed.h"

int main()
{
	vector<int> numbers = {1, 5, 3, 4, 2};
	vector<int> rev     = Reversed(numbers);
	for (auto i : rev)
		cout << i;

	return 0;
}
