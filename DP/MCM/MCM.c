#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int matChainMultiplicationBottomUp(int* arr, int nSize) {
    int minCost;
    int curCost = 0;
    int memArr[nSize][nSize];

    for(int i = 0; i < nSize; i++){
        for (int j = 0; j < nSize; j++) {
            memArr[i][j] = 0;
        }
    }

    for(int i = nSize-1; i >= 1; i--){
        for(int j = i + 1; j < nSize; j++){
            minCost = INT_MAX;
            for(int k = i; k < j; k++){
                curCost = arr[i-1] * arr[k] * arr[j] \
                        + memArr[i][k]\
                        + memArr[k+1][j];
                minCost = curCost <= minCost ? curCost : minCost;
            }
            memArr[i][j] = minCost;
        }
    }

    puts("\nMem table after tabulation solution: \n");
    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < nSize; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    return memArr[1][nSize-1]; // i last index -> 1 and j last index -> nSize-1
}


int matChainMultiplicationMeoization(int* arr, int startIdx, int endIdx, int** memArr) {
    if (startIdx == endIdx) { // when true, no more splitting needed
        return 0;
    }
    if (memArr[startIdx][endIdx] != -1) {
        return memArr[startIdx][endIdx];
    }
    int minCost;
    int curCost = 0;
    for (int k = startIdx; k < endIdx; k++) {
        minCost = INT_MAX;
        curCost = arr[startIdx-1] * arr[k] * arr[endIdx] \
                + matChainMultiplicationMeoization(arr, startIdx, k, memArr) \
                + matChainMultiplicationMeoization(arr, k+1, endIdx, memArr);
        // printf("curCost :>> %d, arr[startIdx-1] %d arr[k] %d arr[endIdx] %d\n", curCost, arr[startIdx-1], arr[k], arr[endIdx]);
        minCost = curCost <= minCost ? curCost : minCost;
        memArr[startIdx][endIdx] = minCost;
    }
    return memArr[startIdx][endIdx];
}

int main (int argc, char *argv[]) {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    int** memArr = malloc(nSize*sizeof(int*));

    for(int i = 0; i < nSize; i++){
        memArr[i] = malloc(nSize*sizeof(int));
        for (int j = 0; j < nSize; j++) {
            memArr[i][j] = -1;
        }
    }

    // int costForMCM = matChainMultiplicationMeoization(arr, 1, nSize-1, memArr);
    int costForMCM = matChainMultiplicationBottomUp(arr, nSize);

    printf("costForMCM :>> %d\n", costForMCM);

    puts("\nMem table after memoization solution: \n");
    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < nSize; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < nSize; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}