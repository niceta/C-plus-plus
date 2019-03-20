//#pragma once
#include <map>
#include <tuple>
#include <vector>

using namespace std;

bool operator<(const Region &lhs, const Region &rhs) {
return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	map<Region, int> regions_map;
	for (const auto& item : regions) {
		++regions_map[item];
	}

	int count = 0;
	for (const auto& item : regions_map) {
		int temp_count = item.second;
		if (temp_count > count)
			count = temp_count;
	}
	return count;
}