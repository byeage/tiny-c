#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTE_PER_LINE 18
#define LENGTH (BYTE_PER_LINE * 3 + 1)

int main() {

  char line[LENGTH];
  int x, ch, hex;
  char *r;
  int values[BYTE_PER_LINE];
  int index, checksum;

  x = 0;

  r = fgets(line, LENGTH, stdin);

  if (r == NULL || strncmp(line, "HEX ENCODE", 10) != 0) {
    fprintf(stderr, "Invalid HEX ENCODE data\n");
    exit(1);
  }

  if (r == NULL || strncmp(line, "HEX ENCODE v2.0", 15) != 0) {
    fprintf(stderr, "Invalid HEX ENCODE version\n");
    exit(1);
  }

  while ((ch = getchar()) != EOF) {
    line[x] = ch;
    x++;

    if (ch == '\n' || x == LENGTH) {
      if (line[x - 1] == '\n') {
        line[x - 1] = '\0';
      } else {
        line[x] = '\0';
      }

      if (strncmp(line, "HEX ENCODE END", 13) == 0) {
        break;
      }

      r = strtok(line, " ");

      index = 0;
      checksum = 0;
      while (r) {

        sscanf(r, "%02X", &hex);
        values[index++] = hex;
        r = strtok(NULL, " ");
      }

      // checksum
      for (int i = 0; i < index - 1; i++) {
        checksum += values[i];
      }

      if ((checksum % 0x100) != values[index - 1]) {
        fprintf(stderr, "invalid checksum %02X, %02X", checksum % 0x100,
                values[index - 1]);
      }

      for (int i = 0; i < index - 1; i++) {
        printf("%c", values[i]);
      }

      x = 0;
    }
  }

  return 0;
}
