#include "stack.hpp"

/*The main difference between the stack and the queue 
(as you maybe noticed the stack is copied) is that the add 
of values is from the start and not from the end (look at the push method).*/

void Stack::push(int add){
	node *toadd = new node{add};//a node which hold the vertex add.
	if(head == NULL){
		head = toadd;
		tail = toadd;
	} else{
		node *temp = head;
		head = toadd;
		head->next = temp;
		free(temp);
	}
}

int Stack::pop(){
	if(isEmpty())
		return NULL;
	int ans = head->data;
	node *temp = head;
	head = head->next;
	free(temp);
	return ans;
}

bool Stack::isEmpty(){
	return head==NULL;
}

int Stack::peek(){
	return head->data;
}

Stack::~Stack(){
	node *temp;
	while(head!=NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
	free(tail);
}