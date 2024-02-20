#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 11
#define TABLE_SIZE 10
typedef struct
{
    char name[MAX_NAME];
    int age;
} Person;

Person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = hash_value * name[i] % TABLE_SIZE;
    }
    return hash_value;
}

bool init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_hash_table()
{
    printf("begin\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%d => NULL\n", i);
        }
        else
        {
            printf("\t%d => %s\n", i, hash_table[i]->name);
        }
    }
    printf("end\n");
}

bool hash_table_insert(Person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name);

    if (hash_table[index] != NULL)
    {
        return false;
    }

    hash_table[index] = p;
    return true;
}

Person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL && strcmp(hash_table[index]->name, name) == 0)
    {
        return hash_table[index];
    }
    else
    {
        return NULL;
    }
}

Person *hash_table_delete(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL && strcmp(hash_table[index]->name, name) == 0)
    {
        Person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    init_hash_table();
    print_hash_table();

    Person jacob = {.name = "Jacob", .age = 25};
    Person kate = {.name = "Kate", .age = 26};
    Person mpho = {.name = "mpho", .age = 26};

    // insert
    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);

    print_hash_table();

    // lookup
    Person *tmp = hash_table_lookup("Jacob");
    if (tmp == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found %s\n", tmp->name);
    }

    tmp = hash_table_lookup("Kate");
    if (tmp == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found %s\n", tmp->name);
    }

    // delete
    hash_table_delete("Kate");
    // lookup
    tmp = hash_table_lookup("Kate");
    if (tmp == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found %s\n", tmp->name);
    }
    // print
    print_hash_table();

    return 0;
}
