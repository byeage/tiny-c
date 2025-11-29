#include <locale.h>
#include <stdio.h>

int main() {

  char *locale;
  locale = setlocale(LC_ALL, "");

  printf("The current locale is %s\n", locale);

  return 0;
}
