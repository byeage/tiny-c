#include <stdio.h>

int tohex(char ch);

int main() {

  int ch;
  int a, b;

  while (1) {
    ch = getchar();

    if (ch == EOF)
      break;
    a = tohex(ch);
    if (a < 0)
      break;

    a <<= 4;

    ch = getchar();
    if (ch == EOF)
      break;
    b = tohex(ch);
    if (b < 0)
      break;
    putchar(a + b);
  }
}

int tohex(char ch) {

  if (ch > '0' && ch < '9') {
    return ch - '0';
  } else if (ch >= 'A' && ch <= 'F') {
    return ch - 'A' + 0xA;
  }
  return -1;
}
