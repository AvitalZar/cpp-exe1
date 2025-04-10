//tchykzr@gmail.com
#pragma once
#include <iostream>
#include "vertex.hpp"
#include <string>

/*header file of the graph class, and also of vertex class, which used in the graph. */

namespace graph{

	
	class Graph {
	private:
		Vertex *vers;
		int v_num;
	public:
		Graph(unsigned int numOfVer):v_num(numOfVer)
			{vers = new Vertex[v_num];};
		void add_edge(int source, int dest, int weight);
		void add_edge(int source, int dest);
		void remove_edge(int source,int dest);
		void print_graph();

		int numOfVer(){return v_num;}
		Vertex* get(int ind);

		Graph& operator=(const Graph& other);
		Graph(const Graph& other);

		~Graph();
	};
	
}