/*
* La idea del algoritmo es eliminar los elementos repetidos puesto que como repetidos nunca van a ser
*iguales ya que las permutaciones del arreglo no van  a tener numero repetidos para que al sumarlos den el mismo resultado.
*Luego de tener eliminado los elementos repetidos bastaria ir comparando las diferencias entre los elementos 
*restantes del arreglo, puesto que recordemos que las permutaciones son de numeros desde 1 - n donde n
*es el tamaño del arreglo, entonces, si la diferencia de este de estos elemetos supera el mayor numero en este caso
* n entonces no hay forma de que sean iguales, todo esto teniendo el arreglo ordenado para hacer mejor la busqueda 
* de esta cantidad de elementos que pueden ser iguales. Todo esto se plasmo en lel codigo utilizando elementos como set para realizar de manera mas rapida y sencilla eliminacion de elemtnos repetido y vectores
*/

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int longitud;
        vector<int> array;
        set<int> conjunto;
        
        cin >> longitud;
        array.resize(longitud);
        
        for(int j = 0; j < longitud; j++){
            cin >> array[j];
            conjunto.insert(array[j]);
        }
        
        sort(array.begin(),array.end());

        vector<int> arrayN(conjunto.size());
        
        arrayN.clear();
        for (auto it = conjunto.begin(); it != conjunto.end(); it++) {
        	arrayN.push_back(*it);
        }

        int punteroLeft = 0, punteroRight = 0;
        int maximo = 0;
  

        while(punteroRight < arrayN.size()) {
            if (arrayN[punteroRight] - arrayN[punteroLeft] < longitud) {
                punteroRight++;
                maximo = max(maximo, punteroRight - punteroLeft);
            } else {
                punteroLeft++;
                punteroRight = max(punteroLeft, punteroRight);
            }
        }
        cout << maximo << '\n';
      
    }
    
    return 0;
}