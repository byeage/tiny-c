#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define TAB_SIZE 4

const char *extract(char *path) {

  const char *p;
  unsigned long len;

  len = strlen(path);
  if (len == 0) {
    return NULL;
  }

  if (len == 1 && *(path + 0) == '/') {
    return path;
  }

  p = path + len;

  while (*p != '/') {
    p--;
    if (p == path) {
      return NULL;
    }
  }

  p++;

  if (*p == '\0') {
    return NULL;
  }

  return p;
}

void dir(const char *dirpath, char *parentpath, int depth) {

  DIR *dp;
  struct dirent *entry;
  struct stat fs;
  char subdirpath[BUFSIZ];

  dp = opendir(dirpath);

  if (dp == NULL) {
    fprintf(stderr, "Unable to red directory:%s\n", dirpath);
    exit(1);
  }

  for (int i = 0; i < depth; ++i) {
    for (int n = 0; n < TAB_SIZE; n++) {
      putchar(' ');
    }
  }
  putchar('|');
  for (int n = 0; n < TAB_SIZE; n++) {
    putchar('-');
  }
  printf("%s\n", extract(dirpath));

  while ((entry = readdir(dp)) != NULL) {

    if (strncmp(entry->d_name, ".", 1) == 0) {
      continue;
    }

    stat(entry->d_name, &fs);

    if (S_ISDIR(fs.st_mode)) {

      if (chdir(entry->d_name) == -1) {
        fprintf(stderr, "Unable to change to %s\n", entry->d_name);
        exit(1);
      }

      getcwd(subdirpath, BUFSIZ);
      dir(subdirpath, dirpath, depth + 1);
    } else {

      for (int i = 0; i <= depth; ++i) {
        for (int n = 0; n < TAB_SIZE; n++) {
          putchar(' ');
        }
      }
      putchar('|');
      for (int n = 0; n < TAB_SIZE; n++) {
        putchar('-');
      }
      printf("%s\n", entry->d_name);
    }
  }

  closedir(dp);

  if (chdir(parentpath) == -1) {
    if (parentpath == NULL) {
      return;
    }
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
    getcwd(current, BUFSIZ);
  }

  dir(current, NULL, 0);

  return (0);
}
