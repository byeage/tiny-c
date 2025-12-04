#include <stdio.h>
#include <time.h>

int main() {

  time_t now;
  struct tm *today;

  int month, day, year, weekday;

  now = time(NULL);
  today = localtime(&now);

  month = today->tm_mon + 1;
  day = today->tm_mday;
  weekday = today->tm_wday;
  year = today->tm_year + 1900;

  char *week_names[] = {
    "Sun", "Mon", "Tue", "Wed", "Thus", "Fri", "Sat",
  };
  char *month_names[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  printf("Today is %s, %s %d %d\n", week_names[weekday], month_names[month - 1],
         day, year);

  return 0;
}
