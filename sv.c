#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  size_t len;
} String_View;

String_View sv_create(char *str, size_t len) {
  return (String_View){
      .data = str,
      .len = len,
  };
}

char *sv_to_cstr(String_View view) {
  char *str = malloc(sizeof(char) * view.len + 1);
  strncpy(str, view.data, view.len);
  str[view.len] = '\0';
  return str;
}

int sv_is_equal(String_View a, String_View b) {
  if (a.len != b.len)
    return false;

  for (size_t i = 0; i < a.len; i++) {
    if (a.data[i] != b.data[i])
      return false;
  }
  return true;
}

int main() {
  // test sv_create
  String_View view = sv_create("Hello, World!", strlen("Hello, World!"));
  printf("data: %.*s, len: %llu\n", (int)view.len, view.data, view.len);

  // test sv_to_cstr
  char *str = sv_to_cstr(view);
  printf("cstr: %s\n", str);

  // test sv_is_equal
  String_View view1 = sv_create("Hello, World!", strlen("Hello, World!"));
  String_View view2 = sv_create("Hello, World!", strlen("Hello, World!"));
  printf("view1 is equal to view2: %d", sv_is_equal(view1, view2));
}