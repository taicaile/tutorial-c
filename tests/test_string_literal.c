#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s1[] = "s1abcdef"; // the string is located in the stack, modifiable.
    char *s2 = "s2abcdef";  // the string is located in the text section, non-modifiable
    char s3[9] = "s3abcdef";

    s1[0] = 'x';
    printf("s1=%s\n", s1);
    printf("size of s1: %lu\n", sizeof(s1)); // 这里获取的其实是 s1 指针类型的size
    printf("s1+1=%s\n", s1 + 1);
    printf("&s1=%p\n", &s1);
    printf("&s1+1=%p\n", &s1 + 1);
    printf("length of pointer plus one((char *)(&s1 + 1) - (char *)&s1)=%ld\n", (char *)(&s1 + 1) - (char *)&s1);
    printf("length of pointer plus one(sizeof(*(&s1)))=%ld\n", sizeof(*(&s1)));

    // s1++; // error: cannot increment value of type 'char[9]'

    // s2[0] = 'X'; // error
    printf("s2=%s\n", s2);
    printf("size of s2: %lu\n", sizeof(s2));
    printf("s2+1=%s\n", s2 + 1);
    printf("&s2=%p\n", &s2);
    printf("&s2+1=%p\n", &s2 + 1);
    printf("length of pointer plus one((char *)(&s2 + 1) - (char *)&s2)=%ld\n", (char *)(&s2 + 1) - (char *)&s2);
    s2++; // s2 is modifiable.

    printf("s3=%s\n", s3);
    printf("size of s3: %lu\n", sizeof(s3));
    printf("s3+1=%s\n", s3 + 1);
    printf("&s3=%p\n", &s3);
    printf("&s3+1=%p\n", &s3 + 1);
    printf("length of pointer plus one(&s3+1-&s3)=%ld\n", (char *)(&s3 + 1) - (char *)&s3);
    // s3++; // error

    return 0;
}
