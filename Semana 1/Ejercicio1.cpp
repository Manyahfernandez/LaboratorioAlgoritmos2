#include <iostream>
using namespace std;

int main(){
	int numero;

	while(true){
		cin >> numero;
		if(numero == 42){
			break;
		}
		cout << numero << endl;
	}

	return 0;
}