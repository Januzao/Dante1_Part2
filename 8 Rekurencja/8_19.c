#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long long decimal_to_octal(unsigned int number) {
    if (number == 0) {
        return 0;
    } else {
        return (number % 8) + 10 * decimal_to_octal(number / 8);
    }
}


int main() {
    int n;
    printf("Ktory liczbe:");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    unsigned long long result = decimal_to_octal(n);
    printf("%llu", result);
    return 0;
}



