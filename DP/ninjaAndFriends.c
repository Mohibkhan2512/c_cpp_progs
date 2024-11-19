#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4

#define max(a, b) (a >= b ? a : b)

// Function to find the maximum chocolates that can be collected recursively
int maxChocoUtil(int i, int j1, int j2, int grid[][M], int*** memArr) {
    if (j1 < 0 || j1 >= M || j2 < 0 || j2 >= M) return -1e9;
    if (i == N - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (memArr[i][j1][j2] != -1) return memArr[i][j1][j2];
    
    int ways[] = {-1, 0, 1};
    int nWays = sizeof(ways)/sizeof(ways[0]);

    int maxChoco = -1e9, curChoco = -1e9;
    for(int dj1 = 0; dj1 < nWays; dj1++){
        for(int dj2 = 0; dj2 < nWays; dj2++){
            if (dj1 == dj2) {
                curChoco = grid[i][j1] + maxChocoUtil(i+1, j1+ways[dj1], j2+ways[dj2], grid, memArr);
            } 
            else {
                curChoco = grid[i][j1] + grid[i][j2] + maxChocoUtil(i+1, j1+ways[dj1], j2+ways[dj2], grid, memArr);
            }
            maxChoco = max(maxChoco, curChoco);
        }
    }

    return memArr[i][j1][j2] = maxChoco;
}

int main (int argc, char *argv[]) {
    int grid[N][M] = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int*** memArr = malloc(N*sizeof(int**));

    for(int i = 0; i < N; i++){
        memArr[i] = malloc(M*sizeof(int*));
        for (int j = 0; j < M; j++) {
            memArr[i][j] = malloc(M*sizeof(int));
            for (int k = 0; k < M; k++) {
             memArr[i][j][k] = -1;
            }
        }
    }

    int maxPathSum = maxChocoUtil(0, 0, M-1, grid, memArr);

    printf("maxPathSum:>> %d\n", maxPathSum);

    puts("Mem table after tabulation solution: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                printf("\t%d", memArr[i][j][k]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(memArr[i][j]); // Free each innermost array
        }
        free(memArr[i]); // Free each middle array
    }
    free(memArr); // Finally, free the outer array


    return EXIT_SUCCESS;
}