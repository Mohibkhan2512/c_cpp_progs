#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a <= b ? a : b)
#define INT_MAX 10000000

int minPathSumInGridBottomUp(int grid[][3], int rows, int cols, int memArr[3][3]){
    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cols; j++){
            memArr[i][j] = 0;
        }
    }

    int up, right;

    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            up = INT_MAX; right = INT_MAX;
            if (i == 0 && j == 0) {
                memArr[i][j] = grid[i][j]; 
                continue;
            }
            if(i > 0) up = grid[i][j] + memArr[i-1][j];
            if(j > 0) right = grid[i][j] + memArr[i][j-1];
            // printf("i, j, up, right :>> %d, %d, %d, %d\n", i, j, up, right);

            memArr[i][j] = min(up, right);
        }
    }

    return memArr[rows][cols];
}

int minPathSumInGrid(int grid[][3], int rows, int cols, int memArr[3][3]){
    if(rows == 0 && cols == 0) return grid[0][0];
    if(rows < 0 || cols < 0) return INT_MAX;
    if(memArr[rows][cols] != -1) return memArr[rows][cols];

    int up = grid[rows][cols] + minPathSumInGrid(grid, rows-1, cols, memArr);
    int right = grid[rows][cols] + minPathSumInGrid(grid, rows, cols-1, memArr);

    // printf("up, right :>> %d, %d\n", up, right);

    return memArr[rows][cols] = min(up, right);
}

int main (int argc, char *argv[]) {
    int size = 3;
    int grid[3][3] = {{1,3,1},{1,5,1},{4,2,1}};
    int memArr[size][size];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            memArr[i][j] = -1;
        }
    }

    // int minPath = minPathSumInGrid(grid, size-1,size-1, memArr);
    int minPath = minPathSumInGridBottomUp(grid, size-1,size-1, memArr);
    
    printf("minPath :>> %d\n", minPath);

    printf("memArr :");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %d ", memArr[i][j]);
        }
    }

    return EXIT_SUCCESS;
}

