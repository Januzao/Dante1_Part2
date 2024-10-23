#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int arr[20];

    int *hi = arr;
    for (int i = 0; i < 20; ++i) {
        *hi = rand() % 20;
         hi++;
    }
    hi = arr;
    for (int i = 0; i < 20; ++i) {
        printf("%d ", *hi);
        hi++;
    }
    printf("\n");

    hi = arr;
    for (int i = 0; i < 20; i+=2) {
        printf("%d ", *hi);
        hi+=2;
    }

    return 0;
}
