//cirular doblemente enlazada

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int numero;
	Nodo *siguiente;
	Nodo *anterior;	
}*lc, *Nuevo;

void Inicializar(){
	lc = NULL;
}

void InsertarPrimerElemento(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = Nuevo;
	Nuevo->anterior = Nuevo;
	lc = Nuevo;
}

void InsertarInicio(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = lc->siguiente;
	Nuevo->anterior = lc;
	lc->siguiente = Nuevo;
	lc->siguiente->siguiente->anterior = Nuevo;
}

void InsertarFinal(int dato){
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->numero = dato;
	Nuevo->siguiente = lc->siguiente;
	Nuevo->anterior = lc;
	lc->siguiente = Nuevo;
	lc = Nuevo;
}

void EliminarInicio(){
	lc->siguiente = lc->siguiente->siguiente;
	lc->siguiente->siguiente->anterior = lc;
}


void EliminarFinal(){
	struct Nodo *antFinal;
	antFinal = lc->anterior;
	antFinal->siguiente = lc->siguiente;
	antFinal->siguiente->anterior = lc->anterior;
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
