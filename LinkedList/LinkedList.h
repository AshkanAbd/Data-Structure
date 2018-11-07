#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <bits/allocator.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Item {
private:
    void *data;
    void *link;
public:
    Item() {
        Item::data = nullptr;
        Item::link = nullptr;
    }

    ~Item() = default;

    void set_data(void *data) {
        Item::data = data;
    }

    void set_link(void *link) {
        Item::link = link;
    }

    void *get_data() {
        return Item::data;
    }

    void *get_link() {
        return Item::link;
    }
};


template<typename type, typename _Alloc = std::allocator<type> >
class LinkedList {
private:
    int size;
    Item *head;
public:
    LinkedList() {
        LinkedList::size = 0;
        LinkedList::head = nullptr;
    }

    ~LinkedList() {
        delete (LinkedList::head);
    }

    void add(type item) {
        if (head == nullptr) {
            head = new Item;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            head->set_data(data);
        } else {
            Item *last, *next = nullptr;
            last = head;
            while (true) {
                if (last->get_link() == nullptr) break;
                last = (Item *) last->get_link();
            }
            next = new Item;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            next->set_data(data);
            last->set_link(next);
        }
        size++;
    }

    type get(int index) {
        int i = 0;
        Item *last = head;
        if (index + 1 > size) throw std::invalid_argument("Index out of bound exception");
        for (; i < index; ++i) {
            last = (Item *) last->get_link();
        }
        return *((type *) last->get_data());
    }

    int index_of(type object, int start = 0) {
        Item *q = head;
        int i = start;
        for (;; i++) {
            type t = *((type *) q->get_data());
            if (t == object) {
                return i;
            }
            if (q->get_link() == nullptr) break;
            q = (Item *) q->get_link();
        }
        return -1;
    }

    template<type N>
    void add_all(const type (&arr_item)[N]) {
        for (const auto &item: arr_item) {
            add(item);
        }
    }

    void remove(int index) {
        int i = 0;
        Item *last = nullptr, *current = head, *next;
        if (index + 1 > size) throw std::invalid_argument("Index out of bound exception");
        for (; i < index; ++i) { ;
            last = current;
            current = (Item *) current->get_link();
        }
        next = (Item *) current->get_link();
        if (last == nullptr) {
            head = next;
        } else {
            last->set_link(next);
        }
        delete (current);
        size--;
    }

    int get_size() {
        return size;
    }
};


#endif //LINKEDLIST_LINKEDLIST_H
