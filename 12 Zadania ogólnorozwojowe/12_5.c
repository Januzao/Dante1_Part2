#include <stdio.h>

void drawPositivePattern(int wynik) {
    for (int i = 0; i < 2 * wynik; i++) {
        if (i < wynik) {
            for (int j = 0; j < i + 1; ++j) {
                printf("X");
            }
            for (int j = 0; j < wynik - 1 - i; ++j) {
                printf(" ");
            }
            for (int j = 0; j < wynik - i; ++j) {
                printf("X");
            }
            if (i != 0) {
                for (int j = 0; j < i - 1; ++j) {
                    if (j + 1 != i) {
                        printf(" ");
                    } else {
                        printf(" ");
                    }
                }
            }
        } else {
            for (int j = 0; j < 2 * wynik - 1 - i; ++j) {
                printf(" ");
            }
            for (int j = 0; j < i + 1 - wynik; ++j) {
                printf("X");
            }
            for (int j = 0; j < i - wynik; ++j) {
                printf(" ");
            }
            if (2 * wynik - i != 0) {
                for (int j = 0; j < 2 * wynik - i; ++j) {
                    if (j + 1 != 2 * wynik - i) {
                        printf("X");
                    } else {
                        printf("X");
                    }
                }
            }
        }
        printf("\n");
    }
}

void drawNegativePattern(int result) {
    result *= -1;
    for (int i = 0; i < 2 * result; i++) {
        if (i < result) {
            for (int j = 0; j < i; ++j) {
                printf(" ");
            }
            for (int j = 0; j < result - i; ++j) {
                printf("X");
            }
            for (int j = 0; j < result - i - 1; ++j) {
                printf(" ");
            }
            if (i + 1 != 0) {
                for (int j = 0; j < i + 1; ++j) {
                    if (j + 1 != i + 1) {
                        printf("X");
                    } else {
                        printf("X");
                    }
                }
            }
        } else {
            for (int j = 0; j < 2 * result - i; ++j) {
                printf("X");
            }
            for (int j = 0; j < i - result; ++j) {
                printf(" ");
            }
            for (int j = 0; j < i - result + 1; ++j) {
                printf("X");
            }
            if (2 * result - i != 0) {
                for (int j = 0; j < 2 * result - i; ++j) {
                    if (j + 1 != 2 * result - i) {
                        printf(" ");
                    } else {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int numbers[10];
    int userInput;
    for (int index = 0; index < 12; index++) {
        printf("Enter a number:");
        if (scanf("%d", &userInput) != 1) {
            printf("Incorrect input");
            return 1;
        }
        if (userInput < -10 || userInput > 10) {
            printf("Incorrect input data");
            return 2;
        } else {
            numbers[index] = userInput;
            if (userInput == 0) {
                break;
            }
        }
    }

    int result;
    for (int k = 0; numbers[k] != 0; k++) {
        result = numbers[k];
        if (result > 0) {
            drawPositivePattern(result);
        } else if (result < 0) {
            drawNegativePattern(result);
        }
        printf("\n\n");
    }

    return 0;
}
