#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.hpp"

//O(1), Omega(1), Theta(1)
int abs_val(int x) {
  if (x >= 0) return x;
  else return abs_val(x * -1);
}

//O(n), Omega(1)
int pow(int base, int num) {
  if (num == 0) return 1;
  else return base * pow(base, num - 1);
}

//O(n), Omega(1)
int log(int base, int num) {
  if (num == 1) return 0;
  else return log(base, num / base) + 1;
}

//SKIP
int chartoint(char c) {
  int result = (int)c;
  result -= '0';
  return result;
}

//SKIP
char inttochar(int x) {
  return (char)(x + '0');
}

//SKIP
char chr(int x) {
  return (char)x;
}

//SKIP
int ord(char c) {
  return (int)c;
}

//O(1), Omega(1), Theta(1)
int max(int x, int y) {
  // return (x > y) ? x : y;
  return (x >= y) ? x : max(y, x);
}

//O(1), Omega(1), Theta(1)
int max(int x, int y, int z) {
  return max(x, max(y, z));
}

//O(1), Omega(1), Theta(1)
int min(int x, int y) {
  return (x <= y) ? x : min(y, x);
}

//O(1), Omega(1), Theta(1)
int min(int x, int y, int z) {
  return min(x, min(y, z));
}

//O(1), Omega(1), Theta(1)
int round(double x, char c) {
  if (x == (int)x) return (int)x;
  if (x > 0) {
    return (c == 'd') ? round((int)x, c) : round((int)x + 1, c);
  } else {
    return (c == 'd') ? round((int)x - 1, c) : round((int)x, c);
  }
}

//O(n), Omega(1)
int max(int arr[], int n) {
  if (n == 1) return arr[0];
  else {
    return max(arr[0], max(arr + 1, n - 1));
  }
}

//O(n), Omega(1)
int min(int arr[], int n) {
  if (n == 1) return arr[0];
  else {
    return min(arr[0], min(arr + 1, n - 1));
  }
}

bool all(bool arr[], int n) {
  if (n <= 1 && *arr) return true;
  return (*arr) ? all(arr + 1, n - 1) : false;
}

bool any(bool arr[], int n) {
  if (n <= 1 && *arr) return true;
  return (!*arr) ? all(arr + 1, n - 1) : true;
}

int frequency(int arr[], int n, int x) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == x)
      count++;
  }
  return count;
}

//O(n), Omega(1)
long sum(int arr[], int n) {
  if (n == 0) return 0;
  else return arr[0] + sum(arr + 1, n - 1);
}

int index(char str[], char substr[]) {
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (substr[j] == '\0')
      return i - j;
    if (str[i] == substr[j])
      ++j;
    else
      j = 0;
    ++i;
  }
  if (substr[j] == '\0')
    return i - j;
  return -1;
}

bool is_sorted(int arr[], int n) {
  // if (n <= 2)
  //   return true;
  // else {
  //   int increasing = 1, decreasing = 1;
  //   for (int i = 0; i < (n - 1); ++i) {
  //     if (arr[i] <= arr[i + 1])
  //       ++increasing;

  //     if (arr[i] >= arr[i + 1])
  //       ++decreasing;
  //   }
  //   return (increasing == n || decreasing == n);
  // }

}