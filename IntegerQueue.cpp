#include <iostream>
#include "IntegerQueue.h"

IntegerQueue::IntegerQueue(){
	qSize=2;
	queue=new int[qSize];
	head=0;
	tail=0;
}

IntegerQueue::IntegerQueue(const IntegerQueue& a){
	qSize=a.qSize;
	queue=new int[a.qSize];
	head=a.head;
	tail=a.tail;
	for(int i=a.head; i<a.tail; i++)
		queue[i]=a.queue[i];
}

IntegerQueue::~IntegerQueue(){
	delete[] queue;
}

void IntegerQueue::push(int val){
	if(tail==qSize){
		int* temp=new int[qSize*2];
		for(int i=0; i<tail-head; i++){
			temp[i]=queue[head+i];
		}
		delete[] queue;
		queue=temp;
		qSize*=2;
		tail-=head;
		head=0;
	}
	queue[tail]=val;
	tail++;
}

bool IntegerQueue::empty() const{
	return tail-head==0;
}

int IntegerQueue::pop(){
	int val=queue[head];
	head++;
	return val;
}

int IntegerQueue::size() const{
	return tail-head;
}

std::ostream& operator<<(std::ostream& lhs, const IntegerQueue& rhs){
	if(rhs.empty())
		return lhs<<"{}";
	lhs<<"{";
	for(int i=rhs.head; i<rhs.tail-1; i++){
		lhs<<rhs.queue[i]<<",";
	}
	lhs<<rhs.queue[rhs.tail-1]<<"}";
	return lhs;
}

IntegerQueue& IntegerQueue::operator=(const IntegerQueue& rhs){
	IntegerQueue tmp(rhs);
	std::swap(head,tmp.head);
	std::swap(tail,tmp.tail);
	std::swap(queue,tmp.queue);
	std::swap(qSize,tmp.qSize);
	return *this;
}