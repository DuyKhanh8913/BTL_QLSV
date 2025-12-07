#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
  string id;
  string studentName;
  string className;

public:
  Student() {}
  Student(string id, string studentName, string className);

  void inputAdd();
  void inputUpdate();
  void display() const;

  string getId() const;
  string serialize() const;
  static Student deserialize(const string &line);
};

#endif
