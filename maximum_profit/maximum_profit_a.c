#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int i, r[n];
  for (i = 0; i < n; i++)
    scanf("%d", r + i);
  int min = r[0] > r[1] ? r[1] : r[0], ans = r[1] - r[0];
  for (i = 2; i < n; i++) {
    if (ans < (r[i] - min))
      ans = r[i] - min;
    if (min > r[i])
      min = r[i];
  }
  printf("%d\n", ans);
  return 0;
}
