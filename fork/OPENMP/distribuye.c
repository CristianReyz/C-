#include <omp.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

struct timeval t0, t1;
double tej;
#define N 4000

double calculo(int veces)
{
   usleep(veces);
   return (1);
}

int i, A[N], nth=-1;
double total;

void main() {
  for(i=0; i<N; i++) A[i]=1;

  A[1]= 100000;
  A[5]=100000;
  
  gettimeofday(&t0,0);
  total = 0.0;

  #pragma omp parallel for schedule(static,4) reduction(+:total)
    for (i=0; i<N; i++){
      total += calculo(A[i]);
	printf("hilo=%d\t total=%f\n",omp_get_thread_num(),total);
	}
    gettimeofday(&t1,0);
    tej = (t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec)/ 1e6;
    nth = omp_get_max_threads();
    printf("tej con %d hilos = %1.3f segs Total = %.2f\n\n", nth,tej, total);
}


























