#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {

  char *filename;
  struct stat fs;

  int r;

  if (argc < 2) {
    fprintf(stderr, "Specify a filename\n");
    exit(1);
  }

  filename = argv[1];
  printf("Info for file '%s' \n", filename);

  r = stat(filename, &fs);

  if (r == -1) {
    fprintf(stderr, "Error reading '%s' \n", filename);
    exit(1);
  }

  printf("Media ID: %lu\n", fs.st_dev);
  printf("Type and mode:%u\n", fs.st_mode);
  if (S_ISREG(fs.st_mode)) {
    printf("%s is a regular file\n", filename);
  } else if (S_ISDIR(fs.st_mode)) {
    printf("%s is a directory\n", filename);
  } else {
    printf("%s is not a reguluar file\n", filename);
  }
  printf("Hard Links = %lu\n", fs.st_nlink);
  printf("Owner ID:%u\n", fs.st_uid);
  printf("Group ID:%u\n", fs.st_gid);
  printf("Device ID:%lu\n", fs.st_rdev);
  printf("File size = %lu bytes\n", fs.st_size);
  printf("Block size= %lu \n", fs.st_blksize);
  printf("Allocate blocks = %lu\n", fs.st_blocks);
  printf("Modification:%s", ctime(&fs.st_atime));
  printf("changed:%s", ctime(&fs.st_ctime));

  return 0;
}
