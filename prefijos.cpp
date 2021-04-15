#include <iostream>

using namespace std;
const int maxFilas = 3;
const int maxColumnas = 3;

int array[maxFilas][maxColumnas];
int arrayAux[maxFilas][maxColumnas-1];
int vector[maxFilas];


int main(){
	int filas = 0,columnas = 0;
	
	for(filas = 0; filas<maxFilas ;filas++){
		for(columnas = 0; columnas<maxColumnas ;columnas++){
			cout<<"llena el array en la posicion ["<<filas<<"] ["<<columnas<<"]"<<endl; 
			cin>>array[filas][columnas];
		}
	}
	
	
	
	
	
	
	
	for(filas = 0; filas<maxFilas; filas++){
		arrayAux[filas][1] = array[filas][2];
	}
/*	arrayAux[0][1] = array[0][2];
	arrayAux[1][1] = array[1][2];
	arrayAux[2][1] = array[2][2]; */
	
	
	
	//seccion 1
	arrayAux[0][0] = array[0][0] + array[0][1];  
	vector[0] = arrayAux[0][0] + arrayAux[0][1];
	
	
	//seccion 2
	arrayAux[1][0] = array[1][0] + array[1][1];
	vector[1] = arrayAux[1][0] + arrayAux[1][1];
	
	//seccion 3
	arrayAux[2][0] = array[2][0] + array[2][1];
	vector[2] = arrayAux[2][0] + arrayAux[2][1];
	
	
	
	
	
	
	
	
	
	
	for(filas = 0; filas<3; filas++){
		for(columnas = 0; columnas<2; columnas++){
			cout<<arrayAux[filas][columnas]<<endl;
		}
	}
	
	
	for(filas = 0; filas<3; filas++){
		cout<<vector[filas];
	}
	
}
