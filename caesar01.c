//================================================================================
// carser
//================================================================================

#include <ctype.h>
#include <stdio.h>

int main() {

  int ch;

  while ((ch = getchar()) != EOF) {
    if (isalpha(ch)) {
      if (toupper(ch) >= 'A' && toupper(ch) <= 'M') {
        ch += 13;
      } else {
        ch -= 13;
      }
      putchar(ch);
    } else {
      putchar(ch);
    }
  }

  return 0;
}
