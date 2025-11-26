#include <stdio.h>

char *binString(char a);

int main() {
  char ch = 'A';
  printf("%c: %s", ch, binString(ch));

  return 0;
}

char *binString(char a) {

  static char b[9];

  int i;
  i = 0;

  while (i < 8) {
    b[i] = a & 0x80 ? '1' : '0';
    a <<= 1;
    i++;
  }

  b[i] = '\0';

  return b;
}
