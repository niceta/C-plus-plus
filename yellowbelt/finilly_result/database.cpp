#include "database.h"

void Database::Add(const Date & date, const std::string & str) {
  auto it = dbSet[date].insert(str);
  if (it.second) {
    dbVec[date].push_back(str);
  }
}

int Database::RemoveIf(Pred pred) {
  int counter = 0;
  std::vector<Date> itemsToRemove;
  for (auto& itemMap : dbVec) {
    auto tempPred = [&] (const std::string& ev) {return pred(itemMap.first, ev); };
    auto it = remove_if(itemMap.second.begin(), itemMap.second.end(), tempPred);
    itemMap.second.erase(it, itemMap.second.end());
    
    if (itemMap.second.empty()) {
      itemsToRemove.push_back(itemMap.first);
    }

    counter += dbSet.at(itemMap.first).size() - itemMap.second.size();

    dbSet[itemMap.first].clear();
    dbSet[itemMap.first] = std::set<std::string>(itemMap.second.begin(), itemMap.second.end());
  }

  for (const auto& date : itemsToRemove) {
    dbVec.erase(date);
    dbSet.erase(date);
  }

  return counter;
}

const std::vector<VecType> Database::FindIf(Pred pred) const {
  if (dbVec.empty()) {
    return {};
  }
  else {
    std::vector<VecType> result;
    for (const auto& itemMap : dbVec) {
      //auto tempPred = [&] (const std::string& s) {return pred(itemMap.first, s); };
      //copy_if(itemMap.second.begin(), itemMap.second.end(),
      //  back_inserter(result), tempPred);
      for (const auto& ev : itemMap.second) {
        if (pred(itemMap.first, ev)) {
          result.push_back({ itemMap.first, ev });
        }
      }
    }

    return result;
  }
}

std::string Database::Last(const Date& date) const {
  if (dbSet.empty() || date < dbSet.begin()->first) {
    return "No entries";
  }
  auto it = dbVec.upper_bound(date);

  Date d = prev(it)->first;
  std::stringstream ss;
  ss << d;
  return ss.str() + " " + prev(it)->second.back();
}

void Database::Print(std::ostream & stream) const {
  for (const auto& itemMap : dbVec) {
    for (const auto& ev : itemMap.second) {
      stream << itemMap.first << " " << ev << std::endl;
    }
  }
}

std::ostream & operator<<(std::ostream & stream, const VecType & item) {
  return stream << item.date << " " << item.ev;
}
