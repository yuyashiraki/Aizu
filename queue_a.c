#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct __elem_ {
  char name[MAX];
  int time;
} __elem_t;

struct __queue_ {
  __elem_t *ring_buf;
  int size, head, tail;
} Q;

void initialize(int size) {
  Q.size = size;
  Q.ring_buf = malloc(sizeof(__elem_t) * (size + 1));
  Q.head = 0;
  Q.tail = 0;
}

int isFull() {
  if (((Q.head - Q.tail) == 1) || ((Q.head == 0) && (Q.tail == Q.size))) {
    return 1;
  }
  return 0;
}

int isEmpty() {
  if (Q.head == Q.tail)
    return 1;
  return 0;
}

void enqueue(__elem_t e) {
  if (isFull())
    return;
  strcpy(Q.ring_buf[Q.tail].name, e.name);
  Q.ring_buf[Q.tail].time = e.time;
  if (Q.tail == Q.size) {
    Q.tail = 0;
  } else {
    Q.tail++;
  }
}

__elem_t dequeue() {
  __elem_t ret;
  if (isEmpty()) {
    return ret;
  }
  ret = Q.ring_buf[Q.head];
  if (Q.head == Q.size) {
    Q.head = 0;
  } else {
    Q.head++;
  }
  return ret;
}


int main() {
  int n, q, now = 0;
  scanf("%d %d", &n, &q);
  initialize(n);
  __elem_t e;
  while (n--) {
    scanf("%s %d", e.name, &(e.time));
    enqueue(e);
  }
  while (!isEmpty()) {
    e = dequeue();
    if (e.time <= q) {
      now += e.time;
      printf("%s %d\n", e.name, now);
    } else {
      now += q;
      e.time -= q;
      enqueue(e);
    }
  }
  return 0;
}
