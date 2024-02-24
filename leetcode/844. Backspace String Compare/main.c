#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *backspace(char *ins)
{
    int size = strlen(ins) + 1;
    char *newins = malloc(size);
    memset(newins, '\0', size);

    int start = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (ins[i] == '#')
        {
            if (start > 0)
            {
                start--;
                newins[start] = '\0';
            }
        }
        else
        {
            newins[start] = ins[i];
            start++;
        }
    }
    printf("%s\n", newins);
    return newins;
}

bool backspaceCompare(char *s, char *t)
{
    char *news = backspace(s);
    char *newt = backspace(t);

    return 0 == strcmp(news, newt);
}

int main(int argc, char const *argv[])
{
    char *s = "ab#c";
    char *t = "ad#c";

    printf("%s,%s, the result is: %d\n", s, t, backspaceCompare(s, t));

    return 0;
}
