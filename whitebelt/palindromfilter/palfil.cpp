#include <string>
#include <vector>

using namespace std;
//#include "palfil.h"

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


vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> newVec;

	for (auto w : words)
	{
		if (IsPalindrom(w) && w.size() >= minLength)
			newVec.push_back(w);
	}

	return newVec;
}
