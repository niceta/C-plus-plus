#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int n;

	cin >> n;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	vector<int> temp;//, bin;

	int k;
	while (n > 1)
	{
		k = n % 2;
		n = n / 2;

		temp.push_back(k);
	}

	temp.push_back(1);

	for (int i = temp.size() - 1; i >= 0; --i)
		cout << temp[i];

	return 0;
}
