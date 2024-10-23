#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define SIZE 100
#define STOP 0

int reverse_vector(int *tab, int size) {
    if (tab == NULL) {
        return 1;
    }
    if (size <= 0) {
        return 1;
    }

    int arr = size / 2;

    for (int i = 0; i < arr; ++i) {
        int kol = *(tab + i);
        *(tab + i) = *(tab + size - 1 - i);
        *(tab + size - 1 - i) = kol;
    }

    return 0;

}

int main() {
    int tab[SIZE];
    int size;

    printf("Podaj liczby:");
    size = read_vector(tab, SIZE, STOP);

    if (size == -2) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size == 0) {
        printf("Not enough data available\n");
        return 3;
    }
    display_vector(tab, size);

    int wynik = reverse_vector(tab, size);

    if (wynik == 0) {
        display_vector(tab, size);
        return 0;
    } else {
        printf("Incorrect input");
        return 1;
    }
}
