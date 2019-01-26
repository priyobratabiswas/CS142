#include<iostream>
#include<cstring>
using namespace std;
//pro-------------generic mode
class node{
	public:
		
	//Data
	int data;
	//Pointer to the next Node
	node * next;
	//constructor the makes the ptr to null
	node(){
		next=NULL;
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
		/*node ** curr =&head;
		while((*curr)!= NULL){
			curr=&((*curr)-> next);
		}
		*curr=temp;
		//head will be given by *curr */
		if (head==NULL){
			head=temp;
			temp->next=head;
		}
		//any other temp only
		else{
			tail->next=temp;
			temp->next=head;
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
		current->next=temp;
		//update the code for 1ast position
	}
	else{
		//create a node
		node * temp=new node;
		temp->data=value;//assign value
		//link it to the value of head
		temp->next=current;
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
		current->next=head;
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
			//deletion
			delete temp;
			
			
		
	}
	void revDisplay(){
		revDisplay2(head);
		cout<<endl;
		
	}
	void revDisplay2(node * current){
		//moves to next(till available)
		if(current==tail){
			cout<<current->data<<"->";
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
				cout<<current->data<<"(This is head)->"<<"then goes to tail"<<endl;
			}
		}
	}
	//reversing link list
	void revLL(){
		node * temp=head;
		revLL2(head);
		tail=temp;
		temp->next=head;
		
	}
	void revLL2(node * current){
		//condition for empty LL
		if(current->next==head){
		head=current;
		return;
		}
			revLL2(current->next);
			current->next->next =current;
			return;
		
		
	}
	//display
	void display(){
		node * current=head;
		while(current !=tail){
			cout<< current ->data<<"->";	
			current =current->next;	
		}
		cout<<current->data<<"->then reverses to head"<<endl;	
	}
	void countItems(){
		node * current=head;
		int i=1;
		while(current !=tail){	
			current =current->next;	
			i++;
		}
		
		cout<<"the number of elements in the linked list is-"<<i<<endl;
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
	l1.revLL();
	l1.display();
	return 0;
}
