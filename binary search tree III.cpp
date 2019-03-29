#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node * left;
		node * right;
		node * parent;
		node(int val){
			data=val;
			left=NULL;
			right=NULL;
			parent=NULL;
		}
};
class bst{
	public:
		node * root;
		//int ct=0;
		bst(){
			root=NULL;
		}
		void insert(int value){
			insertHelper(root, value);
		}
		void insertHelper(node * curr, int value){
			if(curr == NULL){
				curr=new node (value);
		//		ct++;
				curr->parent=NULL;
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
					curr->left->parent=curr;
		//			ct++;
				}
				else {
				insertHelper(curr->left, value);}
			}
			else{
				if(curr->right ==NULL){
					curr->right= new node(value);
					curr->right->parent=curr;
		//			ct++;
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
		//Display2D
				//always count the number of call
				//for number of call insert the spacec
				//after each cout endl
		void display2d(){
			int sz=0;
			display3(root,sz);
			}
		void display3(node * curr, int sz){
			//base condition
			if (curr==NULL)return;
			//display left
			sz++;
			display3(curr->right, sz);
			for(int j=sz; j>0;j--){
				cout<<"  ";
			}
			cout<< curr->data<<endl;
			//display right
			//sz++;
			display3(curr->left, sz);
			
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
			if(curr != NULL){
				if( curr->data == value)return curr;
				else if(curr->data >value){
					//only search in left side
					return search2(curr->left,value);
				}
				else{
					//only search in right side
					return search2(curr->right, value);
	
				}
			}
			else{
				cout<<"am i a joke to you? there is no such node"<<endl;
				return NULL;
			}
		}
		//count2
		/*int counttwo(){
			return ct;	
		}*/
		//count
		int count(){
		int  sz=0;
		count2(root,&sz);
		return sz;}
		void count2(node * curr ,int* sz){
			//base condition
			if (curr==NULL)return;
			//display left
			count2(curr->left, sz);
			(*sz)++;
			//display right
			count2(curr->right,sz);
			
		}
		//find min
		node * find_min(node * start){
			if(start==NULL){
				cout<<"Am I a Joke to you?"<<endl;
				return NULL;
			}
			while(start->left != NULL){
				start = start->left;
			}
			return start;
		}
		//replace with parent
			//curr is left or right
			//curr->parent ->left or right with temp
	void replace_with_parent(node *curr, node * xp){
		
		
		node * par=curr->parent;
		if(par->left==curr){
			par->left=xp;
			xp->parent=par;
			delete curr;
		}
		else {
			par->right=xp;
			xp->parent=par;
			delete curr;
		}
	}
		//delete
		void deletenode(int value){
			node * d=search(value);
			deletenode2(d);
			//if no son
		/*	if ((d->left==NULL) && (d->right==NULL)){
				node * par=d->parent;
				if(par->left== d){
					par->left=NULL;
					delete d;
				}
				else{
					par->right=NULL;
					delete d;
				}
			
			}
		//	replace_with_parent(d,NULL);
			//replace with null
		//	}
			//if one son//
			//if(left exists
			else if(d->left==NULL || d->right ==NULL){
				if(d->left != NULL){
					replace_with_parent(d,d->left );
				//	delete d;	
				}
				else{
					replace_with_parent(d,d->right);
				//	delete d;	
				}
			}
			else{
				node * f=find_min(d->right);
				d->data= f->data;
				
			}*/
			//value replace crr with curr->left
			//delete temp//
			//for both kids
			//search
			//check if two kids
			//find the succesor--either min of rhs or max of lhs
			//value relace with that guy
			//I CANNOT RELACE THE NODES BUT ONLY THE VALUE
		}
			void deletenode2(node * d){
			//if no son
			if ((d->left==NULL) && (d->right==NULL)){
				node * par=d->parent;
				if(par->left== d){
					par->left=NULL;
					delete d;
				}
				else{
					par->right=NULL;
					delete d;
				}
			
			}
		//	replace_with_parent(d,NULL);
			//replace with null
		//	}
			//if one son//
			//if(left exists
			else if(d->left==NULL || d->right ==NULL){
				if(d->left != NULL){
					replace_with_parent(d,d->left );
				//	delete d;	
				}
				else{
					replace_with_parent(d,d->right);
				//	delete d;	
				}
			}
			else{
				node * f=find_min(d->right);
				d->data= f->data;
				deletenode2(f);
			}
			//value replace crr with curr->left
			//delete temp//
			//for both kids
		}
	
	int rangesearch(int k1,int k2){
		node * low=search(k1);
		node * high=search(k2);
		int count=0;
		rs(root,low,high,& count);
		return count;
		}
		void rs(node* curr,node * low,node * high,int * count){
			//base condition
			if (curr==NULL)return;
			//display left
			
			rs(curr->left,low,high, count);
			if (low->data < curr->data && curr->data < high->data){
			cout<< curr->data<<" ";
			(*count)++;}			//display right
			rs(curr->right,low,high, count);
			
		}
		//next class
		int height(){
			return height2(root);
		}
		int height2(node * start){
			//base case
			if(start == NULL){
				return 0;
			}
			//to take the values and doing the recursion
			int lheight= height2(start->left);
			int rheight= height2(start->right);
			
			//what values should be returned
			if(lheight > rheight){
				return (lheight+1);
			}
			else{
				return (rheight+1);
			}
		}
		
};
int main(){
	node * jones=new node(10);
	bst tree;
	tree.insert(4);
	tree.insert(6);
	tree.insert(2);
	tree.insert(5);
	tree.insert(7);
	tree.insert(3);
	tree.insert(4);
	tree.insert(0);
	tree.insert(8);
	
	tree.display2d();
	
	cout<<endl;
	//tree.replace_with_parent(tree.root->left->left,jones);
	//cout<<tree.root->right->parent->data<<endl;
/*	if(tree.search(8) != NULL)cout<<"found"<<endl;
	else cout<<"the value is missing"<<endl;
	node * h=tree.find_min(tree.root);
	cout<<h->data<<endl;*/
	tree.deletenode(4);
	tree.display2d();
	tree.search(1);
//	cout<<endl<<tree.count()<<endl;
///	int k=tree.rangesearch(0,5);
//	cout<<endl<<k<<endl;
//	int height= tree.height();
//	cout<<height<<endl;
	return 0;
	}
	/*
	1. search
	2.find_min
	3.find_max
	4. case I-both child
	5. case II- only one child
	6. no child
	*/
