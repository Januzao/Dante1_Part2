#include <stdio.h>
#include <math.h>

int isSignificantNumber(int number) {
    if (number <= 0) {
        return 0;
    }

    int sum = 0;
    int count = 0;

    for (int i = 1; i <= number; i++) {
        if (number % i == 0 && i != number) {
            sum += i;
            count++;
        }
    }

    double average = (double) sum / count;
    double sqrtNumber = sqrt(number);

    if (average <= sqrtNumber) {
        return 1;
    } else {
        return 0;
    }
}

int countSignificantNumbers(int start, int end) {
    if (start > end) {
        return 2;
    }

    int count = 0;

    for (int i = start; i <= end; i++) {
        if (isSignificantNumber(i)) {
            count++;
        }
    }

    return count;
}

int main() {
    int start, end;

    printf("Podaj poczatek:");
    if (scanf("%d", &start) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    printf("Podaj koniec:");
    if (scanf("%d", &end) != 1) {
        printf("Incorrect input\n");
        return 1;
    }
    if (start > end){
        printf("Incorrect input data");
        return 2;
    }

    int count = countSignificantNumbers(start, end);
    printf("%d\n", count);

    return 0;
}