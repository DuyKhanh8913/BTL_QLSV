#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "Person.h"
#include "Student.h"
#include <bits/stdc++.h>

using namespace std;

class DataManager {
public:
  static vector<shared_ptr<Person>> loadData(const string &filename);
  static void saveData(const vector<shared_ptr<Person>> &persons,
                       const string &filename);

  static void addPerson(const string &filename);
  static void removePerson(const string &filename);
  static void findPerson(const string &filename);
  static void updatePerson(const string &filename);
  static void displayAll(const string &filename);

  static void addStudent(const string &filename);
};

#endif