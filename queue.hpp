#include "vertex.hpp"
using namespace graph;
/*a queue which implemented by a liked list.*/
class Queue{
private:
	node *head;
	node *tail;
public:
	Queue(){};
	void enqueue(Vertex *add);
	Vertex* dequeue();
	bool isEmpty();
	Vertex* peek();
	~Queue();
};



typedef struct node{
	Vertex *ver;
	struct node *next;
};