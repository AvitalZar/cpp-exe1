#include <iostream>
/*a stack which implemented by a linked list.*/
class Stack{
private:
	node *head;
	node *tail;
public:
	Stack(){};
	void push(int add);
	int pop();
	bool isEmpty();
	int peek();
	~Stack();
};



typedef struct node{
	int data;
	struct node *next;
};