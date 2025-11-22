#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 4  // Size of the matrices (NxN)

int main() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices A and B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i * j;
            C[i][j] = 0; // Initialize result matrix
        }
    }

    // Matrix multiplication using OpenMP parallel region
    #pragma omp parallel for shared(A, B, C) default(none)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    // Print result matrix
    printf("Result matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

