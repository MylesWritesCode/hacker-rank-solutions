/*
 * File: /day-17-more-exceptions.cpp
 * Project: 30-days-of-code
 * Created Date: Friday November 5th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Friday November 5th 2021 5:58:38 pm
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

class Calculator {
  // No member variables
 public:
  Calculator(){};

  int power(const int &n, const int &p) {
    if (n < 0 || p < 0) {
      throw std::invalid_argument("n and p should be non-negative");
    }
    return pow(n, p);
  }
};

int main() {
  Calculator myCalculator = Calculator();
  int T, n, p;
  cin >> T;
  while (T-- > 0) {
    if (scanf("%d %d", &n, &p) == 2) {
      try {
        int ans = myCalculator.power(n, p);
        cout << ans << endl;
      } catch (exception &e) {
        cout << e.what() << endl;
      }
    }
  }
}