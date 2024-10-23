#include <stdio.h>
#include <stdlib.h>

int main() {
    int ocena;

    printf("prosze podac liczbe punktow:");
    if (scanf("%d", &ocena) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    if (ocena >= 0 && ocena <= 10) {
        printf("Ocena 2\n");
    } else if (ocena >= 11 && ocena <= 13) {
        printf("Ocena 3\n");
    } else if (ocena >= 14 && ocena <= 16) {
        printf("Ocena 4\n");
    } else if (ocena >= 17 && ocena <= 20) {
        printf("Ocena 5\n");
    } else {
        printf("Incorrect input\n");
        return 1;
    }

    return 0;
}
