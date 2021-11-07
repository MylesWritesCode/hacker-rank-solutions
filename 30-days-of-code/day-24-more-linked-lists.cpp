/**
 * File: /day-24-more-linked-lists.cpp
 * Project: 30-days-of-code
 * Purpose:
 *https://www.hackerrank.com/challenges/30-linked-list-deletion/problem
 *
 * @author Myles Berueda
 * @date   Saturday November 6th 2021
 * -----
 * Modified: Saturday November 6th 2021 10:40:51 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 **/
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int d) {
    data = d;
    next = NULL;
  }
};
class Solution {
 public:
  Node* removeDuplicates(Node* head) {
    if (head == NULL)
      return NULL;
    // Write your code here
    Node* curr_node = head;

    // This whole thing feels hacky, but it works for the test cases:
    while (curr_node->next != NULL) {
      if (curr_node->data == curr_node->next->data) {
        curr_node->next = curr_node->next->next;
      } else {
        curr_node = curr_node->next;
      }
    }

    return head;
  }

  Node* insert(Node* head, int data) {
    Node* p = new Node(data);
    if (head == NULL) {
      head = p;

    } else if (head->next == NULL) {
      head->next = p;

    } else {
      Node* start = head;
      while (start->next != NULL) {
        start = start->next;
      }
      start->next = p;
    }
    return head;
  }
  void display(Node* head) {
    Node* start = head;
    while (start) {
      cout << start->data << " ";
      start = start->next;
    }
  }
};

int main() {
  Node* head = NULL;
  Solution mylist;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    head = mylist.insert(head, data);
  }
  head = mylist.removeDuplicates(head);

  mylist.display(head);
}