#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    float arr[20];

    float *hi = arr;

    for (int i = 0; i < 20; ++i) {
        *hi = ((float)rand() / RAND_MAX) * 20.0;
        hi++;
    }

    hi = arr;

    for (int i = 0; i < 20; ++i) {
        printf("%.1f ", *hi);
        hi++;
    }

    printf("\n");

    hi = arr;

    for (int i = 0; i < 20; i += 2) {
        printf("%.1f ", *hi);
        hi += 2;
    }

    return 0;
}
