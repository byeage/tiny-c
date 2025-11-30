#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Format: dumpfile filename\n");
    exit(1);
  }

  char *filename;
  FILE *fp;

  filename = argv[1];
  fp = fopen(filename, "r");

  if (fp == NULL) {
    fprintf(stderr, "Unable to open file '%s'\n", filename);
    exit(1);
  }

  const int length = 16;
  char ch;
  int index;
  unsigned char buffer[16];
  int offset;
  offset = 0;
  index = 0;
  while (!feof(fp)) {
    ch = fgetc(fp);
    if (ch == EOF) {
      if (index != 0) {
        line_out(offset, index, buffer);
      }
      break;
    }

    buffer[index] = ch;
    index++;

    if (index == length) {
      line_out(offset, length, buffer);
      offset += length;
      index = 0;
    }
  }

  return 0;
}
