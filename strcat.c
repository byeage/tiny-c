#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strappend(char *dest, char *src) {

  char *str = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 1));
  int all = 0;
  for (int i = 0; i < strlen(dest); i++) {
    str[all++] = dest[i];
  }
  for (int i = 0; i < strlen(src); i++) {
    str[all++] = src[i];
  }

  str[all] = '\0';

  return str;
}
int main() {

  char s1[] = "this is anohter ";
  char s2[] = "fine mess!";

  char *s3;

  s3 = strappend(s1, s2);

  printf("%s\n", s3);

  return 0;
}
