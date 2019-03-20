#include <iostream>
#include <set>
#include <string>

using namespace std;

int main ()
{
	set<string> uniqeStrings;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		uniqeStrings.insert(s);
	}

	cout << uniqeStrings.size();
	return 0;
}
