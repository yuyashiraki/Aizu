#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int key;
  struct _node *next, *prev;
} NODE, *PHODE;
PHODE root;

void init() {
  root = (NODE *)malloc(sizeof(NODE));
  root->next = root;
  root->prev = root;
}

void insert(int key) {
  PHODE t = (NODE *)malloc(sizeof(NODE));
  t->key = key;
  t->next = root->next;
  t->prev = root;
  root->next->prev = t;
  root->next = t;
}

void deleteNode(NODE *cur) {
  cur->next->prev = cur->prev;
  cur->prev->next = cur->next;
  free(cur);
}

void _delete(int key) {
  PHODE cur = root->next;
  while (cur != root) {
    if (cur->key  == key) {
      deleteNode(cur);
      break;
    }
    else {
      cur = cur->next;
    }
  }
}

void deleteFirst() {
  if (root != root->next)
    deleteNode(root->next);
}

void deleteLast() {
  if (root != root->prev)
    deleteNode(root->prev);
}

void printNodes() {
  PHODE cur = root->next;
  while (1) {
    printf("%d", cur->key);
    if ((cur = cur->next) == root) {
      printf("\n");
      break;
    }
    else {
      printf(" ");
    }
  }
}

int main() {
  init();
  int n, f, key;
  char command[255];
  scanf("%d", &n);
  while (n--) {
    f = 0;
    scanf("%s", command);
    if ('i' == command[0]) {
      scanf("%d", &key);
      insert(key);
    }
    else {
      if ('F' == command[6]) {
        deleteFirst();
      } else if ('L' == command[6]) {
        deleteLast();
      } else {
        scanf("%d", &key);
        _delete(key);
      }
    }
  }
  printNodes();
  return 0;
}
