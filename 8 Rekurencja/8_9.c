#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

long long binary_exponentiation(long long x, unsigned int n);

int main() {
    long long x;
    unsigned n;
    printf("Podaj podstawe:");
    if(scanf("%lld", &x) != 1){
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj wykladnik:");
    if(scanf("%u", &n) != 1){
        printf("Incorrect input");
        return 1;
    }
    long long result = binary_exponentiation(x, n);
    printf("Wynik: %lld", result);

    return 0;
}
long long binary_exponentiation(long long x, unsigned int n)
{
    if (n == 0){
        return 1;
    }
    if(n % 2 == 0){
        long long temp = binary_exponentiation(x, n/2);
        return temp * temp;
    } else {
        return x * binary_exponentiation(x, n-1);
    }
}

