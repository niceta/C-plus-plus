#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print (const vector<string>& v)
{
	for (const auto &i : v)
		cout << i << " ";
}

string GetPositivity(int x) {
    return x > 0 ? "positive"
                 : (x == 0 ? "zero" : "negative");
}

int main ()
{
	//cout << GetPositivity(-5);

	int n;
	cin >> n;

	vector<string> v(n);

	for (auto &i : v)
		cin >> i;

	sort(begin(v), end(v), [](string x, string y) {
		for (auto &i : x)
			i = tolower(i);
		for (auto &i : y)
			i = tolower(i);
		return x < y;
	});

	print(v);
	return 0;
}
