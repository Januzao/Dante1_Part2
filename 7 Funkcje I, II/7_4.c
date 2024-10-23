#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sign(int value) {
    return (value > 0) - (value < 0);
}

int main() {
    int number, result;

    printf("Podaj liczbe:");
    switch (scanf("%d", &number) != 1) {
        case 1:
            printf("Incorrect input\n");
            return 1;
    }

    result = sign(number);

    switch (result) {
        case -1:
            printf("negative\n");
            break;
        case 0:
            printf("zero\n");
            break;
        case 1:
            printf("positive\n");
            break;
    }

    return 0;
}

