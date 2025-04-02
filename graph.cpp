#include "graph.hpp"
using namespace std;

namespace graph{
	

	void Graph::add_edge(int source, int dest, int weight){
		if(dest<0||dest>numOfVer()||source<0||source>numOfVer())
			throw std::string("The vertexes' numbers are between 0-"+numOfVer());
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
		for(int i = 0;i<numOfVer();i++){
			cout << i+": "+vers[i].toString() << endl;
		}
	}

	Vertex* Graph::get(int ind){
		if(ind<numOfVer()||ind<0){
			return vers+ind;
		}
		throw string("there's no vertex in that index.");
	}

	Graph::~Graph()
	{
		delete[] vers;
	}
}