/*
 * File: /day-14-scope.cpp
 * Project: 30-days-of-code
 * Created Date: Friday November 5th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Friday November 5th 2021 1:23:01 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Difference {
 private:
  vector<int> elements;

 public:
  int maximumDifference;

  // Add your code here
 public:
  Difference(vector<int> &elements) : elements(elements) {}

  void computeDifference() {
    // Can't do this in HackerRank
    const auto [min, max] = minmax_element(elements.begin(), elements.end());

    maximumDifference = *max - *min;
  }
};  // End of Difference class

int main() {
  int N;
  cin >> N;

  vector<int> a;

  for (int i = 0; i < N; i++) {
    int e;
    cin >> e;

    a.push_back(e);
  }

  Difference d(a);

  d.computeDifference();

  cout << d.maximumDifference;

  return 0;
}