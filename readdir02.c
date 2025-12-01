#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  DIR *dp;
  struct dirent *entry;

  dp = opendir(".");
  if (dp == NULL) {
    puts("Unabled to read directory.");
    exit(1);
  }

  while ((entry = readdir(dp)) != NULL) {

    printf("File %s\n", entry->d_name);
  }

  closedir(dp);

  return 0;
}
