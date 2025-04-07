//tchykzr@gmail.com
#pragma once
#include <iostream>

struct node{
	int data;
	struct node *next;
};
/*a queue which implemented by a liked list.*/
class Queue{
private:
	node *head;
	node *tail;
public:
	Queue():head(nullptr), tail(nullptr){};
	void enqueue(int add);
	int dequeue();
	bool isEmpty();
	int peek();
	~Queue();
};

