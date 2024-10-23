#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int add(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    printf("Podaj pierwsza liczbe:");
    if (scanf("%d", &num1) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    printf("Podaj druga liczbe:");
    if (scanf("%d", &num2) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    int sum = add(num1, num2);
    printf("Wynik: %d\n", sum);

    return 0;
}
