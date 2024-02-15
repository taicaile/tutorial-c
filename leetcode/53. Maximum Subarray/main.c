#include <stdio.h>
#include <math.h>

int maxSubArray(int *nums, int numsSize)
{
    int maxsum = nums[0];
    int presum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        presum = fmax(nums[i], presum + nums[i]);
        maxsum = fmax(maxsum, presum);
    }
    return maxsum;
}

int main(int argc, char const *argv[])
{
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int sizeofnum = sizeof(nums) / sizeof(nums[0]);

    printf("The max subarray is: %d\n", maxSubArray(&nums[0], sizeofnum));

    return 0;
}
