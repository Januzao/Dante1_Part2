#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define SIZE 100
int read_vector(int* tab, int size, int stop_value){
    if (tab == NULL){
        return -1;
    } else if (size <=0){
        return -1;
    }

    int count = 0;
    float wartosc;
    for (int i = 0; i < SIZE; ++i) {
        if (scanf("%f", &wartosc) != 1) {
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

