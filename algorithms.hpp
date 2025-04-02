#include <iostream>
#include "graph.hpp"
#include "queInt.hpp"
#include "stack.hpp"

namespace graph{

	class Algorithms{

	public:
		Algorithms(){}
		Graph bfs(Graph g, int s);
		Graph dfs(Graph g, int s);
		Graph dijkstra(Graph g, int s);
		Graph prim(Graph g, int s);
		Graph kruskal(Graph g, int s);
	};
}