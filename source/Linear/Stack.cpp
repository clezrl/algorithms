#include "Stack.hpp"
#include <iostream>

Stack::Stack() {
    head = nullptr;
    len = 0;
}

Stack::~Stack() {
    clear();
}

unsigned int Stack::size() {
    return len;
}

void Stack::push(int data) {
    Node* n = new Node(data);
    if (!head) {
        head = n;
    } else {
        n->next = head;
        head = n;
    }
    ++len;
}

int Stack::pop() {
    if (len == 0) throw "NOPE!";
    Node* to_remove = head;
    int val = head->data;
    if (len == 1) {
        head = nullptr;
    } else {
        head = head->next;
    }
    delete to_remove;
    --len;
    return val;
}

int Stack::top() {
    if (!head) throw "NOPE!";
    return head->data;
}

bool Stack::empty() {
    return (!head) ? true : false;
}

void Stack::clear() {
    Node* iter = head;
    while (head) {
        iter = head;
        head = head->next;
        delete iter;
    }
    len = 0;
}