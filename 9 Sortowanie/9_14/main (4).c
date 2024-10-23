#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort_negative_asc_positive_desc(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (tab[i] < 0 && tab[j] < 0 && tab[i] > tab[j]) {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            else if (tab[i] >= 0 && tab[j] >= 0 && tab[i] < tab[j]) {
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

    printf("Enter vector:\n");

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

    if (sort_negative_asc_positive_desc(tab, count) != 0) {
        printf("Incorrect input\n");
        free(tab);
        return 1;
    }

    display_vector(tab, count);

    free(tab);

    return 0;
}

