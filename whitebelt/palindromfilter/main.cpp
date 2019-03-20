#include <iostream>
#include "palfil.h"

int main ()
{
	vector<string> s = {"abacaba", "aba", "code"};

	vector<string> a = PalindromFilter(s, 5);

	for(auto x : a)
		cout << x;

	return 0;
}
