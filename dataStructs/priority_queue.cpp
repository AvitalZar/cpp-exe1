#include "priority_queue.hpp"
using namespace std;

void PrioQ::enqueue(int ver,int key){
	node *toadd = new node{ver,key};
	if(isEmpty()){
		cout<<"add first "<<ver<<endl;
		head = toadd;
		return;
	}
	
	if(head->key > toadd->key){
		cout<<"add in the start "<<toadd->ver<<endl;
		toadd->next = head;
		head = toadd;
		return;
	}

	cout<<"add in the middle "<<toadd->ver<<endl;
	node *prev = head;
	while(prev->next!=nullptr&&prev->next->key < toadd->key){
		prev = prev->next;
	}
	node *after = prev->next;
	prev->next = toadd;
	toadd->next = after;

}

int PrioQ::dequeue(){
	if(isEmpty())
		throw std::runtime_error("Can't dequeue empty proiQ.");
	cout<<"dequeue: 1th key:"<<head->key;
	int ans = head->ver;
	node *temp = head;
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
	node *todo = head;
	
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
	
	node *temp = todo->next;
	todo->next = todo->next->next;
	delete temp;
	enqueue(ver,new_key);
	
}

PrioQ::~PrioQ(){
	node *temp;
	while(head!=nullptr){
		temp = head;
		head = head->next;
		delete temp;
	}
}
