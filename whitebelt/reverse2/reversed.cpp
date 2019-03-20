//#include "reversed.h"
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int> &v)
{
	int n = v.size();
	vector<int> result = v;

	for (int i = 0; i < n / 2; ++i)
	{
		int temp  = result[i];
		result[i] = result[n - 1 - i];
		result[n - 1 - i] = temp;
	}

	return result;
}
