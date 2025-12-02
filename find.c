#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syslimits.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

int count = 0;

void find(char *dirpath, char *parentpath, char *match) {
  DIR *dp;
  struct dirent *entry;
  struct stat fs;
  char subdirpath[PATH_MAX];

  dp = opendir(dirpath);
  if (dp == NULL) {
    fprintf(stderr, "Unable to read directory '%s'\n", dirpath);
    exit(1);
  }

  while ((entry = readdir(dp)) != NULL) {
    if (strcmp(entry->d_name, match) == 0) {
      printf("%s/%s\n", dirpath, match);
      count++;
    }

    stat(entry->d_name, &fs);
    if (S_ISDIR(fs.st_mode)) {
      if (strncmp(entry->d_name, ".", 1) == 0)
        continue;
      if (chdir(entry->d_name) == -1) {
        fprintf(stderr, "Unable to change to %s\n", entry->d_name);
        exit(1);
      }

      getcwd(subdirpath, PATH_MAX);
      find(subdirpath, dirpath, match);
    }
  }

  closedir(dp);

  if (chdir(parentpath) == -1) {
    if (parentpath == NULL)
      return;
    fprintf(stderr, "Parent directory lost\n");
    exit(1);
  }
}

int main(int argc, char *argv[]) {

  char current[BUFSIZ];
  if (argc < 2) {
    getcwd(current, BUFSIZ);
  } else {
    strcpy(current, argv[1]);

    if (chdir(current) == -1) {
      fprintf(stderr, "unable to access directory %s\n", current);
      exit(1);
    }
    getcwd(current, PATH_MAX);
  }

  find(current, NULL, "ransom");
}
