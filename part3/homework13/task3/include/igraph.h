#ifndef H_IGRAPH
#define H_IGRAPH

#include <vector>

class IGraph {
public:
  virtual ~IGraph();
  IGraph();
  IGraph(const IGraph &other);
  virtual void addEdge(int from, int to) = 0;
  virtual int getVerticesCount() const = 0;
  virtual void getNextVertices(int vertex,
                               std::vector<int> &vertices) const = 0;
  virtual void getPrevVertices(int vertex,
                               std::vector<int> &vertices) const = 0;
};

#endif