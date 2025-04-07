//tchykzr@gmail.com
#include "doctest.h"
#include "iostream"
#include "../../basis/Graph/vertex.hpp"
using namespace graph;

TEST_CASE("vertex add neigbors"){
	std::cout<<"1";
	Vertex v;
	v.add_neighbor(1);
	v.add_neighbor(2);

	
	CHECK(v.numOfNeigh()==2);
	CHECK(v.getNeigh()[1].vertex==2);
	CHECK_THROWS(v.add_neighbor(-1));
	bool is2neigh = false;
	for(int i=0;i<v.numOfNeigh();i++){
		if(v.getNeigh()[i].vertex==2){
			is2neigh = true;
		}
	}
	CHECK(is2neigh);

	v.add_neighbor(3);
	v.add_neighbor(4);
	v.add_neighbor(5);
	v.add_neighbor(6);
	v.add_neighbor(7);
	CHECK(v.numOfNeigh()==7);
	CHECK(v.getNeigh()[6].vertex==7);
}

TEST_CASE("vertex weights"){
	std::cout<<"2";
	Vertex v;
	v.add_neighbor(1,3);
	CHECK(v.isNeigh(1));
	v.add_neighbor(2);
	CHECK(v.getWeightOf(1)==3);
	CHECK(v.getWeightOf(2)==1);
	v.set_weight(2,3);
	CHECK(v.getWeightOf(2)==3);
}

TEST_CASE("vertex deleting"){
	std::cout<<"3";
	Vertex v;
	v.add_neighbor(1);
	v.del_neighbor(1);
	CHECK(!v.isNeigh(1));
	v.add_neighbor(2);
	v.add_neighbor(2);
	v.del_neighbor(2);
	CHECK(!v.isNeigh(2));
}

TEST_CASE("vertex to string"){
	std::cout<<"4";
	Vertex v;
	v.add_neighbor(1);
	v.add_neighbor(1);
	v.add_neighbor(2);
	v.del_neighbor(2);
	v.add_neighbor(3,4);
	CHECK(v.toString()=="v-1,w-1;v-3,w-4");
}

TEST_CASE("vertex exceptions"){
	std::cout<<5;
	Vertex v;
	CHECK_THROWS(v.del_neighbor(1));
	CHECK_THROWS(v.getWeightOf(1));
}