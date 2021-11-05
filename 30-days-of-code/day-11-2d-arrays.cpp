/*
 * File: /day-11-2d-arrays.cpp
 * Project: 30-days-of-code
 * Created Date: Thursday November 4th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Thursday November 4th 2021 10:52:16 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <bits/stdc++.h>
#include <algorithm>
#include <limits>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int sum_hourglass_from_point(const int &x, const int &y,
                             const vector<vector<int>> &arr);

int main() {
  vector<vector<int>> arr(6);

  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    string arr_row_temp_temp;
    getline(cin, arr_row_temp_temp);

    vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

    for (int j = 0; j < 6; j++) {
      int arr_row_item = stoi(arr_row_temp[j]);

      arr[i][j] = arr_row_item;
    }
  }

  // Start of solution:
  int max_sum = INT_MIN;
  
  for (int x = 0; x < arr.size() - 2; ++x) {
    for (int y = 0; y < arr[x].size() - 2; ++y) {
      max_sum = max(max_sum, sum_hourglass_from_point(x, y, arr));
    }
  }
  
  cout << max_sum << endl;

  return 0;
}

int sum_hourglass_from_point(const int &x, const int &y,
                             const vector<vector<int>> &arr) {

  return (arr[y + 0][x + 0] + arr[y + 0][x + 1] + arr[y + 0][x + 2]
                            + arr[y + 1][x + 1] +                  
          arr[y + 2][x + 0] + arr[y + 2][x + 1] + arr[y + 2][x + 2]);
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
}
