#include "BinaryTree.h"

void DataStructureBinaryTree::Initialize()
{
  node = nullptr;
}

void DataStructureBinaryTree::insertElement(int value)
{
  if (node)
  {
    Node* aux  = node;      
    if (value < node->key)
    {
      node = node->left;
      insertElement(value);
      aux->left = node;
      node = aux;
    }
    if (value >= node->key)
    {
      node = node->right;
      insertElement(value);
      aux->right = node;
    }
    node = aux;
  }
  else
  {
    node = new Node;
    node->key = value;
  }
}

bool DataStructureBinaryTree::removeElement(int value)
{
  bool result = false;
  if (node)
  {
    if (value == node->key && !(node->left && node->right))
    {
      result = true;
      node = nullptr;
      delete node;
    }
    else 
    {
      Node* aux;
      aux = node;
      if (node->left && value < node->key)
      {
        node = node->left;
        result = removeElement(value);
      }
      else if (node->right && value >= node->right->key)
      {
        node = node->right;
        result = removeElement(value);
      }
      node = aux;
    }
  }
  return result;
}

std::string DataStructureBinaryTree::printTree()
{
  return std::string();
}
