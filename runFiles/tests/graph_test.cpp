//tchykzr@gmail.com
#include "doctest.h"
#include "../../basis/Graph/graph.hpp"
using namespace graph;

TEST_CASE("Graph basic functionality") {
	Graph g(3);

	CHECK(g.numOfVer() == 3);

	for (int i = 0; i < 3; ++i) {
		CHECK(g.get(i)->numOfNeigh() == 0);
	}

	g.add_edge(0, 1);
	g.add_edge(1, 2, 7);

	CHECK(g.get(0)->isNeigh(1));
	CHECK(g.get(1)->isNeigh(2));
	CHECK(g.get(2)->isNeigh(1));

	//weights:
	CHECK(g.get(0)->getWeightOf(1) == 1);
	CHECK(g.get(2)->getWeightOf(1)==7);
	
	g.print_graph();

	g.remove_edge(1, 2);
	CHECK_FALSE(g.get(1)->isNeigh(2));

	g.print_graph();
}

TEST_CASE("Exceptions"){
	Graph g(4);

	CHECK_THROWS(g.add_edge(0,4));
	CHECK_THROWS(g.add_edge(-1,3));
	CHECK_THROWS(g.remove_edge(2,-5));
	CHECK_THROWS(g.remove_edge(2,0));

	CHECK_THROWS(g.get(4));
}