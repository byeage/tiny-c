#include <locale.h>
#include <wchar.h>

int main() {

  wchar_t yen = 0xa5;

  setlocale(LC_CTYPE, "en_US.UTF-8");
  wprintf(L"This will be %lc500\n", yen);

  return 0;
}
