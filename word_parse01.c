#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char sometext[64];
  char *match;

  printf("Type Some text: ");
  fgets(sometext, 64, stdin);

  match = strtok(sometext, " ");
  while (match) {
    printf("%s\n", match);
    // 使用 NULL 来继续搜索同一个字符串
    match = strtok(NULL, " ");
  }

  printf("%c", 'A' | 0x20);
  return 0;
}
