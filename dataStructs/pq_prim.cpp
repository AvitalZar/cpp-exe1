//tchykzr@gmail.com
#include "pq_prim.hpp"
using namespace std;

void PrimQ::enqueue(edge e,int key){
	PItem *toadd = new PItem{e,key};
	if(isEmpty()){
		head = toadd;
		return;
	}
	
	if(head->key > toadd->key){
		toadd->next = head;
		head = toadd;
		return;
	}

	PItem *prev = head;
	while(prev->next!=nullptr&&prev->next->key < toadd->key){
		prev = prev->next;
	}
	PItem *after = prev->next;
	prev->next = toadd;
	toadd->next = after;

}

edge PrimQ::dequeue(){
	if(isEmpty())
		throw std::runtime_error("Can't dequeue empty proiQ.");
	edge ans = head->e;
	PItem *temp = head;
	head = head->next;
	delete temp;
	return ans;
}

bool PrimQ::isEmpty()
{
	return head==nullptr;
}

edge PrimQ::peek()
{
	if(isEmpty())
		throw std::runtime_error("Can't peek empty primQ.");
	return head->e;
}

void PrimQ::decreaseKey(edge e, int new_key){
	if(isEmpty())
		throw runtime_error("primrity queue is empty.");
	PItem *todo = head;
	
	if(todo->e == e){
		head = head->next;
		delete todo;
		enqueue(e,new_key);
		return;
	}
	while(todo->next!=nullptr && !(todo->next->e==e)){
		todo = todo->next;
	}
	if(todo->next == nullptr)
		throw runtime_error("no such vertex in my primrity queue.");
	
	PItem *temp = todo->next;
	todo->next = todo->next->next;
	delete temp;
	enqueue(e,new_key);
	
}

PrimQ::~PrimQ(){
	PItem *temp;
	while(head!=nullptr){
		temp = head;
		head = head->next;
		delete temp;
	}
}

