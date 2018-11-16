#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <bits/allocator.h>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
private:
    void *data;
    void *link;
    void *back_link;
public:
    Node();

    ~Node() = default;;

    void set_data(void *data);

    void set_back_link(void *back_link);

    void set_link(void *link);

    void *get_back_link();

    void *get_data();

    void *get_link();
};


template<typename type, typename _Alloc = std::allocator<type>>
class LinkedList {
protected:
    int size;
    Node *head;
public:
    LinkedList() {
        LinkedList::size = 0;
        LinkedList::head = nullptr;
    }

    virtual void add(type item) {
        if (head == nullptr) {
            head = new Node;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            head->set_data(data);
        } else {
            Node *last, *next = nullptr;
            last = head;
            while (true) {
                if (last->get_link() == nullptr) break;
                last = (Node *) last->get_link();
            }
            next = new Node;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            next->set_data(data);
            last->set_link(next);
        }
        size++;
    }

    virtual type get(int index) {
        int i = 0;
        Node *last = head;
        if (index + 1 > size) throw std::invalid_argument("Index out of bounds exception");
        for (; i < index; ++i) {
            last = (Node *) last->get_link();
        }
        return *((type *) last->get_data());
    }

    virtual Node get_node(int index) {
        int i = 0;
        Node *last = head;
        if (index + 1 > size) throw std::invalid_argument("Index out of bounds exception");
        for (; i < index; ++i) {
            last = (Node *) last->get_link();
        }
        return *last;
    }

    virtual int index_of(type object, int start) {
        Node *q = head;
        int i = start;
        for (;; i++) {
            type t = *((type *) q->get_data());
            if (t == object) {
                return i;
            }
            if (q->get_link() == nullptr) break;
            q = (Node *) q->get_link();
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
        Node *last = head;
        int i = 0;
        for (;; i++) {
            t[i] = *((type *) last->get_data());
            if (last->get_link() == nullptr) break;
            last = (Node *) last->get_link();
        }
    }

    virtual void remove(int index) {
        int i = 0;
        Node *last = nullptr, *current = head, *next;
        if (index + 1 > size) throw std::invalid_argument("Index out of bounds exception");
        for (; i < index; ++i) { ;
            last = current;
            current = (Node *) current->get_link();
        }
        next = (Node *) current->get_link();
        if (last == nullptr) {
            head = next;
        } else if (next != nullptr) {
            if (current == head) {
                head = (Node *) head->get_link();
            }
            last->set_link(next);
        }
        delete (current);
        size--;
    }

    virtual void replace(int index, type item) {
        int i = 0;
        Node *current = head;
        if (index + 1 > size) throw std::invalid_argument("Index out of bounds exception");
        for (; i < index; ++i) {
            current = (Node *) current->get_link();
        }
        void *data = malloc(sizeof(item));
        memcpy(data, &item, sizeof(item));
        current->set_data(data);
    }

    virtual void insert(int index, type item) {
        if (index + 1 > size) throw std::invalid_argument("Index out of bounds exception");
        Node *node = new Node;
        void *data = malloc(sizeof(item));
        memcpy(data, &item, sizeof(item));
        node->set_data(data);
        if (index == 0) {
            node->set_link(head);
            head = node;

        } else {
            Node *current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = (Node *) current->get_link();
            }
            Node *next = (Node *) current->get_link();
            current->set_link(node);
            node->set_link(next);
        }
        size++;
    }

    int get_size() {
        return size;
    }
};

template<typename type, typename _Alloc = std::allocator<type>>
class Stack : public LinkedList<type> {
public:

    type pop() {
        type t = Stack<type>::get(Stack<type>::get_size() - 1);
        LinkedList<type>::remove(Stack<type>::get_size() - 1);
        return t;
    }

    type poll() {
        return Stack<type>::get(Stack<type>::get_size() - 1);
    }

private:
    Node get_node(int index) override {
        return LinkedList<type>::get_node(index);
    }

    type get(int index) override {
        return LinkedList<type>::get(index);
    }

    int index_of(type object, int start = 0) override {
        return LinkedList<type>::index_of(object, start);
    }

    void remove(int index) override {
        LinkedList<type>::remove(index);
    }

    void replace(int index, type item) override {
        LinkedList<type>::replace(index, item);
    }

    void insert(int index, type item) override {
        LinkedList<type>::replace(index, item);
    }
};

template<typename type, typename _Alloc = std::allocator<type>>
class Queue : public LinkedList<type> {
public:
    type pop() {
        type t = LinkedList<type>::get(0);
        LinkedList<type>::remove(0);
        return t;
    }

    type poll() {
        return LinkedList<type>::get(0);
    }

private:
    Node get_node(int index) override {
        return LinkedList<type>::get_node(index);
    }

    type get(int index) override {
        return LinkedList<type>::get(index);
    }

    int index_of(type object, int start = 0) override {
        return LinkedList<type>::index_of(object, start);
    }

    void remove(int index) override {
        LinkedList<type>::remove(index);
    }

    void replace(int index, type item) override {
        LinkedList<type>::replace(index, item);
    }

    void insert(int index, type item) override {
        LinkedList<type>::replace(index, item);
    }
};

template<typename type, typename _Alloc=std::allocator<type>>
class CircleLinkedList : public LinkedList<type> {
public:
    void add(type item) override {
        if (LinkedList<type>::head == nullptr) {
            LinkedList<type>::head = new Node;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            LinkedList<type>::head->set_data(data);
            LinkedList<type>::head->set_link(LinkedList<type>::head);
        } else {
            Node *last, *next = nullptr;
            last = LinkedList<type>::head;
            while (true) {
                if (last->get_link() == LinkedList<type>::head) break;
                last = (Node *) last->get_link();
            }
            next = new Node;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            next->set_data(data);
            last->set_link(next);
            next->set_link(LinkedList<type>::head);
        }
        LinkedList<type>::size++;
    }

    int index_of(type object, int start = 0) override {
        Node *q = LinkedList<type>::head;
        int i = start;
        for (;; i++) {
            type t = *((type *) q->get_data());
            if (t == object) {
                return i;
            }
            if (q->get_link() == LinkedList<type>::head) break;
            q = (Node *) q->get_link();
        }
        return -1;
    }

    void to_arr(void *des) override {
        type *t = ((type *) des);
        Node *last = LinkedList<type>::head;
        int i = 0;
        for (;; i++) {
            t[i] = *((type *) last->get_data());
            if (last->get_link() == LinkedList<type>::head) break;
            last = (Node *) last->get_link();
        }
    }

    void remove(int index) override {
        int i = 0;
        Node *last = nullptr, *current = LinkedList<type>::head, *next;
        for (; i < index; ++i) { ;
            last = current;
            current = (Node *) current->get_link();
        }
        next = (Node *) current->get_link();
        if (last == nullptr) {
            LinkedList<type>::head = next;
            Node *last1 = LinkedList<type>::head;
            while (true) {
                if (last1->get_link() == current) break;
                last1 = (Node *) last1->get_link();
            }
            last1->set_link(LinkedList<type>::head);
        } else if (next != nullptr) {
            if (current == LinkedList<type>::head) {
                LinkedList<type>::head = (Node *) LinkedList<type>::head->get_link();
            }
            last->set_link(next);
        }
        delete (current);
        LinkedList<type>::size--;
    }

    void insert(int index, type item) {
        Node *node = new Node;
        void *data = malloc(sizeof(item));
        memcpy(data, &item, sizeof(item));
        node->set_data(data);
        if (index == 0) {
            Node *current = LinkedList<type>::head;
            while (current->get_link() != LinkedList<type>::head) {
                current = (Node *) current->get_link();
            }
            node->set_link(LinkedList<type>::head);
            LinkedList<type>::head = node;
            current->set_link(LinkedList<type>::head);
        } else {
            Node *current = LinkedList<type>::head;
            for (int i = 0; i < index - 1; ++i) {
                current = (Node *) current->get_link();
            }
            Node *next = (Node *) current->get_link();
            current->set_link(node);
            node->set_link(next);
        }
        LinkedList<type>::size++;
    }

    virtual type get(int index) {
        int i = 0;
        Node *last = LinkedList<type>::head;
        for (; i < index; ++i) {
            last = (Node *) last->get_link();
        }
        return *((type *) last->get_data());
    }

    virtual Node get_node(int index) {
        int i = 0;
        Node *last = LinkedList<type>::head;
        for (; i < index; ++i) {
            last = (Node *) last->get_link();
        }
        return *last;
    }


    virtual void replace(int index, type item) {
        int i = 0;
        Node *current = LinkedList<type>::head;
        for (; i < index; ++i) {
            current = (Node *) current->get_link();
        }
        void *data = malloc(sizeof(item));
        memcpy(data, &item, sizeof(item));
        current->set_data(data);
    }
};

template<typename type, typename _Alloc = std::allocator<type> >
class DoublyLinkedList : public LinkedList<type> {
public:
    void add(type item) override {
        if (LinkedList<type>::head == nullptr) {
            LinkedList<type>::head = new Node;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            LinkedList<type>::head->set_data(data);
        } else {
            Node *last, *next = nullptr;
            last = LinkedList<type>::head;
            while (true) {
                if (last->get_link() == nullptr) break;
                last = (Node *) last->get_link();
            }
            next = new Node;
            void *data = malloc(sizeof(item));
            memcpy(data, &item, sizeof(item));
            next->set_data(data);
            next->set_back_link(last);
            last->set_link(next);
        }
        LinkedList<type>::size++;
    }

    type get(int index) override {
        int i = 0;
        Node *last = LinkedList<type>::head;
        if (index + 1 > LinkedList<type>::size) throw std::invalid_argument("Index out of bounds exception");
        for (; i < index; ++i) {
            last = (Node *) last->get_link();
        }
        return *((type *) last->get_data());
    }

    void remove(int index) override {
        int i = 0;
        Node *last = nullptr, *current = LinkedList<type>::head, *next;
        if (index + 1 > LinkedList<type>::size) throw std::invalid_argument("Index out of bounds exception");
        for (; i < index; ++i) { ;
            last = current;
            current = (Node *) current->get_link();
        }
        next = (Node *) current->get_link();
        if (last == nullptr) {
            LinkedList<type>::head = next;
            next->set_back_link(nullptr);
        } else if (next != nullptr) {
            if (current == LinkedList<type>::head) {
                LinkedList<type>::head = (Node *) LinkedList<type>::head->get_link();
            }
            last->set_link(next);
            next->set_back_link(last);
        }
        delete (current);
        LinkedList<type>::size--;
    }

    void insert(int index, type item) {
        Node *node = new Node;
        void *data = malloc(sizeof(item));
        memcpy(data, &item, sizeof(item));
        node->set_data(data);
        if (index == 0) {
            node->set_link(LinkedList<type>::head);
            LinkedList<type>::head = node;
            Node *next = (Node *) LinkedList<type>::head->get_link();
            next->set_back_link(LinkedList<type>::head);
        } else {
            Node *current = LinkedList<type>::head;
            for (int i = 0; i < index - 1; ++i) {
                current = (Node *) current->get_link();
            }
            Node *next = (Node *) current->get_link();
            current->set_link(node);
            node->set_link(next);
            next->set_back_link(node);
        }
        LinkedList<type>::size++;
    }
};


#endif //LINKEDLIST_LINKEDLIST_H
