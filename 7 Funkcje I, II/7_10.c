#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

float quadratic_equation(float a, float b, float c, float x)
{
    float result = a * x * x + b * x + c;
    return result;
}

int main() {
    float a, b, c, x;
    printf("Podaj rownanie:\n");
    if (scanf("%fx^2%fx%f", &a, &b, &c) != 3) {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Podaj x:");
    if (scanf("%f", &x) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    float result = quadratic_equation(a, b, c, x);
    printf("Wynik: %f\n", result);

    return 0;
}
