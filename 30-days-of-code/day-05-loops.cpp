/*
 * File: /day-05-loops.cpp
 * Project: 30-days-of-code
 * Created Date: Sunday October 31st 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Sunday October 31st 2021 2:26:01 am
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <bits/stdc++.h>

#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  for (int i = 1; i <= 10; ++i) {
    printf("%i x %i = %i\n", n, i, n * i);
  }

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
