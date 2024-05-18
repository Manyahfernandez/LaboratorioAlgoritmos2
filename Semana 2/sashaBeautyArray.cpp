/*
* El problema se resolvio utilizando bubble sort para ordenar los elementos, y luego se sumarón los elementos del array para lograr obtener lo que el problema pedia
*/

#include<iostream>
#include<vector>
using namespace std;


/*
*Decripcion: Funcion bubble sort
*/

void bubbleSort(vector<int> &v) {
    for(int i = 0; i < v.size(); i++){
        for(int j = v.size() - 1; j > i; j--){
            if(v[j] < v[j - 1]){
                int tmp = v[j];
                v[j] = v[j-1];
                v[j - 1] = tmp; 
            }
        }
    }
}

/*
*Decripcion: Funcion que suma los elementos del array.
*Parametros: v: vector<int> -> contiene los numeros a sumar
*/

int sumar(vector<int> &v){
	int suma = 0;

	for(int i = 1; i < v.size(); i++){
		suma += (v[i] - v[i - 1]);
	}

	return suma;
}

int main(){
	int t;

	cin >> t;

	for(int i = 0; i < t; i++){
		int a;

		cin >> a;

		vector<int> v;
		v.resize(a);
		for(int j = 0; j < a ; j++){
			cin >> v[j];
		}

		bubbleSort(v);

		int maximo = sumar(v);

		cout << maximo <<endl;
	}

	return 0;
}