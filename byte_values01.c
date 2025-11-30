#include <stdio.h>

int main() {

  unsigned char data[256];

  for (int i = 0; i < 256; i++) {
    data[i] = i;
    printf("%02X", data[i]);
  }

  return 0;
}
