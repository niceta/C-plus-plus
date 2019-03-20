#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int old ()
{
  int reqCount;
  cin >> reqCount;

  map<string, set<string>> synonymsMap;

  for (int i = 0; i < reqCount; ++i)
  {
    string command;
	cin >> command;

	if (command == "ADD")
	{
	  string w1, w2;
	  cin >> w1 >> w2;

	  if (synonymsMap.count(w1) == 0)
	  {
	    set<string> temp;
	    temp.insert(w2);
	    synonymsMap[w1] = temp;
	  }
	  else
		synonymsMap[w1].insert(w2);
	}

	if (command == "COUNT")
	{
	  string w;
	  cin >> w;
	  if (synonymsMap.count(w) != 0)
	  {
		set<string> tempSet = synonymsMap[w];
	    for (const auto &x : synonymsMap)
	    {
	      if (x.second.count(w) > 0)
	      {
	        tempSet.insert(x.first);
	      }

	    }

	    cout << tempSet.size() << endl;
	  }
	  else
	    cout << 0 << endl;
	}

	if (command == "CHECK")
	{
	  string w1, w2;
	  cin >> w1 >> w2;

//	  if (synonymsMap.count(w1) > 0 && synonymsMap.count(w2) > 0)
//	  {
	    if (synonymsMap[w1].count(w2) > 0 ||
			synonymsMap[w2].count(w1) > 0)
		  cout << "YES" << endl;
//	  }
	  else
	    cout << "NO" << endl;
	}
  }
  return 0;
}
