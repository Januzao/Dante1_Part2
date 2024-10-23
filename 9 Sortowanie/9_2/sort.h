#ifndef SORT_H
#define SORT_H

enum direction {
    ASCENDING,
    DESCENDING
};

int bubble_sort_asc(int vector[], int size);
int bubble_sort_desc(int tab[], int size);
int bubble_sort(int tab[], int size, enum direction dir);

#endif