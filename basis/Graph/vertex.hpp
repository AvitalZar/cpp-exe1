#pragma once
#include <iostream>
#include <string>
namespace graph{

	struct EdgeTo{
		int vertex = -1;
		int weight = 0;
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
		const EdgeTo* getNeigh(){return neighbors;}
		int numOfNeigh(){return numOfNeighbors;}
		std::string toString();
		~Vertex();
	};

}