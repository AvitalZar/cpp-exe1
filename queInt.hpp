#include "vertex.hpp"
using namespace graph;
/*a queue which implemented by a liked list.*/
class Queue{
private:
	node *head;
	node *tail;
public:
	Queue(){};
	void enqueue(int add);
	int dequeue();
	bool isEmpty();
	int peek();
	~Queue();
};



typedef struct node{
	int data;
	struct node *next;
};