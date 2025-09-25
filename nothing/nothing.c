#include "nothing.h"

void printArray(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
