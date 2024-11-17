#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a >= b ? a : b)

int longestIncSubSeq(int* arr, int size, int* memArr, int* hashArr) {
    int lenOfLIS = 1;
    int lastIdx = 0;

    for (int curIdx = 0; curIdx < size; curIdx++) {
        for (int prevIdx = 0; prevIdx < curIdx; prevIdx++) {
            if (arr[curIdx] > arr[prevIdx] && memArr[curIdx] < 1 + memArr[prevIdx]) {
                memArr[curIdx] = 1 + memArr[prevIdx];
                hashArr[curIdx] = prevIdx;
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
            // printf("%d ", arr[i]);
            LisArr[index] = arr[i];
            index--;
            maxValOfLIS--;
        }
    }

    printf("\nLongest increasing subsequence method one: ");
    for (int i = 0; i < size; i++) {
        if (LisArr[i] != '\0') {
            printf("\t%d", LisArr[i]);
        }
    }

    puts(" \n hashArr: \n");
    for (int i = 0; i < size; i++) {
        printf("\t%d", hashArr[i]);
    }

    // Print the longest increasing subsequence
    printf("\nLongest increasing subsequence method two: ");
    int* lis = malloc(lenOfLIS * sizeof(int));
    index = lenOfLIS - 1;

    for (int i = lastIdx; i >= 0; i = hashArr[i]) {
        lis[index--] = arr[i];
        if (i == hashArr[i]) break; // Stop if we reach the start of the LIS
    }

    for (int i = 0; i < lenOfLIS; i++) {
        printf("%d ", lis[i]);
    }
    printf("\n");

    free(lis);
    return lenOfLIS;
}

int main(int argc, char *argv[]) {
    int arr[] = {5, 4, 11, 1, 16, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* memArr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        memArr[i] = 1;
    }

    int* hashArr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        hashArr[i] = i;
    }

    int lenOfLIS = longestIncSubSeq(arr, size, memArr, hashArr);
    printf("Length of LIS: %d\n", lenOfLIS);

    puts("\nMemory table after tabulation solution: \n");
    for (int i = 0; i < size; i++) {
        printf("\t%d", memArr[i]);
    }

    puts("\n");

    // Free allocated memory
    free(memArr);
    free(hashArr);

    return EXIT_SUCCESS;
}