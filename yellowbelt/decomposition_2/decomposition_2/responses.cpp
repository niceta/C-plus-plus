#include "responses.h"

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

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
  if (r.buses_to_stops.count(r.bus) == 0) {
    os << "No bus";
  }
  else {
    size_t counter = 0;
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

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
  if (r.buses_to_stops.empty()) {
    os << "No buses";
  }
  else {
    size_t counter = 0;
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
