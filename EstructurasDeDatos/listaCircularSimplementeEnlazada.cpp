//cirular simplemente enlazada

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int numero;
	Nodo *siguiente;	
}*lc, *Nuevo;

void Inicializar(){
	lc = NULL;
}

void InsertarPrimerElemento(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = Nuevo;
	lc = Nuevo;
}

void InsertarInicio(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = lc->siguiente;
	lc->siguiente = Nuevo;
}

void InsertarFinal(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = lc->siguiente;
	lc->siguiente = Nuevo;
	lc = Nuevo;
}

void EliminarInicio(){
	lc->siguiente = lc->siguiente->siguiente;
}

struct Nodo *BuscarAntFinal(){
	struct Nodo *aux;
	
	aux = lc->siguiente;
	
	while(aux->siguiente != lc){
		aux = aux->siguiente;
	}
	return aux;
}

void EliminarFinal(){
	struct Nodo *antFinal;
	antFinal = BuscarAntFinal();
	antFinal->siguiente = lc->siguiente;
	lc = antFinal;
}

struct Nodo *BuscarPosicion(int p){
	struct Nodo *aux;
	int contador = 1;
	aux = lc->siguiente;
	
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
	Posicion->siguiente = Nuevo;
		
}
