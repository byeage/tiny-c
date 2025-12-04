#define _POSIX_C_SOURCE 199309l
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int february(int year) {

  if (year % 400 == 0) {
    return 29;
  }

  if (year % 100 == 0) {
    return 28;
  }
  if (year % 4 != 0) {
    return 28;
  }

  return 29;
}

int thefirst(int wday, int day) { return wday - (day % 7) + 1; }

void center(char *text, int width) {
  int offset = (width - (int)strlen(text)) / 2;
  for (int i = 0; i < offset; ++i) {
    putchar(' ');
  }
  puts(text);
}

int main(int argc, char *argv[]) {

  const char *months[] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",

                          "September", "October",  "November", "December"};
  int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  struct tm date;
  int month, weekday, year, day, dow;

  const int output_width = 27;
  char title[output_width];
  if (argc == 2) {
    date.tm_year = atoi(argv[1]) - 1900;
  } else {

    time_t now;
    time(&now);
    struct tm *current = localtime(&now);

    date.tm_year = current->tm_year;
  }

  date.tm_mon = 0;
  date.tm_mday = 1;
  date.tm_hour = 0;
  date.tm_min = 0;
  date.tm_sec = 0;
  date.tm_isdst = -1; // 禁止 DST 干扰
  putenv("TZ=GMT");
  tzset();
  mktime(&date);

  weekday = date.tm_wday;
  year = date.tm_year + 1900;
  mdays[1] = february(year);

  dow = 0;

  for (month = 0; month < 12; ++month) {

    sprintf(title, "%s %d", months[month], year);
    center(title, output_width);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    day = 1;

    while (day <= mdays[month]) {
      if (dow < weekday && day == 1) {
        printf("    ");
        dow++;
      } else {
        printf(" %2d ", day);
        dow++;
        if (dow > 6) {
          dow = 0;
          putchar('\n');
        }

        day++;
        if (day > mdays[month]) {
          break;
        }
      }
    }
    weekday = dow;
    dow = 0;
    printf("\n\n");
  }

  return 0;
}
