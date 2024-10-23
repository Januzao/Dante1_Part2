#include "sort.h"
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int bubble_sort_asc(int vector[], int size){
    if (size <= 0 || !vector) return 1;
    int changed;
    do {
        changed = 0;
        for (int j = 0; j < size - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
                changed = 1;
            }
        }
        display_vector(vector, size);
    } while (changed);

    return 0;
}


int bubble_sort(int tab[], int size, enum direction dir) {
    if (size <= 0 || !tab) return 1;

    if (dir == ASCENDING) {
        bubble_sort_asc(tab, size);
    } else if (dir == DESCENDING) {
        bubble_sort_desc(tab, size);
    } else {
        return 1;
    }

    return 0;
}

int bubble_sort_desc(int tab[], int size){
    if (size <= 0 || !tab) return 1;
    int changed;
    do {
        changed = 0;
        for (int j = 0; j < size - 1; ++j) {
            if (tab[j] < tab[j + 1]) {
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


