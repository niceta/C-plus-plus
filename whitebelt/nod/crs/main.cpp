#include <iostream>
using namespace std;

int main ()
{
	int a, b;

	cin >> a >> b;

	if (a <= 0 || b <= 0)
		return 0;

	if (a == b)
	{
		cout << a;
		return 0;
	}

	int min, max;

	if (a < b)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}

	for (int i = min; i > 0; --i)
	{
		if (max % i == 0 && min % i == 0)
		{
			cout << i;
			break;
		}
	}


	return 0;
}
