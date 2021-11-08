/**
 * File: /day-26-nested-logic.cpp
 * Project: 30-days-of-code
 * Purpose: https://www.hackerrank.com/challenges/30-nested-logic/problem
 *   I really wanted to mess around with operator overloading for this, so I
 *   over-engineered the hell out of it. It really doesn't need to be more than
 *   simply subtracting the days, months, and years, to generate a late fee for
 *   the book.
 *
 * @author Myles Berueda
 * @date   Sunday November 7th 2021
 * -----
 * Modified: Sunday November 7th 2021 11:34:21 pm
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

struct Date {
  int day = 0, month = 0, year = 0;

  Date(){};
  Date(const int day, const int month, const int year)
      : day(day), month(month), year(year) {}

  Date operator-(const Date& other) {
    return Date(day - other.day, month - other.month, year - other.year);
  }

  friend ostream& operator<<(ostream& out, Date& date) {
    out << date.day << " " << date.month << " " << date.year << " ";
    return out;
  }

  bool operator<(const Date& other) {
    if (year < other.year)
      return true;
    else if (month < other.month && year == other.year)
      return true;
    else if (day < other.day && month == other.month && year == other.year)
      return true;

    return false;
  }

  bool operator<=(const Date& other) {
    if (year <= other.year)
      return true;
    else if (month <= other.month && year == other.year)
      return true;
    else if (day <= other.day && month == other.month && year == other.year)
      return true;

    return false;
  }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  Date return_date, due_date;
  const Date epoch = Date(0, 0, 0);

  cin >> return_date.day >> return_date.month >> return_date.year;
  cin >> due_date.day >> due_date.month >> due_date.year;

  // Date date_diff = due_date - return_date;
  Date date_diff = return_date - due_date;

  int fine = (return_date < due_date)
                 ? 0
                 : max({10000 * (return_date.year > due_date.year),
                        500 * date_diff.month, 15 * date_diff.day});

  cout << fine << endl;

  return 0;
}
