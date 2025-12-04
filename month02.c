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

  if (argc < 3) {
    fprintf(stderr, "usage: command year month");
    exit(1);
  }

  int pyear;
  int pmonth;

  pyear = atoi(argv[1]);
  pmonth = atoi(argv[2]);

  printf("input Year: %d,month: %d\n", pyear, pmonth);

  const char *months[] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};
  int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  time_t now;
  int month, thatday, weekday, year, first, day, d, today;

  struct tm date;
  struct tm *current;
  date.tm_mon = pmonth - 1;
  date.tm_year = pyear - 1900;
  date.tm_mday = 1;
  date.tm_hour = 0;
  date.tm_min = 0;
  date.tm_sec = 0;
  date.tm_isdst = -1; // 禁止 DST 干扰

  mktime(&date);

  time(&now);
  current = localtime(&now);

  thatday = date.tm_mday;
  month = date.tm_mon;
  weekday = date.tm_wday;
  year = date.tm_year + 1900;
  mdays[1] = february(year);
  first = thefirst(weekday, thatday);

  char str[100];

  sprintf(str, "%s %d", months[month], year);
  center(str, 4 * 7);

  printf("Sun Mon Tue Wed The Fri Sat\n");

  day = 1;
  today = current->tm_mday;

  while (day <= mdays[month]) {
    for (d = 0; d < 7; d++) {
      if (d < first && day == 1) {
        printf("    ");
      } else {
        if (day == today && (current->tm_year == date.tm_year) &&
            (current->tm_mon == date.tm_mon)) {
          printf("[%2d]", day);
        } else {
          printf(" %2d ", day);
        }
        day++;
        if (day > mdays[month]) {
          break;
        }
      }
    }
    putchar('\n');
  }
  return 0;
}
