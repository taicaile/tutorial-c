#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define View_Print "%.*s"
#define View_Arg(view) (int)view.len, view.data

#define LITERAL_CREATE(lit) sv_create(lit, sizeof(lit)-1)

typedef struct {
  char *data;
  size_t len;
} String_View;


String_View sv_create(char *str, size_t len);

char *sv_to_cstr(String_View view);

int sv_is_equal(String_View a, String_View b);

size_t sv_first_of(String_View view, char target);

size_t sv_last_of(String_View view, char target);

String_View sv_trim_left(String_View view);

String_View sv_trim_right(String_View view);

