#include <stdio.h>

int gcb(int x, int y) {
    if (0 == (x % y))
        return y;
    else
        return gcb(y, x%y);
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", x > y ? gcb(x, y) : gcb(y, x));
    return 0;
}
