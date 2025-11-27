#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UPPER 1
#define LOWER 6
#define NUM 1
#define SYM 2

char getUpperCase();
char getLowerCase();
char getNumber();
char getSymbol();

int main() {
  const int length = 10;

  int upper = 0;
  int lower = 0;
  int sym = 0;
  int num = 0;
  int type;
  int less = 9;
  char password[11];
  srand(time(NULL));

  while (less >= 0) {

    type = rand() % 4;

    switch (type) {

    case 0: { // upper
      if (upper == UPPER) {
        break;
      }
      upper++;
      password[9 - less] = getUpperCase();
      less--;
      break;
    }
    case 1: { // lower
      if (lower == LOWER) {
        break;
      }
      lower++;
      password[9 - less] = getLowerCase();
      less--;
      break;
    }
    case 2: { // num
      if (num == NUM) {
        break;
      }
      num++;

      password[9 - less] = getNumber();
      less--;
      break;
    }
    case 3: {
      if (sym == SYM) {
        break;
      }
      sym++;
      password[9 - less] = getSymbol();
      less--;
      break;
    }
    default:
      printf("in correct type");
    }
  }
  password[10] = '\0';

  printf("password:%s\n", password);

  return 0;
}

char getUpperCase() {
  int df = rand() % 26;
  return 'A' + df;
}

char getLowerCase() {
  int df = rand() % 26;
  return 'a' + df;
}

char getNumber() {
  int df = rand() % 9;
  return '0' + df;
}

char getSymbol() {
  const char syms[] = {'!', '@', '#', '-', '_', '%'};
  int df = rand() % 6;
  return syms[df];
}
