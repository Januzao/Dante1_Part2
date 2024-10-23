#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"
int swap(int*a, int*b)
{
    if (a == NULL || b == NULL){
        return 1;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
int main() {
    int baklazhan, kabachok;
    printf("Wpisz 2 liczby int oddzielajac spacja:");
    if(scanf("%d %d", &baklazhan, &kabachok) != 2){
        printf("Incorrect input");
        return 1;
    }
    swap(&baklazhan, &kabachok);
    printf("a = %d, b = %d", baklazhan, kabachok);
    return 0;
}
