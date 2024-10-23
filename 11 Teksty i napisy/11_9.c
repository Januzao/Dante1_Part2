#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

void clearBuffer() {
    if (getchar() != '\n') clearBuffer();
}

int connect(const char* t1, const char* t2, const char* t3, char* t4, int size) {
    int requiredSize = snprintf(NULL, 0, "%s %s %s", t1, t2, t3);
    if (requiredSize >= size) {
        return 1;
    }
    if (t1 == NULL || t2 == NULL || t3 == NULL || t4 == NULL || size <= 0) {
        return 1;
    }

    snprintf(t4, size, "%s %s %s", t1, t2, t3);
    return 0;
}

int main() {
    char text1[1001], text2[1001], text3[1001], result[3005];

    printf("Podaj tekst:\n");
    scanf("%1000[^\n]", text1);
    clearBuffer();

    printf("Podaj tekst:\n");
    scanf("%1000[^\n]", text2);
    clearBuffer();

    printf("Podaj tekst:\n");
    scanf("%1000[^\n]", text3);
    clearBuffer();

    if (connect(text1, text2, text3, result, sizeof(result)) > 1001) {
        printf("Blad: rozmiar tablicy wynikowej jest niewystarczający.\n");
    }
    if (connect(text1, text2, text3, result, sizeof(result)) == 0) {
        printf("%s\n", result);
    } else {
        printf("Blad: rozmiar tablicy wynikowej jest niewystarczający.\n");
    }

    return 0;
}

