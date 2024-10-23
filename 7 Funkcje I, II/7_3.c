#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

float circumference(float b) {
    if (b <= 0) {
        return -1;
    }
    return 3.14159 * b;
}

int main() {
    float diameter, result;

    printf("Podaj srednice kola:");
    if (scanf("%f", &diameter) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    result = circumference(diameter);
    if (result == -1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Obwod kola to %.4f\n", result);
    return 0;
}
