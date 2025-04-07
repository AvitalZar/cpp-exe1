//tchykzr@gmail.com
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
		throw std::runtime_error("Can't dequeue empty queue.");
	int ans = head->data;
	node *temp = head;
	head = head->next;
	if(head == nullptr)
		tail = nullptr;
	delete temp;
	return ans;
}

bool Queue::isEmpty(){
	return head==nullptr;
}

int Queue::peek(){
	if(isEmpty())
		throw std::runtime_error("Can't peek empty queue.");
	return head->data;
}

Queue::~Queue(){
	node *temp;
	while(head!=nullptr){
		temp = head;
		head = head->next;
		delete temp;
	}
}