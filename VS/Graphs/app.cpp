#include "AdjacentList.h"

int main(int* argc, char *argv[])
{
  CAdjacentList adjacentList;
  //r = 0, s = 1,  t= 2, u = 3
  //v = 4, w = 5,  x= 6, y = 7
  adjacentList.AddEdge(0, 1);//r - s
  adjacentList.AddEdge(0, 4);//r - v
  adjacentList.AddEdge(1, 5);//s - w
  adjacentList.AddEdge(2, 3);//t - u
  adjacentList.AddEdge(2, 5);//t - w
  adjacentList.AddEdge(2, 6);//t - x
  adjacentList.AddEdge(3, 6);//t - u
  adjacentList.AddEdge(3, 7);// u - y
  adjacentList.AddEdge(5, 6);//w - x
  adjacentList.AddEdge(6, 7);//x -y  
  adjacentList.BreathFirstSearch(1);
  //adjacentList.printDistanceFromNode();
  adjacentList.CleanGraph();
  adjacentList.SetDirected(true);
  adjacentList.AddEdge(0, 1);//u - v  
  adjacentList.AddEdge(0, 3);//u - x
  adjacentList.AddEdge(1, 4);//v - y  
  adjacentList.AddEdge(2, 4);//w - y  
  adjacentList.AddEdge(2, 5);//w - z
  adjacentList.AddEdge(3, 1);//x - v  
  adjacentList.AddEdge(4, 3);//y - x  
  adjacentList.AddEdge(5, 5);//z - z  
  adjacentList.DeepFirstSearch();
  adjacentList.PrintHowMuchNodeIsDeep();
  return 0;
}