#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a >= b ? a : b)

int longestIncSubSeq(int* arr, int size, int* memArr, int* countArr) {
    int lenOfLIS = 1;
    int lastIdx = 0;

    for (int curIdx = 0; curIdx < size; curIdx++) {
        for (int prevIdx = 0; prevIdx < curIdx; prevIdx++) {
            if (arr[curIdx] > arr[prevIdx] && memArr[curIdx] < 1 + memArr[prevIdx]) {
                memArr[curIdx] = 1 + memArr[prevIdx];
                countArr[curIdx] = countArr[prevIdx];
            }
            else if (arr[curIdx] > arr[prevIdx] && memArr[curIdx] == 1 + memArr[prevIdx]) {
                countArr[curIdx] += countArr[prevIdx];
            }   
        }
        if (lenOfLIS < memArr[curIdx]) {
            lenOfLIS = memArr[curIdx];
            lastIdx = curIdx;
        }
    }

    int LisArr[size];
    int index = size - 1;

    for (int i = 0; i < size; i++) {
        LisArr[i] = '\0';
    }

    int maxValOfLIS = lenOfLIS;
    for(int i = size-1; i >= 0; i--) {
        if(memArr[i] == maxValOfLIS){
            LisArr[index] = arr[i];
            index--;
            maxValOfLIS--;
        }
    }

    printf("\nLongest increasing subsequence: ");
    for (int i = 0; i < size; i++) {
        if (LisArr[i] != '\0') {
            printf("%d\t", LisArr[i]);
        }
    }

    puts(" \ncountArr: \n");
    for (int i = 0; i < size; i++) {
        printf("\t%d", countArr[i]);
    }

    return lenOfLIS;
}

int main(int argc, char *argv[]) {
    int arr[] = {5, 4, 11, 1, 16, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* memArr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        memArr[i] = 1;
    }

    int* countArr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        countArr[i] = 1;
    }

    int lenOfLIS = longestIncSubSeq(arr, size, memArr, countArr);
    printf("\nLength of LIS: %d\n", lenOfLIS);

    puts("\nMemory table after tabulation solution: \n");
    for (int i = 0; i < size; i++) {
        printf("\t%d", memArr[i]);
    }

    puts("\n");

    // Free allocated memory
    free(memArr);
    free(countArr);

    return EXIT_SUCCESS;
}