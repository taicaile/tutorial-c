#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *str1 = "Hello, World!"; // 在 text section 分配的空间，是不可以修改的。
    char str2[] = "Hello, World!"; // 在 栈 中分配的空间，可以修改的。
    char str3[13] = "Hello, World!"; // 栈，这里 strlen 为什么能正确判断出长度呢？即使是末尾没有空间添加 \0 。
    char str4[] = "Hello, World!"; // 栈

    // str1 是指针类型，指向的是 char * 数据类型
    printf("The string1: %s length is:%lu, size is %lu\n", str1, strlen(str1), sizeof(str1));
    printf("The string2: %s length is:%lu, size is %lu\n", str2, strlen(str2), sizeof(str2));
    printf("The string3: %s length is:%lu, size is %lu\n", str3, strlen(str3), sizeof(str3));

    return 0;
}

/*
> gcc test.c && ./a.out
The string1: Hello, World! length is:13, size is 8
The string2: Hello, World! length is:13, size is 14
The string3: Hello, World! length is:13, size is 13
*/