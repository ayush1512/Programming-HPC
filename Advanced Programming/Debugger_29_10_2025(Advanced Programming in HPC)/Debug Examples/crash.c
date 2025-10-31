#include <stdio.h>
#include <stdlib.h>

int* sophisticated(int *ptr) {
    // Just returns the same pointer
    return ptr;
}

int* complicated(int *ptr) {
    // Simulate a buggy transformation — returns NULL
    return NULL;
}

void crash(int *i) {
    *i = 1;  // Will cause segmentation fault if i == NULL
}

void f(int *i) {
    int *j = i;
    j = sophisticated(j);
    j = complicated(j);
    crash(j);  // This will crash due to j == NULL
}

int main() {
    int i;
    f(&i);
    return 0;
}

