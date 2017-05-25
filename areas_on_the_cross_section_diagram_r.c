#include <stdio.h>
#include <string.h>

typedef struct _data {
  int pos, area;
} _data_t;

char str[20001];
int i, n, U, T, A, sum, u[20000];
_data_t X, B, t[20000];

void init() {
  U = T = sum = 0;
}

void push(int pos) {
  u[U++] = pos;
}

int pop() {
  return u[--U];
}

void T_push(_data_t data) {
  t[T++] = data;
}

_data_t T_pop() {
  return t[--T];
}

_data_t makeData(int area, int pos) {
  _data_t ret;
  ret.area = area;
  ret.pos = pos;
  return ret;
}

int main() {
  scanf("%s", str);
  n = strlen(str);
  init();
  for (i = 0; i < n; i++) {
    if ('\\' == str[i]) push(i);
    else if ('/' == str[i]) {
      if (!U) continue;
      A = pop();
      X = makeData(i - A, A);
      sum += i - A;
      while (T) {
        B = T_pop();
        if (B.pos < A) {
          T_push(B);
          break;
        }
        X.area += B.area;
      }
      T_push(X);
    }
  }
  printf("%d\n%d", sum, T);
  for (i = 0; i < T; i++) {
    printf(" %d", t[i].area);
  }
  printf("\n");
  return 0;
}
