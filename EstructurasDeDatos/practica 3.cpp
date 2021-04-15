#include <iostream>
using namespace std;


int numero;
const int MaxArray = 5;

struct pila{
	int tope;
	int datos[MaxArray];
}p;

int Pilallena(), PilaVacia();

void inicializar(){
	p.tope = -1;
}

void push(int numero){
	if(Pilallena() == 1){
		cout<<"pila llena"<<endl;cout<<endl;
	}
	else{
		p.tope = p.tope + 1;
		p.datos[p.tope] = numero;
		cout<<"Dato registrado con exito"<<endl; cout<<endl;
	}
}

void pop(){
	if(PilaVacia() != 1){
		p.tope = p.tope - 1;
		cout<<"Dato eliminado con exito"<<endl; cout<<endl;
	}
	else{
		cout<<"Pila Vacia"<<endl; cout<<endl;
	}
}

int PilaVacia(){
	if(p.tope == -1){
		return 1;
	}
	else{
		return 0;
	}
}

int Pilallena(){
	if(p.tope == MaxArray - 1){
		return 1;
	}
	else{
		return 0;
	}
}

void cima(){
	if(PilaVacia() != 1){
		cout<<"tope: ["<<p.datos[p.tope]<<"]"<<endl;
	}
	else{
		cout<<"pila vacia"<<endl; cout<<endl;
	}
}

void desplegar(){
	if(PilaVacia() != 1){
		cima(); 					  //aprovechando la funcion cima
		for(int i=p.tope-1;i>=0;i--) //como se imprime el tope arriba, entonces es un recorrido al reves, y como ya se imprimio cima entonces el contador se inicializa diferente
			cout<<"      ["<<p.datos[i]<<"]"<<endl;
			cout<<endl;
	}
	else{
		cout<<"pila vacia"<<endl;
		cout<<endl;
	}
}

int main(){
	cout<<"Practica 3"<<endl; cout<<endl;
	int opcion;
	inicializar();
	do{
		cout<<"menu"<<endl;
		cout<<"1.- push"<<endl;
		cout<<"2.- pop"<<endl;
		cout<<"3.- cima"<<endl;
		cout<<"4.- desplegar"<<endl;
		cout<<"5.- salir"<<endl;
		cin>>opcion;
		cout<<endl;
		switch(opcion){
			case 1:
				cout<<"ingresa un numero: "<<endl; cin>>numero;
				push(numero);
				break;
			case 2:
				pop();
				break;
			case 3:
				cima();
				break;
			case 4:
				desplegar();
				break;
			case 5:
				break;
			default:
				cout<<"error, ingresa una opcion del menu"<<endl;
				break;
				
		}
	}while(opcion < 5);
}
