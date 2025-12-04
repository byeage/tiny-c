#define _POSIX_C_SOURCE 199309L
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  putenv("TZ=GTM");
  tzset();
  time_t epoch = 0;
  printf("Time is %s\n", ctime(&epoch));
  return 0;
}
