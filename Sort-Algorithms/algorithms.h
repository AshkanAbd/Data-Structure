#ifndef LINKEDLIST_ALGORITHMS_H
#define LINKEDLIST_ALGORITHMS_H

#include <iostream>
#include <cstring>

using namespace std;

void bubble_sort(int *src, int *dest, int size) {
    memcpy(dest, src, sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if ((*(dest + j)) > (*(dest + (j + 1)))) {
                swap((*(dest + j)), (*(dest + (j + 1))));
            }
        }
    }
}

void merge_sort(int *src, int *dest, int size) {
    memcpy(dest, src, sizeof(int) * size);
}

#endif //LINKEDLIST_ALGORITHMS_H
