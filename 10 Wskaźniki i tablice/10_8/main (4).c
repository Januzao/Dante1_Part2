#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    int size = 100;
    int stop_value = -1;
    int tab[100];

    printf("Wpisuj wartosci calkowite:\n");

    int count = read_vector(tab, size, stop_value);

    if (count < 0) {
        printf("Incorrect input");
        return 1;
    }

    if (count == 0) {
        printf("Not enough data available\n");
        return 3;
    }


    int result = sort(tab, count);

    if (result != 0) {
        printf("Sorting failed\n");
        return 1;
    }

    display_vector(tab, count);
    return 0;
}
