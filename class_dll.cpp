#include<iostream>
#include<cstring>
using namespace std;
//double linked list node
class node{
	public:
		
	//Data
	int data;
	//Pointer to the next Node
	node * next;
	node * prev;
	//constructor the makes the ptr to null
	node(){
		next=NULL;
		prev=NULL;
	}
};
class linkedlist{
	//head +circles with each other
	public:
	//Head-> Circle(node) type ptr
	node* head;
	node* tail;
	//construct
	linkedlist(){
		head=NULL;
		tail=NULL;
	}
	//Circles inside linked with each other
	//rules hoe circles will be linked
	//insert
	void insert(int value){
		//if first node is added
		node * temp=new node;//new helps to creates an object of node type in heap and returns its adress which  is stored in pointer
		temp->data=value;//using here
		//1st node only
	/*	node ** curr =&head;
		while((*curr)!= NULL){
			curr=&((*curr)-> next);
		}
		*curr=temp;*/
		//head will be given by *curr
		if (head==NULL){
			head=temp;
		}
		//any other temp only
		else{
			temp->prev=tail;
			tail->next=temp;
		}
		tail = temp;
		
		
	}
	
	void insertAT(int pos,int value){
		//reach the place before pos
		node* current=head;
	if(pos!=1){
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//create a node
		node * temp= new node;
		temp->data=value;
		//moving ptrs
		temp->next=current->next;
		current->next->prev=temp;
		current->next=temp;
		temp->prev=current;
		//update the code for 1ast position
	}
	else{
		//create a node
		node * temp=new node;
		temp->data=value;//assign value
		//link it to the value of head
		temp->next=current;
		current->prev=temp;
		//make temp head;
		head=temp;	
	}
		
	}
	//deletion of last element
	void delet(){
		//store the tail in temp
		node * temp = tail;
		// before tail has to point to null
		node * current=head;
		while(current->next !=tail){
		current =current->next;		
		}
		current->next=NULL;
		//update tail
		tail=current;
		delete temp;
	}
	//delete at a given position
	void deletAt(int pos){
			//take one node at the desired position-1
			node *current=head;
				int i=1;
			while(i<pos-1){
				i++;
				current=current->next;
			}
			// crate pointer for the file to be deleted
			node * temp=current->next;
			//assign link of the previous element to the next of next element
			current->next=temp->next;
			temp->next->prev=current;
			//deletion
			delete temp;
			
			
		
	}
	void revDisplay(){
		revDisplay2(head);
		cout<<endl;
		
	}
	void revDisplay2(node * current){
		//moves to next(till available)
		if(current==NULL){
			cout<<"NULL->";
			return;
		}
		else{
			revDisplay2(current->next);
			//cout<<current->data<<"->";
			//while coming back you print
			if(current!=head){
			cout<<current->data<<"->";
			}
			else{
				cout<<current->data;
			}
		}
	}
	void revdisplay(){
		node * current=tail;
		while((current->prev)!= NULL){
			cout<<current->data<<"->";
			current=current->prev;
		}
		cout<<current->data<<"->NULL"<<endl;
		
	}
	//reversing link list
	/*void revLL(){
		node * temp=head;
		revLL2(head);
		tail=temp;
		temp->next=NULL;
		
	}
	void revLL2(node * current){
		//condition for empty LL
		if(current==NULL){return;}
		//condition for 1 element
		else if(current->next ==NULL){
			head=current;
			return;}
		//reverse for rest
		else{
			revLL2(current->next);
			current->next->next =current;
			return;
		}
		
	}
*/	//display
	void display(){
		node * current=head;
		while(current !=NULL){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
		cout<<"Null"<<endl;	
	}
	void countItems(){
		node * current=head;
		int i=0;
		while(current !=NULL){	
			current =current->next;	
			i++;
		}
		cout<<"the number of elemwnts in the linked list is-"<<i<<endl;
	}
	
};
int main(){
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.revDisplay();
	l1.revdisplay();
	l1.countItems();
	l1.insert(9);
	l1.insertAT(3,7);
	cout<<endl;
	l1.display();
	l1.delet();
	cout<<endl;
	l1.display();
	cout<<endl;
	l1.deletAt(2);
	l1.display();
//	l1.revLL();
//	l1.display();
	return 0;
}
