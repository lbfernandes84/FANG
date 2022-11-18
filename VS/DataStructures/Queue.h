#include <iostream>
#pragma once

class DataStructureQueue
{
public:

  struct Queue
  {
    int key;
    Queue* next = nullptr;
  };
  DataStructureQueue();
  ~DataStructureQueue();
  int enqueue(int key);
  int unenqueue();
  std::string printQueue();

private:
  void initialize();
  Queue* start;  
  Queue* end;  
};