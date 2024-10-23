#include <stdio.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

float toRadian(float a) {
    return a * M_PI / 180.0;
}

float toDegree(float a) {
    return a * 180.0 / M_PI;
}

int main() {
    int choice;
    float input, result;

    printf("Wybierz rodzaj konwersji (1=stopnie na radiany, 2=radiany na stopnie): ");
    if (scanf("%d", &choice) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if (choice != 1 && choice != 2) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Podaj miare kata: ");
    if (scanf("%f", &input) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if (choice == 1) {
        result = toRadian(input);
        printf("Wynik: %.2f\n", result);
    } else if (choice == 2) {
        result = toDegree(input);
        printf("Wynik: %.2f\n", result);
    }

    return 0;
}

