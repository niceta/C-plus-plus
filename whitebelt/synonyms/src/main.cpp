#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main ()
{
	map<string, set<string>> synonyms;
	int numReq;
	string w, w1, w2;
	
	cin >> numReq;

	for (int i = 0; i < numReq; ++i)
	{
		string command;
		cin >> command;

		if (command == "ADD")
		{
			cin >> w1 >> w2;

			if (synonyms.count(w1) == 0)
			{
				set<string> s1;

				s1.insert(w2);
				synonyms[w1] = s1;
			}
			else
				synonyms[w1].insert(w2);

			if (synonyms.count(w2) == 0)
			{
				set<string> s2;

				s2.insert(w1);
				synonyms[w2] = s2;
			}
			else
				synonyms[w2].insert(w1);
		}

		if (command == "CHECK")
		{
			cin >> w1 >> w2;

			if (synonyms[w1].count(w2) > 0 || synonyms[w2].count(w1) > 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}

		if (command == "COUNT")
		{
			cin >> w;

			cout << synonyms[w].size() << endl;
		}

	}
	return 0;
}
