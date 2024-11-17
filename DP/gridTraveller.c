#include <stdio.h>
#include <stdlib.h>

int gridTravellerBottomUp(int **memArr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            memArr[i][j] = 0;
        }
    }

    int right, up;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if(i == 0 && j == 0) memArr[i][j] = 1;
            else{
                right = 0, up = 0;
                if (i > 0) right = memArr[i-1][j];
                if (j > 0) up = memArr[i][j-1];
                memArr[i][j] = right + up;
            }
        }
    }

    return memArr[rows-1][columns-1];
}
int gridTraveller(int **memArr, int rows, int columns) {
    if (rows == -1 || columns == -1) {
        return 0;
    }
    if (rows == 0 && columns == 0) {
        memArr[rows][columns] = 1;
        return memArr[rows][columns];
    }
    if (memArr[rows][columns] != -1) {
        return memArr[rows][columns];
    }

    memArr[rows][columns] = gridTraveller(memArr, rows - 1, columns) + gridTraveller(memArr, rows, columns - 1);
    return memArr[rows][columns];
}

int main(int argc, char *argv[]) {
    // if (argc < 3) {
    //     printf("Usage: %s <rows> <columns>\n", argv[0]);
    //     return 1;
    // }

    // int rows = atoi(argv[1]);
    // int columns = atoi(argv[2]);

    int rows = 3;
    int columns = 3;

    // Allocate memory for the 2D memArray
    int **memArr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        memArr[i] = (int *)malloc(columns * sizeof(int));
    }

    // Initialize the memArray with -1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            memArr[i][j] = -1;
        }
    }

    // int totalWays = gridTraveller(memArr, rows - 1, columns - 1);
    int totalWays = gridTravellerBottomUp(memArr, rows, columns);

    printf("totalWays :>> %d\n", totalWays);

    puts("Grid values: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d, %d, memArr[i][j] :>> %d\n", i, j, memArr[i][j]);
        }
    }

    printf("Max num of ways to travel from 0 to %d :>> %d\n", columns-1, memArr[rows - 1][columns - 1]);


    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}
