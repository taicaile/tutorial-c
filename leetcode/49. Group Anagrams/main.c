#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct _dict
{
    char *key;
    char *value[];
} Dict;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{

    return 0;
}

void printStrs(char *strs[], int strSize)
{
    for (int i = 0; i < strSize; i++)
    {
        printf("%s\n", strs[i]);
    }
}

int cmpFunction(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int hash(const char *str)
{
    int hashvalue = 0;
    char *copy = strdup(str);
    qsort(copy, (size_t)strlen(copy), (size_t)sizeof(copy[0]), cmpFunction);
    for (int i = 0; i < strlen(copy); i++)
    {
        hashvalue += str[i];
        hashvalue = hashvalue * str[i] % TABLE_SIZE;
    }
    return hashvalue;
}

int main(int argc, char const *argv[])
{

    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int sizeofStrs = sizeof(strs) / sizeof(strs[0]);
    printStrs(strs, sizeofStrs);

    for (int i = 0; i < sizeofStrs; i++)
    {
        printf("%s\n", strs[i]);
        printf("Hash value: %d\n", hash(strs[i]));
    }

    hash(strs[0]);
    return 0;
}
