#include "algorithms.hpp"
using namespace std;


void white(bool* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = true;
    }
}

namespace graph{
	Graph Algorithms::bfs(Graph g, int s){
		if(s<0||s>=g.numOfVer())
			throw out_of_range("source vertex is not in the graph.");
		cout<<"start build a bfs tree"<<endl;
		Graph ans = Graph(g.numOfVer());
		Vertex current;
		int cur_n;
		bool isWhite[g.numOfVer()];
		white(isWhite,g.numOfVer());
		Queue q;
		q.enqueue(s);
		isWhite[s] = false;
		while(!q.isEmpty()){
			cur_n = q.dequeue();
			current = *g.get(cur_n);
			for(int i = 0;i<current.numOfNeigh();i++){
				EdgeTo n = current.getNeigh()[i];
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


	Graph Algorithms::dfs(Graph g, int s){
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
}

