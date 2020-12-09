// hola mundo open mp

#include <iostream>
#include<omp.h>
using namespace std;

int main(){
	#pragma omp parallel
	{
	int id = open_get_thread_num();
	cout<<"hola ("<<id<<")"<<endl;
	cout<<"mundo("<<id<<")"<<endl;
	}

}