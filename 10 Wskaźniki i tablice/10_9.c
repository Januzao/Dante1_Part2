#include <stdio.h>

int main() {
    // Ile to będzie bajtów i dlaczego?
    // Każdy element tablicy "int" składa się z 4 bajtów (32 bitów).
    // W tablicy "int tab[] = {67305985, 134678021, 202050057};"
    // mamy 3 elementy, więc łącznie będzie to 3 * 4 = 12 bajtów.

    int tab[] = {67305985, 134678021, 202050057};

    // Jakie będą ich wartości?
    // Wartości w tablicy to: 67305985, 134678021, 202050057.

    // Jakie będzie ich znaczenie - w jaki sposób odpowiadają one liczbom w tablicy tab?
    // Każda liczba całkowita w tablicy jest reprezentowana jako 4-bajtowy obiekt.
    // Wartości te są zapisane w formie little-endian, co oznacza,
    // że najmniej znaczący bajt jest przechowywany jako pierwszy.

    unsigned char *bytes = (unsigned char *)tab;

    for (size_t i = 0; i < sizeof(tab); ++i) {
        printf("%d ", *(bytes+i));
    }

    return 0;
}
