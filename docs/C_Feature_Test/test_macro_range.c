#include <stdio.h>

#define uin8 (unsigned char)
#define int8 (signed char)
#define uint16 (unsigned short int)
#define int16 (signed short int)

#define defineValue32 32
#define defineValue32u 32u

#define defineValue320 320
#define defineValue320u 320u

void test()
{
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(long long) = %zu\n", sizeof(long long));
    printf("sizeof(float) = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(long double) = %zu\n", sizeof(long double));

    printf("Size of default defineValue32: %zu bytes\n", sizeof(defineValue32));
    printf("Size of default defineValue32: %zu bytes\n", sizeof(defineValue32));
    printf("Size of default defineValue320: %zu bytes\n", sizeof(defineValue320));
    printf("Size of default defineValue320: %zu bytes\n", sizeof(defineValue320));
}

int main(int argc, char const *argv[])
{

    test();

    /* code */
    return 0;
}
