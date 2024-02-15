#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size_of_arr(arr) (sizeof(arr)/sizeof(arr[0]))
#define COLS 10

int compare_str(const void* a, const void* b)
{
    const char** aa = (char**)a;
    const char** bb = (char**)b;
    return  strcmp(aa, bb);
}

void print_arr(char arr[5][10], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%s\n", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    char arr[][COLS] = {"Apple", "Mongo", "Grape", "Guave", "Banana"};

    qsort(arr, size_of_arr(arr), COLS, compare_str);
    print_arr(arr, size_of_arr(arr));
    return 0;
}
