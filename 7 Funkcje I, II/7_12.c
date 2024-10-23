#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int is_twin(int a, int b) {
    return (is_prime(a) && is_prime(b) && abs(a - b) == 2);
}

int main() {
    int x1, x2;

    printf("Podaj x1=");
    if (scanf("%d", &x1) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Podaj x2=");
    if (scanf("%d", &x2) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (x1 == x2){
        printf("Nothing to show");
        return 0;
    }

    if (x1 >= x2) {
        printf("Incorrect input\n");
        return 1;
    }

    int found = 0;

    for (int i = x1; i <= x2 - 2; i++) {
        if (is_twin(i, i + 2)) {
            printf("%d, %d\n", i, i + 2);
            found = 1;
        }
    }

    if (!found) {
        printf("Nothing to show\n");
    }

    return 0;
}

