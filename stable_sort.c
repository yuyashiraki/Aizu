#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct _card_ {
  char suit;
  int val;
} _card_t;

int pos(_card_t target, _card_t C[]) {
  int ret = 0;
  while (1) {
    if ((C[ret].suit == target.suit) && (C[ret].val == target.val))
      return ret;
    ret++;
  }
}

bool isStable(_card_t C[], _card_t C1[], int n) {
  int i;
  for (i = 0; i < n; i++)
    if ((C1[i].val == C1[i + 1].val) && (pos(C1[i], C) > pos(C1[i + 1], C))) {
      return false;
    }
  return true;
}

void BubbleSort(_card_t C[], int n) {
  int i;
  _card_t C1[n];
  memcpy(C1, C, sizeof(_card_t) * n);
  for (i = 0; i < n; i++) {
    int j;
    for (j = n - 1; j >= i; j--) {
      if (C1[j].val < C1[j - 1].val) {
        _card_t temp = C1[j]; C1[j] = C1[j - 1]; C1[j - 1] = temp;
      }
    }
    printf("%c%d", C1[i].suit, C1[i].val);
    if (i != (n - 1))
      printf(" ");
  }
  printf("\n%s\n", isStable(C, C1, n) ? "Stable" : "Not stable");
}

void SelectionSort(_card_t C[], int n) {
  int i;
  _card_t C1[n];
  memcpy(C1, C, sizeof(_card_t) * n);
  for (i = 0; i < n; i++) {
    int minj = i, j;
    for (j = i; j < n; j++) {
      if (C1[j].val < C1[minj].val)
        minj = j;
    }
    _card_t temp = C1[i]; C1[i] = C1[minj]; C1[minj] = temp;
    printf("%c%d", C1[i].suit, C1[i].val);
    if (i != (n - 1))
      printf(" ");
  }
  printf("\n%s\n", isStable(C, C1, n) ? "Stable" : "Not stable");
}

int main() {
  int i, n;
  scanf("%d\n", &n);
  _card_t C[n];
  for (i = 0; i < n; i++) {
    if (i != n - 1)
      scanf("%c%d ", &C[i].suit, &C[i].val);
    else
      scanf("%c%d", &C[i].suit, &C[i].val);
  }
  BubbleSort(C, n);
  SelectionSort(C, n);
  return 0;
}
