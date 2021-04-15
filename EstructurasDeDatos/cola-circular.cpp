#include <iostream>
using namespace std;

const int maxArray = 5;
int elemento;


struct ColaCircular{
	int datos[maxArray];
	int Frente;
	int Final;
}cola;

void Inicializar(){
	cola.Frente = -1;
	cola.Final = -1;
}

int Colallena(){
        if(cola.Final == maxArray-1){
                return 1;
        }
        else{
                return 0;
        }
}
 
int ColaVacia(){
        if(cola.Frente == -1 && cola.Final == -1){
                return 1;
        }
        else{
                return 0;
        }
}


void Encolar(){
	if((Colallena() == 1  && cola.Frente == 0) || ((cola.Final+1)==cola.Frente)){
		cout<<"colallena"<<endl; cout<<endl;
	}
	else{
		if(cola.Final == maxArray - 1){
			cola.Final = 0;
		}
		else{
			cola.Final = cola.Final + 1;
		}
		cout<<"ingresa elemento: "<<endl; cin>>elemento;
		cola.datos[cola.Final] = elemento;
		cout<<"Elemento registrado con exito"<<endl; cout<<endl;
		if(cola.Frente == -1){
			cola.Frente = 0;
		}
	}
}

void Decolar(){
	if(ColaVacia()==1){
		cout<<"cola Vacia"<<endl; cout<<endl;
	}
	else{
		if(cola.Frente == cola.Final){
			Inicializar();
		}
		else{
			if(cola.Frente == maxArray - 1){
				cola.Frente = 0;
			}
			else{
				cola.Frente = cola.Frente + 1;
				cout<<"Elemento eliminado con exito"<<endl;	cout<<endl;
			}
		}
	}
}

void Desplegar(){
	if(ColaVacia() != 1){
		
		if(cola.Frente < cola.Final){
			for(int i = cola.Frente; i <= cola.Final ; i++){
			cout<<" ["<< cola.datos[i]<<"]"<<endl;
			}	
		}	
		else{
			for(int j = cola.Frente; j <= (maxArray - 1); j++){
				cout<<" ["<< cola.datos[j]<<"]"<<endl;
			}
			for(int k = 0; k <= cola.Final; k++){
				cout<<" ["<< cola.datos[k]<<"]"<<endl;
			}
		}
	}
	if(ColaVacia()==1){
		cout<<"Cola vacia"<<endl; cout<<endl;
	}
}

int main(){
	cout<<"Cola circular"<<endl; cout<<endl;
	int opcion;
	Inicializar();
	do{
		cout<<"menu"<<endl;
		cout<<"1.- Encolar"<<endl;
		cout<<"2.- Decolar"<<endl;
		cout<<"3.- Desplegar"<<endl;
		cout<<"4.- salir"<<endl;
		cin>>opcion;
		cout<<endl;
		switch(opcion){
			case 1:
				Encolar();
				break;
			case 2:
				Decolar();
				break;
			case 3:
				Desplegar();
				break;
			case 4:
				break;
			default:
				cout<<"error, ingresa una opcion del menu"<<endl; cout<<endl;
				break;
		}
	}while(opcion != 4);
}
