#pragma once
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#include <functional>
#include <memory>

#include "node.h"
#include "date.h"

using dbSecond = std::pair<std::set<std::string>, std::vector<std::string>>;

struct VecType {
  VecType() : date({ 1, 1, 1 }), ev("") {}
  VecType(const Date& d, const std::string& e) : date(d), ev(e) {}
  Date date;
  std::string ev;
};

std::ostream& operator<<(std::ostream& stream, const VecType& item);

class Database {
public:
  void Add(const Date& date, const std::string& str); 

  using Pred = std::function<bool(const Date&, const std::string&)>;
  
  int RemoveIf(Pred pred);
  
  const std::vector<VecType> FindIf(Pred pred) const;

  std::string Last(const Date& date) const;

  void Print(std::ostream& stream) const;
private:
  //std::map<Date, std::set<std::string>> db;
  //std::set<dbItem> db;
  std::map<Date, dbSecond> db;
  std::map<Date, std::set<std::string>> dbSet;
  std::map<Date, std::vector<std::string>> dbVec;
};