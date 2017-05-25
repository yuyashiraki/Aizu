#include <stdio.h>
#include <string.h>

void insertionSort(int e[], const int n) {
    int i;
    for (i = 0; i < n; i++) {
        int v = e[i];
        int j = i - 1;
        while ((j >= 0) && (e[j] > v)) {
            e[j + 1] = e[j];
            j -= 1;
        }
        e[j + 1] = v;
        int k;
        printf("%d", e[0]);
        for (k = 1; k < n; k++) {
            printf(" %d", e[k]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    char nc[100], ec[400];
    fgets(nc, 100, stdin);
    sscanf(nc, "%d", &n);
    fgets(ec, 400, stdin);
    char *tok;
    int e[n];
    tok = strtok(ec, " ");
    int i;
    for (i = 0; i < n; i++) {
        sscanf(tok, "%d", e + i);
        tok = strtok(NULL, " ");
    }
    insertionSort(e, n);
    return 0;
}
