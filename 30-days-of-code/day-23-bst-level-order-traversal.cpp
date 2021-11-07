/*
 * File: /day-23-bst-level-order-traversal.cpp
 * Project: 30-days-of-code
 * Created Date: Sunday November 7th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Sunday November 7th 2021 12:02:39 am
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node {
 public:
  int data;
  Node *left, *right;
  Node(int d) {
    data = d;
    left = right = NULL;
  }
};

class Solution {
 public:
  Node* insert(Node* root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node* cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }
      return root;
    }
  }

  void levelOrder(Node* root) {
    // Write your code here
    queue<int> queue;
  }

};  // End of Solution

int main() {
  Solution myTree;
  Node* root = NULL;
  int T, data;
  cin >> T;
  while (T-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }
  myTree.levelOrder(root);
  return 0;
};