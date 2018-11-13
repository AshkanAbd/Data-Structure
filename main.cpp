#include <iostream>
#include "LinkedList/linkedlist.h"
#include "SortAlgorithms/algorithms.h"

using namespace std;

int main() {
    LinkedList<int> linkedList;
    cout << "Enter 5 numbers : " << endl;
    for (int i = 0; i < 5; ++i) {
        int a;
        cin >> a;
        linkedList.add(a);
    }
    int arr[5];
    linkedList.to_arr(arr);
    sort::quick_sort(arr, arr, 5);
    for (int i = 0; i < 5; ++i) {
        cout << *(arr + i) << " ";
    }
}
