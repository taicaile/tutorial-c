#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *middleNode(struct ListNode *head)
{

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printListNode(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d  ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int headVals[] = {1, 2, 3, 4, 5};
    int headValsSize = sizeof(headVals) / sizeof(headVals[0]);
    struct ListNode dummphead;
    struct ListNode *head = &dummphead;
    for (int i = 0; i < headValsSize; i++)
    {
        struct ListNode *temp = malloc(sizeof(struct ListNode));
        temp->val = headVals[i];
        temp->next = NULL;
        head->next = temp;
        head = head->next;
    }

    printListNode(dummphead.next);
    struct ListNode *middle = middleNode(dummphead.next);
    printListNode(middle);

    return 0;
}
