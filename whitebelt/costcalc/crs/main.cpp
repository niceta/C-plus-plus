#include <iostream>

using namespace std;

int main()
{
	double N, A, B, X, Y;

	cin >> N >> A >> B >> X >> Y;

	if (A < B)
	{
		if (N <= A)
		{
			cout << N;
			return 0;
		}

		if (N > A && N <= B)
		{
			N = N - N * X / 100;
		}
		else
		{
			N = N - N * Y / 100;
		}

		cout << N;
	}

	return 0;
}
