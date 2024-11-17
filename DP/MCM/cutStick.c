#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) <= (b) ? (a) : (b))

int minWaysToCutStickBottomUp(int* cutArr, int firstCutIdx, int lastCutIdx, int** memArr) {
    for(int i = lastCutIdx; i >= firstCutIdx; i--){
        for(int j = i; j <= lastCutIdx; j++){
            // printf("i, j :>> %d, %d\n", i, j);
            int minCost = INT_MAX;
            for(int k = i; k <= j; k++){
                // printf("k :>> %d\n", k);
                int curCost = cutArr[j+1] - cutArr[i-1] + \
                                memArr[i][k-1] + memArr[k+1][j];
                minCost = min(minCost, curCost);
            }
            memArr[i][j] = minCost;
        }
    }
    return memArr[1][lastCutIdx];
}


int minWaysToCutStick(int* cutArr, int firstCutIdx, int lastCutIdx, int** memArr) {
    // printf("firstCutIdx, lastCutIdx : %d, %d\n", firstCutIdx, lastCutIdx);
    if (firstCutIdx > lastCutIdx) {
        return 0;
    }
    if (memArr[firstCutIdx][lastCutIdx] != -1) {
        return memArr[firstCutIdx][lastCutIdx];
    }
    int minCost = INT_MAX;
    for (int k = firstCutIdx; k <= lastCutIdx; k++) {
        int curCost = cutArr[lastCutIdx + 1] - cutArr[firstCutIdx - 1] +
                      minWaysToCutStick(cutArr, firstCutIdx, k - 1, memArr) +
                      minWaysToCutStick(cutArr, k + 1, lastCutIdx, memArr);
        minCost = min(minCost, curCost);
    }
    return memArr[firstCutIdx][lastCutIdx] = minCost;
}

int main (int argc, char *argv[]) {
    int initialArr[] = {1,3,5};
    int nSize = sizeof(initialArr)/sizeof(initialArr[0]);
    int firstIdx = 1;
    int lastIdx = nSize;
    int initialCost = 7;
    int cutArr[] = {0,1,3,5,7};

    /* for memoization solution */
    // int** memArr = malloc((lastIdx+1)*sizeof(int*));

    // for(int i = 0; i < (lastIdx+1); i++){
    //     memArr[i] = malloc((lastIdx+1)*sizeof(int));
    //     for (int j = 0; j < (lastIdx+1); j++) {
    //         memArr[i][j] = -1;
    //     }
    // }    

    /* for BottomUp solution */
    int** memArr = malloc((lastIdx+2)*sizeof(int*));
    for(int i = 0; i < (lastIdx+2); i++){
        memArr[i] = malloc((lastIdx+2)*sizeof(int));
        for (int j = 0; j < (lastIdx+2); j++) {
            memArr[i][j] = 0;
        }
    }

    // int minCostToCutSticks = minWaysToCutStick(cutArr, firstIdx, lastIdx, memArr);
    
    int minCostToCutSticks = minWaysToCutStickBottomUp(cutArr, firstIdx, lastIdx, memArr);


    printf("minCostToCutSticks :>> %d\n", minCostToCutSticks);

    puts("\nMem table after bottomup solution: \n");
    for (int i = 0; i < lastIdx+2; i++) {
        for (int j = 0; j < lastIdx+2; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < lastIdx+2; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}