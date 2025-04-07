#include "priority_queue.hpp"
using namespace std;

void PrioQ::enqueue(int ver,int key){
	Item *toadd = new Item{ver,key};
	if(isEmpty()){
		head = toadd;
		return;
	}
	
	if(head->key > toadd->key){
		toadd->next = head;
		head = toadd;
		return;
	}

	Item *prev = head;
	while(prev->next!=nullptr&&prev->next->key < toadd->key){
		prev = prev->next;
	}
	Item *after = prev->next;
	prev->next = toadd;
	toadd->next = after;

}

int PrioQ::dequeue(){
	if(isEmpty())
		throw std::runtime_error("Can't dequeue empty proiQ.");
	int ans = head->ver;
	Item *temp = head;
	head = head->next;
	delete temp;
	return ans;
}

bool PrioQ::isEmpty()
{
	return head==nullptr;
}

int PrioQ::peek()
{
	if(isEmpty())
		throw std::runtime_error("Can't peek empty prioQ.");
	return head->ver;
}

void PrioQ::decreaseKey(int ver, int new_key){
	if(isEmpty())
		throw runtime_error("priority queue is empty.");
	Item *todo = head;
	
	if(todo->ver == ver){
		head = head->next;
		delete todo;
		enqueue(ver,new_key);
		return;
	}
	while(todo->next!=nullptr && todo->next->ver!=ver){
		todo = todo->next;
	}
	if(todo->next == nullptr)
		throw runtime_error("no such vertex in my priority queue.");
	
	Item *temp = todo->next;
	todo->next = todo->next->next;
	delete temp;
	enqueue(ver,new_key);
	
}

PrioQ::~PrioQ(){
	Item *temp;
	while(head!=nullptr){
		temp = head;
		head = head->next;
		delete temp;
	}
}
