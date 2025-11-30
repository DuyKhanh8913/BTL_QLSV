#include "Menu.h"
#include "DataManager.h"
#include <bits/stdc++.h>

using namespace std;

void Menu::run(const string &filename) {
  int choice;
  char cont;

  do {
    system("cls");
    cout << "\n===== MENU =====\n";
    cout << "1. Add student\n";
    cout << "2. Find student by ID\n";
    cout << "3. Update student\n";
    cout << "4. Display all students\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 1:
      DataManager::addStudent(filename);
      break;
    case 2:
      DataManager::findStudent(filename);
      break;
    case 3:
      DataManager::updateStudent(filename);
      break;
    case 4:
      DataManager::displayAllStudents(filename);
      break;
    case 0:
      cout << "Exiting...\n";
      return;
    default:
      cout << "Invalid choice!\n";
    }

    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "\nDo you want to go back to menu? (Y/N): ";
    cin >> cont;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cont != 'Y' && cont != 'y') {
      cout << "Exiting...\n";
      break;
    }

  } while (true);
}
