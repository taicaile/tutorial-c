#include "uthash.h"
#include <stdlib.h>
#include <math.h>

struct HashTable {
  int key, val;
  UT_hash_handle hh; /* makes this structure hashable */
};

int findMaxLength(int *nums, int numsSize) {
  int maxLength = 0;
  struct HashTable *hashTable = NULL;
  struct HashTable *tmp = malloc(sizeof(struct HashTable));
  tmp->key = 0;
  tmp->val = -1;

  HASH_ADD_INT(hashTable, key, tmp);

  int counter = 0;
  int n = numsSize;
  for (int i = 0; i < n; i++) {
    int num = nums[i];
    if (num == 1) {
      counter++;
    } else {
      counter--;
    }
    HASH_FIND_INT(hashTable, &counter, tmp);
    if(tmp != NULL){
      int preIndex = tmp->val;
      maxLength = fmax(maxLength, i-preIndex);
    }else{
      tmp = malloc(sizeof(struct HashTable));
      tmp->key = counter, tmp->val = i;
      HASH_ADD_INT(hashTable, key, tmp);
    }
  }
  return maxLength;
}

int main() {
  int nums[] = {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0};
  int maxsize = findMaxLength(&nums, sizeof(nums) / sizeof(nums[0]));
  printf("maxsize: %d\n", maxsize);
}
