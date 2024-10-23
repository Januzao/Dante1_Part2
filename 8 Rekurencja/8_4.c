#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long sum_rec(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    } else {
        return n + sum_rec(n - 1);
    }
}

int main() {
    int n;
    printf("Podaj liczbe, dla ktorej chcesz policzyc sume:");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (n < 0) {
        printf("Incorrect input data");
        return 2;
    }
    if (n == 0) {
        printf("Incorrect input data");
        return 2;
    }
    unsigned long result = sum_rec(n);
    printf("wynik: %lu", result);
    return 0;
}

