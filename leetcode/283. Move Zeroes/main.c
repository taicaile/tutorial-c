#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int *nums, int numsSize)
{
    int left = 0;
    int right = 0;
    // nums = [0,1,0,3,12]
    // let right to point to the next non-zero
    while (right < numsSize)
    {
        if (nums[right])
        {
            swap(&nums[left], &nums[right]);
            left++;
        }
        right++;
    }
}

void printArray(int *arr, int arrSize)
{

    for (int i = 0; i < arrSize; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void test01()
{
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(int);
    printArray(&nums[0], numsSize);
    moveZeroes(&nums[0], numsSize);
    printArray(&nums[0], numsSize);
    printf("---- test done ----\n");
}

void test02()
{
    int nums[] = {0};
    int numsSize = sizeof(nums) / sizeof(int);
    printArray(&nums[0], numsSize);
    moveZeroes(&nums[0], numsSize);
    printArray(&nums[0], numsSize);
    printf("---- test done ----\n");
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
