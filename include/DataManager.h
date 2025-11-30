#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "Student.h"
#include <string>
#include <vector>

class DataManager {
public:
  static vector<Student> loadData(const string &filename);
  static void saveData(const vector<Student> &students, const string &filename);

  static void addStudent(const string &filename);
  static void findStudent(const string &filename);
  static void updateStudent(const string &filename);
  static void displayAllStudents(const string &filename);
};

#endif
