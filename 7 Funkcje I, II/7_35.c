#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[]) {
    unsigned int length = 0;
    while (tab[length] != '\0') {
        length++;
    }
    return length;
}

int my_atoi(const char tab[]) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (tab[0] == '-') {
        sign = -1;
        i = 1;
    }

    while (tab[i] != '\0') {
        if (tab[i] >= '0' && tab[i] <= '9') {
            result = result * 10 + (tab[i] - '0');
        } else {
            return sign * result;
        }
        i++;
    }

    return sign * result;
}

float my_atof(const char tab[]) {
    float result = 0.0;
    float fraction = 0.1;
    int sign = 1;
    int i = 0;

    if (tab[0] == '-') {
        sign = -1;
        i = 1;
    }

    while (tab[i] != '\0') {
        if (tab[i] >= '0' && tab[i] <= '9') {
            result = result * 10 + (tab[i] - '0');
        } else if (tab[i] == '.') {
            i++;
            while (tab[i] != '\0' && tab[i] >= '0' && tab[i] <= '9') {
                result += (tab[i] - '0') * fraction;
                fraction *= 0.1;
                i++;
            }
            break;
        } else {
            return sign * result;
        }
        i++;
    }

    return sign * result;
}

int main() {
    char input[16];
    printf("podaj liczbe:");
    scanf("%15s", input);

    unsigned int length = my_strlen(input);
    int int_result = my_atoi(input);
    float float_result = my_atof(input);

    printf("%u\n", length);
    printf("%d\n", int_result);
    printf("%.4f\n", float_result);

    return 0;
}

