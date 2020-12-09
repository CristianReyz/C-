#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;
const int maxFilas = 3;
const int maxColumnas = 3;

int array[maxFilas][maxColumnas];
int arrayAux[maxFilas][maxColumnas-1];
int vector[maxFilas];


int main(int argc, char const *argv[]){

	int filas = 0,columnas = 0;
	int numeroDeHilos = maxFilas - 1;
	
	for(filas = 0; filas<maxFilas ;filas++){
		for(columnas = 0; columnas<maxColumnas ;columnas++){
			cout<<"llena el array en la posicion ["<<filas<<"] ["<<columnas<<"]"<<endl; 
			cin>>array[filas][columnas];
		}
	}

	//imprimiendo el array original
	cout<<"array original"<<endl;
	for(filas = 0; filas<maxFilas;filas++){
		for(columnas = 0; columnas<maxColumnas;columnas++){
			cout<<"["<<array[filas][columnas]<<"]";
		}
		cout<<endl;
	}
	cout<<endl;

	
	omp_set_num_threads(numeroDeHilos); //definiendo numero de hilos

	#pragma omp parallel //seccion paralela
	{
		int id = omp_get_thread_num();
		int cantidad = omp_get_num_threads();

		//tareas del hilo maestro
		#pragma omp master //se ejecuta primero este
		{
			printf("hilo maestro: %d",id+1);
			cout<<endl;
			for(filas = 0; filas<maxFilas; filas++){
				arrayAux[filas][1] = array[filas][2]; //llenando los que no se suman
			}


			for(filas = 0; filas<maxFilas; filas++){
				for(columnas = 0; columnas<(maxColumnas-1);columnas++){
					arrayAux[filas][0] = array[filas][0] + array[filas][1];
				}
			}


			cout<<"array del maestro"<<endl;
			for(filas = 0; filas<maxFilas; filas++){
				for(columnas = 0; columnas<(maxColumnas-1); columnas++){
					cout<<"["<<arrayAux[filas][columnas]<<"]";
				}	
			cout<<endl;
			}
	
			cout<<endl;


		}//fin del hilo maestro
		#pragma omp barrier //esperando al maestro


		#pragma omp single
		{
			cout<<"esperando al maestro"<<endl;
			printf("hilo hijo %d",id+1);
			cout<<endl;
			for(filas = 0; filas<maxFilas; filas++){
				for(columnas = 0; columnas<(maxColumnas-1);columnas++){
					vector[filas] = arrayAux[filas][0] + arrayAux[filas][1]; 
				}
			}


			cout<<"vector del hijo"<<endl;
			for(filas = 0; filas<maxFilas; filas++){
				cout<<"["<<vector[filas]<<"]";
			}

			cout<<endl; 

		}

	}

	//codigo paralelizable
	/*for(filas = 0; filas<maxFilas; filas++){
		arrayAux[filas][1] = array[filas][2]; //llenando los que no se suman
		for(columnas = 0; columnas<(maxColumnas-1);columnas++){
			arrayAux[filas][0] = array[filas][0] + array[filas][1];
			vector[filas] = arrayAux[filas][0] + arrayAux[filas][1]; 
		}
	} 


	//solo imprimir
	cout<<"array original"<<endl;
	for(filas = 0; filas<maxFilas;filas++){
		for(columnas = 0; columnas<maxColumnas;columnas++){
			cout<<"["<<array[filas][columnas]<<"]";
		}
		cout<<endl;
	}
	cout<<endl; 

	cout<<"primer array auxiliar"<<endl;
	for(filas = 0; filas<maxFilas; filas++){
		for(columnas = 0; columnas<(maxColumnas-1); columnas++){
			cout<<"["<<arrayAux[filas][columnas]<<"]";
		}	
		cout<<endl;
	}
	
	cout<<endl;

	cout<<"vector final"<<endl;
	for(filas = 0; filas<maxFilas; filas++){
		cout<<"["<<vector[filas]<<"]";
	}

	cout<<endl; */
	
}
