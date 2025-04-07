#pragma once
#include <iostream>

struct Item{
	int ver;
	int key;
	struct Item *next;
};
/*a priority queue which implemented by a linked list.*/
class PrioQ{
private:
	Item *head;
public:
	PrioQ():head(nullptr){};
	void enqueue(int ver,int key);
	int dequeue();
	bool isEmpty();
	int peek();
	void decreaseKey(int ver, int new_key);
	~PrioQ();
};

