#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    char input[11];
    int day, month, year;

    printf("Podaj date (w formacie dd-mm-yyyy): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Incorrect input\n");
        return 1;
    }

    if (sscanf(input, "%d-%d-%d", &day, &month, &year) != 3 || input[2] != '-' || input[5] != '-') {
        printf("Incorrect input\n");
        return 1;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1) {
        printf("Incorrect\n");
        return 0;
    }

    if ((month == 2 && ((isLeapYear(year) && day > 29) || (!isLeapYear(year) && day > 28))) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
        (day > 31)) {
        printf("Incorrect\n");
    } else {
        printf("Correct\n");
    }

    return 0;
}
