#include "Utils.h"
#include <bits/stdc++.h>

using namespace std;

bool Utils::isValidName(const string &studentName) {
  if (studentName.empty())
    return false;
  if (isspace(studentName.front()) || isspace(studentName.back()))
    return false;

  bool lastWasSpace = false;

  for (unsigned char c : studentName) {
    if (isdigit(c))
      return false; // no digits
    if (!isalpha(c) && !isspace(c))
      return false; // no special chars
    if (isspace(c)) {
      if (lastWasSpace)
        return false; // no double spaces
      lastWasSpace = true;
    } else {
      lastWasSpace = false;
    }
  }
  return true;
}

bool Utils::isValidId(const string &id) {
  return !id.empty(); // must not be empty
}

string Utils::toLowerCase(const string &s) {
  string result = s;
  for (char &c : result)
    c = tolower(c); // convert to lowercase
  return result;
}

string Utils::toUpperCase(const string &s) {
  string result = s;
  for (char &c : result)
    c = toupper(c); // convert to uppercase
  return result;
}

string Utils::firstLetterToUpperCase(const string &s) {
  string result = s;
  bool newWord = true;

  for (char &c : result) {
    if (isspace(c)) {
      newWord = true;
    } else {
      if (newWord) {
        c = toupper(c); // first letter uppercase
        newWord = false;
      } else {
        c = tolower(c); // other letters lowercase
      }
    }
  }
  return result;
}

string Utils::trim(const string &s) {
  string result = s;
  result.erase(result.begin(),
               find_if(result.begin(), result.end(), [](unsigned char ch) {
                 return !isspace(ch); // remove leading spaces
               }));
  result.erase(find_if(result.rbegin(), result.rend(),
                       [](unsigned char ch) {
                         return !isspace(ch); // remove trailing spaces
                       })
                   .base(),
               result.end());
  return result;
}

string Utils::sanitizeName(const string &name) {
  string result = trim(name);              // trim spaces
  result = firstLetterToUpperCase(result); // normalize case

  result.erase(remove_if(result.begin(), result.end(),
                         [](unsigned char c) {
                           return !isalpha(c) &&
                                  !isspace(c); // remove invalid chars
                         }),
               result.end());

  return result;
}
