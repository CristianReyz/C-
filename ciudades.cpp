#include <iostream>
#include <string.h>
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

void insertarVertice(int vertice, char ciudad[longitudCadena]){
	if(vertice >= 0 && vertice < cantidadVertices){
		grafo.vertices[vertice] = 1;
		strcpy(grafo.ciudad, ciudad);
		//grafo.ciudad[vertice][longitudCadena] = ciudad[longitudCadena];
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

	int opcion,vertice,vertice2,kilometros;
	char ciudad[longitudCadena];

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
				cout<<"ingresa la posicion del vertice"<<endl;
				cin>>vertice;
				cout<<"ingresa la ciudad"<<endl;
				cin>>ciudad;
				insertarVertice(vertice,ciudad);
				break;
			case 2:
				cout<<"ingresa primer vertice a unir"<<endl;
				cin>>vertice;
				cout<<"ingresa segundo vertice a unir"<<endl;
				cin>>vertice2;
				cout<<"ingresa la distancia en KM"<<endl;
				cin>>kilometros;
				insertarArco(vertice,vertice2,kilometros);
				break;
			case 3:
				cout<<"ingresa el vertice a eliminar"<<endl;
				cin>>vertice;
				eliminarVertice(vertice);
				break;
			case 4:
				cout<<"ingresa primer vertice del arco"<<endl;
				cin>>vertice;
				cout<<"ingresa segundo vertice del arco"<<endl;
				cin>>vertice2;
				eliminarArco(vertice,vertice2);
				break;
			case 5:
				cout<<"vertices"<<endl;
				for(int i = 0; i<cantidadVertices; i++){
					cout<<"["<<grafo.vertices[i]<<"] \t";
					cout<<"["<<grafo.ciudad<<"]"<<endl;	
				}

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
