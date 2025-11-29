#include <ctype.h>
#include <stdio.h>
#include <string.h>

void toMorse(char c) {
  const char *morse_alpha[] = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
  const char *morse_digit[] = {"-----", ".----", "..---", "...--", "....-",
                               ".....", "-....", "--...", "---..", "----."};

  if (isalpha(c)) {
    c = toupper(c);
    printf("%s", morse_alpha[c - 'A']);
  } else if (isdigit(c)) {
    printf("%s", morse_digit[c - '0']);
  } else if (c == ' ' || c == '\n') {
    putchar('\n');
  } else {
    return;
  }
}

int main() {

  char ch;

  while ((ch = getchar()) != EOF) {
    toMorse(ch);
  }

  return 0;
}
