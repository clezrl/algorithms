#include "LinkedList.hpp"

LinkedList::LinkedList() {
  head = tail = nullptr;
  len = 0;
}

LinkedList::~LinkedList() {
  clear();
}

unsigned int LinkedList::length() {
  return len;
}

void LinkedList::push_front(int d) {
  Node* n = new Node(d);
  if (!head) {
    head = tail = n;
    n->next = head;
    n->prev = tail;
  } else {
    n->next = head;
    n->prev = tail;
    head = n;
    
  }
  ++len;
}

int LinkedList::pop_front() {
  Node* to_remove = head;
  int val = head->data;
  if (len == 1) {
    head = tail = nullptr;
  } else {
    head = head->next;
    head->prev = tail;
    tail->next = head;
  }
  delete to_remove;
  --len;
  return val;
}

int LinkedList::index(int data) {
  if (!len) {
    return -1;
  }
  Node* temp = head;
  int i = 0;
  do {
    if (temp->data == data) {
      return i;
    }
    ++i;
    temp = temp->next;
  } while (temp != head);
  return -1;
}

void LinkedList::push_back(int d) {
  Node* n = new Node(d);
  if (!head) {
    head = tail = n;
    n->next = head;
    n->prev = tail;
  } else {
    tail->next = n;
    n->prev = tail;
    n->next = head;
    head->prev = n;
    tail = n;
  }
  ++len;
}

int LinkedList::pop_back() {
  Node* to_remove = tail;
  if (len == 1) {
    head = tail = nullptr;
  } else {
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
  }
  int val = to_remove->data;
  delete to_remove;
  --len;
  return val;
}

int LinkedList::at(int idx) {
  idx = (idx < 0) ? len + idx : idx;

  if (idx < 0 || idx >= len) {
    throw "NOPE!";
  }
  
  Node* iter = head;
  for (int i = 0; i < idx; ++i) {
    iter = iter->next;
  }

  return iter->data;
}

int LinkedList::set(int idx, int d) {
  idx = (idx < 0) ? len + idx : idx;
  if (idx < 0 || idx >= len) {
    throw "NOPE!";
  }
  Node* iter = head;
  while (--idx >= 0) {
    iter = iter->next;
  }
  int old = iter->data;
  iter->data = d;
  return old;
}

void LinkedList::push(int d, int idx) {}

int LinkedList::pop(int idx) {return idx;}

void LinkedList::clear() {
  Node* to_remove;
  ++len;
  while(--len) {
    to_remove = head;
    head = head->next;
    delete to_remove;
  }
  head = tail = nullptr;
  len = 0;
}

void LinkedList::remove(int d) {
  if (len > 0 && head->data == d) {
    pop_front();
  } else if (!len) {
    return;
  } else {
    Node* iter = head;
    do {
      if (iter->next->data == d) {
        Node* to_remove = iter->next;
        iter->next = to_remove->next;
        delete to_remove;
        --len;
      }
    } while (iter != head);
  }
}

void LinkedList::reverse() {}

void LinkedList::print(std::ostream& oss) {
  Node* temp = head;
  while (temp) {
    oss << temp->data << ", ";
    temp = temp->next;
  }
  oss << std::endl;
  return;
}