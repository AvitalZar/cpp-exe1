#include "algorithms.hpp"
using namespace std;

int INF = 1e9;

void white(bool* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = true;
    }
}

namespace graph{

	Graph Algorithms::bfs(Graph& g, int s){
		int length = g.numOfVer();
		if(s<0||s>=length)
			throw out_of_range("source vertex is not in the graph.");
		cout<<"start build a bfs tree"<<endl;
		Graph ans = Graph(length);
		Vertex *current;
		int cur_n;
		bool isWhite[length];
		white(isWhite,length);
		Queue q;
		q.enqueue(s);
		isWhite[s] = false;
		while(!q.isEmpty()){
			cur_n = q.dequeue();
			current = g.get(cur_n);
			for(int i = 0;i<current->numOfNeigh();i++){
				EdgeTo n = current->getNeigh()[i];
				if(isWhite[n.vertex]){
					ans.add_edge(cur_n,n.vertex,n.weight);
					q.enqueue(n.vertex);
					isWhite[n.vertex] = false;
				}
			}
		}
		ans.print_graph();
		return ans;
	}




	Graph Algorithms::dfs(Graph& g, int s){
		if(s<0||s>=g.numOfVer())
			throw out_of_range("source vertex is not in the graph.");
		Graph ans = Graph(g.numOfVer());
		Vertex current;
		int cur_n;
		bool isWhite[g.numOfVer()];
		white(isWhite,g.numOfVer());
		Stack q;
		q.push(s);
		isWhite[s] = false;
		while(true){
			if(q.isEmpty()){//checking for not-connected parts in the graph we maybe didn't go over.
				for(int i = 0;i<g.numOfVer();i++){
					if(isWhite[i]){
						q.push(i);
						isWhite[i] = false;
					}
				}
			}
			//if the stack is steel empty,
			if(q.isEmpty())//if there're no such parts we went over all the graph.
				break;
			cur_n = q.peek();
			current = *g.get(cur_n);
			EdgeTo n;
			for(int i = 0;i<current.numOfNeigh();i++){
				if(isWhite[current.getNeigh()[i].vertex]){
					n = current.getNeigh()[i];
					break;
				}
			}
			if(n.vertex == -1){
				q.pop();
			}
			else{
				q.push(n.vertex);
				isWhite[n.vertex] = false;
				ans.add_edge(cur_n,n.vertex,n.weight);
			}
			
		}
		ans.print_graph();
		return ans;
	}





	struct v_info{
		int key = INF;
		int prev = -1;
		bool visited = false;

		int weight_prev = 0;
	};
	Graph Algorithms::dijkstra(Graph &g, int s)
	{	
		
		int length = g.numOfVer();
		if(s<0||s>=length)
			throw out_of_range("source vertex is not in the graph.");
		v_info *info = new v_info[length];
		PrioQ p;

		int cur_ver;
		Vertex *current;

		info[s].key = 0;
		//insert all the vertices in the queue.
		for(int i = 0;i<length;i++){
			p.enqueue(i,info[i].key);
		}

		while(!p.isEmpty()){
			cur_ver = p.dequeue();
			info[cur_ver].visited = true;
			current = g.get(cur_ver);

			EdgeTo n;
			for(int i = 0; i<current->numOfNeigh(); i++){
				n = current->getNeigh()[i];
				int nei = n.vertex;
				if(info[nei].visited)
					continue;
				
				//if the route from current vertex is lighter, relax.
				if(info[cur_ver].key+n.weight < info[nei].key){
					info[nei].key = info[cur_ver].key+n.weight;
					info[nei].prev = cur_ver;
					info[nei].weight_prev = n.weight;
					p.decreaseKey(nei,info[nei].key);
				}
			}
		}
		
		Graph ans = Graph(length);
		for(int i = 0; i<length; i++){
			if(info[i].prev!=-1){
				ans.add_edge(i,info[i].prev,info[i].weight_prev);
			}
		}


		delete[] info;
		return ans;
	}
}