#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

float add(float a, float b) {
    return a + b;
}

int main() {
    float num1, num2;
    printf("Podaj pierwsza liczbe:");
    if (scanf("%f", &num1) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Podaj druga liczbe:");
    if (scanf("%f", &num2) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    float sum = add(num1, num2);
    printf("Wynik: %.1f\n", sum);

    return 0;
}
