#include "stack.hpp"
using namespace std;

/*The main difference between the stack and the queue 
(as you maybe noticed the stack is copied) is that the add 
of values is from the start and not from the end (look at the push method).*/

void Stack::push(int add){
	node *toadd = new node{add};//a node which hold the vertex add.
	if(head == nullptr){
		head = toadd;
	} else{
		node *temp = head;
		head = toadd;
		head->next = temp;
	}
}

int Stack::pop(){
	if(isEmpty())
		throw string("this stack is empty");
	int ans = head->data;
	if(head->next==nullptr){
		head = nullptr;
		return ans;
	}
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
}