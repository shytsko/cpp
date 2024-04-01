#include "matrix_graph.h"
#include <vector>

// Изменение размера матрицы. Сначала до заданного размера увеличивается
// количество строк, затем до того же размера увеличивается каждая строка
void MatrixGraph::resize(int newVerticesCount) {
  matrix.resize((std::size_t)newVerticesCount);
  for (std::vector<int> &row : matrix)
    row.resize((std::size_t)newVerticesCount);
}

MatrixGraph::~MatrixGraph() {}

MatrixGraph::MatrixGraph(int verticesCount) { resize(verticesCount); }

MatrixGraph::MatrixGraph() {}

MatrixGraph::MatrixGraph(const IGraph &other) {
  resize(other.getVerticesCount());
  for (int fromVertex = 1; fromVertex <= other.getVerticesCount();
       fromVertex++) {
    std::vector<int> toVertices;
    other.getNextVertices(fromVertex, toVertices);
    for (int toVertex : toVertices)
      addEdge(fromVertex, toVertex);
  }
}

void MatrixGraph::addEdge(int from, int to) {
  // Если одна из вершин больше текущего размера, граф расширяется
  if ((std::size_t)from > matrix.size() || (std::size_t)to > matrix.size())
    resize(std::max(from, to));

  matrix[(std::size_t)from - 1][(std::size_t)to - 1] = 1;
}

int MatrixGraph::getVerticesCount() const { return (int)matrix.size(); }

void MatrixGraph::getNextVertices(int vertex,
                                  std::vector<int> &vertices) const {
  vertices.clear();

  if (vertex > matrix.size())
    return;

  for (std::size_t i = 0; i < matrix.size(); i++)
    if (matrix[(std::size_t)vertex - 1][i] > 0)
      vertices.push_back((int)i + 1);
}

void MatrixGraph::getPrevVertices(int vertex,
                                  std::vector<int> &vertices) const {

  vertices.clear();

  if (vertex > matrix.size())
    return;

  for (std::size_t i = 0; i < matrix.size(); i++)
    if (matrix[i][(std::size_t)vertex - 1] > 0)
      vertices.push_back((int)i + 1);
}