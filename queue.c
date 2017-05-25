#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct __queue_ {
  char name[MAX];
  int time;
  struct __queue_ *next;
} __queue_t;

int main() {
  __queue_t *head = malloc(sizeof(__queue_t));
  __queue_t *tail = head;
  tail->next = NULL;
  int n, q, now = 0;
  scanf("%d %d", &n, &q);
  scanf("%s %d", tail->name, &(tail->time));
  n--;
  while (n--) {
    tail->next = malloc(sizeof(__queue_t));
    tail = tail->next;
    tail->next = NULL;
    scanf("%s %d", tail->name, &(tail->time));
  }
  while (NULL != head) {
    if (head->time <= q) {
      now += head->time;
      printf("%s %d\n", head->name, now);
      __queue_t *temp = head;
      head = head->next;
      free(temp);
    } else {
      now += q;
      head->time -= q;
      tail->next = head;
      tail = tail->next;
      head = head->next;
      tail->next = NULL;
    }
  }
  return 0;
}
