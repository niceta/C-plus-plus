#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;
class Figure {
public:
  virtual string Name() const = 0;
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
  Triangle(int a, int b, int c) : a_(a), b_(b), c_(c) {}
  string Name() const override { return "TRIANGLE"; }
  double Perimeter() const override { return a_ + b_ + c_; }
  double Area() const override { 
    return sqrt(Perimeter() / 2
      * (Perimeter() / 2 - a_) 
      * (Perimeter() / 2 - b_)
      * (Perimeter() / 2 - c_));
  }
private:
  const int a_;
  const int b_;
  const int c_;
};

class Rect : public Figure {
public:
  Rect(int a, int b) : a_(a), b_(b) {}
  string Name() const override { return "RECT"; }
  double Perimeter() const override { return 2 * (a_ + b_); }
  double Area() const override { return a_ * b_; }
private:
  int a_;
  int b_;
};

class Circle : public Figure {
public:
  Circle(int r) : r_(r) {}
  string Name() const override { return "CIRCLE"; }
  double Perimeter() const override { return 2 * 3.14 * r_; }
  double Area() const override { return 3.14 * r_ * r_; }
private:
  int r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
  string name;
  is >> name;
  if (name == "RECT") {
    int a, b;
    is >> a >> b;
    return make_shared<Rect>(a, b);
  }
  else if (name == "TRIANGLE") {
    int a, b, c;
    is >> a >> b >> c;
    return make_shared<Triangle>(a, b, c);
  }
  else {
    int r;
    is >> r;
    return make_shared<Circle>(r);
  }
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    }
    else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
          << current_figure->Name() << " "
          << current_figure->Perimeter() << " "
          << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}