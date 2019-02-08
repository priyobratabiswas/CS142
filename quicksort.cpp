#include<iostream>
#include<cstring>
using namespace std;
void swap(int *a,int *b){
	int t= *a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int L,int H){
	//assigning pivot to high
	//L and H are the first and last element (pointer) of the array
	int pivot=arr[H];
	cout<<"pivot"<<pivot<<endl;
	cout<<"L"<<L<<endl;
	cout<<"H"<<H<<endl;
	int i=L-1;
	for(int j=L;j<=H-1/*not accessinh pivot*/;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[j],&arr[i]);
		}
	
	}
	int u=i+1;
	swap(&arr[u],&arr[H]);
	
	return u;
	}

void qs(int arr[],int L,int H){
	//choosing the pivot

	
	if(L>=H){
		return;
	}
	else{
			int pivot;
	pivot=partition(arr,L,H);
		qs(arr,L,pivot-1);
		qs(arr,pivot+1,H);
	}
	//partition will give the pivot
	
}

int main(){
	int arr[50];
	int d;
	cout<<"enter the number of values you  want to enter"<<endl;
	cin>>d;
	for(int k=0;k<d;k++)
	{
		cin>>arr[k];
	}
	qs(arr,0,d-1);
	for(int e=0;e<d;e++){
		cout<<arr[e];
	}
return 0;
}
