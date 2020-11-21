
#include <iostream>
using namespace std;

const int maxArray = 5;
int elemento;

struct Cola{
	int datos[maxArray];
	int PuntFr;
	int PuntFi;
}cola;

void Inicializar(){
	cola.PuntFr = -1;
	cola.PuntFi = -1;
}

int Colallena(){
        if(cola.PuntFi == maxArray-1){
                return 1;
        }
        else{
                return 0;
        }
}
 
int ColaVacia(){
        if(cola.PuntFr == -1 && cola.PuntFi == -1){
                return 1;
        }
        else{
                return 0;
        }
}


void Encolar(){
	if((Colallena() == 1  && cola.PuntFr == 0) || ((cola.PuntFi+1)==cola.PuntFr)){
		cout<<"colallena"<<endl;
	}
	else{
		if(cola.PuntFi == maxArray - 1){
			cola.PuntFi = 0;
		}
		else{
			cola.PuntFi = cola.PuntFi + 1;
		}
		cout<<"ingresa elemento: "<<endl; cin>>elemento;
		cola.datos[cola.PuntFi] = elemento;
		if(cola.PuntFr == -1){
			cola.PuntFr = 0;
		}
	}	
}

void Decolar(){
	if(ColaVacia()==1){
		cout<<"cola Vacia"<<endl;
	}
	else{
		if(cola.PuntFr == cola.PuntFi){
			cola.PuntFr = -1;
			cola.PuntFi = -1;
		}
		else{
			if(cola.PuntFr == maxArray - 1){
				cola.PuntFr = 0;
			}
			else{
				cola.PuntFr = cola.PuntFr + 1;
			}
		}
	}
}

void Desplegar(){
	if(ColaVacia() != 1){
		for(int i = cola.PuntFr; i <= cola.PuntFi ; i++){
			if(cola.PuntFi == maxArray - 1){
					cout<<"       ["<< cola.datos[i]<<"]"<<endl;
			}
		
		}
	}
	if(Colallena()==1){
		cout<<"Cola llena"<<endl;
	}
	if(ColaVacia()==1){
		cout<<"Cola vacia"<<endl;
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
				cout<<"error, ingresa una opcion del menu"<<endl;
				break;
				
		}
	}while(opcion != 4);
}
