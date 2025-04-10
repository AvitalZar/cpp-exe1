//tchykzr@gmail.com
#pragma once
#include <iostream>
#include "./Graph/graph.hpp"
#include "../dataStructs/queInt.hpp"
#include "../dataStructs/stack.hpp"
#include "../dataStructs/priority_queue.hpp"
#include "../dataStructs/pq_prim.hpp"


namespace graph{

	class Algorithms{

	public:
		Algorithms(){}
		Graph bfs(Graph& g, int s);
		Graph dfs(Graph& g, int s);
		Graph dijkstra(Graph& g, int s);
		Graph prim(Graph& g, int s);
		Graph kruskal(Graph& g, int s);
	};
}