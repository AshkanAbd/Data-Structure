#include "linkedlist.h"
#include <iostream>

using namespace std;

Node::Node() {
    Node::data = nullptr;
    Node::link = nullptr;
    Node::back_link = nullptr;
}


void Node::set_data(void *data) {
    Node::data = data;
}

void Node::set_back_link(void *back_link) {
    Node::back_link = back_link;
}

void Node::set_link(void *link) {
    Node::link = link;
}

void *Node::get_back_link() {
    return Node::back_link;
}

void *Node::get_data() {
    return Node::data;
}

void *Node::get_link() {
    return Node::link;
}

