#pragma once
#include <iostream>

class DataStructureBinaryTree {
  
  struct Node
  {
    int key = -1;
    Node* left = nullptr;
    Node* right = nullptr;
  };

public:
  void Initialize();
  void insertElement(int value);
  bool removeElement(int value);
  std::string printTree();

private:
  Node* node;
};
