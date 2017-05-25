#include <stdio.h>

void selectionSort(int A[], int n) {
  int i, count_swap = 0;
  for (i = 0; i < n; i++) {
    int minj = i, j, temp;
    for (j = i; j < n; j++) {
      if (A[j] < A[minj])
        minj = j;
    }
    if (i != minj) {
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      count_swap++;
    }
    printf("%d", A[i]);
    if (i != (n - 1))
      printf(" ");
    else
      printf("\n");
  }
  printf("%d\n", count_swap);
}

int main() {
  int i, n;
  scanf("%d", &n);
  int A[n];
  for (i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  selectionSort(A, n);
  return 0;
}
