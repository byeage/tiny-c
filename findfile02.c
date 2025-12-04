#include <dirent.h>
#include <glob.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
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
  int g;
  glob_t gstruct;
  char **found;
  dp = opendir(dirpath);
  if (dp == NULL) {
    fprintf(stderr, "Unable to read directory '%s'\n", dirpath);
    exit(1);
  }

  g = glob(match, GLOB_ERR, NULL, &gstruct);
  if (g == 0) {
    found = gstruct.gl_pathv;
    while (*found) {
      printf("%s/%s\n", dirpath, *found);
      found++;
      count++;
    }
  }

  while ((entry = readdir(dp)) != NULL) {
    stat(entry->d_name, &fs);
    if (S_ISDIR(fs.st_mode)) {
      if (strncmp(entry->d_name, ".", 1) == 0)
        continue;
      if (chdir(entry->d_name) == -1) {
        fprintf(stderr, "Unable to change to %s\n", entry->d_name);
        exit(1);
      }

      getcwd(subdirpath, BUFSIZ);
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

  char current[PATH_MAX];
  char match[PATH_MAX];

  if (argc < 2) {
    getcwd(current, PATH_MAX);
  } else {
    strncpy(current, argv[1], PATH_MAX);
  }

  if (chdir(current) == -1) {
    fprintf(stderr, "unable to access directory %s\n", current);
    exit(1);
  } else {
    getcwd(current, PATH_MAX);
  }

  count = 0;

  printf("Filename or wildcard: ");
  fgets(match, sizeof match, stdin);
  printf("In fold: %s, search for: %s\n", current, match);

  match[strcspn(match, "\n")] = '\0';
  find(current, NULL, match);
  printf("Found %d match", count);

  if (count != 1) {
    printf("es");
  }
  putchar('\n');
  return 0;
}
