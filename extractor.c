#include <stdio.h>
#include <string.h>

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

int main() {
  const int count = 4;

  const char *pathname[count] = {
    "/Users/daoma",
    "/Users/daoma/data",
    "/",
    "nothing here",
  };

  int x;

  for (x = 0; x < count; x++) {
    printf("%s -> %s\n", pathname[x], extract(pathname[x]));
  }

  return 0;
}
