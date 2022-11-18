#pragma once

struct LinkedListNode
{
  int val = -999;
  LinkedListNode* next = nullptr;
};

class CLinkedList {
  LinkedListNode* list;
  LinkedListNode* last;

public:
  CLinkedList();
  void AddValue(int value);
  int RemoveValue();
  void Print();
};