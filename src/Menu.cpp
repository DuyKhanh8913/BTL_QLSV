#include "Menu.h"
#include "DataManager.h"
#include <bits/stdc++.h>

using namespace std;

void Menu::run(const string &filename) {
  int choice;
  char cont;

  do {
    system("cls");
    cout << "\n===== SCHOOL MANAGEMENT SYSTEM =====\n";
    cout << "1. Add person (Student/Teacher)\n";
    cout << "2. Remove person\n";
    cout << "3. Find person by ID\n";
    cout << "4. Update person\n";
    cout << "5. Display students\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
    cin >> choice;

    switch (choice) {
    case 1:
      DataManager::addPerson(filename);
      break;
    case 2:
      DataManager::removePerson(filename);
      break;
    case 3:
      DataManager::findPerson(filename);
      break;
    case 4:
      DataManager::updatePerson(filename);
      break;
    case 5:
      DataManager::displayAll(filename);
      break;
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