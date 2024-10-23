#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

long power_rec(int a, int n);

int main() {
    int a, n;

    printf("Podaj a:");
    if (scanf("%d", &a) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Podaj n:");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (n < 0){
        printf("Incorrect input data");
        return 2;
    }

    long result = power_rec(a, n);
    printf("Wynik: %ld", result);

    return 0;
}

long power_rec(int a, int n) {
    if (n < 0) {
        printf("Incorrect input data\n");
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    return a * power_rec(a, n - 1);
}
