#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"

<<<<<<< HEAD
//O(1), Omega(1), Theta(1)
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//O(n^2), Omega(n)
void bubble_sort(int* arr, int n) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (int i = 0; i < n - 1; ++i) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        sorted = false;
      }
=======
//O(n^2) - Omega(n)
//
void bubble_sort(int *arr, int n) {
    for(int i = 0; i < (n - 1); i++) {
        if(arr[i] > arr[i + 1]) {
            arr[i] = arr[i] xor arr[i + 1];
            arr[i + 1] = arr[i] xor arr[i + 1];
            arr[i] = arr[i] xor arr[i + 1];
        }
    }
    if ( n != 1) {
        bubble_sort(arr, n - 1);
>>>>>>> upstream/master
    }
}
