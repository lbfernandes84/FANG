#pragma once

class DataStructureStack
{
public:
  
  struct Stack
  {
    int key;
    Stack* next = nullptr;  
  };

  DataStructureStack();
  void push(int key);
  int pop();
  void printStack();

private:
  Stack* top;
};