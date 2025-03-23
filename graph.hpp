#include <iostream>
#include "vertex.hpp"

/*header file of the graph class, and also of vertex class, which used in the graph. */

namespace graph{

	
	class Graph {
	private:
		Vertex *vers;
		int v_num;
	public:
		Graph(int numOfVer);
		void add_edge(int source, int dest, int weight);
		void add_edge(int source, int dest);
		void remove_edge(int source,int dest);
		void print_graph();

		int numOfVer(){return v_num;}

		~Graph();
	};
	
}