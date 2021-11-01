/*
 * File: /day-03-intro-to-conditional-statements.cpp
 * Project: 30-days-of-code
 * Created Date: Saturday October 30th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Saturday October 30th 2021 11:24:28 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main() {
  string N_temp;
  getline(cin, N_temp);

  int N = stoi(ltrim(rtrim(N_temp)));

  if (N % 2 == 1 || N > 5 && N < 21) {
    cout << "Weird" << endl;
  } else {
    cout << "Not Weird" << endl;
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
