#include <stdio.h>

int main() {

  int f, b;

  for (f = 0; f < 8; f++) {

    for (b = 0; b < 8; b++) {

      printf("\x1b[%2d;%2dm%2d:%2d", f + 30, b + 40, f + 3, b + 40);
    }
    printf("\x1b[0m\n");
  }

  return 0;
}
