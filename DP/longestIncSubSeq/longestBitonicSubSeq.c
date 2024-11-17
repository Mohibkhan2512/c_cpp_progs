#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a >= b ? a : b)

int longestBitonicSubSeq(int* arr, int nSize, int* memArrFw, int* memArrBw){
    int lastIndexOfLIS = -1;
    int lastIndexOfLDS = -1;
    int lenOfLIS = 0;
    int lenOfLDS = 0;
    int bitonicSeqArr[nSize];

    for (int curIdx = 0; curIdx < nSize; curIdx++) {
        for (int prevIdx = 0; prevIdx < curIdx; prevIdx++) {
            if(arr[curIdx] > arr[prevIdx] && memArrFw[curIdx] < 1+memArrFw[prevIdx]) {
                memArrFw[curIdx] = 1+memArrFw[prevIdx];
            }
        }
        if(lenOfLIS < memArrFw[curIdx]) {
            lenOfLIS = memArrFw[curIdx];
            lastIndexOfLIS = curIdx;
        }
    }

    for (int curIdx = nSize-1; curIdx >= 0 ; curIdx--) {
        for (int prevIdx = nSize-1; prevIdx > curIdx; prevIdx--) {
            if(arr[curIdx] > arr[prevIdx] && memArrBw[curIdx] < 1+memArrBw[prevIdx]) {
                memArrBw[curIdx] = 1+memArrBw[prevIdx];
            }
        }
        if(lenOfLDS < memArrBw[curIdx]) {
            lenOfLDS = memArrBw[curIdx];
            lastIndexOfLDS = curIdx;
        }
    }

    int index  = 0;
    int maxLenBitonicSeq = 0;
    while (index < nSize) {
        bitonicSeqArr[index] = memArrFw[index] + memArrBw[nSize-index-1] - 1;
        maxLenBitonicSeq = max(maxLenBitonicSeq, bitonicSeqArr[index]);
        index++;
    }

    puts("\nbitonicSeqArrafter tabulation solution: \n");
    for (int i = 0; i < nSize; i++) {
        printf("\t%d", bitonicSeqArr[i]);
    }

    // printf("lenOfLIS :>> %d\n", lenOfLIS);
    // printf("lenOfLDS :>> %d\n", lenOfLDS);

    return maxLenBitonicSeq;
}

int main (int argc, char *argv[]) {
    int arr[] = {5, 4, 11, 1, 16, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* memArrFw = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        memArrFw[i] = 1;
    }

    int* memArrBw = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        memArrBw[i] = 1;
    }

    int lenOflongestBitonicSubSeq = longestBitonicSubSeq(arr, size, memArrFw, memArrBw);
    printf("\nLength of longestBitonicSubSeq: %d\n", lenOflongestBitonicSubSeq);

    puts("\nMemory table memArrFw after tabulation solution: \n");
    for (int i = 0; i < size; i++) {
        printf("\t%d", memArrFw[i]);
    }

    puts("\n");

    puts("\nMemory table  memArrBw after tabulation solution: \n");
    for (int i = 0; i < size; i++) {
        printf("\t%d", memArrBw[i]);
    }

    puts("\n");

    // Free allocated memory
    free(memArrFw);
    free(memArrBw);

    return EXIT_SUCCESS;
}