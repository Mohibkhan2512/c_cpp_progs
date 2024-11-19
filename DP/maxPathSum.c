#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 6

#define max(a, b) (a >= b ? a : b)

int maxSumPathBottomUp(int grid[][M], int** memArr) {
    for(int i = N-1; i >= 0; i--) {
        for(int j = M-1; j >= 0; j--) {
            int leftDiag = INT_MIN; int rightDiag = INT_MIN;
            if (i == N-1) {
                 memArr[i][j] = grid[i][j]; continue;
            }
            int down = grid[i][j] + memArr[i+1][j];
            if (j > 0) {
                leftDiag = grid[i][j] + memArr[i+1][j-1];
            } 
            if (j < M-1) {
                rightDiag = grid[i][j] + memArr[i+1][j+1]; 
            }
            memArr[i][j] = max(down, max(leftDiag, rightDiag));
        }
    }

    int maxSum = memArr[0][0];
    for (int j = 0; j < M; j++) {
        maxSum = max(maxSum, memArr[0][j]);
    }
    
    return maxSum;
}

int maxSumPath(int grid[][M], int row, int col, int** memArr) {
    // printf("grid[row][col], row, col :>> %d, %d, %d\n", grid[row][col], row, col);

    if (row == N-1) {
        return grid[N-1][col];
    }
    if (col < 0 || col >= M) return INT_MIN;
    if(memArr[row][col] != -1) return memArr[row][col];

    int down = grid[row][col] + maxSumPath(grid, row+1, col, memArr);
    int leftDiag = grid[row][col] + maxSumPath(grid, row+1, col-1, memArr);
    int rightDiag = grid[row][col] + maxSumPath(grid, row+1, col+1, memArr);

    // printf("down, leftDiag, rightDiag :>> %d, %d, %d\n", down, leftDiag, rightDiag);

    return memArr[row][col] = max(down, max(leftDiag, rightDiag));
}

int main (int argc, char *argv[]) {
    int grid[N][M] = {  { 10, 10, 2, 0, 20, 4 },
                        { 1, 0, 0, 30, 2, 5 },
                        { 0, 10, 4, 0, 2, 0 },
                        { 1, 0, 2, 20, 0, 4 } };
    
    int** memArr = malloc(N*sizeof(int*));

    for(int i = 0; i < N; i++){
        memArr[i] = malloc(M*sizeof(int));
        for (int j = 0; j < M; j++) {
            memArr[i][j] = -1;
        }
    }
    
    /* for memoization */
    // int maxPathSum = INT_MIN, curPathSum = INT_MIN;
    // for(int i = 0; i < M; i++){
    //     curPathSum = maxSumPath(grid, 0, i, memArr);
    //     maxPathSum = max(curPathSum, maxPathSum);
    //     // printf("maxPathSum, curPathSum :>> %d, %d\n", maxPathSum, curPathSum);
    // }

    int maxPathSum = maxSumPathBottomUp(grid, memArr);

    printf("maxPathSum:>> %d\n", maxPathSum);

    puts("Mem table after tabulation solution: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}