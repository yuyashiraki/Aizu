#include <stdio.h>

int pn(int x) {
    int i;
    for (i = 2; i < x; i++) {
        if (!(x%i))
            return 0;
    }
    return 1;
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        if (pn(x))
            count++;
    }
    printf("%d\n", count);
    return 0;
}
