#include<iostream>
#include<vector>
#include<string>

using namespace std;


void bubbleSort(vector<int> &v, vector<int> &cantidad, vector<int> &prioridad) {
	bool intercambio;
    for(int i = 0; i < v.size(); i++){
    	intercambio = false;
        for(int j = v.size() - 1; j > i; j--){
            if(cantidad[v[j] - 1] > cantidad[v[j - 1] -1]){  
        		intercambio = true;         	
                int tmp = v[j];
                v[j] = v[j-1];
                v[j - 1] = tmp; 
            }
 			if(cantidad[v[j] - 1] == cantidad[v[j - 1] -1]){
 				if(prioridad[v[j] - 1] < prioridad[v[j - 1]-1]){
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
	string cadena = "";
	vector<int> v;

	cin >> n >> c;
	vector<int> cantidad, prioridad;

	v.resize(n);
	cantidad.resize(c,0);
	prioridad.resize(c);

	for(int i = 0; i < n; i++){
		cin >> v[i];
		cantidad[v[i] - 1] +=1;

		if(cadena.find(to_string(v[i]) + "*") == string::npos){
			cadena += to_string(v[i]) + "*" +" ";
			prioridad[v[i]-1] = pos;
			pos++;
		}
	}


	bubbleSort(v,cantidad,prioridad);
	for(int i = 0; i < v.size(); i++){
		if(i == n-1){
			cout<<v[i]<<endl;
		}else{
			cout<< v[i]<< " ";
		}
	}


	return 0;
}