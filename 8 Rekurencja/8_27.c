#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_destination_reachable(int sx, int sy, int dx, int dy)
{
    if(sx > dx || sy > dy)
        return 0;

    if(sx == dx && sy == dy)
        return 1;
    return is_destination_reachable(sx + sy, sy, dx, dy) || is_destination_reachable(sx, sy + sx, dx, dy);
}


int main() {
    int sx, sy, dx, dy;
    printf("Podaj wspolrzedne poczatkowe:");
    if (scanf("%d %d", &sx, &sy) != 2) {
        printf("Incorrect input");
        return 1;
    }

    printf("Podaj wspolrzedne koncowe:");
    if (scanf("%d %d", &dx, &dy) != 2) {
        printf("Incorrect input\n");
        return 1;
    }
    if(is_destination_reachable(sx, sy, dx, dy)){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}




