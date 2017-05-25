#include <stdio.h>
#define MAX 20000

typedef struct __area_each_ {
  int cur, area;
} __area_each_t;

int main() {
  int cur = 0, stack1_size = 0, stack1[MAX], stack2_size = 0, area_all = 0;
  __area_each_t stack2[MAX];
  char c;
  while (scanf("%c", &c)) {
    int f = 0;
    cur++;
    switch (c) {
      case '\\':
        stack1[stack1_size] = cur;
        stack1_size++;
        break;
      case '/':
        if (stack1_size) {
          area_all += (cur - stack1[--stack1_size]);
          __area_each_t area_each;
          area_each.cur = stack1[stack1_size];
          area_each.area = cur - stack1[stack1_size];
          while (stack2_size) {
            if (stack1[stack1_size] < stack2[stack2_size - 1].cur) {
              stack2_size--;
              area_each.area += stack2[stack2_size].area;
            }
            else {
              break;
            }
          }
          stack2[stack2_size] = area_each;
          stack2_size++;
        }
        break;
      case '_':
        break;
      case '\n':
      default:
        f = 1;
        break;
    }
    if (f)
      break;
  }
  printf("%d\n", area_all);
  int i;
  printf("%d", stack2_size);
  for (i = 0; i < stack2_size; i++) {
    printf(" %d", stack2[i].area);
  }
  printf("\n");
  return 0;
}
