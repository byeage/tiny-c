#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main() {
  setlocale(LC_CTYPE, "en_US.UTF-8");

  FILE *fp;
  const wchar_t alpha = 0x391;
  const wchar_t omega = 0x3a9;
  const wchar_t no_sigma = 0x3a2;
  wchar_t a;

  fp = fopen("apphabet.wtxt", "wr");
  wprintf(L"Writing the Greek alphabet...\n");

  for (a = alpha; a <= omega; a++) {
    if (a == no_sigma) {
      continue;
    }
    fputwc(a, fp);
    fputwc(a, stdout);
  }

  fputwc('\n', fp);

  fclose(fp);

  return 0;
}
