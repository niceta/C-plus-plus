#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    //personHistory[year].first_name = first_name;
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    //personHistory[year].last_name = last_name;
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
    string first_name = GetNameByYear(first_names, year);
    string last_name = GetNameByYear(last_names, year);

    string result = first_name + " " + last_name;

    if (first_name == "" && last_name == "")
      result = "Incognito";
    else if (first_name == "")
      result = last_name + " with unknown first name";
    else if (last_name == "")
      result = first_name + " with unknown last name";

    return result;
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;

  string GetNameByYear(const map<int, string> &names, int year) {
    string result = "";

    for (const auto &i : names) {
      if (i.first <= year)
        result = i.second;
      else
        break;
    }

    return result;
  }
};

void TestIncognito() {
  {
    Person p;
    AssertEqual("Incognito", p.GetFullName(1000), "empty person test");
    p.ChangeFirstName(1999, "Petr");
    AssertEqual("Incognito", p.GetFullName(1000), "year less than birthdate");
    p.ChangeFirstName(2000, "aaa");
    AssertEqual("Incognito", p.GetFullName(1000), "year less than birthdate");
  }
}

void TestFirstNameChange() {
  Person p;
  p.ChangeFirstName(1999, "Petr");
  AssertEqual("Petr with unknown last name", p.GetFullName(2000), "first name change 2000");
  AssertEqual("Petr with unknown last name", p.GetFullName(1999), "first name change 1999");
}

void TestLastNameChange() {
  Person p;
  p.ChangeLastName(1999, "aaa");
  AssertEqual("aaa with unknown first name", p.GetFullName(2000), "last name change 2000");
  AssertEqual("aaa with unknown first name", p.GetFullName(1999), "last name change 1999");
}

void TestAllChange() {
  Person p;
  p.ChangeFirstName(1999, "Petr");
  p.ChangeLastName(1999, "aaa");
  AssertEqual("Petr aaa", p.GetFullName(1999), "all change 2000");
  AssertEqual("Petr aaa", p.GetFullName(1999), "all change 1999");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestIncognito, "incognito");
  runner.RunTest(TestLastNameChange, "last name");
  runner.RunTest(TestFirstNameChange, "first name");
  runner.RunTest(TestAllChange, "all");
  // добавьте сюда свои тесты
  return 0;
}
