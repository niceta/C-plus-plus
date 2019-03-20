#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(const map<string, string> &m)
{
	for (const auto &x : m)
	{
		cout << x.first << "/" << x.second << " ";
	}
	cout << endl;
}

int main()
{
	int numReq;
	cin >> numReq;

	map<string, string> capitals;

	for (int i = 0; i < numReq; ++i)
	{
		string code;

		cin >> code;

		if (code == "CHANGE_CAPITAL")
		{
			string country, capital;

			cin >> country >> capital;

			if (capitals.count(country) > 0 && capitals[country] == capital)
			{
				cout << "Country " << country
					 << " hasn't changed its capital" << endl;
			}
			else
			{
				if (capitals.count(country) == 0)
					cout << "Introduce new country " << country
						 << " with capital " << capital << endl;
				else
					cout << "Country " << country << " has changed its capital from "
					     << capitals[country] << " to " << capital << endl;

				capitals[country] = capital;
			}
		}

		if (code == "RENAME")
		{
			string newName, oldName;

			cin >> oldName >> newName;

			if (capitals.count(oldName) > 0 && (newName != oldName) &&
			   (capitals.count(newName) == 0))
			{
				string oldCapital = capitals[oldName];
				capitals.erase(oldName);
				capitals[newName] = oldCapital;

				cout << "Country " << oldName << " with capital "
					 << oldCapital << " has been renamed to " << newName << endl;
			}
			else
				cout << "Incorrect rename, skip" << endl;
		}

		if (code == "ABOUT")
		{
			string country;
			cin >> country;

			if (capitals.count(country) == 0)
				cout << "Country " << country << " doesn't exist" << endl;
			else
				cout << "Country " << country << " has capital "
				     << capitals[country] << endl;
		}

		if (code == "DUMP")
		{
			if (capitals.size() == 0)
				cout << "There are no countries in the world" << endl;
			else
				printMap(capitals);
		}
	}

	return 0;
}
