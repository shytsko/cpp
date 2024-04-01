#include "list_graph.h"
#include <map>
#include <set>
#include <vector>

// Выделение памяти под новые вершины. Словарь дополняется новыми парами до
// достижения заданного количества вершин
void ListGraph::resize(int newVerticesCount) {
  while (graph.size() < newVerticesCount)
    graph[(int)graph.size() + 1] = std::set<int>();
}

ListGraph::~ListGraph() {}

ListGraph::ListGraph(int verticesCount) { resize(verticesCount); }

ListGraph::ListGraph() {}

ListGraph::ListGraph(const IGraph &other) {
  resize(other.getVerticesCount());
  for (int fromVertex = 1; fromVertex <= other.getVerticesCount();
       fromVertex++) {
    std::vector<int> toVertices;
    other.getNextVertices(fromVertex, toVertices);
    for (int toVertex : toVertices)
      addEdge(fromVertex, toVertex);
  }
}

void ListGraph::addEdge(int from, int to) {
  // Если одна из вершин больше текущего размера, граф расширяется
  if ((std::size_t)from > graph.size() || (std::size_t)to > graph.size())
    resize(std::max(from, to));

  graph[from].insert(to);
}

int ListGraph::getVerticesCount() const { return (int)graph.size(); }

void ListGraph::getNextVertices(int vertex, std::vector<int> &vertices) const {
  vertices.clear();

  if (vertex > graph.size())
    return;

  vertices.resize(graph.at(vertex).size());
  std::copy(graph.at(vertex).begin(), graph.at(vertex).end(), vertices.begin());
}

void ListGraph::getPrevVertices(int vertex, std::vector<int> &vertices) const {
  vertices.clear();

  if (vertex > graph.size())
    return;

  for (const auto &[vertexFrom, verticesTo] : graph)
    if (verticesTo.contains(vertex))
      vertices.push_back(vertexFrom);
}