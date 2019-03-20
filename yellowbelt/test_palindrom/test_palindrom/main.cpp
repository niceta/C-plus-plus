#pragma once

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

bool IsPalindrom(const string& s) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  int j = s.size() - 1;

  for (int i = 0; i <= j; ++i)
  {
    if (s[i] == s[j])
      --j;
    else
      return false;
  }

  return true;

}

void TestEmpty() {
  Assert(IsPalindrom(""), "empty");
}

void Test_1_symbol() {
  Assert(IsPalindrom("a"), "letter");
  Assert(IsPalindrom(" "), "space");
  Assert(IsPalindrom("1"), "number");
}

void TestDefaultWork() {
  Assert(IsPalindrom("amama"), "normal string");
  Assert(IsPalindrom("amma"), "even");
  Assert(IsPalindrom("am a ma"), "string with spaces");
  Assert(IsPalindrom("Am a mA"), "upper letters");
  AssertEqual(IsPalindrom("Amama"), false, "first up");
  AssertEqual(IsPalindrom("akma"), false);
  AssertEqual(IsPalindrom("amamA"), false, "last up");
  AssertEqual(IsPalindrom("aamama"), false, "first not used");
  AssertEqual(IsPalindrom("amamaa"), false, "last not used");
  AssertEqual(IsPalindrom("amma 1amma"), false, "problem in center");
  AssertEqual(IsPalindrom("amma1 amma"), false, "problem in center");
  AssertEqual(IsPalindrom("am m  a a m  m a"), false, "ignore space");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "empty tests");
  runner.RunTest(Test_1_symbol, "1 sym");
  runner.RunTest(TestDefaultWork, "default");
  // добавьте сюда свои тесты
  return 0;
}
