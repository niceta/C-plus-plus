#include <iostream>
#include <map>
#include <string>

using namespace std;

string BuildCharCounters(const string& w1, const string& w2)
{
	map<char, int> m1, m2;

	for (auto &c : w1)
		++m1[c];
	for (auto &c : w2)
		++m2[c];

	if (m1 == m2)
		return "YES";
	else
		return "NO";
}

int main ()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string w1, w2;
		cin >> w1 >> w2;

		cout << BuildCharCounters(w1, w2) << endl;
	}

	return 0;
}
