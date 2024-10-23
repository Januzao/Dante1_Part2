#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define SIZE 150

int bubble_sort(int tab[], int size) {
    if (size <= 0 || !tab) return 1;
    int changed;

    do {
        changed = 0;
        for (int j = 0; j < size - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
                changed = 1;
            }
        }
        display_vector(tab, size);
    } while (changed);

    return 0;
}

int main() {
    int vec[SIZE];
    printf("Podaj wektor:\n");
    int rozmiar = read_vector(vec, SIZE, 0);

    switch (rozmiar) {
        case -1:
            printf("Incorrect input\n");
            return 1;
        case 0:
            printf("Not enough data available\n");
            return 3;
        default:
            if (rozmiar < 1) {
                printf("Not enough data available\n");
                return 3;
            }
    }

    bubble_sort(vec, rozmiar);

    return 0;
}
