#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isterm(char *term) {
  const char *nato[] = {
      "Alfa",   "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliett", "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};
  int x;
  const char *n, *t;

  for (x = 0; x < 26; ++x) {
    n = nato[x];
    t = term;

    while (*n != '\0') {
      // 转换成小写字母
      if ((*n | 0x20) != (*t | 0x20)) {

        break;
      }
      n++;
      t++;
    }

    if (*n == '\0') {
      return *nato[x];
    }
  }
  return '\0';
}

int main(int argc, char *argv[]) {
  char *match;
  char ch;
  char phrase[64];

  printf("NATO word or phrase: ");

  FILE *n;
  if (argc < 2) {
    fprintf(stderr, "Please supply a text file argument\n");
    exit(1);
  }

  n = fopen(argv[1], "r");

  //////////////////////////////////////////////////
  // while (!feof(n)) {                           //
  //   fgets(phrase, 64, n);                      //
  //   match = strtok(phrase, " ,.!?=()[]{}'\""); //
  //   while (match) {                            //
  //     if ((ch = isterm(match)) != '\0') {      //
  //       putchar(ch);                           //
  //     }                                        //
  //     match = strtok(NULL, " ,.!?=()[]{}'\""); //
  //   }                                          //
  // }                                            //
  //////////////////////////////////////////////////

  int offset;
  char word[64];
  offset = 0;

  while ((ch = fgetc(n)) != EOF) {

    if (isalpha(ch)) {
      word[offset] = ch;
      offset++;

      if (offset >= 64) {
        fprintf(stderr, "Buffer overlfow\n");
        return 1;
      }
    } else {
      if (offset > 0) {
        word[offset] = '\0';
        putchar(isterm(word));
        offset = 0;
      }
    }
  }

  putchar('\n');

  fclose(n);
  return 0;
}
