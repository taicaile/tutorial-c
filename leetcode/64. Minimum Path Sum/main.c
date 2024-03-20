#include <math.h>
#include <stdio.h>

int minPathSum(int **grid, int gridSize, int *gridColSize) {

  for (int i = 1; i < gridSize; i++) {
    grid[i][0] = grid[i - 1][0] + grid[i][0];
  }

  for (int j = 1; j < *gridColSize; j++) {
    grid[0][j] = grid[0][j - 1] + grid[0][j];
  }

  for (int i = 1; i < gridSize; i++) {
    for (int j = 1; j < *gridColSize; j++) {
      grid[i][j] = fmin(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
    }
  }

  return grid[gridSize - 1][*gridColSize - 1];
}

int main() {
  int grid[3][3] = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

  int colsize = 3;

  printf("%d\n", minPathSum((int **)grid, 3, &colsize));
}