#include <stdio.h>
#include <stdlib.h>

#define a1 int[10]
typedef int a2[10];

typedef struct st_type
{
    int i;
    int a[];
} type_a;

enum Color
{
    GREEN = 1,
    RED,
    BLUE,
    GREEN_RED = 10,
    GREEN_BLUE
} ColorVal;

int checkSystem()
{
    union check
    {
        int i;
        char ch;
    } c;
    c.i = 1;
    return (c.ch == 1);
}

typedef struct student
{
    char name[50];
    int age;
} Stu_st, *Stu_pst;

int main(int argc, char const *argv[])
{

    const Stu_pst stu1_pst;
    Stu_pst const stu2_pst;
    Stu_st stu1_st = {.age = 12};


    printf("size of empty type_a: %lu\n", sizeof(type_a));

    type_a *p = (type_a *)malloc(sizeof(type_a) + 100 * sizeof(int));
    printf("size of p: %lu\n", sizeof(*p));
    for (int i = 0; i <= 100; i++)
    {
        p->a[i] = i;
    }
    printf("is little endness?: %d\n", checkSystem());
    printf("size of ColorVal: %lu\n", sizeof(ColorVal));

    return 0;
}
