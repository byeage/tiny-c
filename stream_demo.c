#include <stdio.h>

int main(int argc, char *argv[]) {
  int a, b;
  printf("Type a  letter:");
  a = getchar();
  printf("Type a  letter:");
  b = getchar();

  printf("a='%c', b='%c'\n", a, b);
  return 0;
}
