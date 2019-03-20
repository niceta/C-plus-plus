#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int main ()
{
	int n, numLine;
	cin >> n;
	map<vector<string>, int> busLines;

	numLine = 1;
	for (int i = 1; i <= n; ++i)
	{
		int stopsCount;
		cin >> stopsCount;

		//vector<string> &stops = busLines[i];
		vector<string> stops;
		stops.resize(stopsCount);

		for(auto &item : stops)
			cin >> item;

		if(busLines.count(stops) > 0)
		{
			cout << "Already exists for " << busLines[stops] << endl;
		}
		else
		{
			busLines[stops] = numLine;
			cout << "New bus " <<  numLine++ << endl;
		}
	}

	return 0;
}
