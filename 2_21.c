#include <stdio.h>

int main() {
    int first_number, second_number;
    char operator;

    // Wprowadzenie pierwszej liczby
    printf("Podaj pierwsza liczbe:");
    if (scanf("%d", &first_number) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    // Wprowadzenie drugiej liczby
    printf("Podaj druga liczbe:");
    if (scanf("%d", &second_number) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    // Wprowadzenie operatora
    printf("Podaj symbol operacji:");
    scanf(" %c", &operator);

    // Obliczenia i wyświetlenie wyniku
    if (operator == '+') {
        printf("%d\n", first_number + second_number);
    } else if (operator == '-') {
        printf("%d\n", first_number - second_number);
    } else if (operator == '*') {
        printf("%d\n", first_number * second_number);
    } else if (operator == '/') {
        if (second_number == 0) {
            printf("Operation not permitted\n");
            return 2;
        } else {
            double result = (double)first_number / second_number;
            printf("wynik = %.2lf\n", result);
        }
    } else {
        printf("Incorrect input\n");
        return 1;
    }

    return 0;
}
