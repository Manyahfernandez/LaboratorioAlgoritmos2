/*
*Se dió de cuenta que para el primer piso se necesitan 2, para el segundo se necesitan 5, para el tercero 8, para el cuarto 11, con esto se verifico trato de conseguir una sucesion la cual viene dada por
3*n - 1 cartas donde n es el piso que se quiere construir,teniendo esto se procedio a crear el programa para que verificara si la cantidad de cartas alcanza para construir el siguiente piso. 
*Si alcanza se construye el siguiente y se resta la cantidad. Si no es posible construir el siguiente piso entonces no se construye se suma una piramide y se verifica si la cantidad de cartas
* que quedan es mayor a 2 para construir una siquiente piramide si es asi se procede a seguir el mismo algoritmo hasta que queden 0 o 1 carta.
*/
#include<iostream>

using namespace std;


int main(){
	int casos;

	cin >> casos;

	for(int i = 0; i < casos; i++){
		int n, piramides = 0, piso = 1; 
		cin >> n; 
		while(n >= (3*piso - 1)){ 
			n -= 3*piso - 1; 
			piso = piso + 1;	
			if(n < (3*piso - 1)){
				piramides++;//1
				if(n >= 2){
					piso = 1;
				}
			}	
		}
		cout << piramides<<endl;
	}
	return 0;
}