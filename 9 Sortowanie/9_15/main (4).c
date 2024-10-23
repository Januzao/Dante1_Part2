#include <stdio.h>
#include "vector_utils.h"
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sort_odd_desc(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }

    for (int i = 1; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (tab[i] < tab[j]) {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    return 0;
}

int sort_even_asc(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }

    for (int i = 0; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (tab[i] > tab[j]) {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

    return 0;
}

int main() {
    int SIZE = 150;
    int *tab = malloc(SIZE * sizeof(int));

    if (tab == NULL) {
        printf("Memory allocation failed\n");
        return 2;
    }

    printf("Podaj wektor:\n");

    int count = read_vector(tab, SIZE, 0);

    if (count == -1) {
        printf("Incorrect input\n");
        free(tab);
        return 1;
    } else if (count == 0) {
        printf("Not enough data available\n");
        free(tab);
        return 3;
    }

    if (count == 1 && tab[0] == 0) {
        printf("Not enough data available\n");
        free(tab);
        return 3;
    }

    if (sort_odd_desc(tab, count) != 0 || sort_even_asc(tab, count) != 0) {
        printf("Incorrect input\n");
        free(tab);
        return 1;
    }

    display_vector(tab, count);

    free(tab);

    return 0;
}

