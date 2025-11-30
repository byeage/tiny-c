#include <stdio.h>
#include <string.h>

int main() {
  char s[] = "0123456789";
  printf("%s is %lu chareacters long\n", s, strlen(s));
  printf("%s occupies %zu bytes of stroage\n", s, sizeof(s));
  return 0;
}
