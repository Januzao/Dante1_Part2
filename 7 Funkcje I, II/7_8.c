#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int compare(int a, int b, int c) {
    return (a == b) && (b == c);
}

int main() {
    int num1, num2, num3;

    printf("Podaj trzy liczby: ");
    if (scanf("%d-%d-%d", &num1, &num2, &num3) != 3) {
        printf("Incorrect input\n");
        return 1;
    }

    if (compare(num1, num2, num3)) {
        printf("EQUAL\n");
    } else {
        printf("NOT EQUAL\n");
    }

    return 0;
}

