#include <stdio.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1001

int containsOnlyDigits(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (!isdigit(text[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int containsLetters = 0;

    printf("Podaj tekst:");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Incorrect input\n");
        return 1;
    }

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            containsLetters = 1;
            break;
        }
    }

    if (containsLetters) {
        int capitalizeNext = 1;

        for (int i = 0; input[i] != '\0'; i++) {
            if (isalpha(input[i])) {
                if (capitalizeNext) {
                    putchar(toupper(input[i]));
                    capitalizeNext = 0;
                } else {
                    putchar(tolower(input[i]));
                }
            } else if (isspace(input[i]) || ispunct(input[i])) {
                capitalizeNext = 1;
            }
        }
    } else if (!containsOnlyDigits(input)) {
        printf("NothingToShow\n");
    } else {
        printf("%s", input);
    }

    return 0;
}
