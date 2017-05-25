#include <stdio.h>

int main() {
    int n, min, a;
    scanf("%d", &n);
    int r1, r2;
    scanf("%d", &r1);
    min = r1;
    scanf("%d", &r2);
    a = r2 - r1;
    if (min > r2)
      min = r2;
    n -= 2;
    while (n--) {
      scanf("%d", &r1);
      if (a < (r1 - min))
        a = r1 - min;
      if (min > r1)
        min = r1;
    }
    printf("%d\n", a);
    return 0;
}
