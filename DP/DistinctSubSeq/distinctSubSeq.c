#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int distinctSubSeq(char* strOne, char* strTwo, int oneIdx, int twoIdx, int** memArr) {
    if (oneIdx < 0) return 0;
    if (twoIdx < 0) return 1;

    if (memArr[oneIdx][twoIdx] != -1) {
        return memArr[oneIdx][twoIdx];
    }

    if (strOne[oneIdx] == strTwo[twoIdx]) {
        memArr[oneIdx][twoIdx] = (distinctSubSeq(strOne, strTwo, oneIdx - 1, twoIdx - 1, memArr) +
                                   distinctSubSeq(strOne, strTwo, oneIdx - 1, twoIdx, memArr));
    } else {
        memArr[oneIdx][twoIdx] = distinctSubSeq(strOne, strTwo, oneIdx - 1, twoIdx, memArr);
    }

    return memArr[oneIdx][twoIdx];
}

int distinctSubSeqBottomUp(char* strOne, char* strTwo, int lenOfStrOne, int lenOfStrTwo, int** memArr) {
    for (int i = 0; i <= lenOfStrOne; i++) {
        for (int j = 0; j <= lenOfStrTwo; j++) {
            if (j == 0) {
                memArr[i][j] = 1; // One way to form empty subsequence
            } else if (i == 0) {
                memArr[i][j] = 0; // No way to form non-empty strTwo from empty strOne
            } else if (strOne[i - 1] == strTwo[j - 1]) {
                memArr[i][j] = memArr[i - 1][j - 1] + memArr[i - 1][j];
            } else {
                memArr[i][j] = memArr[i - 1][j];
            }
        }
    }

    return memArr[lenOfStrOne][lenOfStrTwo];
}

int main(int argc, char *argv[]) {
    char* strOne = "babgbag";
    char* strTwo = "bag";

    int lenOfStrOne = strlen(strOne);
    int lenOfStrTwo = strlen(strTwo);

    int** memArr = malloc((lenOfStrOne + 1) * sizeof(int*));
    for (int i = 0; i <= lenOfStrOne; i++) {
        memArr[i] = malloc((lenOfStrTwo + 1) * sizeof(int));
    }

    for (int i = 0; i <= lenOfStrOne; i++) {
        for (int j = 0; j <= lenOfStrTwo; j++) {
            memArr[i][j] = -1;
        }
    }

    int lenOfDistinctSubSeq = distinctSubSeqBottomUp(strOne, strTwo, lenOfStrOne, lenOfStrTwo, memArr);

    printf("Num Of DistinctSubSeq :>> %d\n", lenOfDistinctSubSeq);

    puts("\nMem table after tabulation solution: \n");
    for (int i = 0; i <= lenOfStrOne; i++) {
        for (int j = 0; j <= lenOfStrTwo; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i <= lenOfStrOne; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}
