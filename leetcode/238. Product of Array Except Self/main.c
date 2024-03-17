#include <stdio.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {

  int *retarr = malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;
  retarr[0] = 1;
  for (int i = 1; i < numsSize; i++) {
    retarr[i] = retarr[i - 1] * nums[i - 1];
  }
  int suf = 1;
  for (int i = numsSize - 1; i >= 0; i--) {
    retarr[i] = suf * retarr[i];
    suf *= nums[i];
  }
  return retarr;
}

int main() {

  int nums[] = {-1, 1, 0, -3, 3};
  int retSize = 0;
  int *retarr =
      productExceptSelf(&nums[0], sizeof(nums) / sizeof(nums[0]), &retSize);

  for (int i = 0; i < retSize; i++) {
    printf("%d ", retarr[i]);
  }

  printf("\n");
}
