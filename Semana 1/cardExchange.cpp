/* Se busco dividir el problema en subproblemas. 
1. Buscar en la mano dada si existen k cartas iguales para intercambiar, esto es lo que hace la función verificar.
2. Si se logró intercambiar un numero de cartas, buscar entre las cartas el valor que más se repite y añadir k-1 cartas, esto es lo que hace la funcion maximoNumero.
Una vez logrado esto, se combinó todo para solucionar el problema.
*/

#include<iostream>
#include<vector>

using namespace std;

/*
*Decripcion: Funcion que permite verificar si hay k cartas del mismo valor que se puedan intercambiar, retorna 1 si hay cartas por intercambiar y -1 si no es posible un intercambio.
*Parametros: v: vector<int> -> contiene las cartas en la mano.
*			 k: int -> numero de cartas que deben ser intercambiadas.
*			 cantidad: vector<int> -> contiene para cada valor escrito en las cartas, el numero de cartas en la mano con ese valor.
*/

int verificar(vector<int> &v, int k, vector<int> &cantidad){
	vector<int> w(cantidad);
	for(int i = 0; i < v.size(); i++){
		if(cantidad[v[i] - 1] >= k){
			cantidad[v[i] - 1] -=k;
			break;
		}
	}

	if(w == cantidad){
		return -1;
	}

	return 1;
}

/*
*Descripcion: Funcion que localiza el valor que mas se repite en la mano y añade k - 1 cartas de dicho valor a la mano en cuestion.
*Parametros: v: vector<int> -> contiene las cartas en la mano.
*			 k: int -> numero de cartas que deben ser intercambiadas.
*			 cantidad: vector<int> -> contiene para cada valor escrito en las cartas, el numero de cartas en la mano con ese valor.
*/

void maximoNumero(vector<int> &v, int k, vector<int> &cantidad){
	int maximo = cantidad[v[0] - 1];
	int posicion = 0;
	for(int i = 1; i < v.size(); i++){
		if(cantidad[v[i] - 1] > maximo){
			maximo = cantidad[v[i] - 1];
			posicion = i;
		}
	}

	cantidad[v[posicion] - 1] += (k-1);
}

int main(){
	int t;

	cin >> t;

	for(int i = 0; i  < t; i++){
		int n, k;

		cin >> n >> k;

		vector<int> v;
		v.resize(n);
		vector<int> cantidad(100,0);

		for(int j = 0; j < n ; j++){
			cin >> v[j];

			cantidad[v[j] - 1] += 1;
		}

		while(n >= k){
			int verificacion = verificar(v,k,cantidad);

			if(verificacion == -1){
				break;
			}else{
				n = n - 1;
				maximoNumero(v,k,cantidad);
			}
		}

		cout << n << endl;
	}
	
	return 0;
}
