//tchykzr@gmail.com
#include "graph.hpp"
using namespace std;

namespace graph{
	

	void Graph::add_edge(int source, int dest, int weight){
		if(dest<0||dest>=numOfVer()||source<0||source>=numOfVer())
			throw out_of_range("The vertexes' numbers are between 0-"+numOfVer());
		vers[source].add_neighbor(dest,weight);//intiliaze the weight automatically.
		vers[dest].add_neighbor(source,weight);
	}
	void Graph::add_edge(int source,int dest){
		add_edge(source,dest,1);
	}

	void Graph::remove_edge(int source, int dest){
		if(dest<0||dest>=numOfVer()||source<0||source>=numOfVer())
			throw out_of_range("Can't remove edge because the vertices' numbers are between 0-"+numOfVer());
		vers[source].del_neighbor(dest);
		vers[dest].del_neighbor(source);
	}

	void Graph::print_graph(){
		cout<<"print graph with "<<numOfVer()<<" vertices:"<<endl;
		cout<<"vertex number: v-neigbor number, w-weight of edge; etc."<<endl;
		for(int i = 0;i<numOfVer();i++){
			if(vers[i].numOfNeigh()>0)
				cout << i<<": "<<vers[i].toString() << endl;
		}
	}

	Vertex* Graph::get(int ind){
		if(ind<numOfVer()||ind<0){
			return vers+ind;
		}
		throw out_of_range("there's no vertex in that index.");
	}

/*	Graph& Graph::operator=(const Graph &other){
		if (this == &other)
			return *this;
	
		delete[] vers;
	
		v_num = other.v_num;
		vers = new Vertex[v_num];
	
		for (int i = 0; i < v_num; ++i)
			vers[i] = other.vers[i];
	
		return *this;
	}*/

	Graph::Graph(const Graph &other){
		v_num = other.v_num;
		vers = new Vertex[v_num];
	
		for (int i = 0; i < v_num; ++i)
			vers[i] = other.vers[i];
	
	}

	Graph::~Graph()
	{
		delete[] vers;
	}
}