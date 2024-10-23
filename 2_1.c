#include <stdio.h>

int main() {
    int num1, num2;

    printf("Podaj dwie liczby calkowite oddzielone spacja:");
    if (scanf("%d %d", &num1, &num2) == 2) {
        int suma = num1 + num2;
        printf("Suma podanych liczb: %d\n", suma);
        return 0;
    } else {
        printf("Incorrect input\n");
        return 1;
    }
}
