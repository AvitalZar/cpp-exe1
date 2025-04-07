//tchykzr@gmail.com
#pragma once
#include <iostream>

struct edge{
	int s;
	int d;
	int w;

	bool operator==(const edge& other) const {
        return s == other.s && d == other.d && w==other.w;
    }
};
struct PItem{
	edge e;
	int key;
	struct PItem *next;
};
/*a priority queue which implemented by a linked list.*/
class PrimQ{
private:
	PItem *head;
public:
	PrimQ():head(nullptr){};
	void enqueue(edge e,int key);
	edge dequeue();
	bool isEmpty();
	edge peek();
	void decreaseKey(edge e, int new_key);
	~PrimQ();
};

