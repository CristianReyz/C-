#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define NA 2000000
#define NB 2000000
#define NC 2000000

struct timeval t0, t1;
double tej;

double func (int N)
{
  usleep(N);
  return(1);
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
       #pragma omp section//solo uno de los hilos hara esta seccion
       {
         A = func(NA);
       }
       #pragma omp section
       {
         B = func(NB);
	}
       #pragma omp section
       {
         C = func(NC);
       }
     }
    } //pragma
  
    D = A+B+C;
    gettimeofday(&t1, 0);
    printf("\n Resultados A = %.2f   B= %.2f   C=%.2f ---> D = %.2f", A,B,C,D);
    tej = (t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec)/1e6;
    printf("\n Tiempo de ejecucion = %1.3f ms\n", tej*1000);
} //main


























    












    





       


















