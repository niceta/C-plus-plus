#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	return 0;
}