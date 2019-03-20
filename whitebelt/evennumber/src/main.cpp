#include <iostream>

using namespace std;

int main ()
{
	int A, B;

	cin >> A >> B;
	if (A <= B && A >= 1)
	{
		for (int i = A; i <= B; i++)
			{
				if (i % 2 == 0)
					cout << i << " ";
			}
	}

	return 0;
}
