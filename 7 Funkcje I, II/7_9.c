#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

float poly(float x) {
    float y = 5 * x * x + 12.55 * x + 0.75;
    return y;
}

int main() {
    float x;
    printf("Podaj x:");
    if (scanf("%f", &x) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    float y = poly(x);
    printf("Wynik: %.2f\n", y);

    return 0;
}
