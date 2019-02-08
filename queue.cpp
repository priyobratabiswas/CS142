#include<iostream>
#include "class.cpp"
using namespace std;
class Queue{
	public:
		//variables
		node * end;
		node * front;
		linkedlist l1;
		//contructor
		Queue(){
			front=l1.tail;
			end=l1.head;
		}
		//Enqueue function
		void Enqueue(int value){
			l1.insertAT(1,value);
			end=l1.head;
			front=l1.tail;
		}
		//Dequeue function
		void Dequeue(){
			l1.delet();
			front=l1.tail;
		}
		//front displaying function
		void frontdisplay(){
			cout<<"the front is->"<<front->data<<endl;
		}
		int frontdata(){
			return front->data;
		}
		//enddisplaying function
		void enddisplay(){
			cout<<"the end is->"<<end->data<<endl;
		}
		//isempty function
		bool isEmpty(){
			if(front==NULL) return true;
			else return false;
	}
		int size(){
			
		return l1.countItems();
		
	}
};
/*int main(){
	Queue s1;
	s1.Dequeue();
	for(int i=0;i<5;i++){
		s1.Enqueue(i);
	}
	s1.frontdisplay();
	s1.enddisplay();
	for(int j=0;j<6;j++){
		s1.Dequeue();
		if(s1.front   != NULL){
		
		s1.frontdisplay();
		s1.enddisplay();}
	}
	/*s1.frontdisplay();
	s1.enddisplay();*
	return 0;
	
}*/
