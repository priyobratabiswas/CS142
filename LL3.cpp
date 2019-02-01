#include <iostream>
#include <cstring>
#include "class.cpp"
using namespace std;

class Stack{
	public:
	node * top;
	linkedlist l1;
	Stack(){
		top=l1.head;
	}
	//Pushes on top
	void push(int value){
		//void inserAT(int pos,int value)
		l1.insertAT(1,value);
		//top= new head
		top= l1.head;
		
	}
	//Pops the top
	void pop(){
		//void deleteAT(int pos){
		l1.deletAt(1);
		//top=new head;
		top= l1.head;
	}
	bool isEmpty(){
		if(top==NULL) return true;
		return false;
	}
	int size(){
		return l1.countItems();
		
	}
	void topDisplay(){
	}
	void Display(){
		l1.display();	}
};

int main(){
	Stack s1;
	for(int i=0;i<5;i++){
		s1.push(i);
		
	}
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();
	s1.pop();
	s1.Display();
	return 0;
}
/*
STACKS/QUEUES
*********find what is a c++ header file***********
push()-insert at top i.e.; 1st position
pop()- delete at top i.e.; 1st position
isEmpty(){returns true if empty and false ifnot}
size()-same as count
top()-gives back 1st element
ENque()-adds a new element in the que in the end
Deque()- deletes from the front.
[]<-end
[]
[]
[]
[]<- front
[FIFO,FILO]




 
*/
