#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct BusesForStopResponse {
  // Наполните полями эту структуру
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  // Наполните полями эту структуру
  string bus;
  map<string, vector<string>> stops_to_buses;
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  // Наполните полями эту структуру
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
