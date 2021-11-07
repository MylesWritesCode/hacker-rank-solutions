/*
 * File: /day-18-queues-and-stacks.cpp
 * Project: 30-days-of-code
 * Created Date: Saturday November 6th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Saturday November 6th 2021 3:37:41 pm
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

class Solution {
  // Write your code here
 public:
  string stack, queue;

 public:
  Solution(){};
  // e -> abcd => abcde
  void pushCharacter(const char &ch) {
    // stack.insert(stack.begin(), ch);
    stack.push_back(ch);
  };

  // e -> abcd => abcde
  void enqueueCharacter(const char &ch) { 
    queue.push_back(ch);
  };

  // abcde -> e => abcd
  char popCharacter() {
    const char res = stack.back();
    stack.pop_back();
    return res;
  };

  // abcde -> a => bcde
  char dequeueCharacter() {
    const char res = queue.front();
    queue.erase(0, 1);
    return res;
  };
};

int main() {
  // read the string s.
  string s;
  getline(cin, s);

  // create the Solution class object p.
  Solution obj;

  // push/enqueue all the characters of string s to stack.
  for (int i = 0; i < s.length(); i++) {
    obj.pushCharacter(s[i]);
    obj.enqueueCharacter(s[i]);
  }

  bool isPalindrome = true;

  // pop the top character from stack.
  // dequeue the first character from queue.
  // compare both the characters.
  for (int i = 0; i < s.length() / 2; i++) {
    if (obj.popCharacter() != obj.dequeueCharacter()) {
      isPalindrome = false;

      break;
    }
  }

  // finally print whether string s is palindrome or not.
  if (isPalindrome) {
    cout << "The word, " << s << ", is a palindrome.";
  } else {
    cout << "The word, " << s << ", is not a palindrome.";
  }

  return 0;
}