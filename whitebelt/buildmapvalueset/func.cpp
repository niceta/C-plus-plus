//#include "func.h"
#include <set>
#include <string>
#include <map>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m)
{
	set<string> result;

	for (const auto &x : m)
	{
		result.insert(x.second);
	}

	return result;
}
