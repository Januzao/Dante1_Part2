#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_prime(int a) {
    if (a <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }

    return 1;
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
    if(x1 > x2){
        printf("Incorrect input");
        return 1;
    }

    int found = 0;
    for (int i = x1; i <= x2; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Nothing to show\n");
    }

    return 0;
}
