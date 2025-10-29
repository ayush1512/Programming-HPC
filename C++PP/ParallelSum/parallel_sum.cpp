#include <omp.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <stdio.h>
using namespace std;
int main() {
    // omp_set_num_threads(1000);
    const int N = 1000000;
    std::vector<int> data(N, 1);  // 1 million ones
    long long sum = 0;

    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        //printf("Iteration %d handled by Thread %d\n",i,omp_get_thread_num());
        sum += data[i];
    }

    double end = omp_get_wtime();
    
    double start1 = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        //printf("Iteration %i\n",i);
        sum += data[i];
    }

    double end1 = omp_get_wtime();

    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Threads used = " << omp_get_max_threads() << std::endl;
    std::cout << "Time taken(Threading)= " << (end - start) << " seconds" << std::endl;
    std::cout << "Time taken(Normal) = " << (end1 - start1) << " seconds" << std::endl;
    return 0;
}
