#include "DataManager.h"
#include "Utils.h"
#include <bits/stdc++.h>

using namespace std;

vector<shared_ptr<Person>> DataManager::loadData(const string &filename) {
  vector<shared_ptr<Person>> persons;
  ifstream file(filename);

  if (!file.is_open()) {
    cerr << "Error: Could not open file '" << filename << "'\n";
    return persons;
  }

  string line;
  int lineNum = 0;
  while (getline(file, line)) {
    lineNum++;
    line = Utils::trim(line);

    if (line.empty()) {
      continue;
    }

    stringstream ss(line);
    string type;
    getline(ss, type, '|');

    Student s = Student::deserialize(line);
    if (!s.getId().empty()) {
      persons.push_back(make_shared<Student>(s));
    }
  }

  return persons;
}

void DataManager::saveData(const vector<shared_ptr<Person>> &persons,
                           const string &filename) {
  ofstream file(filename, ios::out);
  for (const auto &p : persons) {
    file << p->serialize() << endl;
  }
}

void DataManager::addPerson(const string &filename) {
  vector<shared_ptr<Person>> persons = loadData(filename);

  shared_ptr<Person> p;

  p = make_shared<Student>();
  cout << "\n--- Enter Student Details ---\n";

  p->inputAdd();
  persons.push_back(p);
  saveData(persons, filename);
  cout << ">> " << p->getType() << " saved successfully!\n";
}

void DataManager::removePerson(const string &filename) {
  vector<shared_ptr<Person>> persons = loadData(filename);

  cout << "\n--- Enter ID to remove ---\n";
  string id;
  cin >> id;

  bool found = false;
  auto it = remove_if(
      persons.begin(), persons.end(), [&](const shared_ptr<Person> &p) {
        return Utils::toLowerCase(p->getId()) == Utils::toLowerCase(id);
      });

  if (it != persons.end()) {
    persons.erase(it, persons.end());
    found = true;
  }

  if (found) {
    saveData(persons, filename);
    cout << ">> Person with ID " << id << " removed successfully!\n";
  } else {
    cout << ">> ID not found!\n";
  }
}

// Find person
void DataManager::findPerson(const string &filename) {
  vector<shared_ptr<Person>> persons = loadData(filename);
  cout << "\nEnter ID: ";
  string id;
  cin >> id;

  for (const auto &p : persons) {
    if (Utils::toLowerCase(p->getId()) == Utils::toLowerCase(id)) {
      cout << ">> Found:\n";
      p->display();
      return;
    }
  }
  cout << ">> Not found!\n";
}

void DataManager::updatePerson(const string &filename) {
  vector<shared_ptr<Person>> persons = loadData(filename);
  cout << "\nEnter the ID to update: ";
  string id;
  cin >> id;

  for (auto &p : persons) {
    if (Utils::toUpperCase(p->getId()) == Utils::toUpperCase(id)) {
      cout << "\n--- Update " << p->getType() << " Information ---\n";
      p->inputUpdate();
      saveData(persons, filename);
      cout << ">> " << p->getType() << " " << id << " Updated Successfully!\n";
      return;
    }
  }

  cout << ">> ID Not Found!\n";
}

void DataManager::displayAll(const string &filename) {
  vector<shared_ptr<Person>> persons = loadData(filename);

  if (persons.empty()) {
    cout << ">> No records found!\n";
    return;
  }

  cout << "\n===== All Records =====\n";
  for (const auto &p : persons) {
    p->display();
  }
  cout << "=======================\n";
}

void DataManager::addStudent(const string &filename) {
  vector<shared_ptr<Person>> persons = loadData(filename);
  auto s = make_shared<Student>();
  cout << "\n--- Enter Student Details ---\n";
  s->inputAdd();
  persons.push_back(s);
  saveData(persons, filename);
  cout << ">> Student saved successfully!\n";
}
