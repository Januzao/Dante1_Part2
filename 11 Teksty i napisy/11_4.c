#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"
#define SIZE 1001

int is_alpha_alternative(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}


char *get_word(char *str) {
    static char *vector = 0;
    if (str != 0) {
        vector = str;
    }
    if (vector == 0) {
        return 0;
    }

    while (*vector && !is_alpha_alternative(*vector)) {
        vector++;
    }
    switch (*vector) {
        case '\0':
            return 0;
        default:
            break;
    }

    char *word = vector;
    while (*vector && is_alpha_alternative(*vector)) {
        vector++;
    }
    switch (*vector) {
        case '\0':
            break;
        default:
            *vector = '\0';
            vector++;
            break;
    }


    return word;
}


int main() {
    char text[SIZE];
    printf("Podaj tekst:");
    scanf("%1000[^\n]", text);
    for (char *p = text; *p != '\0'; p++) {
        switch (*p) {
            case '\n':
                *p = '\0';
                break;
            default:
                break;
        }

    }
    char *word = get_word(text);
    if (word == 0) {
        printf("Nothing\nto\nshow\n");
        return 0;
    }

    do{
        printf("%s\n", word);
        word = get_word(0);
    }while(word);


    return 0;
}
