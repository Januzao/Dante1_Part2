#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_balanced(unsigned long long a) {
    int evenDivisors = 0;
    int oddDivisors = 0;

    for (unsigned long long i = 1; i <= a; i++) {
        if (a % i == 0) {
            if (i % 2 == 0) {
                evenDivisors++;
            } else {
                oddDivisors++;
            }
        }
    }

    return evenDivisors == oddDivisors;
}

int main() {
    unsigned long long N;

    printf("Podaj liczbe:\n");
    if (scanf("%llu", &N) != 1) {
        fprintf(stderr, "Incorrect input\n");
        return 1;
    }

    if (N == 0) {
        fprintf(stderr, "Incorrect input\n");
        return 1;
    }

    unsigned long long result = N + 1;
    while (!is_balanced(result)) {
        result++;
    }

    printf("%llu\n", result);

    return 0;
}

