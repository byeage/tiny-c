#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void toArr(int arr[], long i) {
  long t;
  int index = 0;
  t = i;
  arr[index++] = t % 26;

  t = i / 26;

  while (t != 0) {
    arr[index++] = t % 26;
    t = t / 26;
  }
}

void ptrArr(int arr[]) {

  for (int i = 0; i < 8; ++i) {
    printf("%c", 'a' + arr[i]);
  }
  putchar('\n');
}

int main() {

  time_t now;

  time(&now);

  printf("Start at: %ld\n", now);

  time_t prev = now;

  for (long i = 0; i < pow(26, 8); ++i) {
    int inc[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    toArr(inc, i);
    /* ptrArr(inc); */
    char start[] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', '\0'};

    for (int n = 0; n < 8; n++) {
      start[n] = 'a' + inc[n];
      /* printf("%s\n", start); */
      if (strcmp(start, "password") == 0) {
        printf("break down\n");
        time(&now);
        printf("end at: %ld, during: %ld", now, now - prev);
        exit(0);
      }
    }
  }
}
