#ifndef Utils_H
#define Utils_H

#include <bits/stdc++.h>
using namespace std;

class Utils {
public:
  static bool isValidName(const string &studentName);
  static bool isValidId(const string &id);
  static string toLowerCase(const string &s);
  static string toUpperCase(const string &s);
  static string firstLetterToUpperCase(const string &s);
  static string trim(const string &s);
  static string sanitizeName(const string &s);
};

#endif
