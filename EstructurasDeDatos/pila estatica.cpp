#include <iostream>
using namespace std;


int numero;

struct pila{
	int tope;
	int datos[5];
}p;

int Pilallena(), PilaVacia();

void inicializar(){
	p.tope = -1;
}

void push(int numero){
	if(Pilallena() == 1){
		cout<<"pila llena"<<endl;
	}
	else{
		p.tope = p.tope + 1;
		p.datos[p.tope] = numero;
	}
}

void pop(){
	if(PilaVacia() != 1){
		p.tope = p.tope - 1;
	}
	else{
		cout<<"Pila Vacia"<<endl;
	}
}

int PilaVacia(){
	if(p.tope == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int Pilallena(){
	if(p.tope == 5){
		return 1;
	}
	else{
		return 0;
	}
}

void cima(){
	if(PilaVacia() != 1){
		cout<<p.datos[p.tope]<<endl;
	}
	else{
		cout<<"pila vacia"<<endl;
	}
}

int main(){
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
				cout<<"["<< p.datos[p.tope]<<"]"<<endl;
				break;
			case 5:
				break;
			default:
				cout<<"error, ingresa una opcion del menu"<<endl;
				break;
				
		}
	}while(opcion < 5);
}
