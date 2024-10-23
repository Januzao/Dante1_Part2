#include <stdio.h>

int main() {
    double lczb1, lczb2, lczb3, lczb4, lczb5;
    double max, min, average;

    printf("Podaj 5 liczb: \n");
    scanf("%lf %lf %lf %lf %lf", &lczb1, &lczb2, &lczb3, &lczb4, &lczb5);

    max = lczb1;
    if (lczb2 > max) {
        max = lczb2;
    }
    if (lczb3 > max) {
        max = lczb3;
    }
    if (lczb4 > max) {
        max = lczb4;
    }
    if (lczb5 > max) {
        max = lczb5;
    }
    min = lczb1;
    if (lczb2 < min) {
        min = lczb2;
    }
    if (lczb3 < min) {
        min = lczb3;
    }
    if (lczb4 < min) {
        min = lczb4;
    }
    if (lczb5 < min) {
        min = lczb5;
    }
    average = (lczb1 + lczb2 + lczb3 + lczb4 + lczb5) / 5.0;

    printf("%.6lf\n", min);
    printf("%.6lf\n", max);
    printf("%.2lf\n", average);
    return 0;
}

