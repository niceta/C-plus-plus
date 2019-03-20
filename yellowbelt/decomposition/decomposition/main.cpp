#include <string>
#include <sstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
  string operation_code;
  is >> operation_code;
  
  if (operation_code == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    
    int stop_count;
    is >> stop_count;
    
    q.stops.resize(stop_count);
    for (auto& stop : q.stops) {
      is >> stop;
    }
  }
  else if (operation_code == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }
  else if (operation_code == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  else if (operation_code == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
  if (r.buses.empty()) {
    os << "No stop";
  }
  else {
    for (const auto& bus : r.buses) {
      os << bus << " ";
    }
  }
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
  string bus;
  map<string, vector<string>> stops_to_buses;
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  if (r.buses_to_stops.count(r.bus) == 0) {
    os << "No bus";
  }
  else {
    int counter = 0;
    for (const string& stop : r.buses_to_stops.at(r.bus)) {
      os << "Stop " << stop << ": ";
      if (r.stops_to_buses.at(stop).size() == 1) {
        os << "no interchange";
      }
      else {
        for (const auto& bus : r.stops_to_buses.at(stop)) {
          if (bus != r.bus) {
            os << bus << " ";
          }
        }
      }
      
      ++counter;
      if (counter < r.buses_to_stops.at(r.bus).size()) {
        os << endl;
      }
    }
  }
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
  map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  if (r.buses_to_stops.empty()) {
    os << "No buses";
  }
  else {
    int counter = 0;
    for (const auto& map_item : r.buses_to_stops) {
      os << "Bus " << map_item.first << ": ";
      for (const auto& stop : map_item.second) {
        os << stop << " ";
      }
      ++counter;
      if (counter < r.buses_to_stops.size()) {
        os << endl;
      }
    }
  }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
    buses_to_stops[bus] = stops;
    for (const auto& stop : stops) {
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
    // Реализуйте этот метод
    BusesForStopResponse response = { {} };
    if (stops_to_buses.count(stop) > 0) {
      response.buses = stops_to_buses.at(stop);
    }
    return response;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    // Реализуйте этот метод
    StopsForBusResponse response;
    response.bus = bus;
    response.buses_to_stops = buses_to_stops;
    response.stops_to_buses = stops_to_buses;
    return response;
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
    AllBusesResponse response = { {} };
    if (!buses_to_stops.empty()) {
      response.buses_to_stops = buses_to_stops;
    }
    return response;
  }

private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

void testBusesForStop() {
  {
    BusesForStopResponse r = { {} };
    stringstream ss;
    ss << r;
    assert(ss.str() == "No stop");
  }

  {
    BusesForStopResponse r = { { "1", "2" } };
    stringstream ss;
    ss << r;
    assert(ss.str() == "1 2 ");
  }

  cout << "Buses for stop OK" << endl;
}

using BusMap = map<string, vector<string>>;

void testAllBuses() {
  {
    AllBusesResponse r;
    stringstream ss;
    ss << r;
    assert(ss.str() == "No buses");
  }

  {
    AllBusesResponse r;
    stringstream ss;
    r.buses_to_stops = { { "1",{ "a", "b" } },
    { "2",{ "c" } } };
    ss << r;
    string str = ss.str();
    assert(ss.str() == "Bus 1: a b \nBus 2: c ");
  }

  cout << "all buses ok" << endl;
}

void testStopsForBus() {
  {
    StopsForBusResponse r;
    stringstream ss;
    ss << r;
    assert(ss.str() == "No bus");
  }
  {
    StopsForBusResponse r;
    r.bus = "1";
    r.buses_to_stops = { {"2", {"a"}} };
    stringstream ss;
    ss << r;
    assert(ss.str() == "No bus");
  }
  {
    StopsForBusResponse r;
    r.bus = "1";
    r.buses_to_stops = { { "1", { "b" } }, { "2", { "a" } } };
    r.stops_to_buses = { {"a", {"2"}}, {"b", {"1"}} };
    stringstream ss;
    ss << r;
    string str = ss.str();
    assert(ss.str() == "Stop b: no interchange");
  }
  cout << "stops for bus ok" << endl;
}

void testAll() {
  testBusesForStop();
  testAllBuses();
  testStopsForBus();
}
// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  //testAll();
  //system("pause");
  //return 0;

  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
