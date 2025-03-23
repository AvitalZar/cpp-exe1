#include <iostream>

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

		~Graph();
	};
	

	class Vertex
	{
	private:
		EdgeTo *neighbors;
		int numOfNeighbors;
	public:
		Vertex();
		void add_neighbor(int num);
		void add_neighbor(int num, int weight);
		void del_neighbor(int num);
		void set_weight(int ver, int weight);
		std::string toString();
		~Vertex();
	};

	typedef struct EdgeTo{
		int vertex = -1;
		int weight = 0;
	};
	
	
}