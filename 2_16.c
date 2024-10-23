#include <stdio.h>
#include <stdlib.h>

int main() {
    double number;

    printf("Podaj swoja liczbe: ");
    if (scanf("%lf", &number) != 1) {
        printf("incorrect input\n");
        return 1;
    }

    if (number > 0) {
        printf("Dodatnia\n");
    } else if (number < 0) {
        printf("Ujemna\n");
    } else {
        printf("Zerowa\n");
    }

    return 0;
}
