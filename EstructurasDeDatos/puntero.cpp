#include <iostream>
using namespace std;

main(){
	int numero = 10;
	int * entpunt = &numero;
	
	cout<<"Practica 1 apuntadores...";
	
	cout<<&entpunt <<endl;
	cout<<* entpunt; //  &entpunt la dirección de memoria y *entpunt el valor del valor de la memoria a la que apunta
	
	
	// la diferencia entre el & y el * es que & marca la dirección de memoria y * el valor de la variable a la que apunta
}
