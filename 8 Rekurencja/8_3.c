#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

long int fibonacci_helper(int n, long int a, long int b);

long int fibonacci(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci_helper(n, 0, 1);
}

long int fibonacci_helper(int n, long int a, long int b) {
    if (n == 0) {
        return a;
    }
    return fibonacci_helper(n - 1, b, a + b);
}

int main() {
    int n;

    printf("Ktory wyraz ciagu fibonacciego chcesz wyznaczyc:");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (n < 0) {
        printf("Incorrect input data");
        return 2;
    }

    long int result = fibonacci(n);
    printf("Wynik: %ld", result);

    return 0;
}

