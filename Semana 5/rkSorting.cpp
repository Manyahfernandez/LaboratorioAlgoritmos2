#include<iostream>
#include<vector>
#include<string>

using namespace std;

int partition(vector<int> &v, int p, int r, vector<int> &frecuencia, vector<int> &prioridad){
    int x = frecuencia[v[r]];
    int i =  p - 1;
    int intercambiar;
    for(int j = p; j < r; j++){
        if(frecuencia[v[j]] > x || (frecuencia[v[j]] == x && prioridad[v[j]] < prioridad[v[r]])){
            i = i + 1;
            intercambiar = v[i];
            v[i] = v[j];
            v[j] = intercambiar;
        }
    } 
    intercambiar = v[i + 1];
    v[i + 1] = v[r];
    v[r] = intercambiar;
    return i + 1;
}


void quicksort(vector<int> &v, int p, int r, vector<int> &frecuencia, vector<int> &prioridad){
    int q;
    if(p < r){
        q = partition(v,p,r,frecuencia,prioridad);
        quicksort(v,p,q-1,frecuencia,prioridad);
        quicksort(v,q+1,r,frecuencia,prioridad);
    }
}

int main(){

	int n, c;
	vector<int> v;
	int pos = 0;

	cin >> n >> c;

	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	vector<int> frecuencia(c+1, 0), prioridad;
	prioridad.resize(c + 1);
	vector<bool> verificar(c+1,false);

	for (int i = 0; i < n; i++) {
    	frecuencia[v[i]]++;

		if(!verificar[v[i]]){
			prioridad[v[i]] = pos;
			verificar[v[i]] = true;
			pos++;
		}
	}	

	quicksort(v,0,v.size()-1,frecuencia, prioridad);

	for(int i = 0; i < v.size(); i++){
		cout<< v[i]<< " ";
	}


	return 0;
}