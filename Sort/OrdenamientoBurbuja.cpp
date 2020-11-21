#include <iostream>
using namespace std;
main(){
	int i,j,aux;
	char elementos[5];
	for(i=0;i<5;i++){
		cout<<"ingresa numeros: "<<endl; cin>>elementos[i];
	}
	for(i=0;i<5;i++){
		cout<<"Numeros: "<< elementos[i];
		cout<<endl;
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(elementos[j]>elementos[j+1]){
				aux = elementos[j];
				elementos[j]=elementos[j+1];
				elementos[j+1]=aux;
			}
		}
	}
	cout<<endl;
	for(i=0;i<6;i++){
		cout<<elementos[i];
	}
}
