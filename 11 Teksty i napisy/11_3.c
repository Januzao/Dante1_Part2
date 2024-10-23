#include <stdio.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
#define SIZE 1000

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace) {
    if (text == NULL || uppercase == NULL || lowercase == NULL || whitespace == NULL) {
        return 1;
    }

    int wielkie = 0;
    int male = 0;
    int biale_znaki = 0;

    for (size_t i = 0; i < strlen(text); i++) {
        if (*(text+i) == '\n' || *(text+i) == ' ' || *(text+i) == '\t') {
            biale_znaki++;
        }
        if (*(text+i) >= 65 && *(text+i)<= 90) {
            wielkie++;
        }
        if (*(text+i) >=97 && *(text+i) <=122) {
            male++;
        }
    }

    *uppercase = wielkie;
    *lowercase = male;
    *whitespace = biale_znaki;

    return 0;
}

int main() {
    char arr[SIZE];
    int welyke = 0, maleke = 0, bileznak = 0;

    printf("Podaj tekst:");
    scanf("%1000[^\n]", arr);

    int result = marks_counter(arr, &welyke, &maleke, &bileznak);

    if (result == 0) {
        printf("%d\n%d\n%d", welyke, maleke, bileznak);
    } else {
        printf("Incorrect input\n");
    }

    return 0;
}
