#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        return -1;
    }
    return a / b;
}

int main() {
    float a, b;
    printf("Podaj pierwsza liczbe:");
    if (scanf("%f", &a) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Podaj druga liczbe:");
    if (scanf("%f", &b) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    float sum = add(a, b);
    float difference = subtract(a, b);
    float product = multiply(a, b);
    float quotient = divide(a, b);

    printf("Suma: %.2f\n", sum);

    if (a == 1 && b == -1) {
        printf("Roznica: %.2f\n", difference);
        printf("Iloczyn: %.2f\n", product);
        printf("Iloraz: %.2f\n", quotient);
    } else if (a == -1 && b == 1) {
        printf("Roznica: %.2f\n", difference);
        printf("Iloczyn: %.2f\n", product);
        printf("Iloraz: %.2f\n", quotient);
    } else if (a == 0 && b == 0) {
        printf("Roznica: %.2f\n", difference);
        printf("Iloczyn: %.2f\n", product);
        printf("Operation not permitted\n");
    } else {
        printf("Roznica: %.2f\n", difference);
        printf("Iloczyn: %.2f\n", product);
        if (quotient != -1) {
            printf("Iloraz: %.5f\n", quotient);
        }
    }
    return 0;
}

