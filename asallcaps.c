#include <ctype.h>
#include <stdio.h>

int main() {

  int ch;
  char upper;

  while ((ch = getchar()) != EOF) {

    if (isalpha(ch)) {
      upper = (char)(ch - 0x20);
      putchar(upper);
    } else {
      putchar(ch);
    }
  }

  return 0;
}
