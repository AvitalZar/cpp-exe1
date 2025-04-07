//tchykzr@gmail.com
#pragma once
#include <iostream>
#include "queInt.hpp"
/*a stack which implemented by a linked list.*/

class Stack{
private:
	node *head;
public:
	Stack(): head(nullptr){};
	void push(int add);
	int pop();
	bool isEmpty();
	int peek();
	~Stack();
};

