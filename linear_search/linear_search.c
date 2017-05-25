#include <stdio.h>

#define NOT_FOUND -1
#define MAX 10001

int n, q;
int A[MAX];

/* 普通の線形探索 */
int linearSearch(int key) {
  int i;
  for (i = 0; i < n; i++) {
    if (A[i] == key)
      return i;
  }
  return NOT_FOUND;
}

/* 番兵を用いた線形探索で,比較演算数を減らし高速化 */
int linearSearch_b(int key) {
  int i = 0;
  A[n] = key;
  while (A[i] != key)
    i++;
  if (i == n)
    return NOT_FOUND;
  else
    return i;
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
    if (linearSearch_b(key) != NOT_FOUND)
      count++;
  }
  printf("%d\n", count);
  return 0;
}
