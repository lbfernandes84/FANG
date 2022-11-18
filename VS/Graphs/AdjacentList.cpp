#include <iostream>;
#include "AdjacentList.h"

char CAdjacentList::firstChar = 'r';

GraphNode::GraphNode(const GraphNode& rhs)
{
  index = rhs.index;
  distance = rhs.distance;
  color = rhs.color;
  timeToArrive = rhs.timeToArrive;
  timeToGraphEnd = rhs.timeToGraphEnd;
  adjacents  = rhs.adjacents;
}

CAdjacentList::CAdjacentList()
{
  m_isDirected = false;
  int m_startTime = 0;
  int m_endTime = 0;
}

void CAdjacentList::SetDirected(bool flag)
{
  m_isDirected = flag;
}

void CAdjacentList::AddEdge(int u, int v)
{
  std::map<int, GraphNode>::iterator it = m_adjacentMap.find(u);
  if (it == m_adjacentMap.end())
  {
    m_adjacentMap[u] = GraphNode();
    if (!m_isDirected && m_adjacentMap.find(v) == m_adjacentMap.end())
    {
      m_adjacentMap[v] = GraphNode();
    }
  }
  m_adjacentMap[u].adjacents.push_back(v);
  m_adjacentMap[u].index = u;
  if (!m_isDirected)
  {
    m_adjacentMap[v].adjacents.push_back(u);
    m_adjacentMap[v].index = v;
  }
}

void CAdjacentList::BreathFirstSearch(int source)
{
  std::vector<GraphNode> queue;
  if (m_adjacentMap.find(source) != m_adjacentMap.end())
  {
    GraphNode &sourceNode = m_adjacentMap[source];
    sourceNode.color = GraphNode::GREY;
    sourceNode.distance = 0;
    queue.push_back(sourceNode);    
    while(queue.size() > 0)
    {       
      std::vector<int> adjacents = queue.front().adjacents;
      int current_distance= queue.front().distance;
      int current_index= queue.front().index;
      queue.erase(queue.begin());
      for (int adjacentIndex = 0; adjacentIndex < adjacents.size(); ++adjacentIndex)
      {
        if (m_adjacentMap[adjacents[adjacentIndex]].color == GraphNode::WHITE)
        {
          m_adjacentMap[adjacents[adjacentIndex]].distance = current_distance + 1;
          m_adjacentMap[adjacents[adjacentIndex]].color = GraphNode::GREY;
          queue.push_back(m_adjacentMap[adjacents[adjacentIndex]]);
        }
      }
      m_adjacentMap[current_index].color = GraphNode::BLACK;
    }
  }
}


void CAdjacentList::DeepFirstSearch()
{
  std::map<int, GraphNode>::iterator it;
  m_startTime= 0;  
  for (it = m_adjacentMap.begin(); it != m_adjacentMap.end(); ++it)
  {
    if (it->second.color == GraphNode::WHITE)
    {
      HelpDeepFirstSearch(it->first);
    }
  }
}

void CAdjacentList::HelpDeepFirstSearch(int vertexIndex)
{
  GraphNode& node = m_adjacentMap[vertexIndex];
  node.timeToArrive = ++m_startTime;
  node.color = GraphNode::GREY;
  for (int i = 0; i < node.adjacents.size(); ++i)
  {
    if (m_adjacentMap[node.adjacents[i]].color == GraphNode::WHITE)
    {
      HelpDeepFirstSearch(node.adjacents[i]);
    }
  }
  node.color = GraphNode::BLACK;
  node.timeToGraphEnd = ++m_startTime;
}

void CAdjacentList::CleanGraph()
{
  m_adjacentMap.clear();
}

void CAdjacentList::printDistanceFromNode()
{
  std::map<int, GraphNode>::iterator it;
  for (it = m_adjacentMap.begin(); it != m_adjacentMap.end(); ++it)
  { 
    std::vector<int>::iterator it2 = it->second.adjacents.begin();
    char vertex = it->first + 114;
    std::cout<< vertex <<" - "<< std::to_string(m_adjacentMap[it->first].distance)<<std::endl;
  }
}

void CAdjacentList::PrintHowMuchNodeIsDeep()
{
  std::map<int, GraphNode>::iterator it;
  for (it = m_adjacentMap.begin(); it != m_adjacentMap.end(); ++it)
  {
    std::vector<int>::iterator it2 = it->second.adjacents.begin();
    char vertex = it->first + 117;
    std::cout << vertex << " - " << std::to_string(m_adjacentMap[it->first].timeToArrive);
    std::cout <<" / " << std::to_string(m_adjacentMap[it->first].timeToGraphEnd) << std::endl;
  }
}


