#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
  
typedef struct _node {
    int key;
    struct _node *next;
    struct _node *prev;
} NODE, *PNODE;
  
PNODE root;
  
void init(void) {
    root = (NODE *)malloc(sizeof(NODE));
    root->next = root;
    root->prev = root;
}
  
void insert(int key) {
    PNODE t = (NODE *)malloc(sizeof(NODE));
    t->key = key;
    t->next = root->next;
    t->prev = root;
    root->next->prev = t;
    root->next = t;
}
  
void deleteNode(PNODE node) {
    if (node == root) {
        return;
    }
    node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node);
}
  
void _delete(int key) {
    PNODE cur = root->next;
    while (cur != root) {
        if (cur->key == key) {
            deleteNode(cur);
            return;
        }
        cur = cur->next;
    }
}
  
void deleteFirst(void) {
    deleteNode(root->next);
}
  
void deleteLast(void) {
    deleteNode(root->prev);
}
  
void printNodes(void) {
    PNODE cur = root->next;
    while (1) {
        printf("%d", cur->key);
        cur = cur->next;
        if (cur != root) {
            putchar(' ');
        }
        else {
            break;
        }
    }
    putchar('\n');
}
  
void release(void) {
    PNODE tmp, cur = root->next;
    while (cur != root) {
        tmp = cur;
        cur = cur->next;
        deleteNode(tmp);
    }
    free(root);
}
  
int main(void) {
    char cmd[100];
    int n, i, f;
    int key;
  
    init();
  
    scanf("%d", &n);
  
    f = 0;
    while (scanf("%s", cmd) > 0) {
        if (cmd[0] == 'i') {
            f = 1;
        }
        else if (cmd[0] == 'd') {
            switch (cmd[6]) {
            case '\0':
                f = 2;
                break;
            case 'F':
                deleteFirst();
                break;
            case 'L':
                deleteLast();
                break;
            }
        }
        else {
            key = atoi(cmd);
            if (f == 1) {
                insert(key);
            }
            else if (f == 2) {
                _delete(key);
            }
        }
    }
  
    printNodes();
  
    release();
  
    return 0;
}
