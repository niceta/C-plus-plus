#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, string> capitals;

	string c, cc;

	cin >> c >> cc;

	if (capitals.count(c) && capitals[c] == cc)
		cout << capitals.size();
	else
		cout << capitals.size();

	return 0;
}