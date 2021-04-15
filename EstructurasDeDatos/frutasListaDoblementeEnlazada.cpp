//practica
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;
const int arrayFruta = 15;

struct Nodo{
	char fruta[arrayFruta];
	Nodo *siguiente;
	Nodo *anterior;	
}*NodoLc, *NodoNuevo;

void Inicializar(){
	NodoLc = NULL;
}

void InsertarPrimerElemento(char fruta[arrayFruta]){
	NodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(NodoNuevo->fruta,fruta);
	NodoNuevo->siguiente = NodoNuevo;
	NodoNuevo->anterior = NodoNuevo;
	NodoLc = NodoNuevo;
}

void InsertarInicio(char fruta[arrayFruta]){
	NodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(NodoNuevo->fruta,fruta);
	NodoNuevo->siguiente = NodoLc->siguiente;
	NodoNuevo->anterior = NodoLc;
	NodoLc->siguiente = NodoNuevo;
	NodoLc->siguiente->siguiente->anterior = NodoNuevo;
}

void InsertarFinal(char fruta[arrayFruta]){
	NodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(NodoNuevo->fruta,fruta);
	NodoNuevo->siguiente = NodoLc->siguiente;
	NodoNuevo->anterior = NodoLc;
	NodoLc->siguiente = NodoNuevo;
	NodoLc = NodoNuevo;
}

void EliminarInicio(){
	NodoLc->siguiente = NodoLc->siguiente->siguiente;
	NodoLc->siguiente->siguiente->anterior = NodoLc->siguiente;
}


void EliminarFinal(){
	struct Nodo *NodoPenultimo;
	NodoPenultimo = NodoLc->anterior;
	NodoPenultimo->siguiente = NodoLc->siguiente;
	NodoPenultimo->siguiente->anterior = NodoLc->anterior;
	NodoLc = NodoPenultimo;
}

void MenuInsertar(){
	int opcion;
	char fruta[arrayFruta];
	do{
		system("cls");
		cout<<endl;cout<<"Menu de Insercion"<<endl;
		cout<<"1.-Insertar al Inicio"<<endl;
		cout<<"2.-Insertar al Final"<<endl;
		cout<<"3.-Regresar al menu principal"<<endl;
		
		cout<<"elige opcion"<<endl; cin>>opcion; cout<<endl;
		switch(opcion){
			case 1:
				cout<<"Ingresa la fruta: "<<endl;
					cin>>fruta;
				if(NodoLc == NULL){
					InsertarPrimerElemento(fruta);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
					getch();
				}else{
					InsertarInicio(fruta);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
					getch();
				}
				break;
			case 2:
				cout<<"Ingresa la fruta: "<<endl;
					cin>>fruta;
					if(NodoLc == NULL){
						InsertarPrimerElemento(fruta);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
						getch();
					}else{
						InsertarFinal(fruta);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
						getch();
					}
				break;
			case 3:
				break;
			default:
				cout<<"Error, Ingresa una opcion del menu"<<endl; cout<<endl; getch();
		}
	}while(opcion != 3);
}

void DesplegarInicioFinal(){
	struct Nodo *NodoAuxiliar;
	NodoAuxiliar = NodoLc->siguiente;
	int i = 1;
	while(NodoAuxiliar != NodoLc){
		cout<<endl;cout<<"Registro numero ["<< i <<"]"<<endl;
		cout<<"\t ["<<NodoAuxiliar->fruta<<"]"<<endl; 
		NodoAuxiliar = NodoAuxiliar->siguiente;
		i++;
	}
	cout<<endl;cout<<"Registro numero ["<< i <<"]"<<endl;
	cout<<"\t ["<<NodoLc->fruta<<"]"<<endl; 
}

void DesplegarFinalInicio(){
	struct Nodo *NodoAuxiliar;
	NodoAuxiliar = NodoLc;
	
	int i = 1;
	while(NodoAuxiliar != NodoLc->siguiente){
		cout<<endl;cout<<"Registro numero ["<< i <<"]"<<endl;
		cout<<"\t ["<<NodoAuxiliar->fruta<<"]"<<endl; 
		NodoAuxiliar = NodoAuxiliar->anterior;
		i++;
	}
	cout<<endl;cout<<"Registro numero ["<< i <<"]"<<endl;
	cout<<"\t ["<<NodoLc->siguiente->fruta<<"]"<<endl;
}

void MenuDesplegar(){
	int opcion;
	do{
		system("cls");
		cout<<endl;cout<<"Menu de Despliegue"<<endl;
		cout<<"1.-Inicio - Final"<<endl;
		cout<<"2.-Final - Inicio"<<endl;
		cout<<"3.-Regresar al menu principal"<<endl;
		cout<<"Elige opcion: "<<endl; cin>>opcion; cout<<endl;
		switch(opcion){
			case 1:
				DesplegarInicioFinal();
				getch();
				break;
			case 2:
				DesplegarFinalInicio();
				getch();
				break;
			case 3:
				break;
			default:
				cout<<"Error, Ingresa una opcion del menu"<<endl; cout<<endl;
		}

	}while(opcion !=3);
}

void MenuEliminar(){
	int opcion;
	do{
		system("cls");
		cout<<endl;cout<<"Menu de Eliminacion"<<endl;
		cout<<"1.-Eliminar al Inicio"<<endl;
		cout<<"2.-Eliminar al Final"<<endl;
		cout<<"3.-Regresar al menu principal"<<endl;
		
		cout<<"elige opcion"<<endl; cin>>opcion; cout<<endl;
		switch(opcion){
			case 1:
				if(NodoLc != NULL){
					EliminarInicio();
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
					getch();
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
					getch();
				}
				getch();
				break;
			case 2:
				if(NodoLc != NULL){
					EliminarFinal();
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
					getch();
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
					getch();
				}
				break;
			case 3:
				break;
			default:
				cout<<"Error, Ingresa una opcion del menu"<<endl; cout<<endl;
				getch();
		}
	}while(opcion != 3);
}

void Salir(){
	cout<<"Programa terminado"<<endl;
}

int main(){
	int opcion;
	do{
		system("cls");
		cout<<endl;cout<<"Menu Principal"<<endl;
		cout<<"1.-Insertar"<<endl;
		cout<<"2.-Eliminar"<<endl;
		cout<<"3.-Desplegar"<<endl;
		cout<<"4.-Salir"<<endl;
		
		cout<<"elige opcion"<<endl; cin>>opcion; cout<<endl; system("cls");
		switch(opcion){
			case 1:
				MenuInsertar();
			case 2:
				MenuEliminar();
				break;
			case 3:
				if(NodoLc != NULL){
				MenuDesplegar();
			}else{
				cout<<"lista vacia"<<endl; cout<<endl;
				getch();
			}
				break;
			case 4:
				Salir();
				break;
			default:
				cout<<"Error, ingresa una opcion del menu"<<endl; getch();

		}
	}while(opcion != 4);
}
