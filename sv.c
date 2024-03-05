#include "sv.h"

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

int sv_starts_with_c(String_View view, char c) { return view.data[0] == c; }

int sv_starts_with_s(String_View view, String_View s) {

  if (view.len < s.len) {
    return 0;
  }

  for (size_t i = 0; i < s.len; i++) {
    if (view.data[i] != s.data[i]) {
      return 0;
    }
  }
  return 1;
}

size_t sv_first_of(String_View view, char target) {

  for (size_t i = 0; i < view.len; i++) {
    if (view.data[i] == target) {
      return i;
    }
  }
  return -1;
}

size_t sv_last_of(String_View view, char target) {

  for (size_t i = view.len - 1; i > 0; i--) {
    if (view.data[i] == target) {
      return i;
    }
  }
  return -1;
}

String_View sv_trim_left(String_View view) {
  size_t i = 0;
  while (isspace((int)view.data[i]) && i <= view.len) {
    i++;
  }

  return (String_View){
      .data = view.data + i,
      .len = view.len - i,
  };
}

String_View sv_trim_right(String_View view) {

  size_t i = view.len - 1;
  while (isspace((int)view.data[i])) {
    i--;
  }
  // better set an null terminator at i+1, but it is not dynamic allocated.
  return (String_View){
      .data = view.data,
      .len = i + 1,
  };
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
    printf("view1 is equal to view2: %d\n", sv_is_equal(view1, view2));

    // test sv_first_of
    printf("first index of ',' is %llu\n", sv_first_of(view, ','));

    // test sv_last_of
    printf("last index of ',' is %llu\n", sv_last_of(view, ','));

    // test sv_strm_left
    String_View viewtrim =
        sv_create("  Hello, World!  ", strlen("  Hello, World!  "));

    // trim left
    String_View trimed = sv_trim_left(viewtrim);
    printf("trim before: %s, trim after: %s#end\n", viewtrim.data, trimed.data);

    // trim right
    trimed = sv_trim_right(viewtrim);
    printf("trim before: %s, trim after: %s#end\n", viewtrim.data, trimed.data);

    // starts with char
    printf("%s, starts with H: %d\n", view.data, sv_starts_with_c(view, 'H'));

    // starts with string
    printf("%s, starts with Hello: %d\n", view.data, sv_starts_with_s(view, sv_create("Hello", (strlen("Hello")))));
}
