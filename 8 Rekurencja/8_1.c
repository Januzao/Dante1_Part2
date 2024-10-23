#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long factorial_rec(int n);

int main() {
    int n;
    printf("Podaj n:");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (n < 0 || n > 20) {
        printf("Incorrect input data\n");
        return 2;
    }
    unsigned long result = factorial_rec(n);
    printf("Wynik: %lu\n", result);
    return 0;
}

unsigned long factorial_rec(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    return n * factorial_rec(n - 1);
}




