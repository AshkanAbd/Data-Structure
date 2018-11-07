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
    void *back_link;
public:
    Item() {
        Item::data = nullptr;
        Item::link = nullptr;
        Item::back_link = nullptr;
    }

    ~Item() = default;

    void set_data(void *data) {
        Item::data = data;
    }

    void set_back_link(void *back_link) {
        Item::back_link = back_link;
    }

    void set_link(void *link) {
        Item::link = link;
    }

    void *get_back_link() const {
        return back_link;
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
protected:
    int size;
    Item *head;
public:
    LinkedList() {
        LinkedList::size = 0;
        LinkedList::head = nullptr;
    }

    virtual ~LinkedList() {
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

    virtual type get(int index) {
        int i = 0;
        Item *last = head;
        if (index + 1 > size) throw std::invalid_argument("Index out of bound exception");
        for (; i < index; ++i) {
            last = (Item *) last->get_link();
        }
        return *((type *) last->get_data());
    }

    virtual int index_of(type object, int start = 0) {
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

    virtual void to_arr(void *des) {
        type *t = ((type *) des);
        Item *last = head;
        int i = 0;
        for (;; i++) {
            t[i] = *((type *) last->get_data());
            if (last->get_link() == nullptr) break;
            last = (Item *) last->get_link();
        }
    }

    virtual void remove(int index) {
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

    virtual void insert(int index, type item) {
        int i = 0;
        Item *current = head;
        if (index + 1 > size) throw std::invalid_argument("Index out of bound exception");
        for (; i < index; ++i) {
            current = (Item *) current->get_link();
        }
        void *data = malloc(sizeof(item));
        memcpy(data, &item, sizeof(item));
        current->set_data(data);
    }

    int get_size() {
        return size;
    }
};

template<typename type, typename _Alloc = std::allocator<type> >
class Stack : public LinkedList<type> {
public:
    Stack() : LinkedList<type>() {

    }

    ~Stack() override {
        delete (Stack<type>::head);
    }

    type pop() {
        type t = Stack<type>::get(Stack<type>::get_size() - 1);
        LinkedList<type>::remove(Stack<type>::get_size() - 1);
        return t;
    }

    type poll() {
        return Stack<type>::get(Stack<type>::get_size() - 1);
    }

private:
    type get(int index) override {
        return LinkedList<type>::get(index);
    }

    int index_of(type object, int start = 0) override {
        return LinkedList<type>::index_of(object, start);
    }

    void remove(int index) override {
        LinkedList<type>::remove(index);
    }

    void insert(int index, type item) override {
        LinkedList<type>::insert(index, item);
    }
};

template<typename type, typename _Alloc = std::allocator<type> >
class Queue : public LinkedList<type> {
public:
    Queue() : LinkedList<type>() {

    }

    ~Queue() override {
        delete (Queue<type>::head);
    }

    type pop() {
        type t = LinkedList<type>::get(0);
        LinkedList<type>::remove(0);
        return t;
    }

    type poll() {
        return LinkedList<type>::get(0);
    }

private:
    type get(int index) override {
        return LinkedList<type>::get(index);
    }

    int index_of(type object, int start = 0) override {
        return LinkedList<type>::index_of(object, start);
    }

    void remove(int index) override {
        LinkedList<type>::remove(index);
    }

    void insert(int index, type item) override {
        LinkedList<type>::insert(index, item);
    }
};

#endif //LINKEDLIST_LINKEDLIST_H
