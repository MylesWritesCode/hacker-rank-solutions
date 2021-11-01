/*
 * File: /day-01-data-types.cpp
 * Project: 30-days-of-code
 * Created Date: Saturday October 30th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Saturday October 30th 2021 10:35:36 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

int main() {
  int i = 4;
  double d = 4.0;
  string s = "HackerRank ";

  // Declare second integer, double, and String variables.
  int num_int;
  double num_double;
  string str;

  // Read and save an integer, double, and String to your variables.
  // Note: If you have trouble reading the entire string, please go back and
  // review the Tutorial closely.
  cin >> num_int;
  cin >> num_double;
  cin.ignore();
  getline(cin, str);

  // Print the sum of both integer variables on a new line.
  std::cout << num_int + i << std::endl;

  // Print the sum of the double variables on a new line.
  std::cout << fixed << setprecision(1) << num_double + d << std::endl;

  // Concatenate and print the String variables on a new line
  // The 's' variable above should be printed first.
  std::cout << s + str << std::endl;

  return 0;
}