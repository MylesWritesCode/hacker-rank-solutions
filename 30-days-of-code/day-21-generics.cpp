/*
 * File: /day-21-generics.cpp
 * Project: 30-days-of-code
 * Created Date: Saturday November 6th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Saturday November 6th 2021 9:10:20 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
*    Name: printArray
*    Print each element of the generic vector on a new line. Do not return anything.
*    @param A generic vector
**/

// Write your code here
template <typename T>
void printArray(const T &array) {
  for (const auto& element : array) {
    cout << element << " ";
  }
  cout << endl;
};

int main() {
	int n;
	
	cin >> n;
	vector<int> int_vector(n);
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;
		int_vector[i] = value;
	}
	
	cin >> n;
	vector<string> string_vector(n);
	for (int i = 0; i < n; i++) {
		string value;
		cin >> value;
		string_vector[i] = value;
	}

	printArray<vector<int>>(int_vector);
	printArray<vector<string>>(string_vector);

	return 0;
};