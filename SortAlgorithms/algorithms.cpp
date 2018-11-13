#include "algorithms.h"
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

namespace sort {
    void merge(int *arr, int start, int mid, int end) {
/*
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
*/
        int *a = new int[mid - start + 1];
        int *b = new int[end - mid];
        copy(arr + start, arr + mid + 1, a);
        copy(arr + mid + 1, arr + end + 1, b);
        int x = 0, y = 0;
        for (int i = start; i <= end; ++i) {
            if (x >= mid - start + 1) {
                *(arr + i) = *(b + y);
                y++;
            } else if (y >= end - mid) {
                *(arr + i) = *(a + x);
                x++;
            } else if (*(a + x) < *(b + y)) {
                *(arr + i) = *(a + x);
                x++;
            } else {
                *(arr + i) = *(b + y);
                y++;
            }
        }
    }

    void merge_sort(int *arr, int start, int end) {
        if (start >= end) return;
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    void quick_sort(int *arr, int start, int end) {
        if (end < start) return;
        if (start < 0 || end < 0) return;
        if (end - start == 0) return;
        if (end - start == 1) {
            if (*(arr + start) > *(arr + end)) {
                swap(*(arr + start), *(arr + end));
            }
            return;
        }
        int p = start, temp;
        for (int i = start + 1; i <= end; ++i) {
            if (*(arr + p) > *(arr + i)) {
                temp = *(arr + i);
                copy(arr + start, arr + i, arr + start + 1);
                *(arr + start) = temp;
                p++;
            }
        }
        quick_sort(arr, start, p - 1);
        quick_sort(arr, p + 1, end);
    }

    void bubble_sort(int *src, int *dst, int size) {
        copy(src, src + size, dst);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size - 1; ++j) {
                if ((*(dst + j)) > (*(dst + (j + 1)))) {
                    swap((*(dst + j)), (*(dst + (j + 1))));
                }
            }
        }
    }

    void merge_sort(int *src, int *dst, int size) {
        copy(src, src + size, dst);
        merge_sort(dst, 0, size - 1);
    }

    void quick_sort(int *src, int *dst, int size) {
        copy(src, src + size, dst);
        quick_sort(dst, 0, size - 1);
    }

    void insertion_sort(int *src, int *dst, int size) {
        copy(src, src + size, dst);
        for (int i = 0; i < size; ++i) {
            int k = i;
            int temp = *(dst + i);
            for (int j = i - 1; j >= 0; j--) {
                if (*(dst + j) > *(dst + i)) {
                    k--;
                } else {
                    break;
                }
            }
            copy(dst + k, dst + i, dst + k + 1);
            *(dst + k) = temp;
        }
    }

    void selection_sort(int *src, int *dst, int size) {
        copy(src, src + size, dst);
        for (int i = 0; i < size; ++i) {
            int min = i;
            for (int j = i; j < size; ++j) {
                if (*(dst + j) < *(dst + min))
                    min = j;
            }
            swap(*(dst + min), *(dst + i));
        }
    }
}