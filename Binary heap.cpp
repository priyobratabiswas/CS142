#include<iostream>
using namespace std;

/*

2 Rules for Binary Heap
- Its a complete tree. -> So you can use an array
- Either a max-heap or min-heap. 

Array Implementation 
Root - A[0]

Parent Node : Arr[(i-1)/2]
Left Child  : Arr[(2*i)+1]
Right Child : Arr[(2*i)+2]

Functions:
1. GetMin()
2. ExtractMin()
3. DecreaseKey()
4. Insert()
5. Delete()
6. Display()

*/


class BinaryHeap{
    public:
    // Pointer to array of elements
    int * hArr;
    // Maximum possible size of array
    int mSize;
    // Current size of array 
    int cSize;

    BinaryHeap(int mSize){
        // Constructor 
        hArr = new int[mSize];
        this->mSize = mSize;
        cSize = 0;
    }

    void swap(int *a, int *b){
        // Swap elements ... 
        int temp = *a; 
        *a = *b; 
        *b = temp;
    }

    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (i*2)+1;}
    int right(int i){ return (i*2)+2;}

    int getMin(){ return hArr[0]; }

    void insert(int value){
        // Base case. for Heap Overflow
        if(mSize <= cSize){
        	cout<<"heap overflow"<<endl;
        	return;
		}

        // Insert the new key at the end.
        hArr[cSize]=value;
        cSize++;
		//Check it for all hierarchy with loop
            //Check if it breaks the heap property and fix it.
       	//if smaller than parent ,swap
       	int j=cSize-1;
       	while(j != 0 && hArr[parent(j)]>hArr[j]){
		   
		
			swap(&hArr[j] ,&hArr[parent(j)]);
			j=parent(j);
		}   
		cout<<cSize<<endl;

	
	
		} 
    
    void display(){
        // Display the array
        int i=0;
        while(i<cSize){
        	 cout<<hArr[i];
        	 i++;
		}
		
		cout<<endl;
    }

    int extractMin() 
    { 
        // Base case for Empty Heap
        if(cSize<=0){
        	cout<<INT_MIN<<endl;
        	return 0;
		}
        // Base case for Heap with 1 value.
		if(cSize==1){
			cSize--;
			return hArr[0];
		}
        // Copy the last element to the root. 
        int root=hArr[0];
        hArr[0]=hArr[cSize-1];
        // Call MinHeapify on root.
		cSize--; 
		MinHeapify(0);
        // Return the min (Store it, before you replace the root with the last element)
        return root;
    }

    void decreaseKey(int i, int new_val) 
    { 
        // Algorithm for what happens when I reduce the value of an element indexed at i to new_val. You can assume new_val to be less than the present value of the element. 
        hArr[i] = new_val; 
        // Loop for correcting the Property 2.
        while(i != 0 && hArr[parent(i)]>hArr[i]){
		   
		
			swap(&hArr[i] ,&hArr[parent(i)]);
			i=parent(i);
		}   
        // Compare with parent and move up till i == 0 or there is no violation. 

    } 
    // Deletes the element indexed at i. 
    void deleteKeyAt(int i) 
    { 
        // Decrease the value to INT_MIN at index i use decreaseKey()
        decreaseKey(i,INT_MIN);
        // Call ExtractMin
         extractMin() ;
        
    }

    void MinHeapify(int i) 
    { 
        // Compare with left and right
		int smallest= i; 
        int l=left(i); 
        int r=right(i);
        if(hArr[l]<hArr[i] && l < cSize){
        	smallest=l;
		}
		if(hArr[r] < hArr[smallest] && r< cSize){
			smallest=r;
		}
		
        
        // Replace with the smallest.
        if(smallest != i){
        	swap( &hArr[i], &hArr[smallest]);
        	MinHeapify(smallest);
		}
        // Call MinHeapify at the replaced child. 
    } 

};


int main(){
    BinaryHeap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
       bh1.display();
    }
    bh1.extractMin();
    bh1.display();
   bh1.deleteKeyAt(3);
    bh1.display();
    cout << endl;
}
