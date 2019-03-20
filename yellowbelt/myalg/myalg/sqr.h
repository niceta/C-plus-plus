#pragma once
#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <sstream>

template <typename T> T Sqr(T value);
template <typename T> vector<T> Sqr(const vector<T>& v);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p);

template <typename T> 
T Sqr(T value) {
	return value * value;
}

template <typename T> 
vector<T> Sqr(const vector<T>& v) {
	vector<T> res;
	for (const auto& i : v) {
		res.push_back(Sqr(i));
	}
	return res;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
	return make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
	map<Key, Value> res;
	for (const auto& i : m) {
		res[i.first] = Sqr(i.second);
	}
	return res;
}