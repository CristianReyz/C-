#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

const int cantidadVertices = 4;
const int longitudCadena = 20; 

struct Grafo{
	char ciudad[cantidadVertices][longitudCadena];
	int vertices[cantidadVertices];
	int arcos[cantidadVertices][cantidadVertices];
}grafo;

void inicializar(){
	for(int i = 0; i<cantidadVertices;i++){
		grafo.vertices[i] = 0;
		for(int j = 0; j<cantidadVertices; j++){
			grafo.arcos[i][j] = 0;  
		}
	}
}

void insertarVertice(int vertice){
	if(vertice >= 0 && vertice < cantidadVertices){
		grafo.vertices[vertice] = 1;
	}
}

int buscarVertice(int vertice){
	for(int i = 0; i<cantidadVertices; i++){
		if(grafo.vertices[vertice] == 1){
			return vertice;
		}
	}
	return -1;
}

void insertarArco(int v1, int v2, int kilometros){
	int vertice1, vertice2;
	vertice1 = buscarVertice(v1);
	if(vertice1 != -1){
		vertice2 = buscarVertice(v2);
		if(vertice2 != -1){
			grafo.arcos[v1][v2] = kilometros;
		}
		else{
			cout<<"el vertice 2 no existe"<<endl;
		}
	}
	else{
		cout<<"el vertice 1 no existe"<<endl;
	}
}

void eliminarArco(int v1, int v2){
	int vertice1, vertice2;
	vertice1 = buscarVertice(v1);
	if(vertice1 != -1){
		vertice2 = buscarVertice(v2);
		if(vertice2 != -1){
			grafo.arcos[v1][v2] = 0;
		}
		else{
			cout<<"el vertice 2 no existe"<<endl;
		}
	}
	else{
		cout<<"el vertice 1 no existe"<<endl;
	}
}

void eliminarVertice(int v1){
	int vertice1;
	vertice1 = buscarVertice(v1);
	if(vertice1 != -1){
		grafo.vertices[vertice1] = 0;
		for(int i = 0; i<longitudCadena;i++){
				grafo.ciudad[vertice1][i] = ' ';	
		}
		for(int i = 0; i<cantidadVertices; i++){
			grafo.arcos[vertice1][i] = 0;
			grafo.arcos[i][vertice1] = 0;
		}
	}
	else{
		cout<<"el vertice no existe"<<endl;
	}
}
int main(){

	int opcion,kilometros;
	int vertice,vertice2;
	char vertice1[longitudCadena], verticeAux[longitudCadena];
	char ciudad[cantidadVertices][longitudCadena];
	int posicion,posicion2;
	int comparacion;
	do{
		cout<<"menu"<<endl;
		cout<<"1.- insertar ciudad"<<endl;
		cout<<"2.- insertar distancia"<<endl;
		cout<<"3.- eliminar ciudad"<<endl;
		cout<<"4.- eliminar distancia"<<endl;
		cout<<"5.- desplegar matriz"<<endl;
		cout<<"6.- salir"<<endl;
		cout<<"ingresa una opcion: "<<endl; cin>>opcion;
		switch(opcion){
			case 1:
				int opcion,i;
				i = 0;
				do{
					fflush(stdin);
					cout<<"ingresa una ciudad"<<endl;
					gets(grafo.ciudad[i]);
					fflush(stdin);
					insertarVertice(i);	
					i++;
					cout<<"Desea ingresar otra ciudad? 1/si 2/no"<<endl;
					cin>>opcion;
				}while(opcion !=2);
				break;
			case 2:
				fflush(stdin);
				cout<<"ingresa primer ciudad a unir"<<endl;
				cin>>vertice1;
				for(int i = 0;i<cantidadVertices;i++){
					comparacion = strcmp(vertice1,grafo.ciudad[i]);
					if(comparacion == 0){
						posicion = i;
						i=cantidadVertices;
					}	
				}
			
				fflush(stdin);
				cout<<"ingresa segunda ciudad a unir"<<endl;
				cin>>verticeAux;
				for(int i = 0;i<cantidadVertices;i++){
					comparacion = strcmp(verticeAux,grafo.ciudad[i]);
					if(comparacion == 0){
						posicion2 = i;
						i=cantidadVertices;
					}	
				}
				cout<<"ingresa la distancia en KM"<<endl;
				cin>>kilometros;
				insertarArco(posicion,posicion2,kilometros);
				break;
			case 3:
				cout<<"ingresa ciudad a eliminar"<<endl;
				cin>>vertice1;
				for(int i = 0;i<cantidadVertices;i++){
					comparacion = strcmp(vertice1,grafo.ciudad[i]);
					if(comparacion == 0){
						posicion = i;
						i=cantidadVertices;
						eliminarVertice(posicion);
						fflush(stdin);
					}	
				}
				break;
			case 4:
								fflush(stdin);
				cout<<"ingresa primer ciudad a desconectar"<<endl;
				cin>>vertice1;
				for(int i = 0;i<cantidadVertices;i++){
					comparacion = strcmp(vertice1,grafo.ciudad[i]);
					if(comparacion == 0){
						posicion = i;
						i=cantidadVertices;
					}	
				}
			
				fflush(stdin);
				cout<<"ingresa segunda ciudad a desconectar"<<endl;
				cin>>verticeAux;
				for(int i = 0;i<cantidadVertices;i++){
					comparacion = strcmp(verticeAux,grafo.ciudad[i]);
					if(comparacion == 0){
						posicion2 = i;
						i=cantidadVertices;
					}	
				}
				eliminarArco(posicion,posicion2);
				break;
			case 5:
				cout<<"vertices"<<endl;
				
				fflush(stdin);
				for(int i = 0; i<cantidadVertices; i++){
					cout<<"["<<grafo.vertices[i]<<"] ";
					puts(grafo.ciudad[i]);
				}

				cout<<endl;
				cout<<"Arcos"<<endl;
				for(int i = 0; i<cantidadVertices;i++){
					for(int j = 0; j<cantidadVertices; j++){
						cout<<"["<<grafo.arcos[i][j]<<"]";
					}
					cout<<endl;
				}
				break;
			case 6:
				break;

		}

	}while(opcion != 6);

}
