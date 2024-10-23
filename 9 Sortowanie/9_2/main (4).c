#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define SIZE 50
int main() {
    int tab[SIZE];
    int sortowanie;
    enum direction dir;

    printf("Podaj wektor:");

    int size = read_vector(tab, SIZE, 0);

    if (size == -1) {
        printf("Incorrect input\n");
        return 1;
    } else if (size < 1) {
        printf("Not enough data available\n");
        return 3;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Podaj kierunek sortowania:");
    if (scanf("%d", &sortowanie) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if (sortowanie != 1 && sortowanie != 2) {
        printf("Incorrect input data\n");
        return 2;
    }

    dir = (sortowanie == 1) ? ASCENDING : DESCENDING;

    bubble_sort(tab, size, dir);

    return 0;
}

