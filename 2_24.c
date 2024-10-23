#include <stdio.h>

int main() {
    int num1, num2;

    printf("Podaj liczby:");
    switch (scanf("%d %d", &num1, &num2)) {
        case 2:
            break;
        default:
            printf("Incorrect input\n");
            return 1;
    }


    int diff = num1 - num2;
    int sign = (diff >> (sizeof(int) * 8 - 1)) & 1;

    int max = num1 - diff * sign;
    int min = num1 - diff * (1 - sign);

    printf("Najwieksza liczba: %d\n", max);
    printf("Najmniejsza liczba: %d\n", min);

    return 0;
}
