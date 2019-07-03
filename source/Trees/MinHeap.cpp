#include "MinHeap.hpp"

void swap(int* x, int*y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}

MinHeap::MinHeap(unsigned int cap) {
    capacity = cap;
    array = new int[capacity];
    size = 1;
}

MinHeap::~MinHeap() {
    delete[] array;
}

void MinHeap::swim() {
    int pos = size;
    while (array[pos/2] > array[pos]) {
        swap(&array[pos/2], &array[pos]);
        pos = pos/2;
    }
}

void MinHeap::sink(int i) {
    int pos = 1;
    while (pos <= size && (array[pos] > array[2*pos] || array[pos] > array[2*pos + 1])) {
        (array[2*pos] < array[2*pos + 1]) ? swap(&array[pos], &array[2*pos]) : swap(&array[pos], &array[2*pos + 1]);
    }
}

bool MinHeap::search(int i, int data) {
    if (i > size || array[i] > data) return false;
    if (array[i] == data) return true;
    return (search(2*i, data) || search(2*i + 1, data));
}

void MinHeap::erase(int i, int data) {
    if (i > size || array[i] > data) return;
    if (array[i] == data) remove(i);
    erase(2*i, data);
    erase(2*i + 1, data);
}

void MinHeap::push(int data) {
    if (size == capacity) {
        int* newArray = new int[capacity * 2];
        for (int i = 0; i <= size; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity *= 2;
    }

    array[size++] = data;
    swim();
}

int MinHeap::count() {
    return size - 1;
}

int MinHeap::pop() {
    if (count() == 0) throw "Empty Heap";
}

int MinHeap::peek() {
    return 1;
}

bool MinHeap::search(int data) {
    return true;
}

int MinHeap::remove(int i) {
    return 1;
}

void MinHeap::erase(int data) {

}

void MinHeap::print(std::ostream& oss) {

}