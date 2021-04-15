#include<iostream>
using namespace std;
int arrayOriginal[10];
	int size,tam;

int divide(int arr[],int minimo,int mitad, int maximo){
	int arrayTemporal1[5];
	int arrayTemporal2[5];
	
	int n1,n2,i,j,k;
	n1 = mitad - minimo + 1;
	n2 = maximo - mitad;

	for(i = 0; i < n1;i++){
		arrayTemporal1[i] = arrayOriginal[minimo + i];
	}
	for(j = 0;j < n2;j++){
		arrayTemporal2[j] = arrayOriginal[mitad + j + 1];
	}
	arrayTemporal1[i]=9999;
	arrayTemporal2[j]=9999;
	i = 0; j = 0;
	for(k = minimo ;k <= maximo ; k++){
		if(arrayTemporal1[i] <= arrayTemporal2[j]){
			arrayOriginal[k] = arrayTemporal1[i++];
		}
		else{
			arrayOriginal[k] = arrayTemporal2[j++];
		}
	}
}

int ordena(int array[],int minimo,int maximo){
	int mitad;
	if(minimo < maximo){ 
		mitad = (minimo + maximo)/2;		
		//dividiendo y venciendo recursividad
		ordena(array,minimo,mitad);		
		ordena(array,mitad+1,maximo);
		//combinando
		divide(array,minimo,mitad,maximo);
	}
}

int main(){


	cout<<"ingresa el tamaño del arreglo: "<<endl; cin>>size; tam = size-1;
	for(int i = 0;i< size; i++){
		cout<<"ingresa elemento: "<<endl; cin>>arrayOriginal[i];
	}
	ordena(arrayOriginal,0,tam);
	for(int i = 0; i < size ; i++){
		cout<<"["<<arrayOriginal[i]<<"]"<<endl;
	}
}
