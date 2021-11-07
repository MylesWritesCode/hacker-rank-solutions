/**
 * File: /day-23-bst-level-order-traversal.cpp
 * Project: 30-days-of-code
 * Purpose: https://www.hackerrank.com/challenges/30-binary-trees/problem
 * 
 * @author Myles Berueda
 * @date   Saturday November 6th 2021
 * -----
 * Modified: Saturday November 6th 2021 9:59:15 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
**/
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
    queue<Node*> queue;
    
    if (root == NULL) return;
    
    queue.push(root);
    
    while (queue.empty() == false) {
      Node* node = queue.front();
      cout << node->data << " ";
      queue.pop();
      
      if (node->left != NULL) queue.push(node->left);
      if (node->right != NULL) queue.push(node->right);
    }
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