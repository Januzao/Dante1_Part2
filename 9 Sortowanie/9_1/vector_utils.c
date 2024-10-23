#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int read_vector(int tab[], int size, int stop_value) {
    int value, count = 0;
    if (size <= 0) {
        return -1;
    }
    for (int i = 0; i < 150; ++i) {
        if (scanf("%d,", &value) != 1) {
            return -1;
        }
        if (value == stop_value) {
            break;
        }

        tab[count++] = value;

        if (count >= size) {
            break;
        }
    }

    return count;
}

void display_vector(const int vec[], int size) {
    if (size > 0) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", vec[j]);
        }
        printf("\n");
    }
}

