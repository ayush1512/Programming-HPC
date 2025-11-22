#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000  // 10 million elements

void vector_add(float *a, float *b, float *c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    float *a, *b, *c;
    struct timespec start, end;
    double time_taken;
    
    // Allocate memory
    a = (float*)malloc(N * sizeof(float));
    b = (float*)malloc(N * sizeof(float));
    c = (float*)malloc(N * sizeof(float));
    
    if (a == NULL || b == NULL || c == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Initialize vectors
    for (int i = 0; i < N; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
    }
    
    // Measure time
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    vector_add(a, b, c, N);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // Calculate time in milliseconds
    time_taken = (end.tv_sec - start.tv_sec) * 1000.0;
    time_taken += (end.tv_nsec - start.tv_nsec) / 1000000.0;
    
    printf("Vector addition completed\n");
    printf("Size: %d elements\n", N);
    printf("Time taken: %.3f ms\n", time_taken);
    printf("Sample result: c[0] = %.2f\n", c[0]);
    
    // Free memory
    free(a);
    free(b);
    free(c);
    
    return 0;
}