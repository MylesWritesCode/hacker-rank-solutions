/*
 * File: /day-13-abstract-classes.cpp
 * Project: 30-days-of-code
 * Created Date: Friday November 5th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Friday November 5th 2021 12:41:48 pm
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
class Book {
 protected:
  string title;
  string author;

 public:
  Book(string t, string a) {
    title = t;
    author = a;
  }
  virtual void display() = 0;
};

// Write your MyBook class here
class MyBook : public Book {
 public:
  int price;
  //   Class Constructor
  //
  //   Parameters:
  //   title - The book's title.
  //   author - The book's author.
  //   price - The book's price.
  //
  // Write your constructor here
 public:
  MyBook(string &title, string &author, int &price)
      : Book(title, author), price(price) {}

  //   Function Name: display
  //   Print the title, author, and price in the specified format.
  //
  // Write your method here
  void display() {
    cout << "Title: " << this->title << "\n"
         << "Author: " << this->author << "\n"
         << "Price: " << this->price << endl;
  }

  // End class
};

int main() {
  string title, author;
  int price;
  getline(cin, title);
  getline(cin, author);
  cin >> price;
  MyBook novel(title, author, price);
  novel.display();
  return 0;
}
