

#include <stdio.h>
#include <omp.h>
/*
#ifdef _OPENMP
	#include <omp.h>
	#define TRUE 1
	#define TRUE 0
#else						en caso de no haberlo incluido la libreria omp
	#define omp_get_thread_num() 0
	#define omp_get_num_threads() 1
#endif
*/
int x,y,z,i,tid;
#pragma omp threadprivate(x,y)
//se conservaran los valores calculados de la ultima region paralella aplicada

void imprimir(int tid)
{
	printf("Thread %d: x=%d y=%d z=%d\n",tid, x, y,z);
}

void main()
{
	x=y=z=5;
	printf("\n\n Valores antes de la region paralela: x,y,z= %d  %d %d\n",x,y,z);
	printf("\n Region paralela 1: x/y threadprivate;x copyn; z/tid private\n\n");
	//inicia x con el valor que le asigne el hilo maestro,la var x en la reg x toma el valor que le asigne el hilo 0, es exclusivo para el hilo 0
	omp_set_num_threads(1);
	#pragma omp parallel private(z,tid) copyin(x)
	{
		tid=omp_get_thread_num();
		printf("A:Thread %d: x=%d y=%d z=%d\n",tid,x,y,z);
		x=x+tid+1;
		y=tid;
		z=tid+20;
	//hasta que se ejecuten los hilos esas intrucciones 
	#pragma omp barrier
		printf("B: Thread %d: x=%d y=%d z=%d\n",tid,x,y,z);
	}
	printf("C: Thread %d: x=%d y=%d z=%d\n",tid,x,y,z);

	printf("\n >>>>>>>>>> Ejecucion de un trozo en serie \n");
	printf("Region paralela 2: x/y threadprivate; z/tid private \n\n");
		

	#pragma omp parallel private (z, tid)
	{
		tid= omp_get_thread_num();

		printf(" Thread  %d: x= %d  y=%d z=%d\n",tid, x, y, z);
	}
	printf("D: Thread %d: x=%d y=%d z=%d\n",tid,x,y,z);


	printf(" \n >>>>>>>>>> Enjecucion de un trozo en serie \n");
	printf(" \n Region paralela 3: Se imprime desde una rutin: tid como parametro \n \n");
/* 
	#pragma omp parallel private(z,tid)
	{
		tid=omp_get_thread_num();
		imprimir(tid);
	}
	printf("\n Main: se imprime desde una rutina: -1 como parametro \n\n");
	imprimir(-1);
	printf("\n Fin del main: x=%d y=%d z=%d\n\n",x,y,z);
*/
	
	x=x+3;
	printf("x=%d",x);
}




