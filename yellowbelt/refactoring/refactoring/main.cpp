#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
  Human(const string& name, const string& activity) 
    : name_(name), activity_(activity) {}

  string getName() const { return name_; }
  string getActivity() const { return activity_; }
  ostream& log() const {
    return cout << getActivity() << ": " << getName();
  }

  virtual void Walk(const string& destination) const = 0;

protected:
  const string name_ = "incognito";
  const string activity_ = "none";
};

class Student : public Human {
public:
  Student(const string& name, const string& favouriteSong)
    : Human(name, "Student"), favouriteSong_(favouriteSong) {}

  void Learn() const {
    log() << " learns" << endl;
  }

  void SingSong() const {
    log() << " sings a song: " << favouriteSong_ << endl;
  }

  void Walk(const string& destination) const override {
    log() << " walks to: " << destination << endl;
    SingSong();
  }

private:
  const string favouriteSong_;
};

class Teacher : public Human {
public:

  Teacher(const string& name, const string& subject)
    : Human(name, "Teacher"), subject_(subject) {}

  void Teach() const {
    log() << " teaches: " << subject_ << endl;
  }

  void Walk(const string& destination) const override {
    log() << " walks to: " << destination << endl;
  }

private:
  const string subject_;
};


class Policeman : Human {
public:
  Policeman(const string& name) : Human(name, "Policeman") {}

  void Check(const Human& human) const {
    log() << " checks " << human.getActivity() << ". "
      << human.getActivity() << "'s name is: " << human.getName() << endl; 
  }

  void Walk(const string& destination) const override {
    log() << " walks to: " << destination << endl;
  }
};


void VisitPlaces(Human& human, const vector<string>& places) {
  for (const auto& place : places) {
    human.Walk(place);
  }
}


int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, { "Moscow", "London" });
  p.Check(s);
  VisitPlaces(s, { "Moscow", "London" });
  return 0;
}
