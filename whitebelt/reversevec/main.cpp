#include <iostream>
#include "reverse.h"

int main()
{
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);

	for (auto i : numbers)
		cout << i;

	return 0;
}
