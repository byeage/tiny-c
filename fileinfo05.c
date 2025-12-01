#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void permissions_out(mode_t m) {
  /* I use the ternary operator to output either the
     appropriate letter or the dash */
  putchar(m & S_IRUSR ? 'r' : '-');
  /* each of the 9 settings are output in turn */
  putchar(m & S_IWUSR ? 'w' : '-');
  putchar(m & S_IXUSR ? 'x' : '-');
  putchar(m & S_IRGRP ? 'r' : '-');
  putchar(m & S_IWGRP ? 'w' : '-');
  putchar(m & S_IXGRP ? 'x' : '-');
  putchar(m & S_IROTH ? 'r' : '-');
  putchar(m & S_IWOTH ? 'w' : '-');
  putchar(m & S_IXOTH ? 'x' : '-');
  /* a final putchar() to end the string */
  putchar('\n');
}

int main(int argc, char *argv[]) {

  char *filename;
  struct stat fs;

  int r;

  if (argc < 2) {
    fprintf(stderr, "Special a filename\n");
    exit(1);
  }

  filename = argv[1];
  r = stat(filename, &fs);

  if (r == -1) {
    fprintf(stderr, "Error reading %s\n", filename);
  }

  printf("File %s is a ", filename);

  if (S_ISBLK(fs.st_mode)) {
    printf("block special\n");
  } else if (S_ISCHR(fs.st_mode)) {
    printf("character special\n");
  } else if (S_ISREG(fs.st_mode)) {
    printf("regular file\n");
  } else if (S_ISDIR(fs.st_mode)) {
    printf("directory\n");
  } else if (S_ISFIFO(fs.st_mode)) {
    printf("named pipe or socket\n");
  } else if (S_ISLNK(fs.st_mode)) {
    printf("symbolic link\n");
  } else {
    printf("type unknown\n");
  }

  permissions_out(fs.st_mode);

  return 0;
}
