#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> busesForStop(const vector<string> &v, map<string, vector<string>> m,
							const string &value)
{
	vector<string> result;

	for(const string &item : v)
	{
		int num = count(m[item].begin(), m[item].end(), value);
		if (num > 0)
			result.push_back(item);
	}

	return result;
}

void printVec (const vector<string> &v)
{
	for (const auto &i : v)
		cout << i << " ";
}

int main()
{
	int n;
	cin >> n;

	map<string, vector<string>> busesMap;
	vector<string>				busesVec;

	for (int i = 0; i < n; ++i)
	{
		string command;
		cin >> command;

		if (command == "NEW_BUS")
		{
			string busName;
			int    stopCount;
			vector<string> stops;

			cin >> busName >> stopCount;

			string stopName;
			for (int j = 0; j < stopCount; ++j)
			{
				cin >> stopName;
				stops.push_back(stopName);
			}

			busesMap[busName] = stops;
			busesVec.push_back(busName);
		}

		if (command == "BUSES_FOR_STOP")
		{
			string stopName;
			cin >> stopName;

			vector<string> res;

			res = busesForStop(busesVec, busesMap, stopName);

			if(res.size() > 0)
				printVec(res);
			else
				cout << "No stop";

			cout << endl;
		}

		if (command == "STOPS_FOR_BUS")
		{
			string busName;
			cin >> busName;

			if (busesMap.count(busName) > 0)
			{
				for (const auto &s : busesMap[busName])
				{
					vector<string> res = busesForStop(busesVec, busesMap, s);
					if (res.size() > 0)
					{
						cout << "Stop " << s << ": ";
						if (res.size() > 1)
							for (const auto &item : res)
							{
								if (item != busName)
									cout << item << " ";
							}
						else
							cout << "no interchange";

						cout << endl;
					}
				}
			}
			else
				cout << "No bus" << endl;
		}

		if (command == "ALL_BUSES")
		{
			if (busesMap.size() > 0)
			{
				for (const auto &s : busesMap)
				{
					cout << "Bus " << s.first << ": ";
					for (const auto &item : s.second)
						cout << item << " ";

					cout << endl;
				}
			}
			else
				cout << "No buses" << endl;
		}
	}

	return 0;
}
