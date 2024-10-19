#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *data;
    size_t len;
} StringView;

StringView stringview_create(char *str, size_t len)
{
    StringView sv = {
        .data = str,
        .len = len,
    };
    return sv;
}

char *stringview_to_cstr(StringView view)
{
    char *str = (char *)malloc(sizeof(char) * view.len + 1);
    strncpy(str, view.data, view.len);
    return str;
}

int main()
{
    StringView sv = stringview_create("Hello, World!", sizeof("Hello, World!") - 1);
    printf("data:%s, length:%zu\n", sv.data, sv.len);
    char *str = stringview_to_cstr(sv);
    printf("%s\n", str);

    return 0;
}
