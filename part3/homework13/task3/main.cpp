/*У вас есть базовый интерфейс для представления ориентированного графа.
Напишите две реализации интерфейса: ListGraph, хранящий граф в виде массива
списков смежности; MatrixGraph, хранящий граф в виде матрицы смежности.
Реализуйте конструктор, принимающий IGraph. Такой конструктор должен скопировать
переданный граф в создаваемый объект. Обратите внимание, что иногда в одну
реализацию графа копируется другая. Реализуйте все конструкторы копий и
операторы присваивания, если это необходимо.*/

#include "matrix_graph.h"

int main() {
  MatrixGraph graph(5);
  graph.addEdge(2, 5);
  graph.addEdge(1, 3);
  graph.addEdge(3, 5);
  graph.addEdge(1, 2);
  graph.addEdge(4, 3);
  graph.addEdge(1, 5);

  std::vector<int> vertices;

  graph.getNextVertices(1, vertices);
  graph.getNextVertices(3, vertices);
  graph.getNextVertices(4, vertices);

  graph.getPrevVertices(5, vertices);
  graph.getPrevVertices(2, vertices);
  graph.getPrevVertices(3, vertices);

  return 0;
}
