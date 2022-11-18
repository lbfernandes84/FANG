#include "Common.h";

#pragma once

class GraphNode
{
public:
  enum {
    WHITE,
    GREY,
    BLACK
  };

  GraphNode() {};
  GraphNode(const GraphNode& rhs);
  int index = -1;
  int distance = INT_MAX;
  int color = GraphNode::WHITE;
  int timeToArrive = 0;
  int timeToGraphEnd= 0;
  std::vector<int> adjacents;
};

class CAdjacentList
{
  static char firstChar;
  int m_startTime;
  int m_endTime;
  bool m_isDirected;
  std::map<int, GraphNode> m_adjacentMap;
public:
  CAdjacentList();
  void SetDirected(bool);
  void AddEdge(int a, int b);
  void BreathFirstSearch(int source);
  void DeepFirstSearch();
  void HelpDeepFirstSearch(int vertexIndex);
  void CleanGraph();
  void printDistanceFromNode();
  void PrintHowMuchNodeIsDeep();
};