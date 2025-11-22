#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1024

// Function to add two matrices
void matrixAdd(float *A, float *B, float *C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i * n + j] = A[i * n + j] + B[i * n + j];
        }
    }
}

// Function to initialize matrix with random values
void initMatrix(float *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i * n + j] = (float)rand() / RAND_MAX;
        }
    }
}

int main() {
    int n = N;
    size_t size = n * n * sizeof(float);
    
    // Allocate memory for matrices
    float *A = (float *)malloc(size);
    float *B = (float *)malloc(size);
    float *C = (float *)malloc(size);
    
    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Initialize matrices
    srand(time(NULL));
    initMatrix(A, n);
    initMatrix(B, n);
    
    // Measure time using clock()
    clock_t start = clock();
    
    // Perform matrix addition
    matrixAdd(A, B, C, n);
    
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Matrix size: %d x %d\n", n, n);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    // Free memory
    free(A);
    free(B);
    free(C);
    
    return 0;
}