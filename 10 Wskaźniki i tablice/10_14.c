#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"
int add(const int *first, const int *second, int* result){
    if (first == NULL || second == NULL || result == NULL){
        return 1;
    }
    *result = *first + *second;
    return 0;
}

int subtract(const int *first, const int *second, int* result){
    if (first == NULL || second == NULL || result == NULL){
        return 1;
    }
    *result = *first - *second;
    return 0;

}
int multiply(const int *first, const int *second, int* result){
    if (first == NULL || second == NULL || result == NULL){
        return 1;
    }
    *result = *first * *second;
    return 0;

}
int divide(const int *first, const int *second, float* result){
    if (first == NULL || second == NULL || result == NULL){
        return 1;
    }
    if (*second == 0){
        return 1;
    }
    *result = (float)*first / (float)*second;
    return 0;

}
int main() {
    int banan, truskawka;
    float jablko;
    int persik;
    char bigmac;
    printf("Podaj dzialanie:");
    if(scanf("%d%c%d", &banan, &bigmac, &truskawka) != 3){
        printf("Incorrect input");
        return 1;
    }

    if (bigmac == '+'){
        if(add(&banan, &truskawka, &persik) == 1){
            printf("Incorrect input");
            return 1;
        } else {
            printf("%d", persik);
            return 0;
        }

    }
    else if (bigmac == '-'){
        if(subtract(&banan, &truskawka, &persik) == 1){
            printf("Incorrect input");
            return 1;
        } else {
            printf("%d", persik);
            return 0;
        }
    }
    else if (bigmac == '*'){
        if(multiply(&banan, &truskawka, &persik) == 1){
            printf("Incorrect input");
            return 1;
        } else {
            printf("%d", persik);
            return 0;
        }
    }
    else if(bigmac == '/'){
        if (truskawka == 0){
            printf("operation not permitted");
            return 4;
        }
        if(divide(&banan, &truskawka, &jablko) == 1){
            printf("Incorrect input");
            return 1;
        } else {
            printf("%lf", jablko);
            return 0;
        }
    }
    else {
        printf("Incorrect input");
        return 1;
    }
}
