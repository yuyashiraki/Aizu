#include <stdio.h>
#include <ctype.h>
 
#define STACK_SIZE 110
 
int stack[STACK_SIZE];
int stack_pos = 0;
 
int pop() {
  return stack[--stack_pos];
}
 
void push(int a) {
  stack[stack_pos++] =a;
}
 
int empty() {
  return stack_pos;
}
 
int main() {
  char str[128];
  int a, b;
  while(scanf("%s", str) != EOF) {
    if(isdigit(str[0])) {
      push(atoi(str));
    } else {
      b = pop();
      a = pop();
      switch(str[0]) {
      case '+':
        push(a+b);
        break;
      case '-':
        push(a-b);
        break;
      case '*':
        push(a*b);
        break;
      }
    }
  }
  printf("%d\n", pop());
  return 0;
}
