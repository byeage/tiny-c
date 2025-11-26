#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80

int main() {
  int ch;
  int width = 0;
  char *chStr;

  while ((ch = getchar()) != EOF) {

    if (ch == '\n') {
      putchar('\n');
    } else {

      sprintf(chStr, "%02X", ch);

      width += strlen(chStr);
      if (width >= MAX_WIDTH) {
        width = 0;
        putchar('\n');
      }
      printf("%s", chStr);
    }
  }

  return 0;
}
