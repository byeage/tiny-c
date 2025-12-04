#include <stdio.h>
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

int main() {

  const char *months[] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};
  int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  time_t now;
  struct tm *date;
  int month, today, weekday, year, first, day, d;

  time(&now);
  date = localtime(&now);

  today = date->tm_mday;
  month = date->tm_mon;
  weekday = date->tm_wday;
  year = date->tm_year + 1900;
  mdays[1] = february(year);
  first = thefirst(weekday, today);

  char str[100];

  sprintf(str, "%s %d", months[month], year);
  center(str, 4 * 7);

  printf("Sun Mon Tue Wed The Fri Sat\n");

  day = 1;

  while (day <= mdays[month]) {
    for (d = 0; d < 7; d++) {
      if (d < first && day == 1) {
        printf("    ");
      } else {
        if (day == today) {
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
