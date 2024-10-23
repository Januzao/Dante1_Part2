#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define SIZE 100

int find_min(const int *tab, int size, int *min) {
    if (tab == NULL || min == NULL ) {
        return 1;
    }

    if (size <= 0) {
        return 1;
    }

    *min = *(tab);

    for (int i = 1; i < size; ++i) {
        if (*min > *(tab+i)) {
            *min = *(tab+i);
        }
    }

    return 0;
}

int main() {
    int tab[SIZE];
    int size;
    int stop_value = -1;
    printf("Podaj liczby:");

    size = read_vector(tab, SIZE, stop_value);

    if (size == 0) {
        printf("Not enough data available");
        return 3;
    }

    if (size == -2) {
        printf("Incorrect input");
        return 1;
    }

    int minimum;
    int result = find_min(tab, size, &minimum);

    if (result == 0) {
        printf("Min: %d\n", minimum);
    } else {
        printf("Error finding minimum\n");
    }

    return 0;
}
