#include <stdio.h>
#include <stdlib.h>

unsigned gaps[] = {1,8,23,77,281,1073,4193,16577,65921,262913,1050113};

int insertionSort(unsigned A[], unsigned n, unsigned g) {
  int i, count = 0;
  for (i = g; i < n; i++) {
    unsigned v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      count++;
    }
    A[j + g] = v;
  }
  return count;
}

void shellSort(unsigned A[], unsigned n) {
  unsigned count, m = 0;
  while (gaps[++m] < n);
  m--;
  int i;
  for (i = m; i >= 0; i--) count += insertionSort(A, n, gaps[i]);
  printf("%u\n", m + 1);
  for (i = m; i; i--) printf("%u ", gaps[i]);
  printf("%u\n", gaps[0]);
  printf("%u\n", count);
}

int main() {
  unsigned i, n;
  scanf("%d", &n);
  unsigned *A = (unsigned *)malloc(sizeof(unsigned) * n);
  for (i = 0; i < n; i++) scanf("%u", &A[i]);
  shellSort(A, n);
  for (i = 0; i < n; i++) printf("%u\n", A[i]);
  free(A);
  return 0;
}
