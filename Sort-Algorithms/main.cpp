#include <iostream>
#include "algorithms.h"

using namespace std;

int main() {
    int a[] = {2, 5, 1, 8, 4, 3, 9, 6, 7};
    int size = (sizeof(a) / sizeof(a[0]));
    int b[size];
    sort::merge_sort(a, b, size);
    cout << "src = ";
    for (int i = 0; i < size; ++i) {
        cout << *(a + i) << "   ";
    }
    cout << endl << "dst = ";
    for (int i = 0; i < size; ++i) {
        cout << *(b + i) << "   ";
    }
}
