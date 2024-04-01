/*У вас есть базовый интерфейс для представления ориентированного графа.
Напишите две реализации интерфейса: ListGraph, хранящий граф в виде массива
списков смежности; MatrixGraph, хранящий граф в виде матрицы смежности.
Реализуйте конструктор, принимающий IGraph. Такой конструктор должен скопировать
переданный граф в создаваемый объект. Обратите внимание, что иногда в одну
реализацию графа копируется другая. Реализуйте все конструкторы копий и
операторы присваивания, если это необходимо.*/

#include "list_graph.h"
#include "matrix_graph.h"

int main() {
  ListGraph listGraph;
  listGraph.addEdge(1, 2);
  listGraph.addEdge(2, 3);
  listGraph.addEdge(2, 4);
  listGraph.addEdge(3, 1);
  listGraph.addEdge(3, 5);
  listGraph.addEdge(3, 7);
  listGraph.addEdge(4, 3);
  listGraph.addEdge(4, 5);
  listGraph.addEdge(5, 2);
  listGraph.addEdge(5, 6);
  listGraph.addEdge(6, 1);
  listGraph.addEdge(7, 6);

  std::vector<int> vertices;

  listGraph.getNextVertices(1, vertices);
  listGraph.getNextVertices(3, vertices);
  listGraph.getNextVertices(4, vertices);

  listGraph.getPrevVertices(5, vertices);
  listGraph.getPrevVertices(2, vertices);
  listGraph.getPrevVertices(3, vertices);

  MatrixGraph matrixGraph(listGraph);

  matrixGraph.getNextVertices(5, vertices);
  matrixGraph.getNextVertices(2, vertices);
  matrixGraph.getNextVertices(7, vertices);

  matrixGraph.getPrevVertices(1, vertices);
  matrixGraph.getPrevVertices(2, vertices);
  matrixGraph.getPrevVertices(3, vertices);

  ListGraph listGraph2(matrixGraph);
  listGraph2.getNextVertices(5, vertices);
  listGraph2.getNextVertices(2, vertices);
  listGraph2.getNextVertices(7, vertices);

  listGraph2.getPrevVertices(1, vertices);
  listGraph2.getPrevVertices(2, vertices);
  listGraph2.getPrevVertices(3, vertices);

  return 0;
}
