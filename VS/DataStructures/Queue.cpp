#include <string>
#include "Queue.h"

DataStructureQueue::DataStructureQueue()
{
  initialize();
}

DataStructureQueue::~DataStructureQueue()
{  
}

void DataStructureQueue::initialize()
{
  start = nullptr;
  end = start;  
}

int DataStructureQueue::enqueue(int key)
{
  if (!start)
  {
    start = new Queue();
    end = start;
    start->key = key;
  }
  else
  {
    Queue* aux = end;
    end = new Queue;
    end->key = key;
    aux->next = end;
  }
  return 0;
}

int DataStructureQueue::unenqueue()
{
  
  return 0;
}

std::string DataStructureQueue::printQueue()
{
  std::string result;
  result+= '{';
  Queue* curentMember = start;
  while (curentMember)
  {
    result += std::to_string(curentMember->key) + ",";
    curentMember = curentMember->next;
  }
  result += "}\n";
   return result;
}


