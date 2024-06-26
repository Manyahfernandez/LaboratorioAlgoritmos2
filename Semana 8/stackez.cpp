/*
*	Se creó  una clase que permitiera implementar las operaciones de una pila de manera facil, para ello se creo una clase nodo que sera de gran ayuda
* para implementar la clase de stack.
*/
#include<iostream>

using namespace std;

template <class T>
class node {
	public:
		T info;
		node<T> *next;
};

template<class T>
class Stack {
public:
	node<T> *top;
	int size;

	Stack() {
		top = NULL;
		size = 0;
	}

	bool isEmpty() {
		return top == NULL;
	}

	void push(T info) {
		node<T> *nodes = new node<T>;
		nodes->info = info;
		nodes->next = top;
		top = nodes;
		size++;
	}

	void pop() {
		if (!isEmpty()) {
			node<T> *temp = top;
			top = top->next;
			delete temp;
			size--;
		}
	}
	
	int getsize(){
		return size;
	}
	
	~Stack() {
		while (top != NULL) {
			node<T> *temp = top;
			top = top->next;
			delete temp;
		}
	}
};


int main(){
	int t;
	Stack<int> pilad;
	

	cin >> t;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < t; i++){
		int option;

		cin >> option;

		switch(option){
		 case 1:
		 	int n;
		 	cin >> n;
		 	pilad.push(n);
		 	break;
		 case 2:
		 	pilad.pop();
		 	break;
		 case 3:
		 	if(pilad.isEmpty()){
		 		cout<<"Empty! \n";
		 	}else{
		 		cout<<pilad.top->info<<"\n";
		 	}
		 	break;
		}
	}
	pilad.~Stack();
	return 0;
}
