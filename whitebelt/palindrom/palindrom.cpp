#include <string>
using namespace std;
#include "palindrom.h"

bool IsPalindrom(string s)
{
	int j = s.size() - 1;

	for (int i = 0; i <= j; ++i)
	{
		if (s[i] == s[j])
			--j;
		else
			return false;
	}

	return true;
}



