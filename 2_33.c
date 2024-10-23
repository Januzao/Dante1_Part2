#include <stdio.h>

int main() {
    double kwota;
    char symbol;

    printf("Podaj liczbe:");
    switch (scanf("%lf", &kwota) != 1 || kwota <= 0) {
        case 1:
            printf("Incorrect input\n");
            return 1;
    }

    printf("Podaj symbol operacji ('e' - euro, 'f' - funty, 'd' - dolary):");
    switch (scanf(" %c", &symbol) != 1 || (symbol != 'e' && symbol != 'f' && symbol != 'd')) {
        case 1:
            printf("Incorrect input\n");
            return 1;
    }

    int incorrectInput = 0;  // Змінна для визначення коректності введення
    double przelicznik = 0.0; // Змінна для зберігання курсу обміну

    switch (symbol) {
        case 'e':
            przelicznik = 4.2074;
            break;
        case 'f':
            przelicznik = 4.7073;
            break;
        case 'd':
            przelicznik = 3.5382;
            break;
        default:
            incorrectInput = 1;  // Означимо некоректне введення
    }

    switch (incorrectInput) {
        case 1:
            printf("Incorrect input\n");
            return 1;
    }

    double wynik = kwota / przelicznik;
    printf("%.2lf\n", wynik);

    return 0;
}
