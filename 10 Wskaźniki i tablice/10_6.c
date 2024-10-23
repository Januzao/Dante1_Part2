#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    printf("Ile liczb chcesz wprowadzic? -> ");
    if (scanf("%d", &size) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (size <= 0 || size > 100) {
        printf("Incorrect input data\n");
        return 2;
    }

    float *hi = (float *)malloc(size * sizeof(float));

    if (hi == NULL) {
        printf("Nie udalo sie allokowac pamiec\n");
        return 1;
    }

    printf("Podaj liczby: ");
    float *current = hi;

    for (int i = 0; i < size; ++i) {
        if (scanf("%f", current) != 1) {
            printf("Incorrect input\n");
            free(hi);
            return 1;
        }
        current++;
    }

    current = hi + size - 1;

    for (int i = 0; i < size; ++i) {
        printf("%.6f ", *current);
        current--;
    }
    printf("\n");

    float sum = 0.0;
    current = hi;

    for (int i = 0; i < size; ++i) {
        sum += *current;
        current++;
    }

    float sred = sum / size;
    printf("Suma = %.2f\n", sum);
    printf("Srednia = %.2f\n", sred);

    free(hi);

    return 0;
}
