#pragma once
#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename Collection>
string Join(Collection c, char d) {
	stringstream ss;
	bool first = true;

	for (auto& i : c) {
		if (!first) {
			ss << d;
		}
		first = false;
		ss << i;
	}
	return ss.str();
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	return out << '[' << Join(v, ',') << ']';
}

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
	return out << '(' << p.first << ',' << p.second << ')';
}

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m) {
	return out << '{' << Join(m, ',') << '}';
}