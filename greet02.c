#include<stdio.h>

int main(int argc, char** argv) {
  if (argc < 2) {
    puts("Hello, you hansome beast!");
  } else {
    printf("hello, %s\n", argv[1]);
  }
 
  return 0;
}
