#include <omp.h>
#include<stdio.h>
#include<stdlib.h>
 #define N 5

 void main(int argc, char *argv[]) {

 int i,tid;
 float a[N], b[N], c[N], d[N];

 /* inicializar */
 for (i=0; i < N; i++) {
   a[i] = i * 1;
   b[i] = i + 2;
   }

 #pragma omp parallel shared(a,b,c,d) private(i)
   {

   #pragma omp sections nowait
     {

     #pragma omp section
     for (i=0; i < N; i++){
		tid = omp_get_thread_num();
       		c[i] = a[i] + b[i];
		printf("hilo:%d c[%d]:%d\n",tid,i,c[i]);
	}
     #pragma omp section
     for (i=0; i < N; i++){
		tid = omp_get_thread_num();
       		d[i] = a[i] * b[i];
		printf("hilo:%d d[%d]:%d\n",tid,i,d[i]);
	}

     }  /* fin de sections */

   }  /* fin de la region paralela */

 }

