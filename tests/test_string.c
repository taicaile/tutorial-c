#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    const char *hexstr = "FF";
    int value = 0;

    value = strtol(hexstr, NULL, 16);
    printf("%d\n", value);
    return 0;
}

/*
> ./a.out
255
*/
