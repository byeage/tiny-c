#include <stdio.h>
#include <time.h>

int moon_phase(int year, int month, int day);

int main(int argc, char *argv[]) {
  char *phase[8] = {
      "waxing crescent", "at first quater", "waxing gibbous",   "full",
      "waning gibbous",  "at last quater",  "wanning crescent", "new"};

  time_t now;
  struct tm *clock;
  int phase_state;
  int year;
  int month;
  int day;

  time(&now);

  clock = localtime(&now);
  year = clock->tm_year + 1900;
  month = clock->tm_mon;
  day = clock->tm_mday;
  phase_state = moon_phase(year, month, day);

  printf("current moon phase is %s", phase[phase_state]);

  return 0;
}

int moon_phase(int year, int month, int day) {
  int d, g, e;

  d = day;
  if (month == 2)
    d += 31;
  else if (month > 2)
    d += 59 + (month - 3) * 30.6 + 0.5;
  g = (year - 1900) % 19;
  e = (11 * g + 29) % 30;
  if (e == 25 || e == 24)
    ++e;
  return ((((e + d) * 6 + 5) % 177) / 22 & 7);
}
