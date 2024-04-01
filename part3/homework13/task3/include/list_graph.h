#ifndef H_LIST_GRAPH
#define H_LIST_GRAPH

#include "igraph.h"
#include <map>
#include <set>
#include <vector>

class ListGraph : public IGraph {

  // Граф хранится в словаре, в котором ключ это вершина, а занчение - множетво
  // вершин, в которые можно перейти
  std::map<int, std::set<int>> graph;

  void resize(int newVerticesCount);

public:
  virtual ~ListGraph();
  ListGraph(int verticesCount);
  ListGraph();
  ListGraph(const IGraph &other);
  virtual void addEdge(int from, int to) override;
  virtual int getVerticesCount() const override;
  virtual void getNextVertices(int vertex,
                               std::vector<int> &vertices) const override;
  virtual void getPrevVertices(int vertex,
                               std::vector<int> &vertices) const override;
};

#endif