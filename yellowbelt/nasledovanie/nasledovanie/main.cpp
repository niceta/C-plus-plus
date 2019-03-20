﻿#include <iostream>

using namespace std;

class Animal {
public:
  // ваш код
  Animal(const string& s) : Name(s) {};
  const string Name;
};


class Dog: public Animal {
public:
  // ваш код
  Dog(const string& s) : Animal(s) {};
  void Bark() {
    cout << Name << " barks: woof!" << endl;
  }
};

int main() {
  
  return 0;
}
