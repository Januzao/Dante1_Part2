#include <stdio.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

void clearInputBuffer();

int starts_with(const char* txt, const char* find);
int ends_with(const char* txt, const char* find);

int main() {
    char txt[101];
    char find[101];

    printf("Podaj tekst:\n");
    fgets(txt, sizeof(txt), stdin);

    if (strlen(txt) == 100 && *(txt + 99) != '\n') {
        clearInputBuffer();
    } else {
        char *newlineTxt = strchr(txt, '\n');
        if (newlineTxt != NULL) {
            *newlineTxt = '\0';
        }
    }

    printf("Podaj drugi tekst:\n");
    fgets(find, sizeof(find), stdin);

    if (strlen(find) == 100 && *(find + 99) != '\n') {
        clearInputBuffer();
    } else {
        char *newlineFind = strchr(find, '\n');
        if (newlineFind != NULL) {
            *newlineFind = '\0';
        }
    }

    int startsResult = starts_with(txt, find);
    int endsResult = ends_with(txt, find);

    printf("%d\n%d\n", startsResult, endsResult);
    return 0;
}

void clearInputBuffer() {
    if (getchar() != '\n') clearInputBuffer();
}

int starts_with(const char* txt, const char* find) {
    if (txt == NULL || find == NULL) {
        return -1;
    }

    size_t txtLen = strlen(txt);
    size_t findLen = strlen(find);

    if (findLen > txtLen) {
        return 0;
    }

    return strncmp(txt, find, findLen) == 0 ? 1 : 0;
}

int ends_with(const char* txt, const char* find) {
    if (txt == NULL || find == NULL) {
        return -1;
    }

    size_t txtLen = strlen(txt);
    size_t findLen = strlen(find);

    if (findLen > txtLen) {
        return 0;
    }

    return strncmp(txt + txtLen - findLen, find, findLen) == 0 ? 1 : 0;
}

