// file: unoptimized.c
#include <stdio.h>
#include <stdlib.h>

#define WORK_SIZE 10000
#define REPEAT 100000

double do_heavy_work() {
    double result = 0.0;
    double *arr = malloc(WORK_SIZE * sizeof(double));

    for (int i = 0; i < WORK_SIZE; ++i)
        arr[i] = i * 0.00001;

    for (int r = 0; r < REPEAT; ++r)
        for (int i = 0; i < WORK_SIZE; ++i)
            result += arr[i] * arr[i] + arr[i];

    free(arr);
    return result;
}

int main() {
    double res = do_heavy_work();
    printf("Result: %f\n", res);
    return 0;
}

