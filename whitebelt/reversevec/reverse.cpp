//#include "reverse.h"

#include <vector>
using namespace std;

void Reverse(vector<int> &v)
{
	vector<int> temp;

	for (int i = v.size() - 1; i >= 0; --i)
		temp.push_back(v[i]);

	v = temp;
}
