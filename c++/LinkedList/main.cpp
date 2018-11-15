#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> linkedList;
    int a = 3;
    linkedList.add(a);
    a = 2;
    linkedList.add(a);
    linkedList.add(5);
    linkedList.remove(0);
    for (int i = 0; i < linkedList.get_size(); ++i) {
        cout << linkedList.get(i) << endl;
    }
}