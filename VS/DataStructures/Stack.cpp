#include "Stack.h"
#include <iostream>

using namespace std;

DataStructureStack::DataStructureStack()
{  
  top = nullptr;
}

int DataStructureStack::pop()
{
  int value = -1;
  Stack* aux;
  if(top)
  {
    aux = top;
    value = top->key;
    top = top->next;
    delete aux;
    aux = nullptr;
  }
  return value;
}

void DataStructureStack::push(int key)
{
  Stack* aux = top;
  top = new Stack();
  if (aux)
  {
    top->next = aux;
  }
  top->key = key;
}

void DataStructureStack::printStack()
{
  cout << '{';
  Stack* curentMember = top;
  while (curentMember)
  {
    cout << curentMember->key << ",";
    curentMember = curentMember->next;
  }
  cout << '}'<<endl;
}

