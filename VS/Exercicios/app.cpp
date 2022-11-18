#include <iostream>

using namespace std;

struct LinkedList
{
  int data = -1;
  LinkedList* next = nullptr;
};

void addItem(LinkedList* list, int value)
{
  list->data = value;
}

void revertLinkedList(LinkedList* list)
{
  LinkedList* aux = list;
  while (list)
  {
    //cout << "Address list: " << list << ", Address aux: " << aux << endl;
    list = nullptr;
    list = aux->next;
    //cout << "Address list: " << list << ", Address aux: " << aux << endl;
    //cout << "Next de auxiliar: " << aux->next->data << endl << endl;
    list->next = aux;
    aux = aux->next;
  }
}

int main(int argc, char *argv[])
{  
  return 0;
}