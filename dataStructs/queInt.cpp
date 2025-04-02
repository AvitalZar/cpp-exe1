#include "queInt.hpp"

void Queue::enqueue(int add){
	node *toadd = new node{add};//a node which hold the vertex add.
	if(head == NULL){
		head = toadd;
		tail = toadd;
	} else{
		tail->next = toadd;
		tail = toadd;
	}
}

int Queue::dequeue(){
	if(isEmpty())
		throw std::string("this queue is empty");
	int ans = head->data;
	node *temp = head;
	head = head->next;
	free(temp);
	return ans;
}

bool Queue::isEmpty(){
	return head==NULL;
}

int Queue::peek(){
	return head->data;
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