#include <locale.h>
#include <stdio.h>
#include <wchar.h>

int main() {

  const int size = 32;

  wchar_t input[size];

  setlocale(LC_ALL, "zh_CN.UTF-8");

  wprintf(L"Type sime fancy text:");
  fgetws(input, size, stdin);
  wprintf(L"you typed: %ls\n", input);

  return 0;
}
