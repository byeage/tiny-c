#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  DIR *dp;

  dp = opendir(".");
  if (dp == NULL) {
    puts("Unabled to read directory.");
    exit(1);
  }

  puts("Directory is opened");

  closedir(dp);
  puts("Directory is closed!");

  return 0;
}
