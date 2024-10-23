#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_divisible_by_7(int number);

int main() {
    int number;
    printf("Podaj liczbe:");
    if (scanf("%d", &number) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (is_divisible_by_7(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

int is_divisible_by_7(int number) {
    if (number < 0) {
        number = -number;
    }
    if (number == 0 || number == 7) {
        return 1;
    }
    if (number < 10) {
        return 0;
    }
    return is_divisible_by_7(number / 10 - 2 * (number - number / 10 * 10));
}
