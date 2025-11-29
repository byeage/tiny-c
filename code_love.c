#include <locale.h>
#include <wchar.h>

int main() {

  setlocale(LC_CTYPE, "en_US.UTF-8");

  wprintf(L"I %lc to code.\n", 0x2665);
  return 0;
}
