#include <omp.h>
#include <stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#define N 3

int vec[3][3]={{5,7,1},{9,4,3},{6,2,8}},bandera=0,aux;

void imprimir(int aux[]){
	int m;
	printf("\n");
	for(m=0;m<N;m++){
		printf("%d\t",aux[m]);	
	}printf("\n");
}

void imprimirMatriz(){
	int m,n;
	printf("\n");
	for(n=0;n<N;n++){
		for(m=0;m<N;m++){
			printf("%d\t",vec[n][m]);	
		}printf("\n");
	}printf("\n\n");
}


int par(int aux[],int n){
	int tid,i,aux2;
	printf("\n==================Fase par===============\n");
	//#pragma omp parallel for schedule(dynamic) private(tid)
	for(i=0;i<N-1;i=i+2){
	//tid = omp_get_thread_num();
		if(n==1){
			if(aux[i]>aux[i+1]){
				aux2=aux[i];
				aux[i]=aux[i+1];
				aux[i+1]=aux2;
				bandera=1;	
			}
		}else{
			if(aux[i]<aux[i+1]){
				aux2=aux[i];
				aux[i]=aux[i+1];
				aux[i+1]=aux2;
				bandera=1;	
			}
		}
		//printf("\nhilo:%d\n",tid);
		imprimir(aux);
	}
	if(bandera==1){
		bandera=0;
		return 1;
	}else{
		return 0;
	}

}

int impar(int aux[],int n){
	int tid,i,aux2;
	printf("\n===================Fase impar============\n");
	//#pragma omp parallel for schedule(static,2) private(tid)
	for(i=1;i<N;i=i+2){
		//tid = omp_get_thread_num();
		if(n==1){
			if(aux[i]>aux[i+1]){
				aux2=aux[i];
				aux[i]=aux[i+1];
				aux[i+1]=aux2;
				bandera=1;	
			}
		}else{
			if(aux[i]<aux[i+1]){
				aux2=aux[i];
				aux[i]=aux[i+1];
				aux[i+1]=aux2;
				bandera=1;	
			}
		}
		//printf("\nhilo:%d\n",tid);
		imprimir(aux);
	}
	if(bandera==1){
		bandera=0;
		return 1;
	}else{
		return 0;
	}	
}



void procesos(int aux[],int n){
	int fp,fi;
	do{
		fi=impar(aux,n);
		fp=par(aux,n);	
	}while((fi==1)&&(fp==1));
	
		
	
	
}

void descendente(){
	int j,tid;
	omp_set_num_threads(3);
	#pragma omp parallel for schedule(static,1) private(tid)
	for(j=0;j<3;j++){
		tid = omp_get_thread_num();
		printf("\nIteracion %d========= hilo:%d\n",j,tid);
		imprimir(vec[j]);
		procesos(vec[j],2);
		//imprimir(vec[j]);
	}
	
	
}

void ascendente(){
	int j,tid;
	omp_set_num_threads(3);
	#pragma omp parallel for schedule(static,1) private(tid)
	for(j=0;j<3;j++){
		tid = omp_get_thread_num();
		printf("\nIteracion %d========= hilo:%d\n",j,tid);
		imprimir(vec[j]);
		procesos(vec[j],1);
		//imprimir(vec[j]);
	}
}

int main(){
	int n;
	printf("Original...\n");
	imprimirMatriz();
	do{
	printf("Dame una opcion:\n\t1.-Ascendente\n\t2.-Descendente\n\t3.Salir\nOpcion:");
	scanf("%d",&n);
	
	switch(n){
		case 1:
			ascendente();
			break;
		case 2:
			descendente();
			break;
		default:
			printf("Hasta luego\n");
			exit(0);
	}
	printf("Finalizado...\n");
	imprimirMatriz();
	}while(n!=3);
}
