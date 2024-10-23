#include <stdio.h>

int main()
{
    char znak1, znak2, znak3, znak4, znak5;

    printf("Podaj 5 znakow:");
    scanf("%c %c %c %c %c, ", &znak1, &znak2, &znak3, &znak4, &znak5);

    int symbol_x = (znak1 == 'x') + (znak2 == 'x') + (znak3 == 'x') + (znak4 == 'x') + (znak5 == 'x');
    int symbol_y = (znak1 == 'y') + (znak2 == 'y') + (znak3 == 'y') + (znak4 == 'y') + (znak5 == 'y');
    int symbol_z = (znak1 == 'z') + (znak2 == 'z') + (znak3 == 'z') + (znak4 == 'z') + (znak5 == 'z');
    int symbol_2 = (znak1 == '2') + (znak2 == '2') + (znak3 == '2') + (znak4 == '2') + (znak5 == '2');
    int symbol_7 = (znak1 == '7') + (znak2 == '7') + (znak3 == '7') + (znak4 == '7') + (znak5 == '7');

    printf("\"Szukane znaki wystapily %d raz(y)\\n", symbol_x + symbol_y + symbol_z + symbol_2 + symbol_7);

    return 0;
}
