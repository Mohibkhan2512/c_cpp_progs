#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a <= b ? a : b)

int minPathToReachLastRowBottomUp(int triangle[][4], int totalRows, int totalCols, int** memArr){
    for(int i = 0; i < totalRows; i++){
        for (int j = 0; j < totalCols; j++) {
            memArr[i][j] = 0;
        }
    }

    int down, diag;
    for(int i = totalRows-1; i >= 0; i--){
        for (int j = i; j >= 0; j--) {
            if(i == totalRows - 1) {
                // printf("i, j :>> %d, %d\n", i, j);
                memArr[i][j] = triangle[i][j]; 
                continue;
            }
            down = triangle[i][j] + memArr[i+1][j];
            diag = triangle[i][j] + memArr[i+1][j+1];
            memArr[i][j] = min(down, diag);
        }
    }

    return memArr[0][0];
}

int minPathToReachLastRow(int triangle[][4], int lastRow, int row, int col, int** memArr){
    if(row == lastRow) return triangle[lastRow][col];

    if (memArr[row][col] != -1) {
        return memArr[row][col];
    }

    int down = triangle[row][col] + minPathToReachLastRow(triangle, lastRow, row+1, col, memArr);
    int diag = triangle[row][col] + minPathToReachLastRow(triangle, lastRow, row+1, col+1, memArr);

    return memArr[row][col] = min(down, diag);
}

int main (int argc, char *argv[]) {
    int triangle[][4] = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int totalRows = 4;
    int totalCols = 4;
    int** memArr = malloc(totalRows*sizeof(int*));

    for(int i = 0; i < totalRows; i++){
        memArr[i] = malloc(totalCols*sizeof(int));
        for (int j = 0; j < totalCols; j++) {
            memArr[i][j] = -1;
        }
    }

    // int minPath = minPathToReachLastRow(triangle, totalRows-1, 0, 0, memArr);
    int minPath = minPathToReachLastRowBottomUp(triangle, totalRows, totalCols, memArr);

    printf("minPath :>> %d\n", minPath);

    puts("Mem table after tabulation solution: \n");
    for (int i = 0; i < totalRows; i++) {
        for (int j = 0; j < totalCols; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < totalCols; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}