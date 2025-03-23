#include "graph.hpp"
#include <string>
using namespace std;

namespace graph{
	Graph::Graph(int numOfVer){
		v_num = numOfVer;
		vers = new Vertex[v_num];
	}

	void Graph::add_edge(int source, int dest, int weight){
		if(dest<0||dest>v_num||source<0||source>v_num)
			throw std::string("The vertexes' numbers are between 0-"+v_num);
		vers[source].add_neighbor(dest,weight);//intiliaze the weight automatically.
		vers[dest].add_neighbor(source,weight);
	}
	void Graph::add_edge(int source,int dest){
		add_edge(source,dest,1);
	}

	void Graph::remove_edge(int source, int dest){
		vers[source].del_neighbor(dest);
		vers[dest].del_neighbor(source);
	}

	void Graph::print_graph(){
		for(int i = 0;i<v_num;i++){
			cout << i+": "+vers[i].toString() << endl;
		}
	}

	Graph::~Graph(){
		delete[] vers;
	}



	//implementation of the vertex' functions. using dinamic array - see the add and del function.
	Vertex::Vertex(){
		neighbors = new EdgeTo[2];
		numOfNeighbors = 0;
	}
	void Vertex::add_neighbor(int num){
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
		for(int i = 0;i<numOfNeighbors;i++){
			if(neighbors[i].vertex==ver)
				neighbors[i].weight = weight;
				break;
		}
	}

	string Vertex::toString(){
		string ans = string();
		for(int i = 0;i<numOfNeighbors;i++){
			if(i>0)
				ans += ";";
			ans += "v-"+to_string(neighbors[i].vertex)
					+","+"w-"+to_string(neighbors[i].weight);
			
		}
	}

	Vertex::~Vertex(){
		delete[] neighbors;
	}
}