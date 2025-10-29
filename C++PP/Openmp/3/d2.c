#include <stdio.h>
#include <omp.h>

 int main(int argc, char *argv[])
 {

   #pragma omp parallel
   {
      int N; //variable defined INSIDE parallel region, hence NON-SHARED
      int i;

      for ( i = 0; i < 100; i++ )
         N = N + 1;
    //  cout << "N = " << N << endl;
   	printf(" N = %d\n", N);
   }

 }	
