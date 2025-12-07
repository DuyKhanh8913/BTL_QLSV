#ifndef PERSON_H
#define PERSON_H

#include <bits/stdc++.h>
using namespace std;

// Base class
class Person {
protected:
  string id;
  string name;

public:
  Person() {}
  Person(string id, string name) : id(id), name(name) {}

  // Virtual destructor
  virtual ~Person() {}

  // Pure virtual functions
  virtual void inputAdd() = 0;
  virtual void inputUpdate() = 0;
  virtual void display() const = 0;
  virtual string serialize() const = 0;
  virtual string getType() const = 0;

  // Getter methods
  string getId() const { return id; }
  string getName() const { return name; }

  // Setter methods
  void setId(const string &newId) { id = newId; }
  void setName(const string &newName) { name = newName; }
};

#endif