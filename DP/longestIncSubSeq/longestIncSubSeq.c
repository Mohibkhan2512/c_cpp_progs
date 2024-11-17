#include <stdio.h>
#include <stdlib.h>

int maxOfTwoNums(int one, int two){
    return one >= two ? one : two;
}

void printLISubSeq(int* arr, int arrSize, int** memArr) {
    int LISArr[arrSize];
    int index = 0;
    int max;
    for (int i = 0; i < arrSize; i++) {
        LISArr[i] = '\0';
    }

    for (int i = 0; i < arrSize; i++) {
        // printf("memArr[i][0] :>> %d, %d\n", max, memArr[i][0]);
        if (index == 0) {
            LISArr[index] = arr[i];
            max = memArr[i][0];
            index++;
        } 
        if (memArr[i][0] < max) {
            // printf("max < memArr[i][0] :>> %d, %d\n", max, memArr[i][0]);
            LISArr[index] = arr[i];
            max = memArr[i][0];
            index++;
        } else if (memArr[i][0] == max) {
            // printf("max == memArr[i][0] :>> %d, %d\n", max, memArr[i][0]);
            LISArr[index-1] = arr[i];
        }
    }

    printf("Longest inc sub seq :>> ");


    for (int i = 0; i < arrSize; i++) {
        if (LISArr[i] != 0) printf(" %d ", LISArr[i]);
    }
}

int longestIncSubSeqBottomUp(int* arr, int arrSize, int** memArr) {
    int len = 0;
    for (int curIdxItr = arrSize - 1; curIdxItr >= 0; curIdxItr--) {
        for (int prevIdxItr = curIdxItr - 1; prevIdxItr >= -1; prevIdxItr--) {
            // puts("==================");
            len = memArr[curIdxItr + 1][prevIdxItr + 1]; // Don't include num in sub seq
            if (prevIdxItr == -1 || arr[curIdxItr] > arr[prevIdxItr]) { // Include num in sub seq
                len = maxOfTwoNums(len, 1 + memArr[curIdxItr + 1][curIdxItr + 1]);
            }            
            memArr[curIdxItr][prevIdxItr + 1] = len;
            // printf("Updating curIdxItr, prevIdxItr + 1: %d, %d with :>> %d\n", curIdxItr, prevIdxItr + 1, len);
            // puts("==================");
        }
    }
    
    return memArr[0][-1+1]; // prev last index = -1 it's mapped to -1+1 = 0
}

int longestIncSubSeqMemoization(int* arr, int curIdx, int prevIdx, int arrSize, int** memArr) {
    if(curIdx == arrSize) {
        return 0;
    }
    if (memArr[curIdx][prevIdx+1] != 0) {
        return memArr[curIdx][prevIdx+1];
    }
    int len = longestIncSubSeqMemoization(arr, curIdx+1, prevIdx, arrSize, memArr); // Don't include num in sub seq
    if(arr[curIdx] > arr[prevIdx] || prevIdx == -1) { // include num in sub seq
        prevIdx = curIdx;
        len = maxOfTwoNums(len, 1 + longestIncSubSeqMemoization(arr, curIdx+1, prevIdx, arrSize, memArr));
    }

    return memArr[curIdx][prevIdx+1] = len;
}

int main (int argc, char *argv[]) {
    // int arr[] = {7,1,5,3,6,10};
    int arr[] = {5,4,11,1,16,8};
    int size = sizeof(arr)/sizeof(arr[0]);

    /** for memoization */
    // int** memArr = malloc(size * sizeof(int*));

    // for (int i = 0; i < size; i++) {
    //     memArr[i] = malloc((size + 1) * sizeof(int)); // size + 1 because prev goes from -1 to n-1, we map it as 0 to n
    //     for (int j = 0; j < size + 1; j++) {
    //         memArr[i][j] = 0;
    //     }
    // }

    /** for tabulation/bottomUp */
    int** memArr = malloc((size + 1) * sizeof(int*));

    for (int i = 0; i <= size; i++) {
        memArr[i] = malloc((size + 1) * sizeof(int)); // size + 1 because prev goes from -1 to n-1, we map it as 0 to n
        for (int j = 0; j <= size; j++) {
            memArr[i][j] = 0;
        }
    }

    // int lenOfLIS = longestIncSubSeqMemoization(arr, 0, -1, size, memArr);

    int lenOfLIS = longestIncSubSeqBottomUp(arr, size, memArr);

    printf("lenOfLIS :>> %d\n", lenOfLIS);

    printLISubSeq(arr, size, memArr);

    puts("\nMem table after tabulation solution: \n");
    for (int i = 0; i < size+1; i++) {
        for (int j = 0; j < size+1; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < size+1; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}