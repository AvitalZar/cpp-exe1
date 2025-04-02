#pragma once
#include <iostream>
#include "queInt.hpp"
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

