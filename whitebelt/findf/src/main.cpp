#include <iostream>
#include <string>

using namespace std;

int main ()
{
	string str;

	cin >> str;

	int count = 0;
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		if (str[i] == 'f')
			count++;

		if (count == 2)
		{
			cout << i;
			break;
		}
	}

	if (count == 1)
		cout << -1;

	if (count == 0)
		cout << -2;

	return 0;
}
