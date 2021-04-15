#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define NA 200
#define NB 200
#define NC 200

struct timeval t0, t1;
double tej;

double func1(int x){
	return(x+x);
}

double func2(int x){
	return(x-x);
}

double func3(int x){
	return(x/x);
}


void main () {
  int tid=-1, nth;
  double A, B, C, D;

 gettimeofday(&t0,0);
   #pragma omp parallel private(tid, nth)
   {
     tid = omp_get_thread_num();
     nth = omp_get_num_threads();
     if (tid == 0) printf("\n Ejecución en paralelo con % d hilos\n",nth);

     #pragma omp sections
     {
       #pragma omp section//solo uno de los hilos ara esta seccion
       {
         A = func1(NA);
         //B = func1(NA);
	 printf("func1 :%f - hilo:%d\n",A,omp_get_thread_num());
	 //printf("func2 :%f - hilo:%d\n",B,omp_get_thread_num());	
       }
       #pragma omp section
       {
         B = func2(NB);
	 printf("func2 :%f - hilo:%d\n",B,omp_get_thread_num());
	}
       #pragma omp section
       {
         C = func3(NC);
	 printf("func3 :%f- hilo:%d\n",C,omp_get_thread_num());
       }
     }
    } //pragma
  
    D = A+B+C;
    gettimeofday(&t1, 0);
    printf("\n Resultados A = %.2f   B= %.2f   C=%.2f ---> D = %.2f", A,B,C,D);
    tej = (t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec)/1e6;
    printf("\n Tiempo de ejecucion = %1.3f ms\n", tej*1000);
} //main


























    












    





       


















