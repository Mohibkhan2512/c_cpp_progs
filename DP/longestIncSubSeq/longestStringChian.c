#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bubbleSort(char* arr[], int nSize){
    char* temp;
    for(int i = 0; i < nSize - 1; i++){
        for(int j = i + 1; j < nSize; j++){
            if(strcmp(arr[i], arr[j]) > 0){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool compareStrings(char* strOne, char* strTwo){
    // printf("strOne, strTwo :>> %s, %s\n", strOne, strTwo);
    if(strlen(strOne) < strlen(strTwo)+1) return false;
    int strOneIdx = 0;
    int strTwoIdx = 0;

    while (strOneIdx < strlen(strOne)) {
        if(strOne[strOneIdx] == strTwo[strTwoIdx]){
            strOneIdx++;
            strTwoIdx++;
        }
        else{
            strOneIdx++;
        }
    }

    // printf("strOneIdx, strTwoIdx :>> %d, %d\n", strOneIdx, strTwoIdx);

    if(strOneIdx == strlen(strOne) && strTwoIdx == strlen(strTwo)) return true;
    return false;
}

int longestStringChain(char* arr[], int nSize, int* memArr){
    int lenOfLSC = 1;

    for(int curIdx = 0; curIdx < nSize; curIdx++){
        for(int prevIdx = 0; prevIdx < curIdx; prevIdx++){
            if(compareStrings(arr[curIdx], arr[prevIdx]) && memArr[curIdx] < memArr[prevIdx] + 1){
                memArr[curIdx] = 1 + memArr[prevIdx];
            }
        }
        if(lenOfLSC < memArr[curIdx]){
            lenOfLSC = memArr[curIdx];
        }
    }

    return lenOfLSC;
}

int main(int argc, char *argv[]) {
    char* arr[] = {"a", "b", "ba", "bcaa", "baa", "bdca"};
    int nSize = sizeof(arr) / sizeof(arr[0]);

    int* memArr = malloc(nSize * sizeof(int));
    for (int i = 0; i < nSize; i++) {
        memArr[i] = 1;
    }

    bubbleSort(arr, nSize);

    printf("Sorted arr :>> ");
    for(int i = 0; i < nSize; i++){
        printf("%s ", arr[i]);
    }

    int lenOflongestStringChain = longestStringChain(arr, nSize, memArr);
    printf("\nLength of longestStringChain: %d\n", lenOflongestStringChain);

    puts("\nMemory table after tabulation solution: \n");
    for (int i = 0; i < nSize; i++) {
        printf("\t%d", memArr[i]);
    }

    puts("\n");

    // Free allocated memory
    free(memArr);

    return EXIT_SUCCESS;
}