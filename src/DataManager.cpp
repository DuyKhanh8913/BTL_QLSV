#include "DataManager.h"
#include "Utils.h"
#include <bits/stdc++.h>

using namespace std;

vector<Student> DataManager::loadData(const string &filename) {
  vector<Student> students;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    students.push_back(Student::deserialize(line));
  }
  return students;
}

void DataManager::saveData(const vector<Student> &students,
                           const string &filename) {
  ofstream file(filename, ios::out | ios::binary);
  for (const auto &s : students) {
    file << s.serialize() << endl;
  }
}

void DataManager::addStudent(const string &filename) {
  vector<Student> students = loadData(filename);
  Student s;
  cout << "\n--- Enter Student Details ---\n";
  s.input();

  students.push_back(s);
  saveData(students, filename);
  cout << ">> Student saved successfully!\n";
}

void DataManager::findStudent(const string &filename) {
  vector<Student> students = loadData(filename);
  cout << "\nEnter Student ID: ";
  string id;
  cin >> id;

  for (auto &s : students) {
    if (Utils::toLowerCase(s.getId()) == Utils::toLowerCase(id)) {
      cout << ">> Student Found:\n";
      s.display();
      return;
    }
  }
  cout << ">> Not found student!\n";
}

void DataManager::updateStudent(const string &filename) {
  vector<Student> students = loadData(filename);
  cout << "\nEnter the ID of the student to update: ";
  string id;
  cin >> id;

  for (auto &s : students) {
    if (Utils::toUpperCase(s.getId()) == Utils::toUpperCase(id)) {
      cout << "\n--- Update Student Information ---\n";
      s.inputUpdate();
      saveData(students, filename);
      cout << ">> Student " << id << " Updated Successfully!\n";
      return;
    }
  }

  cout << ">> Student ID Not Found!\n";
}

void DataManager::displayAllStudents(const string &filename) {
  vector<Student> students = loadData(filename);

  if (students.empty()) {
    cout << ">> No students found!\n";
    return;
  }

  cout << "\n===== All Students =====\n";
  for (const auto &s : students) {
    s.display();
  }
  cout << "========================\n";
}
