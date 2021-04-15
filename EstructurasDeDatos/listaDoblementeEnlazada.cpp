#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int numero;
	Nodo *siguiente;
	Nodo *anterior;	
}*Inicio, *Nuevo, *Final;

void Inicializar(){
	Inicio = NULL;
	Final = NULL;
}

void InsertarPrimerElemento(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = NULL;
	Nuevo->anterior = NULL;
	Inicio = Nuevo;
	Final = Nuevo;
}

void InsertarInicio(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = Inicio;
	Nuevo->anterior = NULL;
	Inicio->anterior = Nuevo;
	Inicio = Nuevo;
}

void InsertarFinal(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = NULL;
	Nuevo->anterior = Final;
	Final->siguiente = Nuevo;
	Final = Nuevo;
}

struct Nodo *BuscarPosicion(int p){
	struct Nodo *aux;
	int contador = 1;
	aux = Inicio;
	
	while(contador < (p-1)){
		aux = aux->siguiente;
		contador ++;
	}
	return aux;
} 

void InsertarPosicion(int dato, int p){
	struct Nodo *Posicion;
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Posicion = BuscarPosicion(p);
	Nuevo->siguiente = Posicion->siguiente;
	Nuevo->anterior = Posicion;
	Posicion->siguiente = Nuevo;
	Nuevo->siguiente->anterior = Nuevo;
		
}
void EliminarInicio(){
	Inicio = Inicio->siguiente;
	Inicio->anterior = NULL;
}
void EliminarFinal(){
	Final = Final->anterior;
	Final->siguiente = NULL;
}
void EliminarPosicion(int p){
	struct Nodo *pos;
	pos = BuscarPosicion(p);
	pos->siguiente = pos->siguiente->siguiente;
	pos->siguiente->anterior = pos;
	
}

void Salir(){
	cout<<"Programa terminado";
}

void Desplegar(){
	struct Nodo *aux;
	
	aux = Inicio;
	
	while(aux != NULL){
		cout<<"["<<aux->numero<<"]"<<endl; 
		aux = aux->siguiente;
	}
}

int main(){
	int opcion, dato, posicion;
	cout<<"Lista Simplemente enlazada"<<endl;
	do{
		cout<<"1.-Insertar Inicio"<<endl;
		cout<<"2.-Insertar en posicion"<<endl;
		cout<<"3.-Insertar al final"<<endl;
		cout<<"4.-Eliminar Inicio"<<endl;
		cout<<"5.-Eliminar en posicion"<<endl;
		cout<<"6.-Eliminar final"<<endl;
		cout<<"7.-Desplegar"<<endl;
		cout<<"8.- Salir"<<endl; cout<<endl;
		
		cout<<"elige opcion"<<endl; cin>>opcion; cout<<endl;
		switch(opcion){
			case 1:
				cout<<"Dame el elemento a insertar: "<<endl;
					cin>>dato;
				if(Inicio == NULL){
					InsertarPrimerElemento(dato);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
				}else{
					InsertarInicio(dato);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
				}
				break;
			case 2:
				cout<<"Dame el elemento a insertar: "<<endl;
					cin>>dato;
					if(Inicio == NULL){
						InsertarPrimerElemento(dato);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
					}else{
						cout<<"Ingresa la posicion: "<<endl;
						cin>>posicion;
						InsertarPosicion(dato,posicion);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
					}
				break;
			case 3:
				cout<<"Dame el elemento a insertar: "<<endl;
					cin>>dato;
				if(Inicio == NULL){
					InsertarPrimerElemento(dato);
					cout<<"Dato insertado"<<endl; cout<<endl;
				}else{
					InsertarFinal(dato);
					cout<<"Dato insertado"<<endl; cout<<endl;
				}
				break;
			case 4:
				if(Inicio != NULL){
					EliminarInicio();
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
				}
				break;
			case 5:
				if(Inicio != NULL){
					cout<<"dame la posicion"<<endl;
					cin>>posicion;
					EliminarPosicion(posicion);
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
				}
				break;
			case 6:
				if(Inicio != NULL){
					EliminarFinal();
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
				}
				break;
			case 7: 
			if(Inicio != NULL){
				Desplegar();
			}else{
				cout<<"lista vacia"<<endl;
			}
				break;
			case 8:
				Salir();
				break;
		}
	}while(opcion != 8);
	return 0;
	
}
