#include "Student.h"
#include "Utils.h"
#include <bits/stdc++.h>

using namespace std;

Student::Student(string id, string studentName, string className)
    : id(id), studentName(studentName), className(className) {}

void Student::input() {
  cin.ignore();
  string tmp;

  do {
    cout << "Enter student ID: ";
    getline(cin, tmp);
    tmp = Utils::trim(tmp);
    if (!Utils::isValidId(tmp))
      cout << "Invalid student ID!\n";
    else
      break;
  } while (true);
  id = Utils::toUpperCase(tmp);

  do {
    cout << "Enter student name: ";
    getline(cin, tmp);
    tmp = Utils::trim(tmp);
    if (!Utils::isValidName(tmp))
      cout << "Invalid student name! Must not contain numbers.\n";
    else
      break;
  } while (true);
  studentName = Utils::sanitizeName(tmp);

  cout << "Enter class: ";
  getline(cin, tmp);
  tmp = Utils::trim(tmp);
  className = Utils::toUpperCase(tmp);
}

void Student::inputUpdate() {
  cin.ignore();
  string tmp;

  cout << "Enter new student ID (or press Enter to keep [" << id << "]): ";
  getline(cin, tmp);
  tmp = Utils::trim(tmp);
  if (!tmp.empty()) {
    if (Utils::isValidId(tmp))
      id = Utils::toUpperCase(tmp);
    else
      cout << "Invalid ID! Keeping previous value.\n";
  }

  cout << "Enter new student name (or press Enter to keep [" << studentName
       << "]): ";
  getline(cin, tmp);
  tmp = Utils::trim(tmp);
  if (!tmp.empty()) {
    if (Utils::isValidName(tmp))
      studentName = Utils::sanitizeName(tmp);
    else
      cout << "Invalid name! Keeping previous value.\n";
  }

  cout << "Enter new class (or press Enter to keep [" << className << "]): ";
  getline(cin, tmp);
  tmp = Utils::trim(tmp);
  if (!tmp.empty()) {
    className = Utils::toUpperCase(tmp);
  }
}

void Student::display() const {
  cout << "ID: " << id << " | Name: " << studentName
       << " | Class: " << className << endl;
}

string Student::getId() const { return id; }

string Student::serialize() const {
  return id + "|" + studentName + "|" + className;
}

Student Student::deserialize(const string &line) {
  stringstream ss(line);
  string id, studentName, className;

  getline(ss, id, '|');
  getline(ss, studentName, '|');
  getline(ss, className, '|');

  // Apply sanitization
  id = Utils::toUpperCase(id);
  studentName = Utils::sanitizeName(studentName);
  className = Utils::toUpperCase(className);

  return Student(id, studentName, className);
}
