//arbol ABB
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

void eliminaCaso3(struct Nodo *);

struct Nodo{
	int dato;
	Nodo *izquierdo;
	Nodo *derecho;	
}*raiz;

void mostrarOrden(struct Nodo *A){
	if(A != NULL){
		mostrarOrden(A->izquierdo);
		cout<<A->dato<<"-> "<<endl;
		mostrarOrden(A->derecho);
	}
}

void inicializar(){
	raiz = NULL;
}

struct Nodo *buscarNodo(int numero){
	struct Nodo *aux;
	
	aux= raiz;
	while(aux->dato != numero){
		if(numero < aux->dato){
			aux = aux->izquierdo;
		}else{
			aux = aux->derecho;
		}
		if(aux == NULL){
			break;
		}
	}
	return aux;
}

struct Nodo *buscarPadre(int numero){
	Nodo *padre, *aux;
	padre = NULL;
	aux = raiz;
	while(aux != NULL){
		padre  = aux;
		if(aux->dato > numero){
			aux = aux->izquierdo;
		}else{
			aux = aux->derecho;
		}
	}
	return padre;
}

void eliminaCaso1(struct Nodo *nodo){
	struct Nodo *hijoIzquierdo, *hijoDerecho, *padre;
	padre = buscarPadre(nodo->dato);
	hijoIzquierdo = padre->izquierdo;
	hijoDerecho = padre->derecho;
	
	if(hijoIzquierdo == nodo){
		padre->izquierdo = NULL;
	}
	if(hijoDerecho == nodo){
		padre->derecho = NULL;
	}
}

void eliminaCaso2(struct Nodo *nodo){
	struct Nodo *hijoIzquierdo, *hijoDerecho, *hijoActual, *padre;
	padre = buscarPadre(nodo->dato);
	hijoIzquierdo = padre->izquierdo;
	hijoDerecho = padre->derecho;
	if(nodo->izquierdo != NULL){
		hijoActual = nodo->izquierdo;
	}else{
		hijoActual = nodo->derecho;
	}
	if(hijoIzquierdo == nodo){
		padre->izquierdo = hijoActual;
	}
	if(hijoDerecho == nodo){
		padre->derecho = hijoActual;
	}
}

struct Nodo *recorrerIzquierda(struct Nodo *nodo){
	if(nodo->izquierdo != NULL){
		return recorrerIzquierda(nodo->izquierdo);
	}
	return nodo;
}

void eliminar(struct Nodo *nodo){
	int tieneHijoDerecho, tieneHijoIzquierdo;
	if(nodo->derecho != NULL){
		tieneHijoDerecho = 1;
	}else{
		tieneHijoDerecho = 0;
	}
	if(nodo->izquierdo != NULL){
		tieneHijoIzquierdo = 1;
	}else{
		tieneHijoIzquierdo = 0;
	}
	
	if(tieneHijoIzquierdo == 0 && tieneHijoDerecho == 0){
		eliminaCaso1(nodo); //no tiene hijos
	}else{
		if(tieneHijoIzquierdo == 1 && tieneHijoDerecho == 1){
			eliminaCaso3(nodo); //2 hijos
		}else{
			eliminaCaso2(nodo); //1 hijo
		}
	}
}


void eliminaCaso3(struct Nodo *nodo){
	struct Nodo *masIzq;
	masIzq = recorrerIzquierda(nodo->derecho);
	if(masIzq !=NULL){
		nodo->dato = masIzq->dato;
		eliminar(masIzq);
	}
	
}



void insertarNumero(int numero){
	Nodo *Padre, *Nuevo;
	Nuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	Nuevo->dato = numero;
	Nuevo->izquierdo = NULL;
	Nuevo->derecho = NULL;
	
	Padre = buscarPadre(numero);
	if(raiz == NULL){
		raiz = Nuevo;
	}else{
		if(Nuevo->dato <= Padre->dato){
			Padre->izquierdo =Nuevo;
		}else{
			Padre->derecho =Nuevo;
		}
	}
	
}


int main(){
	
}
