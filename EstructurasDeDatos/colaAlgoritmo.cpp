#include <iostream>
using namespace std;

const int maxArray = 5;

struct Cola{
	int datos[maxArray];
	int PuntFr;
	int PuntFi;
}cola;

void inicializar(){
	cola.PuntFr = -1;
	cola.PuntFi = -1;
}

int Colallena(),ColaVacia();

void insertar(int elemento){
	if(Colallena() != 1){
		cola.PuntFi = cola.PuntFi + 1; //se incrementa el final de la cola al insertar un elemento
		cola.datos[cola.PuntFi] = elemento;
		if(cola.PuntFr == -1){
			cola.PuntFr = cola.PuntFr + 1; 
		}
	}
	else{
		cout<<"Cola llena"<<endl;
	}
}

void Quitar(){
	if(ColaVacia() != 1){
		cola.PuntFr = cola.PuntFr + 1;
	}
	else{
		cout<<"Cola Vacia"<<endl;
	}
}

int Colallena(){
	if(cola.PuntFi == maxArray){
		return 1;
	}
	else{
		return 0;
	}
}

int ColaVacia(){
	if(cola.PuntFr == -1){
		return 1;
	}
	else{
		return 0;
	}
}

void Frente(){
	if(ColaVacia() != 1){
		cout<<cola.datos[cola.PuntFr]<<endl;
	}
}



main(){
	cout<<"Cola implementacion algoritmo"<<endl;
	inicializar();
	int elemento;
	cout<<"Ingresa un elemento"<<endl; cin>>elemento;
	insertar(elemento);
	
}
