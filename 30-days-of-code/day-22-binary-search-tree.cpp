/*
 * File: /day-22-binary-search-tree.cpp
 * Project: 30-days-of-code
 * Created Date: Saturday November 6th 2021
 * Author: Myles Berueda
 * -----
 * Last Modified: Saturday November 6th 2021 10:43:23 pm
 * -----
 * Copyright (c) 2021 MylesWritesCode
 * -----
 * HISTORY
 */
#include <cstddef>
#include <iostream>

using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
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

  int getHeight(Node* root) {
    // Write your code here
    if (root == NULL) {
      return -1; // If this isn't -1, then this whole function will return 
                 // actual_max_height + 1, which is wrong.
    }
    
    // Should do this recursively
    int left_depth = getHeight(root->left);
    int right_depth = getHeight(root->right);

    // Return the larger depth + 1
    return (max(left_depth, right_depth) + 1);
  }

};  // End of Solution

int main() {
  Solution myTree;
  Node* root = NULL;
  int t;
  int data;

  cin >> t;

  while (t-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }
  int height = myTree.getHeight(root);
  cout << height;

  return 0;
}
