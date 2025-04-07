//tchykzr@gmail.com
#include "../basis/Graph/graph.hpp"
#include "../basis/algorithms.hpp"
#include "../dataStructs/queInt.hpp"
#include "../dataStructs/stack.hpp"
#include <iostream>
using namespace std;
using namespace graph;

int main(){
	Graph g(5);
	g.add_edge(1,0);
	g.add_edge(2,4);
	g.add_edge(4,3,5);
	g.add_edge(2,3);
	g.add_edge(3,1,2);
	g.print_graph();

	Algorithms a;
	Graph bfs = a.bfs(g,1);
	bfs.print_graph();
	cout<<"end of main"<<endl;


	//dijkstra - workinggg!!!!!
	Graph d(6);
	d.add_edge(0,4);
	d.add_edge(0,3,2);
	d.add_edge(4,1,3);
	d.add_edge(3,1);
	d.add_edge(2,5,5);
	d.add_edge(2,3,2);

	Graph dijkstra = a.dijkstra(d,0);
	dijkstra.print_graph();

	Graph prim = a.prim(d,0);
	prim.print_graph();
}