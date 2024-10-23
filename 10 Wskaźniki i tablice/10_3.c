#include <stdio.h>

int main(){
    int T[10];
    int *hi = T;

    for (int i = 0; i < 10; ++i) {
        *hi = i;
        hi++;

    }
    hi = T;
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", *hi);
        hi++;
    }

    printf("\n");

    return 0;
}
