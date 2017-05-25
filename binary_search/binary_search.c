#include <stdio.h>

#define NOT_FOUND -1
#define MAX 100001

int n, q;
int A[MAX], T[MAX];

int binarySearch(int key) {
  int left = 0, right = n, mid;
  while (left < right) {
    mid = (left + right) / 2;
    if (A[mid] == key)
      return mid;
    else if (key < A[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return NOT_FOUND;
}

int main() {
  scanf("%d", &n);
  int j;
  for (j = 0; j < n; j++) {
    scanf("%d", A + j);
  }
  scanf("%d", &q);
  int key, count = 0;
  while (q--) {
    scanf("%d", &key);
    if (binarySearch(key) != NOT_FOUND)
      count++;
  }
  printf("%d\n", count);
  return 0;
}
