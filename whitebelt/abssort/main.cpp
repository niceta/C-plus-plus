#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print (const vector<int> &v)
{
	for (const auto &i : v)
		cout << i << " ";
}

int main ()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (auto& i : v)
		cin >> i;

	sort(begin(v), end(v), [](int x,  int y) {
							  return abs(x) < abs(y); });

	print(v);

	return 0;
}
