/*
 * File: /day-20-sorting.cpp
 * Project: 30-days-of-code
 * Created Date: Saturday November 6th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Saturday November 6th 2021 8:31:15 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split(rtrim(a_temp_temp));

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }
  
  int total_num_swaps = 0;

  // Write your code here
  for (int i = 0; i < a.size(); ++i) {
    int num_swaps = 0;
    for (int j = 0; j < a.size() - 1; ++j) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        num_swaps++;
      }
    }

    total_num_swaps += num_swaps;
    if (num_swaps == 0) {
      break;
    }
  }
  
  cout << "Array is sorted in " << total_num_swaps << " swaps." << endl;
  cout << "First Element: " << a.front() << endl;
  cout << "Last Element: " << a.back() << endl;

  return 0;
};

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
};

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
};

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
};