#include <math.h>

int dfs(char **grid, int row, int column, int maxrow, int maxcol){
    if(row>=0 && row<maxrow && column>=0 && column<maxcol){
        if(grid[row][column]!='1'){
            return 0;
        }
        grid[row][column] = 2;

        return 1 + dfs(grid, row-1, column, maxrow, maxcol) + dfs(grid, row+1, column, maxrow, maxcol) + dfs(grid, row, column-1, maxrow, maxcol) + dfs(grid, row, column+1, maxrow, maxcol);
    }
    return 0;
}


int numIslands(char** grid, int gridSize, int* gridColSize) {

    int res = 0;
    for(int r=0; r<gridSize; r++){
        for( int c=0; c<*gridColSize; c++){
            if(grid[r][c]=='1'){
                printf("%d,%d\n", r,c);
                int a = dfs(grid, r, c, gridSize, *gridColSize);
                res = fmax(res, a);
            }
        }
    }
    return res;
}
