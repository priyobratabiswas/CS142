#include "queue.cpp"
//#include "stack.cpp"
class mystack {
	private:
		Queue q1;
		int stsize;
	public:
		mystack(){
			stsize=0;
		}
	/*	void push(int value){
			//adding to q2
			if(q1.isEmpty()){
				q1.Enqueue(value);
				stsize++;
			}
			else{
			
			q2.Enqueue(value);
			stsize++;
			while (!q1.isEmpty()){
			q2.Enqueue(q1.frontdata());
			q1.Dequeue();
			}
			
			node *tt1=q1.front;
			node *tt2=q1.end;
			q1.front=q2.front;
			q1.end=q2.end;
			q2.front=tt1;
			q2.end=tt2;}
		}*/
		void push(int value){
			q1.Enqueue(value);
			stsize++;
			for(int h=1;h<=(q1.size())-1;h++){
				int data=q1.front->data;
				q1.Dequeue();
				q1.Enqueue(data);
			}
		}
		void pop(){
			q1.Dequeue();
			stsize--;
		}
		void top(){
			cout<<"the top is->"<<q1.frontdata()<<endl;
		}
		bool isempty(){
			return q1.isEmpty();
		}
		int size(){
			return stsize;
		}
};
int main(){
	mystack s1;
	for(int i=0;i<5;i++){
		s1.push(i);
	}
	s1.pop();
	//s1.pop();
	int x=s1.size();
	cout<<"the size is ->"<<x<<endl;
	s1.top();
	for (int h=0;h<5;h++)
	{
		s1.pop();	}
	
	
	return 0;
}
