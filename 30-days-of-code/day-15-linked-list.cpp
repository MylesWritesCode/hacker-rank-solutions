/*
 * File: /day-15-linked-list.cpp
 * Project: 30-days-of-code
 * Created Date: Friday November 5th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Friday November 5th 2021 2:23:35 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class Node {
 public:
  T data = NULL;
  Node* prev = nullptr;
  Node* next = nullptr;

 public:
  Node(){};
  Node(T data) : data(data){};
  Node(T data, T* prev) : data(data), prev(prev){};
  Node(T data, T* prev, T* next) : data(data), prev(prev), next(next){};
};

template <typename T>
class LinkedList {
 public:
  Node<T>* head = nullptr;
  Node<T>* tail = nullptr;

 public:
  LinkedList(){};
  LinkedList(Node<T>* head) : head(head) {
    Node<T>* current_pointer = head;
    while (current_pointer->next != nullptr) {
      current_pointer = current_pointer->next;
    }

    tail = current_pointer;
  }

  void insert(T data) {
    Node<T>* node = new Node<T>(data);
    if (head == nullptr) {
      head = node;
      tail = node;
    } else {
      node->prev = tail;
      tail->next = node;
      tail = node;
    }
  }

  void display() {
    Node<T>* current_pointer = head;
    while (current_pointer->next != nullptr) {
      cout << current_pointer->data << " ";
      current_pointer = current_pointer->next;
    }
    cout << current_pointer->data << endl;
  }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  // Get user input:                              // e.g.
  // - T number of elements that will be inputted // T = 4
  // 2                                            // first data = 2
  // 3
  // 4
  // 1                                            // fourth data = 1
  // Resulting array: { 2, 3, 4, 1 }
  int num_elements = 0;
  LinkedList<int> list;
  // cout << "Enter how many elements you plan to insert: ";
  cin >> num_elements;
  // cout << endl;

  // cout << "Enter the elements: ";
  while (num_elements > 0) {
    int element;
    cin >> element;
    list.insert(element);
    num_elements--;
  }
  
  list.display();

  return 0;
};