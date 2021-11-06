/*
 * File: /day-16-string-to-integer.cpp
 * Project: 30-days-of-code
 * Created Date: Friday November 5th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Friday November 5th 2021 5:10:30 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <bits/stdc++.h>
// #include <optional>

using namespace std;

int main()
{
    string S;
    getline(cin, S);

    // Can't use std::optional::optional<T> on HackerRank
    // optional<int> str_to_int;

    try {
      cout << stoi(S) << endl;
    } catch (exception e) {
      cout << "Bad String" << endl;
    }

    return 0;
}
