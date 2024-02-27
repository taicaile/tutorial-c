#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void str_append(int num, ...);

void str_append(int num, ...)
{
    va_list valist;
    printf("num=%d\n", num);
    va_start(valist, num);
    for (int i = 0; i < num; i++)
        printf("%d\n", va_arg(valist, int));
    va_end(valist);
    putchar('\n');
}

int main(int argc, char const *argv[])
{

    str_append(3, 2, 3, 4);
    return 0;
}
