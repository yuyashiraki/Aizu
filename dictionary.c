#include <stdio.h>

#define COMMAND_MAX 7
#define STRING_MAX 12
#define WORDS_MAX 1000001

char dic[WORDS_MAX][STRING_MAX];
int dic_size;

int main() {
  int n;
  dic_size = 0;
  scanf("%d", &n);
  while (n--) {
    char command[COMMAND_MAX];
    scanf("%s", command);
    if (strcmp(command, "insert") == 0) {
      strcpy(dic[);
    } else if (strcmp(command, "find") == 0) {
    } else {
      return 0;
    }
  }
}
