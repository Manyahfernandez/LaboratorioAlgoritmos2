#include<iostream>
#include<vector>
#include<string>

using namespace std;


void bubbleSort(vector<int> &v, vector<int> &cantidad, vector<int> &prioridad) {
	bool intercambio;
    for(int i = 0; i < v.size(); i++){
    	intercambio = false;
        for(int j = v.size() - 1; j > i; j--){
            if(cantidad[v[j]] > cantidad[v[j - 1]]){  
        		intercambio = true;         	
                int tmp = v[j];
                v[j] = v[j-1];
                v[j - 1] = tmp; 
            }
 			if(cantidad[v[j]] == cantidad[v[j - 1]]){
 				if(prioridad[v[j]] < prioridad[v[j - 1]]){
 					intercambio = true;
 					int tmp = v[j];
                	v[j] = v[j-1];
                	v[j - 1] = tmp; 
 				}
 			}
        }
        if(!intercambio){
        	break;
        }
    }
}

int main(){

	int n, c;
	int pos = 0;
	vector<int> v;

	cin >> n >> c;
	vector<int> frecuencia, prioridad, verificar;

	v.resize(n);
	frecuencia.resize(c+1,0);
	prioridad.resize(c+1);
	verificar.resize(c+1,false);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
    	frecuencia[v[i]]++;

		if(!verificar[v[i]]){
			prioridad[v[i]] = pos;
			verificar[v[i]] = true;
			pos++;
		}
	}	

	bubbleSort(v,frecuencia,prioridad);
	
	for(int i = 0; i < v.size(); i++){
		if(i == n-1){
			cout<<v[i]<<endl;
		}else{
			cout<< v[i]<< " ";
		}
	}


	return 0;
}