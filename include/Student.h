#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <bits/stdc++.h>
using namespace std;

// Student extend from Person
class Student : public Person {
private:
  string className;

public:
  Student() : Person() {}
  Student(string id, string name, string className)
      : Person(id, name), className(className) {}

  // Override virtual functions from Person
  void inputAdd() override;
  void inputUpdate() override;
  void display() const override;
  string serialize() const override;
  string getType() const override { return "Student"; }

  string getClassName() const { return className; }
  void setClassName(const string &newClass) { className = newClass; }

  static Student deserialize(const string &line);
};

#endif