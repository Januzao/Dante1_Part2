#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

#define SIZE 1000

void initialize_alert(char alert[][SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            alert[i][j] = '\0';
        }
    }
}

void extract_words(char tab[], char alert[][SIZE], int *num) {
    *num = 0;
    for (int i = 0; tab[i] != '\0'; ++i) {
        if (tab[i] != ' ') {
            for (int j = i, k = 0; tab[j] != '\0' && tab[j] != ' '; ++j) {
                alert[*num][k++] = *(tab+j);
                i = j;
            }
            (*num)++;
        }
    }
}

void sort_alert(char alert[][SIZE], int num) {
    for (int i = 0; i < num; ++i) {
        for (int j = 1; j < num; ++j) {
            char* current = alert[j];
            char* previous = alert[j - 1];

            if (strlen(current) < strlen(previous) ||
                (strlen(current) == strlen(previous) && strcmp(current, previous) < 0)) {
                char temp[SIZE];
                strcpy(temp, current);
                strcpy(current, previous);
                strcpy(previous, temp);
            }
        }
    }
}

int sort_by_length(char tab[]) {
    for (int i = 0; *(tab+i) != '\0'; ++i) {
        if (!isalpha(*(tab+i)) && *(tab+i) != ' ') {
            return 1;
        }
    }

    char alert[SIZE][SIZE];
    initialize_alert(alert, SIZE);

    int num;
    extract_words(tab, alert, &num);

    sort_alert(alert, num);

    int i = 0, k = 0;
    while (i < num) {
        for (int j = 0; j < (int) strlen(alert[i]); ++j, ++k) {
            tab[k] = alert[i][j];
        }
        if (++i < num) {
            tab[k++] = ' ';
        }
    }
    *(tab+k) = '\0';

    return 0;
}

int main(void) {
    char tekst[SIZE];
    printf("Podaj tekst:\n");
    scanf("%1000[^\n]", tekst);
    int result = sort_by_length(tekst);
    if (result == 1) {
        printf("Incorrect input data");
        return 2;
    }
    printf("%s", tekst);
    return 0;
}

