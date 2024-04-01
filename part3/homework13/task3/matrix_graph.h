#ifndef H_MATRIX_GRAPH
#define H_MATRIX_GRAPH

#include "igtaph.h"
#include <vector>

class MatrixGraph : public IGraph {

  std::vector<std::vector<int>> matrix;
  void resize(int newVerticesCount);

public:
  virtual ~MatrixGraph();
  MatrixGraph(int verticesCount);
  MatrixGraph();
  MatrixGraph(IGraph *_oth);
  virtual void addEdge(int from, int to) override;
  virtual int getVerticesCount() const override;
  virtual void getNextVertices(int vertex,
                               std::vector<int> &vertices) const override;
  virtual void getPrevVertices(int vertex,
                               std::vector<int> &vertices) const override;
};

#endif