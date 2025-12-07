#define _POSIX_C_SOURCE 199309l
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COLUMNS 3
#define LEAP_FEB_DAYS 29
#define NORM_FEB_DAYS 28
#define GAP 4

#define COLOR 30
#define BG_COLOR 40
#define RESET "\x1b[0m"

/**
 * - 普通年份（非整百年份）
 * 能被 4 整除但不能被 100 整除的年份为闰年。
 * - 整百年份
 * 能被 400 整除的年份为闰年。
 */
int februray_days(int year) {
  if (year % 400 == 0) {
    return LEAP_FEB_DAYS;
  }
  if (year % 100 == 0) {
    return NORM_FEB_DAYS;
  }

  if (year % 4 != 0) {
    return NORM_FEB_DAYS;
  }

  return LEAP_FEB_DAYS;
}

int the_first(int wday, int day) {

  int i = wday - (day % 7) + 1;

  return i;
}

void center(const char *text, int width) {
  int offset = (width - (int)strlen(text)) / 2;

  for (int i = 0; i < offset; i++) {
    putchar(' ');
  }

  while (*text) {
    putchar(*text);
    text++;
  }

  for (int i = 0; i < width - offset - (int)strlen(text); i++) {
    putchar(' ');
  }
}

void printgap(int col) {
  if (col != 0) {
    for (int i = 0; i < GAP; i++) {
      putchar(' ');
    }
  }
}

int main() {

  const int output_width = 27;
  const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                          "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  const char *week_names[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  int day_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int first_day_in_week[12];
  int start_in_month[12];

  time_t now;
  struct tm *date;
  int day;

  time(&now);
  date = localtime(&now);

  struct tm cur;

  day_in_months[1] = februray_days(date->tm_year + 1900);

  for (int i = 0; i < 12; i++) {

    cur.tm_year = date->tm_year;
    cur.tm_mon = i;
    cur.tm_mday = 1;
    cur.tm_hour = 0;
    cur.tm_min = 0;
    cur.tm_sec = 0;
    cur.tm_isdst = -1; // 禁止 DST 干扰扰
    putenv("TZ=GMT");
    tzset();
    mktime(&cur);
    first_day_in_week[i] = cur.tm_wday;
  }

  for (int i = 0; i < 12; i += COLUMNS) {
    // month names
    for (int j = 0; j < COLUMNS; j++) {
      printgap(j);
      center(months[i + j], output_width);
    }
    putchar('\n');

    // week names
    for (int i = 0; i < COLUMNS; i++) {
      printgap(i);
      for (int j = 0; j < 7; j++) {
        printf("%s ", week_names[j]);
      }
    }
    putchar('\n');

    // first row
    for (int j = 0; j < COLUMNS; j++) {
      printgap(j);
      day = 1;
      for (int col = 0; col < 7; col++) {
        if (col < first_day_in_week[i + j]) {
          if (col % 2 == 0) {
            printf("\x1b[%d;%dm%s%s", COLOR + 7, BG_COLOR + 4, "    ", RESET);
          } else {
            printf("\x1b[%d;%dm%s%s", COLOR + 1, BG_COLOR + 7, "    ", RESET);
          }

        } else {
          if (col % 2 == 0) {
            printf("\x1b[%d;%dm %2d %s", COLOR + 7, BG_COLOR + 4, day++, RESET);
          } else {
            printf("\x1b[%d;%dm %2d %s", COLOR + 1, BG_COLOR + 7, day++, RESET);
          }
          start_in_month[i + j] = day;
        }
      }
    }

    putchar('\n');

    printf("    ");

    for (int n = 0; n < 5; n++) {
      for (int j = 0; j < COLUMNS; j++) {
        printgap(j);
        for (int col = 0; col < 7; col++) {
          if (start_in_month[i + j] <= day_in_months[i + j]) {

            if (col % 2 == 0) {
              printf("\x1b[%d;%dm %2d %s", COLOR + 7, BG_COLOR + 4,
                     start_in_month[i + j]++, RESET);
            } else {
              printf("\x1b[%d;%dm %2d %s", COLOR + 1, BG_COLOR + 7,
                     start_in_month[i + j]++, RESET);
            }
          } else {
            if (col % 2 == 0) {
              printf("\x1b[%d;%dm%s%s", COLOR + 7, BG_COLOR + 4, "    ", RESET);
            } else {
              printf("\x1b[%d;%dm%s%s", COLOR + 1, BG_COLOR + 7, "    ", RESET);
            }
          }
        }
      }
      putchar('\n');
    }
  }

  return 0;
}
