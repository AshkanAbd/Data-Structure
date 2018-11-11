#include "algorithms.h"

using namespace std;

namespace sort {
    void merge(int *arr, int start, int mid, int end) {
        int i = mid + 1, j = start, k, l;
        for (; i <= end; i++) {
            while (*(arr + j) <= *(arr + i) && j < i) {
                j++;
            }
            if (j == i) break;
            l = *(arr + i);
            for (k = i; k > j; k--) {
                *(arr + k) = *(arr + k - 1);
            }
            *(arr + j) = l;
        }
    }

    void merge_sort(int *arr, int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    void bubble_sort(int *src, int *dst, int size) {
        memcpy(dst, src, sizeof(int) * size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size - 1; ++j) {
                if ((*(dst + j)) > (*(dst + (j + 1)))) {
                    swap((*(dst + j)), (*(dst + (j + 1))));
                }
            }
        }
    }

    void merge_sort(int *src, int *dst, int size) {
        memcpy(dst, src, sizeof(int) * size);
        merge_sort(dst, 0, size - 1);
    }
}