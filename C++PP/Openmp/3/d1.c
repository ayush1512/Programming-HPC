#include <stdio.h>
#include <omp.h>

 int main(int argc, char *argv[])
 {
   int N; // Variable defined OUTSIDE parallel region....
	       // It is therefore SHARED 
   N = 0;

   printf("Before parallel section: N = %d\n", N);

   #pragma omp parallel
   {
      int i;
      // #pragma omp critical
      for ( i = 0; i < 100; i++ )
         N = N + 1;
    //  cout << "N = " << N << endl;
   	printf(" N = %d\n", N);
	//when multiple-threads update a shared variable concurrently it can lead to unexpected results, such as the variable being incremented only once instead of twice. This is known as a race condition. 
	//
   }

 }	
