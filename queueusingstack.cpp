//#include "queue.cpp"
#include "stack.cpp"
class myqueue {
	public:
		stack s1;
		int stsize;
		myqueue(){
			stsize=0;
		}
		void Enqueue(int value){
			if(s1.isEmpty()){
				s1.push(value);
				stsize++;
				return;}
			int data=s1.top();
			s1.pop();
			Enqueue(value);
			
			s1.push(data);
			
			
			}
		void display(){
			cout<<"the front is "<<s1.top()<<endl;
			cout<<"the end is "<<s1.end()<<endl;
		}
		
		void Dequeue(){
			s1.pop();
			stsize--;
		}
		int front(){
			//cout<<"the top is->"<<s1.top()<<endl;
		cout<<"the front is->"<<s1.top()<<endl;
		}
		bool isempty(){
			return s1.isEmpty();
		}
		int size(){
			return stsize;
		}
};
int main(){
	myqueue q;
	for(int i=0;i<5;i++){
		q.Enqueue(i);
	}
	q.display();

	//q.Dequeue();
	int x=q.size();
	cout<<"the size is->"<<x<<endl;
	q.front();
	for(int j=0;j<6;j++){
		q.Dequeue();
	//	if(s1.top()   != NULL){
		
		//s1.top();
		}
	
	return 0;
}
