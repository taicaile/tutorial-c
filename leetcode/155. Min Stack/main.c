
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define StackSizeDefault 10000

typedef struct
{
    int *stack;
    int *minstack;
    int top;
    unsigned int capcity;
} MinStack;

MinStack *minStackCreate()
{
    MinStack *minstack = malloc(sizeof(MinStack));
    minstack->capcity = StackSizeDefault;
    minstack->minstack = malloc(sizeof(int) * minstack->capcity);
    minstack->stack = malloc(sizeof(int) * minstack->capcity);
    minstack->top = -1;
    return minstack;
}

void minStackPush(MinStack *obj, int val)
{
    obj->top++;
    if (obj->top + 1 > obj->capcity)
    {
        printf("the stack is too small to hold the values.\n");
        return;
    }

    obj->stack[obj->top] = val;

    if (obj->top == 0)
    {
        obj->minstack[obj->top] = val;
    }
    else
    {
        obj->minstack[obj->top] = obj->minstack[obj->top - 1] < val ? obj->minstack[obj->top - 1] : val;
    }
}

void minStackPop(MinStack *obj)
{
    if (obj->top >= 0)
    {
        obj->top--;
    }
}

int minStackTop(MinStack *obj)
{
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack *obj)
{
    return obj->minstack[obj->top];
}

void minStackFree(MinStack *obj)
{
    free(obj->stack);
    free(obj->minstack);
    free(obj);
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/

int main(int argc, char const *argv[])
{
    MinStack *obj = minStackCreate();
    minStackPush(obj, 12);
    minStackPush(obj, 120);
    minStackPush(obj, -120);
    minStackPop(obj);

    int param_3 = minStackTop(obj);
    int param_4 = minStackGetMin(obj);
    printf("%d\n", param_3);
    printf("%d\n", param_4);

    minStackFree(obj);
    return 0;
}
