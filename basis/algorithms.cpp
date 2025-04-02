#include "algorithms.hpp"


namespace graph{
	Graph Algorithms::bfs(Graph g, int s){
		Graph ans = Graph(g.numOfVer());
		Vertex *current = g.get(s);//don't forget free it.
		int cur_n;
		bool isWhite[g.numOfVer()] = {true};
		Queue q;
		q.enqueue(s);
		while(!q.isEmpty()){
			cur_n = q.dequeue();
			current = g.get(cur_n);
			for(int i = 0;i<current->numOfNeigh();i++){
				EdgeTo n = current->getNeigh()[i];
				if(isWhite[n.vertex]){
					ans.add_edge(cur_n,n.vertex,n.weight);
					q.enqueue(n.vertex);
				}
			}
			isWhite[cur_n] = false;
		}
		free(current);
		return ans;
	}


	Graph Algorithms::dfs(Graph g, int s){
		Graph ans = Graph(g.numOfVer());
		Vertex *current;
		int cur_n;
		bool isWhite[g.numOfVer()] = {true};
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
			current = g.get(cur_n);
			EdgeTo n;
			for(int i = 0;i<current->numOfNeigh();i++){
				if(isWhite[current->getNeigh()[i].vertex]){
					n = current->getNeigh()[i];
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
		free(current);
		return ans;
	}
}