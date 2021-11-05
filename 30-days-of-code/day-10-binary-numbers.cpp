/*
 * File: /day-10-binary-numbers.cpp
 * Project: 30-days-of-code
 * Created Date: Tuesday November 2nd 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Tuesday November 2nd 2021 7:47:58 am
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <bits/stdc++.h>

#include <bitset>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));
  
  
  // How the below while loop works. Each iteration first shifts the bits to the
  // left by 1, then runs bitwise & to output a new number. Each time & makes 
  // the while-loop continue (because a number exists), a counter increases.
  // 5869 = 1011011101101
  // <<1  = 0110111011010
  // &    = 0010011001000 = 1224
  // <<1  = 0100110000000
  // &    = 0000010000000 = 128
  // <<1  = 0000100000000
  // &    = 0000000000000 = 0
  int count = 0;
  while (n) {
    n = (n & (n << 1));
    count++;
  }

  cout << count << endl;

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
