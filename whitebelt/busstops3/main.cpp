#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<set<string>, int> busLines;
	int num, numLine;

	cin >> num;
	numLine = 1;

	for (int i = 0; i < num; ++i)
	{
		int numStops;
		cin >> numStops;

		set<string> stopsSet;
		string stop;
		for(int j = 0; j < numStops; ++j)
		{
			cin >> stop;
			stopsSet.insert(stop);
		}

		if (busLines.count(stopsSet) > 0)
			cout << "Already exists for " << busLines[stopsSet] << endl;
		else
		{
			busLines[stopsSet] = numLine;
			cout << "New bus " << numLine++ << endl;;
		}
	}
	return 0;
}
