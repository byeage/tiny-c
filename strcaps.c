#include <stdio.h>
#include <string.h>

int main() {

  char input[] = "This is a sample string";

  /*
   * char *input = "This is a sample string";
   * 这样方式，会出现错误， 这样的input 是const， 不能修改，而strtok
   * 会修改原始的字符
   */

  char *token = strtok(input, " ");
  while (token) {

    // if (strlen(token) > 1) {
    //   token[0] += 32;
    // }

    if (token[0] > 'a' && token[0] < 'z') {

      token[0] -= 32;
    }

    puts(token);
    token = strtok(NULL, " ");
  }

  return 0;
}
