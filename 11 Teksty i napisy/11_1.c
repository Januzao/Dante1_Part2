#include <string.h>
#include <stdio.h>

int main() {
    char arr[] = {"Ala Ma Kota a kot Ma AlE"};
    char *array_pointer = arr;
    for (size_t i = 0; i < strlen(array_pointer); ++i) {
        putchar(*(array_pointer+i));
    }
    return 0;
}