/*
*	El problema se resolvio utilizando megersort para ordenar los elementos, asi mismo binary search incluida en la funcion minimaDistancia, asi mismo una funcion esPosible que se utiliza
* para saber si se pueden colocar los elementos en cierta porción del vector.
*/

#include<iostream>
#include<vector>

using namespace std;


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


bool esPosible(int medio, vector<int> &v, int n, int k){
	int pos = v[0], elementos = 1;
	for(int i = 1; i < n; i++){
		if(v[i] - pos >= medio){
			pos = v[i],
			elementos++;
			if(elementos == k){
				return true;
			}
		}
	}

	return false;
}

int minimaDistancia(vector<int> &v, int n, int k){
	int res = -1, izquierda = 1, derecha = v[n-1];
	mergerSort(0, n - 1, v);
	while(izquierda < derecha){
		int medio = (izquierda + derecha)/2;

		if(esPosible(medio, v, n, k)){
			res = max(res,medio);
			izquierda = medio + 1;
		}
		else{
			derecha = medio;
		}
	}
	return res;

}
int main(){
	int casos;
	cin >> casos;

	for(int i = 0; i < casos; i++){
		int longitud, numeroV;
		cin >> longitud >> numeroV;
		vector<int> v;
		v.resize(longitud);

		for(int j = 0; j < longitud;j++){
			cin >> v[j];
		}
		cout << minimaDistancia(v,longitud,numeroV)<<endl;
	}
	return 0;
}