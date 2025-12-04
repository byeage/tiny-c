#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 256
#endif /* FINFO_C */

struct finfo {
  int index;
  int repeat;
  char name[BUFSIZ];
  char path[PATH_MAX];
  struct finfo *next;
};

struct finfo *find(char *dirpath, char *parentpath, struct finfo *f) {
  DIR *dp;
  struct dirent *entry;
  struct stat fs;

  char subdirpath[PATH_MAX];
  int i;

  dp = opendir(dirpath);
  if (dp == NULL) {
    fprintf(stderr, "unable to read directory %s\n");
    exit(1);
  }

  while ((entry = readdir(dp)) != NULL) {
    stat(entry->d_name, &fs);

    if (S_ISDIR(fs.st_mode)) {
      if (strncmp(entry->d_name, ".", 1) == 0) {
        continue;
      }

      if (chdir(entry->d_name) == -1) {
        fprintf(stderr, "unable to change to %s\n");
        exit(1);
      }

      getcwd(subdirpath, BUFSIZ);
      f = find(subdirpath, dirpath, f);
    } else {
      f->next = malloc(sizeof(struct finfo));

      if (f->next == NULL) {
        fprintf(stderr, "unable to allocate new structure\n");
        exit(1);
      }

      i = f->index;
      f = f->next;
      f->index = i + 1;
      f->repeat = 1;

      strcpy(f->name, entry->d_name);
      strcpy(f->path, dirpath);
      f->next = NULL;
    }
  }

  closedir(dp);
  if (chdir(parentpath) == -1) {
    if (parentpath == NULL) {
      return NULL;
    }
    fprintf(stderr, "Parent directory lost\n");
    exit(1);
  }

  return f;
}

int main() {

  char startdir[PATH_MAX];
  struct finfo *first, *current, *scan;

  first = malloc(sizeof(struct finfo));

  if (first == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(1);
  }

  first->index = 0;
  first->repeat = 1;
  strcpy(first->name, "");
  strcpy(first->path, "");
  first->next = NULL;

  getcwd(startdir, PATH_MAX);
  if (chdir(startdir) == -1) {
    fprintf(stderr, "unable to access  directory %s\n", startdir);
    exit(1);
  }

  find(startdir, NULL, first);

  current = first;

  while (current) {
    if (current->index > 0) {
      scan = current->next;

      while (scan) {

        if (strcmp(current->name, scan->name) == 0) {
          current->repeat++;
        }
        scan = scan->next;
      }
    }

    /* printf("%d:%s/%s(%d)\n", current->index, current->path, current->name, */
    /*        current->repeat); */
    current = current->next;
  }

  return 0;
}
