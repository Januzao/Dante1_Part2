#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int read_vector(int* tab, int size, int stop_value) {
    if (tab == NULL || size <= 0) {
        return -1;
    }

    int count = 0;
    int wartosc;

    while (count < size) {
        if (scanf("%d", &wartosc) != 1) {
            while (getchar() != '\n');
            return -2;
        }

        if (wartosc == stop_value) {
            break;
        }

        *tab = wartosc;
        tab++;
        count++;

        if (count >= size) {
            break;
        }
    }

    return count;
}

void display_vector(const int* tab, int size){
    if (size > 0 && tab != NULL) {
        for (int i = 0; i < size; ++i) {
            printf("%d ", *(tab + i));
        }
        printf("\n");
    }
}

