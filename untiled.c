#include <iostream>
#include <stdio.h>
#include <omp.h>

using namespace std;


int main(int argc, char const *argv[]){
	int orden;

	cout<<"ingresa el orden de la matriz: "<<endl;
	cin>>orden;

	int filas,columnas,aux;
	int Hilos = orden - 1;

	int array[orden][orden];
	int array2[orden][orden];
	int vector[orden];

	aux=1;
	cout<<"array original"<<endl;
	for(filas = 0; filas<orden;filas++){
//inicializando e imprimiendo originales
		vector[filas] = 0;
		for(columnas = 0; columnas<orden ;columnas++){
			array[filas][columnas] = aux;
			array2[filas][columnas] = 0;
		}
		aux++;
		for(columnas = 0; columnas < orden;columnas++){
			cout<<"["<<array[filas][columnas]<<"]";
		}
		cout<<endl; 
	}
//final de inicializacion




	cout<<endl; cout<<endl;
	//#pragma omp parallel num_threads(Hilos) 
	//{
		for(filas = 0; filas<orden; filas++){
			//#pragma omp for
			#pragma omp parallel for num_threads(Hilos) //collapse(2)
			for(columnas = 0; columnas<Hilos;columnas++){
				#pragma omp critical
				array2[filas][0] = array[filas][0] + array[filas][1];
				array[filas][0] = array2[filas][0] + array2[filas][1];

				vector[filas] = array[filas][0];
				cout<<"vector en fila: " <<filas<<" hilo: "<<omp_get_thread_num()+1<<
				" ["<<vector[filas]<<"] "<<endl; cout<<endl;
			}
			cout<<endl; cout<<endl;
			#pragma omp barrier
		}
	//}	

		cout<<"vector final"<<endl;
		for(filas = 0; filas<orden; filas++){
			cout<<"["<<vector[filas]<<"]";
			cout<<endl;
		}
}
