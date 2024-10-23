#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

#define SIZE 91
int sort(char const*ptrs[], int size) {
    if (!ptrs||size < 1) {
        return 1;
    }
    for (int i = 0; i < size; ++i) {
        if (!*(ptrs+i)) {
            return 1;
        }
    }
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (strcmp(*(ptrs+i), *(ptrs+j)) > 0) {
                char const*temp = *(ptrs+i);
                *(ptrs+i) = *(ptrs+j);
                *(ptrs+j) = temp;
            }
        }
    }
    return 0;
}

void clearBuffer(){
    if(getchar()!='\n') clearBuffer();
}

int main() {
    char* pString[11];
    int rozmiar = 0;
    printf("Podaj wyrazy:\n");
    for (int i = 0; i < 10; ++i) {
        *(pString + i) = malloc(SIZE * sizeof(char));
        for (int j = 0; j < SIZE; ++j) {
            *(*(pString + i) + j) = '\0';
        }
    }
    do{
        scanf("%90[^\n]", *(pString + rozmiar));clearBuffer();
        if (strcmp(*(pString + rozmiar++), "") == 0) {
            rozmiar--;
            break;
        }
    }while(rozmiar < 10);

    if (rozmiar < 1) {
        for (int i = 0; i < 10; ++i) {
            free(*(pString + i));
        }
        printf("Not enough data available");
        return 3;
    }
    sort((const char**)pString, rozmiar);
    for (int i = 0; i < rozmiar; ++i) {
        printf("%s\n", *(pString + i));
    }
    for (int i = 0; i < 10; ++i) {
        free(*(pString + i));
    }
    return 0;
}
