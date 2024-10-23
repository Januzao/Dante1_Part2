#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define HI 100

int read_vector(int* tab, int size, int stop_value) {
    if(size < 1){
        return -1;
    }
    if (tab == NULL){
        return -1;
    }
    if(size>HI){
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        int check = scanf("%i", &*(tab+i));
        if (*(tab+i) == stop_value) {
            break;
        }
        if (check != 1) {
            return -2;
        }
        count++;
    }

    return count;
}

    void display_vector(const int* tab, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", *(tab+i));
    }
}

int sort(int* tab, int size) {
    if(tab == NULL){
        return 1;
    }
    if (size <= 0){
        return 1;
    } else {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (*(tab + j) > (*(tab + j + 1))) {
                    int temp = *(tab + j);
                    *(tab + j) = *(tab + j + 1);
                    *(tab + j + 1) = temp;
                }
            }
        }
    }
    return 0;
}


