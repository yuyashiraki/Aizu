#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000000

typedef struct __elem_ {
  int key;
  struct __elem_ *before, *next;
} __elem_t;

typedef struct __list_ {
  int size;
  __elem_t *head, *tail;
} __list_t;
__list_t list;

void deleteFirst() {
  __elem_t *t;
  t = list.head;
  list.head = list.head->next;
  list.head->before = NULL;
  free(t);
}

void deleteLast() {
  __elem_t *t;
  t = list.tail;
  list.tail = list.tail->before;
  list.tail->next = NULL;
  free(t);
}

void insert(int x) {
  if (0 == list.size) {
    list.tail = list.head = malloc(sizeof(__elem_t));
    list.tail->before = NULL;
    list.tail->next = NULL;
    list.tail->key = x;
    list.size++;
  } else {
    list.head->before = malloc(sizeof(__elem_t));
    list.head->before->next = list.head;
    list.head = list.head->before;
    list.head->before = NULL;
    list.head->key = x;
    list.size++;
  }
}

void delete(int x) {
  __elem_t *t;
  for (t = list.head; t != NULL; t = t->next) {
    if (x == t->key) {
      if (t == list.head) {
        deleteFirst();
      } else if (t == list.tail) {
        deleteLast();
      } else {
        t->before->next = t->next;
        t->next->before = t->before;
        free(t);
        list.size--;
        break;
      }
    }
  }
}

void printAll() {
  __elem_t *t;
  for (t = list.head; t != NULL; t = t->next) {
    if (list.tail == t) {
      printf("%d\n", t->key);
    } else {
      printf("%d ", t->key);
    }
  }
}

int main() {
  list.size = 0;
  int n;
  scanf("%d", &n);
  while (n--) {
    char command[MAX];
    int key;
    scanf("%s", command);
    if (!strcmp(command, "deleteFirst")) {
      deleteFirst();
    } else if (!strcmp(command, "deleteLast")) {
      deleteLast();
    } else if (!strcmp(command, "insert")) {
      scanf("%d", &key);
      insert(key);
    } else if (!strcmp(command, "delete")) {
      scanf("%d", &key);
      delete(key);
    } else if (!strcmp(command, "deleteFirst")) {
      scanf("%d", &key);
      deleteFirst();
    } else if (!strcmp(command, "deleteLast")) {
      scanf("%d", &key);
      deleteLast();
    } else {
      return 1;
    }
  }
  printAll();
  return 0;
}
