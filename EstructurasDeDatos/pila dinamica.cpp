#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Nodo{
	char colores[20];
	Nodo *siguiente;	
}*Inicio, *Nuevo;

void Inicializar(){
	Inicio = NULL;
}

void pushPrimerElemento(char dato[20]){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(Nuevo->colores,dato);
	Nuevo->siguiente = NULL;
	Inicio = Nuevo;
}

void push(char dato[20]){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(Nuevo->colores,dato);
	Nuevo->siguiente = Inicio;
	Inicio = Nuevo;
}
void pop(){
	Inicio = Inicio->siguiente;
}

void Salir(){
	cout<<"Programa terminado";
}

void Desplegar(){
	struct Nodo *aux;
	
	aux = Inicio;
	
	while(aux != NULL){
		cout<<" ["<<aux->colores<<"]"; 
		aux = aux->siguiente;
	}
}

int main(){
	int opcion;
	char dato[20];
	cout<<"Pila Dinamica"<<endl;
	do{
		cout<<endl;
		cout<<"1.-Push"<<endl;
		cout<<"2.-Pop"<<endl;
		cout<<"3.-Desplegar"<<endl;
		cout<<"4.- Salir"<<endl; cout<<endl;
		
		cout<<"elige opcion"<<endl; cin>>opcion; cout<<endl;
		switch(opcion){
			case 1:
				cout<<"Dame el elemento a insertar: "<<endl;
					cin>>dato;
				if(Inicio == NULL){
					pushPrimerElemento(dato);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
				}else{
					push(dato);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
				}
				break;
			case 2:
				if(Inicio != NULL){
					pop();
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
				}
				break;
			case 3: 
			if(Inicio != NULL){
				Desplegar();
			}else{
				cout<<"lista vacia"<<endl; cout<<endl;
			}
				break;
			case 4:
				Salir();
				break;
		}
	}while(opcion != 4);
	
	
}
