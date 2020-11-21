#include <iostream>
using namespace std;

int main(){
	int numeros[5];
	int i,posicion,aux;
	for(i=0;i<5;i++){
		cout<<"ingresa numeros: "<<endl; cin>>numeros[i];
	}
	for(i=0;i<5;i++){
		cout<<"Numeros: "<< numeros[i];
		cout<<endl;
	}
	cout<<endl;
	// algoritmo
	for(i=0;i<5;i++){
		posicion = i;
		aux = numeros[i];
		while((posicion>0)&&(numeros[posicion-1] > aux)){
			numeros[posicion] = numeros[posicion-1];
			posicion--;
		}
		numeros[posicion] = aux;
	}
	cout<<endl;
	for(i=0;i<5;i++){
		cout<<numeros[i];
	}
}
