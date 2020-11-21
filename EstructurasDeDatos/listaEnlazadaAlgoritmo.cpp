#include <iostream>
using namespace std;

struct Nodo{
	int num;
	int *siguiente;	
}nodo;

//dato= dato que se ingresa

*inicio: nodo;
*final: nodo
*nuevo: nodo;

void inicializar(){
	inicio = null;
	final = null;
}

void InsertarPrimerDato(int num){
	nuevo <-Asignar memoria
	nuevo -> num = dato
	nuevo -> siguiente = nulo
	inicio =nuevo
	final=nuevo 
}

void InsertarInicio(int num){
	nuevo = asignar memoria
	nuevo -> num = dato
	nuevo -> siguiente = inicio
	inicio = nuevo
}

void InsertarFinal(int num){
	nuevo = Asignar memoria
	nuevo -> num = dato
	nuevo -> siguiente = null
	Final -> siguiente = nuevo	
}

void InsertarEnPosicion(int num, int p){
	*pos: nodo
	nuevo = asignar memoria 
	nuevo -> num = dato
	pos = buscarPosicion(p)
	nuevo -> siguiente = pos -> siguiente
	pos -> siguiente = nuevo
}

* nodo buscarPosicion(int p){ //regresa un apuntador de tipo nodo
	*aux: nodo
	aux = inicio
	int i = 1;
	while(i<(p - 1)){
		aux = aux->siguiente 
		i++;
	}
	return aux;
}

void EliminarInicio(){
	inicio = inicio -> siguiente
} 

void EliminarFinal(){
	*anteriorFinal : nodo
	anteriorFinal = BuscarAnteriorFinal();
	anteriorFinal -> siguiente = nulo
	final = anteriorFinal;
}

* nodo BuscarAnteriorFinal(){
	*aux: nodo
	aux = inicio
	while(aux->siguiente != final){
		aux = aux -> siguiente
	}
	return aux;
} 

void EliminarPosicion(int p){
	*pos: nodo
	pos = BuscarPosicion(p)
	pos -> sig = pos -> siguiente -> siguiente
}
int main(){
	cout<<"lista enlazada"<<endl;
	
	
}
