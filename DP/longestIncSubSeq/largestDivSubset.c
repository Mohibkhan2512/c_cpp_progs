#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a >= b ? a : b)

int largestDivSubset(int* arr, int size, int* memArr){
    int lenOfLargestDivSubset = 1;
    for(int curIdx = 0; curIdx < size; curIdx++){
        for(int prevIdx = 0;  prevIdx < curIdx; prevIdx++){
            if(arr[curIdx] % arr[prevIdx] == 0 || arr[prevIdx] % arr[curIdx] == 0){
                // printf("arr[curIdx], arr[prevIdx] :>> %d, %d\n", arr[curIdx], arr[prevIdx]);
                memArr[curIdx] = max(memArr[curIdx], 1+memArr[prevIdx]);
            }
        }
        lenOfLargestDivSubset = max(lenOfLargestDivSubset, memArr[curIdx]);
    }

    int LDSArr[size];
    int index = size-1;
    int maxLenOfLDS = lenOfLargestDivSubset;
    for (int i = 0; i < size; i++) {
        LDSArr[i] = '\0';
    }

    for(int i = size-1; i >= 0; i--){
        if (memArr[i] == maxLenOfLDS){
            // printf("%d ", memArr[i]);
            LDSArr[index] = arr[i];
            index--;
            maxLenOfLDS--;
        }
    }   

    printf("\nLargest Div Subset :>> ");
    for (int i = 0; i < size; i++) {
        if (LDSArr[i] != '\0') {
            printf("%d ", LDSArr[i]);
        }
    }

    return lenOfLargestDivSubset;
}

int main(int argc, char *argv[]) {
    int arr[] = {1, 4, 16, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* memArr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        memArr[i] = 1;
    }

    int lenOfLargestDivSubset = largestDivSubset(arr, size, memArr);
    printf("\nLength of LDS: %d\n", lenOfLargestDivSubset);

    puts("\nMemory table after tabulation solution: \n");
    for (int i = 0; i < size; i++) {
        printf("\t%d", memArr[i]);
    }

    puts("\n");

    // Free allocated memory
    free(memArr);

    return EXIT_SUCCESS;
}