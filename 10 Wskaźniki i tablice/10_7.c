#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"
#define SIZE 100

int sum(const float* tab, unsigned int size, float *result) {
    if (tab == NULL || result == NULL) {
        return 1;
    }
    if(size == 0){
        return 1;
    }
    *result = 0;

    for (unsigned int i = 0; i < size; ++i) {
        *result += *(tab + i);
    }

    return 0;
}


int avg(const float* tab, unsigned int size, float *result) {
    if (tab == NULL || result == NULL || size == 0) {
        return 1;
    }

    float sum_result;
    if (sum(tab, size, &sum_result) != 0) {
        return 1;
    }

    *result = sum_result / size;

    return 0;
}

int read_vector_float(float *vec, int size, float stop_value) {
    if (vec == NULL || size <= 0) {
        return -1;
    }

    int count = 0;
    float value;

    printf("Podaj liczby:\n");

    while (count < size) {
        if (scanf("%f", &value) != 1) {
            printf("Incorrect input\n");
            return -2;
        }

        if (value == stop_value) {
            break;
        }

        *(vec + count++) = value;
    }

    if (count == 0) {
        printf("Not enough data available\n");
        return 0;
    }


    return count;
}

int main() {
    float tab[SIZE];
    int size;

    size = read_vector_float(tab, SIZE, 0.0);

    if (size < 0) {
        return 1;
    }
    if (size == 0){
        return 3;
    }

    float sum_result, avg_result;

    if (sum(tab, size, &sum_result) != 0 || avg(tab, size, &avg_result) != 0) {
        return 1;
    }

    printf("Suma:%.2f\n", sum_result);
    printf("Srednia:%.2f\n", avg_result);

    return 0;
}

