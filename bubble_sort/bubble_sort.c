#include <stdio.h>

int bubbleSort(int a[], int n) {
  int flag = 1;
  int done = 0, count = 0;
  while (flag) {
    flag = 0;
    int j;
    for (j = n - 1; j > done; j--) {
      if (a[j] < a[j - 1]) {
        int temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        flag = 1;
        count += 1;
      }
    }
    done++;
  }
  return count;
}

int main() {
  int n;
  scanf("%d", &n);
  int i, a[n];
  for (i = 0; i < n; i++)
    scanf("%d", a + i);
  int count = bubbleSort(a, n);
  for (i = 0; i < (n - 1); i++)
    printf("%d ", a[i]);
  printf("%d\n%d\n", a[n - 1], count);
  return 0;
}
