#pragma once
#include <iostream>

struct node{
	int ver;
	int key;
	struct node *next;
};
/*a priority queue which implemented by a linked list.*/
class PrioQ{
private:
	node *head;
public:
	PrioQ():head(nullptr){};
	void enqueue(int ver,int key);
	int dequeue();
	bool isEmpty();
	int peek();
	void decreaseKey(int ver, int new_key);
	~PrioQ();
};

