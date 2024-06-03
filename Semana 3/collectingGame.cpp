/*
* Se utilizo mergesort para ordenar el vector guardado en otro vector denominado vOrdernado, se creo una funcion collecionGame que calcula el numero de elementos eliminados
* segun la puntuacion
*/

#include<iostream>
#include<vector>

using namespace std;

/*
*Decripcion: Funcion mergesort
*/

void merge(vector<int> &v, int izquierda, int medio, int derecha){

	int nl,nr,i,j,k;

	nl = medio - izquierda + 1;
	nr = derecha - medio;

	vector<int> larr,rarr;
	larr.resize(nl);
	rarr.resize(nr);

	for(i = 0; i < nl; i++){
		larr[i] = v[izquierda + i];
	}

	for(j = 0; j < nr; j++){
		rarr[j] = v[medio + 1 + j];
	}

	i = 0;
	j = 0;
	k = izquierda;

	while(i < nl && j < nr){
		if(larr[i] <= rarr[j]){
			v[k] = larr[i];
			i++;
		}else{
			v[k] = rarr[j];
			j++;
		}
		k++;
	}

	while(i < nl){
		v[k] = larr[i];
		i++;
		k++;
	}

	while(j < nr){
		v[k] = rarr[j];
		j++;
		k++;
	}

}

void mergerSort(int izquierda, int derecha, vector<int> &v){
	int medio;
	if(izquierda < derecha){
		medio = (derecha + izquierda)/2;
		mergerSort(izquierda,medio,v);
		mergerSort(medio+1,derecha,v);
		merge(v,izquierda,medio,derecha);
	}
}

/*
*Decripcion: Calcula el numero de elementos que se pueden eliminar
*Parametros: v: vector<int> -> vector;
			 numero: int -> numero con el que se inicia a la puntuacion
*/

int collecionGame(vector<int> &v, int numero){
	unsigned long suma = numero;
	int conteo = 0;
	int i = 0;
	bool salto = false;

	while(i < v.size() && v[i] <= suma){
		suma += v[i];
		conteo++;
		if((numero == v[i]) && !salto){
			salto = true;
			conteo--;
			suma -=v[i];
		}
		i++;
	}

	return conteo;
}


int main(){
	int casos;

	cin >> casos;

	for(int i = 0; i < casos; i++){
		int longitud;
		vector<int> v, collect,vOrdenado;

		cin >> longitud;
		v.resize(longitud);
		collect.resize(longitud);

		for(int j = 0; j < longitud; j++){
			cin >> v[j];
		}

		vOrdenado = v;
		mergerSort(0,longitud-1,vOrdenado);

		for(int j = 0; j < longitud; j++){
			collect[j] = collecionGame(vOrdenado,v[j]);
		}

		for(int j = 0; j < longitud; j++){
			cout << collect[j] << " ";
		}
		cout<<endl;
	}

	return 0;
}
