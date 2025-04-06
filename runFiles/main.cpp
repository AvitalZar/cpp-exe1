#include "../basis/Graph/graph.hpp"
#include "../dataStructs/queInt.hpp"
#include "../dataStructs/stack.hpp"
#include <iostream>
using namespace std;
using namespace graph;

int main(){
	Graph g(5);
	g.add_edge(1,5);
	g.add_edge(2,4);
	g.add_edge(4,3);
	g.add_edge(2,3);
	g.add_edge(3,1);
	g.print_graph();
}