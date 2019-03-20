#include <iostream>
#include <vector>

using namespace std;

int getMean(const vector<int> &v)
{
	int res = 0;

	for (auto i : v)
	{
		res+= i;
	}

	res /= v.size();

	return res;
}

int main()
{
	int n;

	cin >> n;
	vector<int> temperature(n);

	for (auto &i : temperature)
	{
		cin >> i;
	}

	int mean = getMean(temperature);
	vector<int> result;

	for (size_t i = 0; i < temperature.size(); ++i)
	{
		if (temperature[i] > mean)
			result.push_back(i);
	}

	cout << result.size() << endl;

	for(auto i : result)
	{
		cout << i << " ";
	}

	return 0;
}