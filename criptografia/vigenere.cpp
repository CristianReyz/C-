#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

char diccionario[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	int aux1,aux2,aux3;
	char mensaje[100];
	char clave[10];

void cifrado_vigenere (){
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(mensaje,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,10);
	int k=0;
	for(int i = 0; i < strlen(mensaje); i++){
		
			for(int j = 0; j < 27; j++){
				if(mensaje[i] == diccionario[j]){
					 aux1 = j;
				}
				if(clave[ k % strlen(clave)] == diccionario[j]){
					 aux2=j;
				}
			}
			aux3 = (aux1 + aux2) % 27;
			mensaje[i] = diccionario[aux3];
			k++;					
	}
	cout<<"El mensaje cifrado es:"<<mensaje<<endl<<endl;
}

void descifrado_vigenere(){
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar: ";
	cin.getline(mensaje,100);
	fflush(stdin);
	cout<<"Ingrese clave: ";
	cin.getline(clave,10);
	
	int k = 0;
	for(int  i = 0 ; i < strlen(mensaje) ; i++){	
			for(int j = 0 ; j < 27; j++ ){
				if( mensaje[i] == diccionario[j] ){
					 aux1 = j;
				}
				if( clave[k % strlen(clave)] == diccionario[j] ){	
					 aux2 = j;
				}
			}
			aux3 = (aux1 - aux2) % 27;
			mensaje[i] = diccionario[aux3];
			k++;					
	}
	cout<<"El mensaje descifrado es: "<<mensaje<<endl<<endl;
}


main(){
	int opc;
	do{	
		cout<<"Menu"<<endl;
		cout<<"1.- Cifrar"<<endl;
		cout<<"2.- Descrifrar"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<"Ingrese Opcion:";
		cin>>opc;
		switch(opc){
			case 1: cifrado_vigenere(); break;
			case 2: descifrado_vigenere(); break;
		}
	}while(opc!=3);
}

