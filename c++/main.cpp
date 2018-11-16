#include <iostream>
#include "LinkedList/linkedlist.h"
#include "SortAlgorithms/algorithms.h"

using namespace std;

int main() {
    DoublyLinkedList<int> linkedList;
    linkedList.add(0);
    linkedList.add(1);
    linkedList.add(2);
    linkedList.add(3);
    for (int i = 0; i < linkedList.get_size(); ++i) {
        cout << linkedList.get(i) << " ";
    }
    cout << endl;
    linkedList.insert(0, 4);
    for (int i = 0; i < 5; ++i) {
        cout << linkedList.get(i) << " ";
    }
    cout << endl;
}
