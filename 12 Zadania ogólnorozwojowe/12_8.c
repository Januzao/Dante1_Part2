#include <stdio.h>

int DigitNumbers(int k) {
    if (k < 10) return 1;
    return 1 + DigitNumbers(k / 10);
}

void findNumbersAndPrint(int N, int *pInt) {
    int second_number;
    for (int number = N - 1; number >= N / 2; number--) {
        second_number = N - number;
        if (DigitNumbers(number) >= 2 && DigitNumbers(second_number) == DigitNumbers(number) - 1) {
            printf("%d + %d = %d\n", number, second_number, N);
            *pInt = 1;
        }
    }
}

int main() {
    int N;
    int correct_number = 0;

    printf("Podaj N:");
    if (scanf("%d", &N) != 1 || N < 0 || N > 100000) {
        printf("Incorrect input\n");
        return 1;
    }

    findNumbersAndPrint(N, &correct_number);

    if (!correct_number){
        printf("Nothing to show\n");
    }
    return 0;
}
