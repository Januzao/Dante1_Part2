#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"
#define MAX 150

int sort_negative_asc_positive_desc(int tab[], int size) {
    if (tab == NULL || size <= 0) {
        return 1;
    }

    int zmiana;
    int negative_count = 0;
    int positive_count = 0;
    int zero_count = 0;

    for (int i = 0; i < size; i++) {
        if (tab[i] < 0) {
            negative_count++;
        } else if (tab[i] > 0) {
            positive_count++;
        } else if (tab[i] == 0) {
            zero_count++;
        }
    }

    if (zero_count == size) {
        return 3;
    }

    do {
        zmiana = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (tab[i] >= 0 && tab[i + 1] < 0) {
                int temp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = temp;
                zmiana = 1;
            }
        }
    } while (zmiana);

    if (negative_count != 0) {
        for (int i = 0; i < negative_count; i++) {
            for (int j = 0; j < negative_count - 1; j++) {
                if (tab[j] > tab[j + 1]) {
                    int temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                }
            }
        }
    }

    if (positive_count != 0) {
        for (int i = negative_count; i < size - 1; i++) {
            for (int j = negative_count; j < size - 1; j++) {
                if (tab[j] < tab[j + 1]) {
                    int temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                }
            }
        }
    }

    return 0;
}

#define MAX 150

int main() {
    int vec[MAX];
    int stop = 0;

    printf("Podaj wektor:\n");
    int count = read_vector(vec, MAX, stop);

    if (count == -1) {
        printf("Incorrect input\n");
        return 1;
    } else if (count == 0) {
        printf("Not enough data available\n");
        return 3;
    }
    if (count < 0){
        printf("Incorrect input\n");
        return 1;
    }

    sort_negative_asc_positive_desc(vec, count);
    display_vector(vec, count);

    return 0;
}

