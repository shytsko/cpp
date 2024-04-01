#include "matrix_graph.h"
#include <vector>

void MatrixGraph::resize(int newVerticesCount) {
  matrix.resize((std::size_t)newVerticesCount);
  for (std::vector<int> &row : matrix)
    row.resize((std::size_t)newVerticesCount);
}

MatrixGraph::~MatrixGraph() {}

MatrixGraph::MatrixGraph(int verticesCount) { resize(verticesCount); }

MatrixGraph::MatrixGraph() {}

MatrixGraph::MatrixGraph(IGraph *_oth) {
  resize(_oth->getVerticesCount());
  for (int fromVertex = 1; fromVertex <= _oth->getVerticesCount();
       fromVertex++) {
    std::vector<int> toVertices;
    _oth->getNextVertices(fromVertex, toVertices);
    for (int toVertex : toVertices)
      addEdge(fromVertex, toVertex);
  }
}

void MatrixGraph::addEdge(int from, int to) {
  if ((std::size_t)from > matrix.size() || (std::size_t)to > matrix.size())
    resize(std::max(from, to));

  matrix[(std::size_t)from - 1][(std::size_t)to - 1] = 1;
}

int MatrixGraph::getVerticesCount() const { return (int)matrix.size(); }

void MatrixGraph::getNextVertices(int vertex,
                                  std::vector<int> &vertices) const {
  if (vertex > matrix.size())
    return;

  vertices.clear();
  for (std::size_t i = 0; i < matrix.size(); i++)
    if (matrix[(std::size_t)vertex - 1][i] > 0)
      vertices.push_back((int)i + 1);
}

void MatrixGraph::getPrevVertices(int vertex,
                                  std::vector<int> &vertices) const {
  if (vertex > matrix.size())
    return;

  vertices.clear();
  for (std::size_t i = 0; i < matrix.size(); i++)
    if (matrix[i][(std::size_t)vertex - 1] > 0)
      vertices.push_back((int)i + 1);
}