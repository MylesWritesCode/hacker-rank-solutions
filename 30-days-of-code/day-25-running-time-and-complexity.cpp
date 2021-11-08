/**
 * File: /day-25-running-time-and-complexity.cpp
 * Project: 30-days-of-code
 * Purpose:
 *https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem
 *
 * @author Myles Berueda
 * @date   Sunday November 7th 2021
 * -----
 * Modified: Sunday November 7th 2021 7:28:49 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 **/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void printIsPrime(const int &n);

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int input, num_inputs;
  cin >> num_inputs;

  for (int i = 0; i < num_inputs; ++i) {
    cin >> input;

    printIsPrime(input);
  }

  return 0;
};

void printIsPrime(const int &n) {
  if (n == 1) {
    cout << "Not prime" << endl;
    return;
  }

  bool isPrime = true;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      isPrime = false;
      break;
    }
  }
  if (isPrime) {
    cout << "Prime" << endl;
  } else {
    cout << "Not prime" << endl;
  }
}
