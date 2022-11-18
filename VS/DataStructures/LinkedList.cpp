#include <iostream>
#include "LinkedList.h"

CLinkedList::CLinkedList()
{
  list = nullptr;
  last = list;
}

void CLinkedList::AddValue(int value)
{
  LinkedListNode* aux;
  aux = new LinkedListNode();
  aux->val = value;
  if (last)
  {
    last->next = aux;
    last = aux;
  }
  else
  {
    last = aux;
    list = last;
  }
}

int CLinkedList::RemoveValue()
{
  int value = -999;
  LinkedListNode* aux;
  if (last)
  {
    aux = last;
    value = last->val;
    last = nullptr;
    delete last;
    last = aux;
  }
  return value;
}

void CLinkedList::Print()
{
  LinkedListNode* aux = list;
  while (aux)
  {
    std::cout << "Element: " << aux->val << " ," << std::endl;
    aux = aux->next;
  }
}