#include "stack.hpp"
using namespace std;

/*The main difference between the stack and the queue 
(as you maybe noticed the stack is copied) is that the add 
of values is from the start and not from the end (look at the push method).*/

void Stack::push(int add){
	
	node *toadd = new node{add};//a node which hold the vertex add.
	if(head != nullptr){
		toadd->next=head;
	}
	head = toadd;
}

int Stack::pop(){
	if(isEmpty())
		throw runtime_error("this stack is empty");
	int ans = head->data;
	node *temp = head;
	head = head->next;
	delete temp;
	return ans;
}

bool Stack::isEmpty(){
	return head==nullptr;
}

int Stack::peek(){
	if(isEmpty())
		throw runtime_error("Can't peek empty stack");
	return head->data;
}

Stack::~Stack(){
	node *temp;
	while(head!=nullptr){
		temp = head;
		head = head->next;
		delete temp;
	}
}