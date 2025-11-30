#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *s) {
  int len, i;
  char *reversed;

  len = 0;

  while (*s) {
    len++;
    s++;
  }

  reversed = malloc(sizeof(char) * len);

  if (reversed == NULL) {
    fprintf(stderr, "Unabled to allocate memory\n");
    exit(1);
  }
  s--;
  i = 0;

  while (len) {
    reversed[i] = *s;
    i++;
    len--;
    s--;
  }
  reversed[i] = '\0';

  return reversed;
}

char *left(char *s, int len) {

  char *buf;
  int x;

  buf = malloc(sizeof(char) * (len + 1));

  if (buf == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    exit(1);
  }

  for (x = 0; x < len; x++) {
    if (*(s + x) == '\n') {
      break;
    }
    *(buf + x) = *(s + x);
  }
  *(buf + x) = '\n';

  return buf;
}

char *right(char *s, int len) {

  char *buf;
  char *start;
  int str_len;
  str_len = 0;
  int x;

  buf = malloc(sizeof(char) * (len + 1));

  start = s;

  while (*start != '\0') {
    start++;
  }

  start -= len;

  if (start < s) {
    exit(1);
  }

  for (x = 0; x < len; x++) {
    *(buf + x) = *(start + x);
  }

  *(buf + x) = '\0';

  return buf;
}

char *mid(char *s, int offset, int len) {

  char *buf;
  int x;

  buf = (char *)malloc(sizeof(char) * (len + 1));

  if (buf == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    exit(1);
  }

  for (x = 0; x < len; ++x) {
    *(buf + x) = *(s + offset - 1 + x);
    if (*(buf + x) == '\0') {
      break;
    }
  }
  *(buf + x) = '\0';

  return buf;
}

int strsplit(char *org, int offset, char **s1, char **s2) {

  int len;
  len = strlen(org);

  if (offset > len) {
    return 0;
  }

  *s1 = malloc(sizeof(char) * (offset + 1));
  *s2 = malloc(sizeof(char) * (len - offset + 1));

  if (s1 == NULL || s2 == NULL) {
    return 0;
  }

  strncpy(*s1, org, offset);
  strncpy(*s2, org + offset, len - offset);

  return 1;
}

char *strinsert(char *org, char *ins, int offset) {

  char *new;
  int size, index, append;
  size = strlen(org) + strlen(ins) + 1;
  new = malloc(size * sizeof(char));
  int idx;

  idx = 0;

  for (index = 0; index < offset; index++) {
    *(new + idx++) = *(org + index);
  }
  for (index = 0; index < strlen(ins); index++) {
    *(new + idx++) = *(ins + index);
  }
  for (index = 0; index < strlen(org) - offset; index++) {
    *(new + idx++) = *(org + offset + index);
  }

  *(new + idx) = '\0';

  return new;
}

int main() {
  char test[] = "Well, this is another mess!";

  /* char *rev = strrev(test); */

  /* printf("reV:%s\n", rev); */
  /* printf("left 2:%s\n", left(test, 2)); */
  /* printf("right 2:%s\n", right(test, 2)); */

  printf("str insert: %s", strinsert(test, "fine ", 22));

  return 0;
}
