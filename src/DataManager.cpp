#include "DataManager.h"
#include "Utils.h"
#include <bits/stdc++.h>

using namespace std;

vector<Student> DataManager::loadData(const string &filename) {
  vector<Student> students;
  ifstream file(filename);

  if (!file.is_open()) {
    cerr << "Error: Could not open file '" << filename << "'\n";
    return students;
  }

  string line;
  int lineNum = 0;
  while (getline(file, line)) {
    lineNum++;
    line = Utils::trim(line);

    if (line.empty()) {
      continue;
    }

    int pipeCount = count(line.begin(), line.end(), '|');
    if (pipeCount < 2) {
      cerr << "Warning: Skipping invalid line " << lineNum << ": " << line
           << "\n";
      continue;
    }

    Student s = Student::deserialize(line);

    if (s.getId().empty() || Utils::trim(s.getId()).empty()) {
      cerr << "Warning: Skipping student with empty ID at line " << lineNum
           << "\n";
      continue;
    }

    students.push_back(s);
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
