#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node * left;
		node * right;
		node(int val){
			data=val;
			left=NULL;
			right=NULL;
		}
};
class bst{
	public:
		node * root;
		bst(){
			root=NULL;
		}
		void insert(int value){
			insertHelper(root, value);
		}
		void insertHelper(node * curr, int value){
			if(curr == NULL){
				curr=new node (value);
				//update the root
				if(root== NULL)
				{
					root=curr;
				}
				return;
			}
			//else compare the current data with value
			else if((curr->data)>value){
				//if value< curr->data
				//if lefi if unull insert it
				//else move on
				if(curr->left ==NULL){
					curr->left= new node(value);
				}
				else {
				insertHelper(curr->left, value);}
			}
			else{
				if(curr->right ==NULL){
					curr->right= new node(value);
				}
				else {
				insertHelper(curr->right, value);}
			}
		}
		//display
		void display(){display2(root);}
		void display2(node * curr){
			//base condition
			if (curr==NULL)return;
			//display left
			display2(curr->left);
			cout<< curr->data<<" ";
			//display right
			display2(curr->right);
			
		}
		//search
	/*	node * search(int value){
			node * now=searcho(root, value);
			return now;
		}
		node * searcho(node * curr, int value){
			//find if it is equal
			if(curr->data == value){
				return curr;}
			// else go to the other via helper
			else if(curr->data > value){
				node *y=searcho(curr->left, value);
				return y;
				
			}	
			else {
				node * x=searcho(curr->right, value);
				return x;
			}*/
		node* search(int value){
			return search2(root, value);
		}
		node* search2(node * curr, int value){
			if(curr==NULL || curr->data == value)return curr;
			else if(curr->data >value){
				//only search in left side
				return search2(curr->left,value);
			}
			else{
				//only search in right side
				return search2(curr->right, value);

			}
		}
	
		//next class
		height();
		deleteNode();
};
int main(){
	bst tree;
	tree.insert(4);
	tree.insert(3);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	
	tree.display();
	cout<<endl;
	if(tree.search(8) != NULL)cout<<"found"<<endl;
	else cout<<"the value is missing";
	return 0;
	}
