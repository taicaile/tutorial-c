#include <stdio.h>

int main(int argc, char const *argv[])
{

    int x = 991;
    printf("start the test of get the bits of a number.\n");
    printf("%d/10=%d\n", x, x / 10);
    while (x > 0)
    {
        printf("bit: %d\n", x % 10);
        x /= 10;
    }
    printf("---- test end ----\n");

    printf("start the test.\n");
    for (x = 100; x >= -100; x--)
    {
        printf("%d / 10 = %d\n", x, x / 10);
    }
    printf("---- test end ----\n");

    printf("start the test: shift operator\n");
    char ch = 0;
    do
    {
        printf("%d << 1 = %d\n", ch, ch << 1);
        ch--;

    } while (ch != 0);
    printf("---- test end ----\n");

    return 0;
}
