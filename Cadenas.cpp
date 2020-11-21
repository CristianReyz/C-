#include <iostream>
#include <conio.h> //para fflush
using namespace std;

struct InfoDireccion{
	char direccion[30];
	char ciudad[20];
	char provincia[20];
};

struct empleado{
	char nombre[20];
	struct InfoDireccion direccionEmpleado; //nombre de la estructura, y se le asigna una variable, en este caso direccionEmpleado
	double salario;
}empleados[2]; //variable que almacena toda la estructura empleado

int main(){
	for(int i=0;i<2;i++){
		fflush(stdin); //vaciar buffer
		cout<<"Ingresa el nombre: "<<endl; cin.getline(empleados[i].nombre,20,'\n'); //getline(variable, rango ,hasta cuando termina de ejecutar getline)
		cout<<"ingresa direccion: "<<endl; cin.getline(empleados[i].direccionEmpleado.direccion,30,'\n');
		cout<<"Ingresa cuidad: "<<endl; cin.getline(empleados[i].direccionEmpleado.ciudad,20,'\n');
		cout<<"Ingresa provincia: "<<endl; cin.getline(empleados[i].direccionEmpleado.provincia,20,'\n');
		cout<<"Ingresa salario: "<<endl; cin>>empleados[i].salario;
	}
	//imprimiendo datos
	for(int i=0;i<2;i++){
		cout<<"Nombre: "<<empleados[i].nombre<<endl;
		cout<<"Direccion: "<<empleados[i].direccionEmpleado.direccion <<endl;
		cout<<"Cuidad: "<<empleados[i].direccionEmpleado.ciudad<<endl;
		cout<<"Provincia: "<<empleados[i].direccionEmpleado.provincia<<endl;
		cout<<"Salario: "<<empleados[i].salario<<endl;
		cout<<endl;
	}
}	


