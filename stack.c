#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 110

typedef struct __stack_ {
  int stack[MAX];
  int top;
} __stack_t;
__stack_t S;

void initialize() {
  S.top = 0;
}

int isEmpty() {
  return 0 == S.top;
}


int isFull() {
  return S.top >= (MAX - 1);
}

void push(const int x) {
  if (isFull()) {
    printf("Error: Overflow\n");
    return;
  }
  S.stack[++S.top] = x;
}

int pop() {
  if (isEmpty()) {
    printf("Error: Underflow\n");
    return 0;
  }
  return S.stack[S.top--];
}

void showStack() {
  int i;
  for (i = 1; i < S.top; i++) {
    printf("%d ", S.stack[i]);
  }
  printf("%d\n", S.stack[S.top]);
}

int main() {
  char c[128];
  while (scanf("%s", c) != EOF) {
    if (isdigit(c[0])) {
      push(atoi(c));
    } else {
      int a, b;
      a = pop();
      b = pop();
      switch (c[0]) {
        case '+':
          push(a + b);
          break;
        case '-':
          push(b - a);
          break;
        case '*':
          push(a * b);
          break;
        default:
          return 1;
          break;
      }
    }
//    showStack();
  }
  printf("%d\n", pop());
  return 0;
}
