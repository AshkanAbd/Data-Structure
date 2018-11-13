#ifndef LINKEDLIST_ALGORITHMS_H
#define LINKEDLIST_ALGORITHMS_H

#include <iostream>
#include <cstring>

using namespace std;

namespace sort {
    void bubble_sort(int *src, int *dst, int size);

    void merge_sort(int *src, int *dst, int size);

    void quick_sort(int *src, int *dst, int size);
}
#endif //LINKEDLIST_ALGORITHMS_H
