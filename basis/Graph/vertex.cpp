#include "vertex.hpp"
using namespace std;

namespace graph{
	//implementation of the vertex' functions. using dinamic array - see the add and del function.
	Vertex::Vertex(){
		neighbors = new EdgeTo[2];
		numOfNeighbors = 0;
	}
	void Vertex::add_neighbor(int num){
		if(num<0){
			throw string("neighbor's number must be positive.");
		}
		for(int i = 0;i<numOfNeighbors;i++){
			if(neighbors[i].vertex==num)
				return;
		}
		//if there's not enough place in the array
		if((sizeof(neighbors)/sizeof(Vertex))<numOfNeighbors){
			neighbors[numOfNeighbors++].vertex = num;
		}
		else{
			EdgeTo *temp = neighbors;
			neighbors = new EdgeTo[2*numOfNeighbors];
			for(int i = 0;i<numOfNeighbors;i++){
				neighbors[i] = temp[i];
			}
			neighbors[numOfNeighbors++].vertex = num;
			delete[] temp;
		}
		set_weight(num,1);
	}

	void Vertex::add_neighbor(int num, int weight){
		add_neighbor(num);
		set_weight(num,weight);
	}

	void Vertex::del_neighbor(int num){
		if(!isNeigh(num)){
			throw string("can't delete unexist neighbor.");
		}
		for(int i = 0;i<numOfNeighbors;i++){
			if(neighbors[i].vertex==num){
				//deleting this neighbor and decreasing the num of neighbors, moving the last neighbor to this place.
				neighbors[i] = neighbors[--numOfNeighbors];
								break;
			}
		}
		//decreasing the array size if needed - when we can decrease by half and stay with half null array.
		if(numOfNeighbors<(sizeof(neighbors)/sizeof(Vertex))/4){
			EdgeTo *temp = neighbors;
			neighbors = new EdgeTo[numOfNeighbors*2];
			for(int i = 0;i<numOfNeighbors;i++){
				neighbors[i] = temp[i];
			}
			delete[] temp;
		}
	}

	void Vertex::set_weight(int ver, int weight){
		if(!isNeigh(ver))
			throw string("can't set weight because there's no neighbor as "+ver);
		for(int i = 0;i<numOfNeighbors;i++){
			if(neighbors[i].vertex==ver){
				neighbors[i].weight = weight;
				break;
			}
		}
	}

	bool Vertex::isNeigh(int ver)
	{
		for(int i = 0;i<numOfNeigh();i++){
			if(getNeigh()[i].vertex==ver){
				return true;
			}
		}
		return false;
	}

	int Vertex::getWeightOf(int ver)
	{
		if(!isNeigh(ver))
			throw string("can't get weight because there's no neighbor as "+ver);
		for(int i = 0;i<numOfNeigh();i++){
			if(getNeigh()[i].vertex==ver){
				return getNeigh()[i].weight;
			}
		}
		return 0;
	}

	string Vertex::toString()
	{
		string ans = string();
		for(int i = 0;i<numOfNeighbors;i++){
			if(i>0)
				ans += ";";
			ans += "v-"+to_string(neighbors[i].vertex)
					+","+"w-"+to_string(neighbors[i].weight);
			
		}
		return ans;
	}

	Vertex::~Vertex(){
		delete[] neighbors;
	}
	
}
