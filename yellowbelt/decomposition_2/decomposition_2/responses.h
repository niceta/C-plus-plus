#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct BusesForStopResponse {
  // ��������� ������ ��� ���������
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  // ��������� ������ ��� ���������
  string bus;
  map<string, vector<string>> stops_to_buses;
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  // ��������� ������ ��� ���������
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
