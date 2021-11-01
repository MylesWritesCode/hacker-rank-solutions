/*
 * File: /day-08-dictionaries-and-maps.cpp
 * Project: 30-days-of-code
 * Created Date: Monday November 1st 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Monday November 1st 2021 9:45:44 am
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string name, phone_number;
    map<string, string> phone_book;
    int num_inputs = 0;

    cin >> num_inputs;
    cin.ignore();

    while (num_inputs > 0) {
      cin >> name >> phone_number;
      
      phone_book[name] = phone_number;
      --num_inputs;
    }
    
    while (cin >> name) {
      auto iter = phone_book.find(name);
      if (iter != phone_book.end()) {
        cout << name << "=" << iter->second << endl;
      } else {
        cout << "Not found" << endl;
      }
    }

    return 0;
}