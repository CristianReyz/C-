/* Private */
/* fisrtprivate */
/*  lastprivate*/


#include <stdio.h>
#include <omp.h>

int main(void)
{
  int i, x;

  x = 44;
  
   omp_set_num_threads(4);
  #pragma omp parallel for lastprivate(x) 
    for ( i =0; i<=10; i++) {
         x = i;
         printf (" thread %d: x = %d\n ",omp_get_thread_num(),x);
      }
  
        printf (" x = %d \n",x);
    return 0;
}
