#include <stdio.h>

unsigned gaps[] = {1,8,23,77,281,1073,4193,16577,65921,262913,1050113};
int cnt;

void insertionSort(int A[], int n, int g) {
  int i;
  for (i = g; i < n; i++) {
    int v = A[i], j = i - g;
    while ((j >= 0) && (A[j] > v)) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  cnt = 0;
  int i;
  for (i = 0; i < m; i++) {
    insertionSort(A, n, G[i]);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n], i;
  for (i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  shellSort(A, n);
  printf("%d\n", m);
  for (i = 0; i < m; i++) {
    printf("%d", G[i]);
    if (i == (m - 1)) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  printf("%d\n", cnt);
  for (i = 0; i < n; i++) {
    printf("%d\n", A[i]);
  }
  return 0;
}
