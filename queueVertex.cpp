#include "queueVertex.hpp"

void Queue::enqueue(Vertex *add){
	node *toadd = new node{add};//a node which hold the vertex add.
	if(head == NULL){
		head = toadd;
		tail = toadd;
	} else{
		tail->next = toadd;
		tail = toadd;
	}
}

Vertex* Queue::dequeue(){
	if(isEmpty())
		return NULL;
	Vertex *ans = head->ver;
	node *temp = head;
	head = head->next;
	free(temp);
	return ans;
}

bool Queue::isEmpty(){
	return head==NULL;
}

Vertex* Queue::peek(){
	return head->ver;
}

Queue::~Queue(){
	node *temp;
	while(head!=NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	free(tail);
}