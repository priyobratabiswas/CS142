
#include<iostream>
#include "class.cpp"
using namespace std;
/*push.pop,isempty,size,top*/
class stack{
	public:
		//variables
		node * head;
		linkedlist l1;
		//contructor
		stack(){
			head=l1.head;
		}
		//Enqueue function
		void push(int value){
			l1.insertAT(1,value);
			head=l1.head;
		}
		//Dequeue function
		void pop(){
			l1.deletAt(1);
			head=l1.head;
		}
		//enddisplaying function
		int top(){
			//cout<<"the top is->"<<head->data<<endl;
		
			return head->data;
		}
		int end(){
			return l1.tail->data;
		}
		//isempty function
		bool isEmpty(){
			if(head==NULL) return true;
			return false;
	}
		int size(){
		return l1.countItems();
		
	}
};
/*int main(){
	stack s1;
	for(int i=0;i<5;i++){
		s1.push(i);
	}
	s1.top();
	for(int j=0;j<6;j++){
		s1.pop();
		if(s1.head   != NULL){
		
		s1.top();
		}
	}
	//s1.frontdisplay();
	//s1.enddisplay();*
	return 0;
	
}*/
