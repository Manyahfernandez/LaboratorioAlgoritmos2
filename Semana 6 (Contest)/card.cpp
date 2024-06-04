/*
*Se busco resolver el problema como si se utilizara una pila, en este caso la pila seria el vector pila1 y el caracter de pila vacia seria  '0'. Primero se verifica si la longitud es impar
* ya que si la longitud es impar entonces ya no se podria hacer nada. Luego se utiliza pila1 para almacenar los caracteres de apertura y una vez conseguido un caracter de cierre se verifica si
* coinciden o no. Se utiliza la variable reemplazos para saber cuantos se deben intercambiar.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	string cadena;
	vector<char> pila1;
	int reemplazos = 0;
	pila1.push_back('0');

	cin>> cadena;

	if(cadena.length() % 2 != 0){
		cout<< "Impossible";
	}else{
		int i = 0;
		while(i < cadena.length()){
			if((cadena[i] == '{') || (cadena[i] == '[') || (cadena[i] == '<') || (cadena[i] == '(')){
				pila1.push_back(cadena[i]);
			}else{
				char caracter = pila1.back();
				pila1.pop_back();
				if(caracter == '0'){
					cout << "Impossible";
					return 0;
				}else{
					switch(caracter){
						case '{':
							if(cadena[i] != '}'){
								reemplazos++;
							}
						break;
						case '<':
							if(cadena[i] != '>'){
								reemplazos++;
							}
						break;
						case '[':
							if(cadena[i] != ']'){
								reemplazos++;
							}
						break;
						case '(':
							if(cadena[i] != ')'){
								reemplazos++;
							}
						break;
					}	
				}
			}
			i++;
		}
		if(pila1.size() != 1){
			cout << "Impossible";
		}else{
			cout << reemplazos;
		}
	}

	return 0;
}