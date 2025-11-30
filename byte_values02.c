#include <stdio.h>

void line_out(int offset, int length, unsigned char *data) {
  int a;

  printf("%05X ", offset);

  for (a = 0; a < length; a++) {
    printf(" %02X", *(data + a));
    if ((a + 1) % 8 == 0)
      putchar(' ');
  }

  putchar(' ');
  for (a = 0; a < length; a++) {
    if (*(data + a) >= ' ' && *(data + a) <= '~')
      putchar(*(data + a));
    else
      putchar(' ');
  }

  putchar('\n');
}

int main() {

  unsigned char data[256];

  for (int i = 0; i < 256; i++) {
    data[i] = i;
  }

  for (int i = 0; i < 256; i += 16) {
    line_out(i, 16, &data[i]);
  }

  return 0;
}
