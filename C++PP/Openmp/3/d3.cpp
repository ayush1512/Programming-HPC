#include <iostream>
#include <omp.h>
using namespace std;

int main(int argc, char *argv[])
{
   int nthreads, myid;

   /* make the values of nthreads and myid private to each thread */

#pragma omp parallel private(nthreads, myid)
   {
      /* ------------------------------
       * 	 Every thread does this
       * 	 	 ------------------------------ */
      myid = omp_get_thread_num();

      cout << "Hello I am thread " << myid << endl;

#pragma omp barrier

/* ------------------------------
 * 	 Only thread 0 does this
 * 	 	 ------------------------------ */
// #pragma omp master
      if (myid == 0)
      {
         nthreads = omp_get_num_threads();
         // cout << "Number of threads = " << nthreads << endl;
         printf("Number of threads = %d\n", nthreads);
      }
   }
   return 0;
}
