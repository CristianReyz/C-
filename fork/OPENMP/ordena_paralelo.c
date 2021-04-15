#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#define N 10

int vec[]={5,7,1,4,9,0,3,6,2,8},bandera=0,aux;

void imprimir(){
	int j;
	printf("\n");
	for(j=0;j<N;j++){
		printf("%d\t",vec[j]);
	}printf("\n");
}


int par(){
	int tid,i;
	printf("\n==================Fase par===============\n");
	#pragma omp parallel for schedule(dynamic) private(tid)
	for(i=1;i<N-1;i=i+2){
	tid = omp_get_thread_num();
		if(vec[i]>vec[i+1]){
			aux=vec[i];
			vec[i]=vec[i+1];
			vec[i+1]=aux;
			bandera=1;	
		}
		printf("\nhilo:%d\n",tid);
		imprimir();
	}
	if(bandera==1){
		bandera=0;
		return 1;
	}else{
		return 0;
	}

}

int impar(){
	int tid,i;
	printf("\n===================Fase impar============\n");
	#pragma omp parallel for schedule(static,2) private(tid)
	for(i=0;i<N;i=i+2){
		tid = omp_get_thread_num();
		if(vec[i]>vec[i+1]){
			aux=vec[i];
			vec[i]=vec[i+1];
			vec[i+1]=aux;
			bandera=1;	
		}
		printf("\nhilo:%d\n",tid);
		imprimir();
	}
	if(bandera==1){
		bandera=0;
		return 1;
	}else{
		return 0;
	}	
}




void main(){
	int fp,fi,j;
	printf("lista original:\n");
	imprimir();
	do{
		fi=impar();
		fp=par();	
	}while((fi==1)&&(fp==1));
}
