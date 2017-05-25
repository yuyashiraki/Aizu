#include <stdio.h>
#include <string.h>
 
#define M 1046527
#define L 14
 
char H[M][L];
 
int char2int(char c) {
  switch (c) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;
    default: return 0;
  }
}
 
long long getKey(char str[]) {
  long long ret = 0, p = 1;
  int i;
  for(i = 0; str[i] != '\0'; i++) {
    ret += p * char2int(str[i]);
    p *= 5;
  }
  return ret;
}
 
int h1(int key) {
  return key % M;
}
 
int h2(int key) {
  return 1 + (key % (M - 1));
}
 
int find(char str[]) {
  long long key, h, i;
  key = getKey(str);
  for(i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if(strcmp(H[h], str) == 0) {
      return 1;
    } else if(strlen(H[h]) == 0) {
      return 0;
    }
  }
  return 0;
}
 
int insert(char str[]) {
  long long key, h, i;
  key = getKey(str);
  for(i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if(strcmp(H[h], str) == 0) {
      return 1;
    } else if(strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}
 
int main(void) {
  int i, n;
  char str[L], cmd[9];
  for(i = 0; i < M; i++) {
    /* initialize hash */
    H[i][0] = '\0';
  }
 
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%s %s", cmd, str);
 
    if(cmd[0] == 'i') {
      insert(str);
    } else {
      if(find(str)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }
  return 0;
}
