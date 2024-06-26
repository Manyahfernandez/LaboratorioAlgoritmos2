/*
*	Se creó  una clase que permitiera implementar las operaciones de una cola de manera facil, para ello se creo una clase nodo que sera de gran ayuda
* para implementar la clase de queue.
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
class Queue {
private:
	node<T> *first;
	node<T> *last;
	int size;
public:
	Queue() {
		first = NULL;
		last = NULL;
		size = 0;
	}

	bool isEmpty() {
		return size == 0;
	}

	void enqueue(T info) {
		node<T> *nodes = new node<T>;
		nodes->info = info;
		nodes->next = NULL;
		if (first == NULL)
			first = nodes;
		else
			last->next = nodes;

		last = nodes;
		size++;
	}

	void dequeue() {
		if (!isEmpty()) {
			node<T> *temp = first;
			first = first->next;
			delete temp;
			size--;
			if (first == NULL)
				last = NULL;
		}
	}

	int sizes() {
		return size;
	}

	node<T> *head() {
		return first;
	}

	~Queue() {
		while (first != NULL) {
			node<T> *temp = first;
			first = first->next;
			delete temp;
		}
	}
};

int main(){
	int t;
	Queue<int> cola;
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
		 	cola.enqueue(n);
		 	break;
		 case 2:
		 	cola.dequeue();
		 	break;
		 case 3:
		 	if(cola.isEmpty()){
		 		cout<<"Empty! \n";
		 	}else{
		 		cout<<cola.head()->info<<"\n";
		 	}
		 	break;
		}
	}
	cola.~Queue();
	return 0;
}