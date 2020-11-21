

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
using namespace std;

const int arrayNombre = 20;
const int arrayTipo = 15;

struct Nodo{
	char nombre[arrayNombre];
	char tipo[arrayTipo];
	int edad;
	Nodo *siguiente;
	Nodo *anterior;	
}*NodoInicio, *NodoNuevo, *NodoFinal;


void Inicializar(){
	NodoInicio = NULL;
	NodoFinal = NULL;
}

void InsertarPrimerElemento(char nombre[arrayNombre], char tipo[arrayTipo], int edad){
	NodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(NodoNuevo->nombre,nombre);
	strcpy(NodoNuevo->tipo,tipo);
	NodoNuevo->edad = edad;
	NodoNuevo->siguiente = NULL;
	NodoNuevo->anterior = NULL;
	NodoInicio = NodoNuevo;
	NodoFinal = NodoNuevo;
}

void InsertarInicio(char nombre[arrayNombre], char tipo[arrayTipo], int edad){
	NodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(NodoNuevo->nombre,nombre);
	strcpy(NodoNuevo->tipo,tipo);
	NodoNuevo->edad = edad;
	NodoNuevo->siguiente = NodoInicio;
	NodoNuevo->anterior = NULL;
	NodoInicio->anterior = NodoNuevo;
	NodoInicio = NodoNuevo;
}

void InsertarFinal(char nombre[arrayNombre], char tipo[arrayTipo], int edad){
	NodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(NodoNuevo->nombre,nombre);
	strcpy(NodoNuevo->tipo,tipo);
	NodoNuevo->edad = edad;
	NodoNuevo->siguiente = NULL;
	NodoNuevo->anterior = NodoFinal;
	NodoFinal->siguiente = NodoNuevo;
	NodoFinal = NodoNuevo;
}

struct Nodo *BuscarPosicion(int p){
	struct Nodo *aux;
	int contador = 1;
	aux = NodoInicio;
	
	while(contador < (p-1)){
		aux = aux->siguiente;
		contador ++;
	}
	return aux;
} 

void InsertarPosicion(char nombre[arrayNombre], char tipo[arrayTipo], int edad, int p){
	struct Nodo *NodoPosicion;
	NodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
	strcpy(NodoNuevo->nombre,nombre);
	strcpy(NodoNuevo->tipo,tipo);
	NodoNuevo->edad = edad;
	NodoPosicion = BuscarPosicion(p);
	NodoNuevo->siguiente = NodoPosicion->siguiente;
	NodoNuevo->anterior = NodoPosicion;
	NodoPosicion->siguiente = NodoNuevo;
	NodoNuevo->siguiente->anterior = NodoNuevo;
		
}
void EliminarInicio(){
	NodoInicio = NodoInicio->siguiente;
	NodoInicio->anterior = NULL;
}
void EliminarFinal(){
	NodoFinal = NodoFinal->anterior;
	NodoFinal->siguiente = NULL;
}
void EliminarPosicion(int p){
	struct Nodo *NodoPosicion;
	NodoPosicion = BuscarPosicion(p);
	NodoPosicion->siguiente = NodoPosicion->siguiente->siguiente;
	NodoPosicion->siguiente->anterior = NodoPosicion;
	
}


void DesplegarInicioFinal(){
	struct Nodo *NodoAuxiliar;
	NodoAuxiliar = NodoInicio;
	int i = 1;
	while(NodoAuxiliar != NULL){
		cout<<endl;cout<<"Registro numero ["<< i <<"]"<<endl;
		cout<<"\t ["<<NodoAuxiliar->nombre<<"]"<<endl; 
		cout<<"\t ["<<NodoAuxiliar->tipo<<"]"<<endl;
		cout<<"\t ["<<NodoAuxiliar->edad<<"]"<<endl;
		NodoAuxiliar = NodoAuxiliar->siguiente;
		i++;
	}
}

void DesplegarFinalInicio(){
	struct Nodo *NodoAuxiliar;
	NodoAuxiliar = NodoFinal;
	int i = 1;
	while(NodoAuxiliar != NULL){
		cout<<endl;cout<<"Registro numero ["<< i <<"]"<<endl;
		cout<<"\t ["<<NodoAuxiliar->nombre<<"]"<<endl; 
		cout<<"\t ["<<NodoAuxiliar->tipo<<"]"<<endl;
		cout<<"\t ["<<NodoAuxiliar->edad<<"]"<<endl;
		NodoAuxiliar = NodoAuxiliar->anterior;
		i++;
	}
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
	int opcion,posicion;
	do{
		system("cls");
		cout<<endl;cout<<"Menu de Eliminacion"<<endl;
		cout<<"1.-Eliminar al Inicio"<<endl;
		cout<<"2.-Eliminar en posicion"<<endl;
		cout<<"3.-Eliminar al Final"<<endl;
		cout<<"4.-Regresar al menu principal"<<endl;
		
		cout<<"elige opcion"<<endl; cin>>opcion; cout<<endl;
		switch(opcion){
			case 1:
				if(NodoInicio != NULL){
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
				if(NodoInicio != NULL){
					cout<<"dame la posicion"<<endl;
					cin>>posicion;
					EliminarPosicion(posicion);
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
					getch();
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
					getch();
				}
				getch();
				break;
			case 3:
				if(NodoInicio != NULL){
					EliminarFinal();
					cout<<"Dato eliminado con exito"<<endl; cout<<endl;
					getch();
				}else{
					cout<<"lista vacia"<<endl; cout<<endl;
					getch();
				}
				break;
			case 4:
				break;
			default:
				cout<<"Error, Ingresa una opcion del menu"<<endl; cout<<endl;
				getch();
		}
	}while(opcion != 4);
}

void MenuInsertar(){
	int opcion,edad, posicion;
	char nombre[arrayNombre], tipo[arrayTipo];
	do{
		system("cls");
		cout<<endl;cout<<"Menu de Insercion"<<endl;
		cout<<"1.-Insertar al Inicio"<<endl;
		cout<<"2.-Insertar en posicion"<<endl;
		cout<<"3.-Insertar al Final"<<endl;
		cout<<"4.-Regresar al menu principal"<<endl;
		
		cout<<"elige opcion"<<endl; cin>>opcion; cout<<endl;
		switch(opcion){
			case 1:
				cout<<"Ingresa el nombre: "<<endl;
					cin>>nombre;
				cout<<"Ingresa el tipo: "<<endl;
					cin>>tipo;
				cout<<"Ingresa la edad: "<<endl;
					cin>>edad;
				if(NodoInicio == NULL){
					InsertarPrimerElemento(nombre,tipo,edad);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
					getch();
				}else{
					InsertarInicio(nombre,tipo,edad);
					cout<<"Dato insertado con exito"<<endl; cout<<endl;
					getch();
				}
				break;
			case 2:
				cout<<"Ingresa el nombre: "<<endl;
					cin>>nombre;
				cout<<"Ingresa el tipo: "<<endl;
					cin>>tipo;
				cout<<"Ingresa la edad: "<<endl;
					cin>>edad;
					if(NodoInicio == NULL){
						InsertarPrimerElemento(nombre,tipo,edad);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
						getch();
					}else{
						cout<<"Ingresa la posicion: "<<endl;
						cin>>posicion;
						InsertarPosicion(nombre,tipo,edad,posicion);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
						getch();
					}
				break;
			case 3:
				cout<<"Ingresa el nombre: "<<endl;
					cin>>nombre;
				cout<<"Ingresa el tipo: "<<endl;
					cin>>tipo;
				cout<<"Ingresa la edad: "<<endl;
					cin>>edad;
					if(NodoInicio == NULL){
						InsertarPrimerElemento(nombre,tipo,edad);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
						getch();
					}else{
						InsertarFinal(nombre,tipo,edad);
						cout<<"Dato insertado con exito"<<endl; cout<<endl;
						getch();
					}
				break;
			case 4:
				break;
			default:
				cout<<"Error, Ingresa una opcion del menu"<<endl; cout<<endl; getch();
		}
	}while(opcion != 4);
}

void Salir(){
	cout<<"Programa Finalizado"<<endl;
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
				getch();
			case 2:
				MenuEliminar();
				getch();
				break;
			case 3:
				if(NodoInicio != NULL){
				MenuDesplegar();
				getch();
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

