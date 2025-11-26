#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int ch;
  char c;
  srand(time(NULL));

  while ((ch = getchar()) != EOF) {

    if (isalpha(ch)) {

      if (rand() % 2 == 0) {
        putchar(toupper(ch));
      } else {
        putchar(tolower(ch));
      }
    } else {
      putchar(ch);
    }
  }
  return 0;
}
