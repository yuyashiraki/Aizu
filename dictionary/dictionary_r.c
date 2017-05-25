#include <stdio.h>
#include <string.h>

#define M 1046527
#define NIL 0
#define L 14



long long getChar(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;
  else return 0;
}

long long getkey(char str[]) {
  long long sum = 0, p = 1, i;
  for (i = 0; i < strlen(str); i++) {
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

long long h1(long long key) {
  return key % M;
}

long long h2(long long key) {
  return 1 + (key % (M - 1));
}

long long h(long long key, long long i) {
  return (h1(key) + i * h2(key)) % M;
}

void insert(long long T[], long long key) {
  int i = 0;
  while (1) {
    long long j = h(key, i);
    if (T[j] == NIL) {
      T[j] = key;
      return;
    } else {
      i += 1;
    }
  }
}

int search(long long T[], long long key) {
  int i = 0;
  while (1) {
    long long j = h(key, i);
    if (T[j] == NIL) {
      return 0;
    } else if (T[j] == key) {
      return 1;
    } else {
      i += 1;
    }
  }
}

int main() {
  int i, n;
  long long T[M] = {NIL};
  char str[L], com[9];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", com, str);
    long long key = getkey(str);
    if (com[0] == 'i') {
      insert(T, key);
    } else {
      int r = search(T, key);
      if (r) printf("yes\n");
      else printf("no\n");
    }
  }
  return 0;
}
