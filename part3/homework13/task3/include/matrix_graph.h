#ifndef H_MATRIX_GRAPH
#define H_MATRIX_GRAPH

#include "igraph.h"
#include <vector>

class MatrixGraph : public IGraph {

  // Грав хранится в виде квадратной матрицы с размером, равным количеству
  // вершин. Ребро задается установкой 1 в ячейке, номер строки которой это
  // начало ребра, а номер столбца - конец ребра
  std::vector<std::vector<int>> matrix;

  void resize(int newVerticesCount);

public:
  virtual ~MatrixGraph();
  MatrixGraph(int verticesCount);
  MatrixGraph();
  MatrixGraph(const IGraph &other);
  virtual void addEdge(int from, int to) override;
  virtual int getVerticesCount() const override;
  virtual void getNextVertices(int vertex,
                               std::vector<int> &vertices) const override;
  virtual void getPrevVertices(int vertex,
                               std::vector<int> &vertices) const override;
};

#endif