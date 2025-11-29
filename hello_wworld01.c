#include <locale.h>
#include <wchar.h>

int main() {
  setlocale(LC_ALL, "zh_CN.UTF-8");
  wprintf(L"hello, wide world!\n");
  putwchar(L'你');

  return 0;
}
