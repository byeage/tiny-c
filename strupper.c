
#include <stdio.h>

void strupper(char *s) {

  while (*s) {

    if (*s >= 'a' && *s <= 'z') {
      *s &= 0xdf;
    }

    s++;
  }
}

void strlower(char *s) {

  while (*s) {

    if (*s >= 'A' && *s <= 'Z') {
      *s |= 0x20;
    }
    s++;
  }
}

int main() {
  char string[] = "Random STRING samle 123@#$";

  printf("Original string:%s\n", string);

  strupper(string);

  printf("Uppercase string: %s\n", string);

  strlower(string);

  printf("Lowercase string: %s\n", string);

  return 0;
}
