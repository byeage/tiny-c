#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { TRUE = 1, FALSE = 0 };

struct string {
  char *value;
  int length;
};

int string_create(struct string *s, char *v) {

  if (s == NULL) {
    return FALSE;
  }

  s->length = strlen(v);

  s->value = (char *)malloc(sizeof(char) * (s->length + 1));
  strcpy(s->value, v);
  return TRUE;
}

void string_destroy(struct string *s) {
  free(s->value);
  s->value = NULL;
  s->length = 0;
}
