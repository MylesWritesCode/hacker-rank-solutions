/*
 * File: /day-19-interfaces.cpp
 * Project: 30-days-of-code
 * Created Date: Saturday November 6th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Saturday November 6th 2021 5:52:17 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AdvancedArithmetic {
 public:
  virtual int divisorSum(int n) = 0;
};

// Only modify this class
class Calculator : public AdvancedArithmetic {
 public:
  int divisorSum(int n) {
    vector<int> factors = findFactors(n);
    int divisor_sum = 0;

    for (const auto &factor : factors) {
      divisor_sum += factor;
    }

    return divisor_sum;
  };

  vector<int> findFactors(const int &n) {
    vector<int> result;
    int i = 1;

    // While i < sqrt(n)
    while (i * i <= n) {
      if (n % i == 0) {
        result.push_back(i);

        if (n / i != i) {
          result.push_back(n / i);
        }
      }
      i++;
    }

    return result;
  };
};

int main() {
  int n;
  cin >> n;
  AdvancedArithmetic *myCalculator = new Calculator();
  int sum = myCalculator->divisorSum(n);
  cout << "I implemented: AdvancedArithmetic\n" << sum;
  return 0;
}