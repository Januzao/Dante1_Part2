#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void draw_cantor(int n) {
    if (n < 1 || n > 6) {
        printf("Incorrect input data\n");
        exit(2);
    }

    int length = (int)pow(3, n - 1);
    char *cantor_line = (char *)malloc((length + 1) * sizeof(char));

    if (cantor_line == NULL) {
        printf("Memory allocation error\n");
        exit(3);
    }

    cantor_line[length] = '\0';

    for (int i = 0; i < length; ++i) {
        cantor_line[i] = '_';
    }

    printf("%s\n", cantor_line);

    for (int i = 1; i < n; ++i) {
        int gap_size = (int)pow(3, n - i - 1);

        for (int j = 0; j < length; j += gap_size * 3) {
            for (int k = j + gap_size; k < j + 2 * gap_size; ++k) {
                cantor_line[k] = ' ';
            }
        }

        printf("%s\n", cantor_line);
    }

    free(cantor_line);
}

int main() {
    int n;

    printf("Podaj liczbe:\n");
    if (scanf("%d", &n) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    draw_cantor(n);

    return 0;
}
