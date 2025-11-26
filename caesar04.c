#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    fprintf(stderr, "usage: ./caesar A B");
    exit(1);
  }

  char a, b;
  int shift, ch;

  a = argv[1][0];
  if (argv[1][1] != '\0') {
    fprintf(stderr, "错误，参数必须是单个字符");
  }

  b = argv[2][0];
  if (argv[2][1] != '\0') {
    fprintf(stderr, "错误，参数必须是单个字符");
  }

  shift = a - b;

  printf("a: %c b: %c shift: %d", a, b, shift);

  while ((ch = getchar()) != EOF) {
    if (isupper(ch)) {
      ch += shift;
      if (ch > 'Z')
        ch -= 26;
      if (ch < 'A')
        ch += 26;
      putchar(ch);
    } else if (islower(ch)) {
      ch += shift;
      if (ch > 'z')
        ch -= 26;
      if (ch < 'a')
        ch += 26;
      putchar(ch);
    } else {
      putchar(ch);
    }
  }
  return 0;
}
