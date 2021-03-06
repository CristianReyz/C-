#include <iostream>
using namespace std;

const int cantidadVertices = 4;

struct Grafo{
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

/*int buscarVertice(int vertice){
	for(int i = 0; i<N; i++){
		if(grafo.V[i] == vertice){
			return i;
		}
	}
	return -1;
} */

int buscarVertice(int vertice){
	for(int i = 0; i<cantidadVertices; i++){
		if(grafo.vertices[vertice] == 1){
			return vertice;
		}
	}
	return -1;
}

void insertarArco(int v1, int v2){
	int vertice1, vertice2;
	vertice1 = buscarVertice(v1);
	if(vertice1 != -1){
		vertice2 = buscarVertice(v2);
		if(vertice2 != -1){
			grafo.arcos[v1][v2] = 1;
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

	int opcion,vertice,vertice2;

	do{
		cout<<"menu"<<endl;
		cout<<"1.- insertar vertice"<<endl;
		cout<<"2.- insertar arco"<<endl;
		cout<<"3.- eliminar vertice"<<endl;
		cout<<"4.- eliminar arco"<<endl;
		cout<<"5.- desplegar matriz"<<endl;
		cout<<"6.- salir"<<endl;
		cout<<"ingresa una opcion: "<<endl; cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"ingresa el vertice"<<endl;
				cin>>vertice;
				insertarVertice(vertice);
				break;
			case 2:
				cout<<"ingresa primer vertice a unir"<<endl;
				cin>>vertice;
				cout<<"ingresa segundo vertice a unir"<<endl;
				cin>>vertice2;
				insertarArco(vertice,vertice2);
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
					cout<<"["<<grafo.vertices[i]<<"]"<<endl;
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
