#include "doctest.h"
#include "../../basis/Graph/vertex.hpp"
using namespace graph;

TEST_CASE("add neigbors"){
	Vertex v;
	v.add_neighbor(1);
	v.add_neighbor(2);
	
	CHECK(v.numOfNeigh()==2);
	CHECK_THROWS(v.add_neighbor(-1));
	bool is2neigh = false;
	for(int i=0;i<v.numOfNeigh();i++){
		if(v.getNeigh()[i].vertex==2){
			is2neigh = true;
		}
	}
	CHECK(is2neigh);
}

TEST_CASE("weights"){
	Vertex v;
	v.add_neighbor(1,3);
	CHECK(v.isNeigh(1));
	v.add_neighbor(2);
	CHECK(v.getWeightOf(1)==3);
	CHECK(v.getWeightOf(2)==1);
	v.set_weight(2,3);
	CHECK(v.getWeightOf(2)==3);
}

TEST_CASE("deleting"){
	Vertex v;
	v.add_neighbor(1);
	v.del_neighbor(1);
	CHECK(!v.isNeigh(1));
	v.add_neighbor(2);
	v.add_neighbor(2);
	v.del_neighbor(2);
	CHECK(!v.isNeigh(2));
}

TEST_CASE("to string"){
	Vertex v;
	v.add_neighbor(1);
	v.add_neighbor(1);
	v.add_neighbor(2);
	v.del_neighbor(2);
	v.add_neighbor(3,4);
	CHECK(v.toString()=="v-1,w-1;v-3,w-4");
}

TEST_CASE("exceptions"){
	Vertex v;
	CHECK_THROWS(v.del_neighbor(1));
	CHECK_THROWS(v.getWeightOf(1));
}