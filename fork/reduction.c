#include <math.h>
#include <omp.h>
#include <stdio.h>
#define N 10

float x[N], y[N];
int i,a,b;

void reduction1
#pragma omp parallel for reduction(+:a) reduction(*:b) private (i) 
	for(i=0;i<N;i++){				
		a+=x[i];  
		b*=y[i];	
}

main(){
	int j;
	a=0.0;
	b=1;
	for(j=0;j<N;j++){
		x[j]=j;
		y[j]=10;
	}
	omp_set_num_threads(2);
	reduction1();
	printf("a = %d b=%d\n", a,b);
}
