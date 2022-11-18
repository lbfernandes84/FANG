#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "LinkedList.h"

void StackHandler();
void QueueHandler();
void BinaryTreeHandler();
void LinkedListHandler();

int main(int argc, char* argv)
{
  //StackHandler();
  QueueHandler();
  //BinaryTreeHandler();
  //LinkedListHandler();
}

void StackHandler()
{
  std::cout <<"--------------Stack----------------------" << std::endl;
  DataStructureStack stack;
  stack.push(5);
  stack.push(10);
  stack.push(15);
  stack.push(20);
  stack.push(25);
  stack.push(30);
  stack.printStack();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.pop();
  stack.printStack();
}

void QueueHandler()
{
  std::cout << "--------------Queue----------------------" << std::endl;
  DataStructureQueue queue;
  queue.enqueue(3);
  queue.enqueue(6);
  queue.enqueue(9);
  queue.enqueue(12);
  queue.enqueue(15);
  queue.enqueue(18);
  //queue.unenqueue();
  //queue.unenqueue();
  std::string a = queue.printQueue();
  //std::cout<<"Queue: "<< a <<std::endl;;
}

void BinaryTreeHandler()
{
  std::cout << "--------------BinaryTree----------------------" << std::endl;
  DataStructureBinaryTree binaryTree;
  binaryTree.Initialize();
  binaryTree.insertElement(6);
  binaryTree.insertElement(5);
  binaryTree.insertElement(2);
  binaryTree.insertElement(5);
  binaryTree.insertElement(7);
  binaryTree.insertElement(8);  
  binaryTree.removeElement(5);
}

void LinkedListHandler()
{
  std::cout << "--------------LinkedList----------------------" << std::endl;
  CLinkedList linkedList;
  linkedList.AddValue(1);
  linkedList.AddValue(3);
  linkedList.AddValue(5);
  linkedList.Print();
  linkedList.RemoveValue();
  linkedList.RemoveValue();
  linkedList.Print();
}