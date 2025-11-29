#include <locale.h>
#include <wchar.h>

int main() {

  wchar_t mode;

  setlocale(LC_CTYPE, "en_US.UTF-8");

  wprintf(L"What is your mode? ");
  mode = getwchar();
  wprintf(L"I feel %lc, too!", mode);

  return 0;
}
