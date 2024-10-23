#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_valid_date(int day, int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        return 0;
    }
    return 1;
}

int has_letters(char *str) {
    while (*str) {
        if (isalpha(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

int sort_dates(int day[], int month[], int year[], int size) {
    if (size <= 0) {
        return 1;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (year[j] > year[j + 1] || (year[j] == year[j + 1] && (month[j] > month[j + 1] || (month[j] == month[j + 1] && day[j] > day[j + 1])))) {
                int temp = day[j];
                day[j] = day[j + 1];
                day[j + 1] = temp;

                temp = month[j];
                month[j] = month[j + 1];
                month[j + 1] = temp;

                temp = year[j];
                year[j] = year[j + 1];
                year[j + 1] = temp;
            }
        }
    }

    return 0;
}

int main() {
    const int max_dates = 150;
    int *day, *month, *year;

    day = (int *)malloc(max_dates * sizeof(int));
    month = (int *)malloc(max_dates * sizeof(int));
    year = (int *)malloc(max_dates * sizeof(int));

    if (day == NULL || month == NULL || year == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Podaj daty:\n");

    int input_day, input_month, input_year;
    char date_str[20];
    int count = 0;

    while (count < max_dates) {
        if (scanf("%19s", date_str) != 1 || has_letters(date_str)) {
            printf("Incorrect input\n");
            free(day);
            free(month);
            free(year);
            return 1;
        }

        sscanf(date_str, "%d-%d-%d", &input_day, &input_month, &input_year);

        if (input_day == 0 && count != 0) {
            break;
        } else if (input_day == 0 && count == 0) {
            printf("Not enough data available");
            free(day);
            free(month);
            free(year);
            return 3;
        }

        if (!is_valid_date(input_day, input_month, input_year)) {
            printf("Incorrect input\n");
            free(day);
            free(month);
            free(year);
            return 1;
        }

        day[count] = input_day;
        month[count] = input_month;
        year[count] = input_year;
        count++;
    }

    int result = sort_dates(day, month, year, count);

    if (result == 0) {
        for (int i = 0; i < count; i++) {
            printf("%02d-%02d-%04d\n", day[i], month[i], year[i]);
        }
    }

    free(day);
    free(month);
    free(year);

    return result;
}
