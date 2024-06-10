/*
* Para la fila de sushi se creo un vector conteo que lo que hace es contar el numero de piezas del mismo tipo consecutivas y lo guarda el vector, una vez contadas las cantidades de piezas 
* del mismo tipo  en toda la fila de sushi se procedio a comparar par de casillas para escoger el menor numero a este se multiplica por 2 y para sacer el segmento luego sacamos 
* el maximo entre el segmento anterior y la nueva longitud.
*
*/
 
 
#include<iostream>
#include <vector>
 
#include<cmath>
 
using namespace std;
 
int main(){
	int piezas;
 
	cin>>piezas;
 
	vector<long> v(piezas), conteo(piezas,1);
 
	for(int i = 0; i < piezas; i++){
		cin >> v[i];
	}
 
	int k = 0;
 
	for(int i = 1; i < piezas; i++){
		if(v[i] == v[i-1]){
			conteo[k]++;
		}else{
			k++;
		}
	}
	long longitud , segmento = 0;
 
	for(int i = 1; i <= k; i++){
		if(conteo[i] == conteo[i-1] || conteo[i] < conteo[i-1]){
			longitud = 2*conteo[i];
		}else{
			longitud = 2*conteo[i-1];
		}
 
		segmento = max(longitud,segmento);
	}
 
	cout << segmento <<endl;
	return 0;
}