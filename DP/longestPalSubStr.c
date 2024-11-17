#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// recursive iterative approach => TC = O(n^3)
void longestPalSubStr(char* string, int stringSize, int* lenOfLongestPalSubStr) {
    // char* pLeft = &string[0];
    // char* pRight = &string[stringSize-1];
    char* pLeft = NULL;
    char* pRight = NULL;
    bool isStringEvenLength = false;

    isStringEvenLength % 2 == 0 ? true: false;

    // printf("*pRight :>> %c\n", *pRight);

    int lenOfCurLongestPalSubStr = 0;

    // for (int i = 0; i < stringSize; i++){
    puts("####################");
    printf("Longest palindrom sub seq: ");
    for (int i = 0; i < stringSize; i++){
        lenOfCurLongestPalSubStr = 0;
        pLeft = &string[i];
        pRight = &string[stringSize-1];
        // printf("&pLeft :>> %p\n", pLeft);
        // printf("string[i] :>> %c\n", string[i]);
        // printf("string[i] :>> %p\n", &string[i]);
        // printf("&string[stringSize-1] :>> %p\n", &string[stringSize-1]);
        // printf("&pRight :>> %p\n", pRight);
        // printf("*pLeft :>> %c\n", *pLeft);
        // printf("*pRight :>> %c\n", *pRight);

        // while (*pLeft != '\0') {
        while (pLeft < pRight) {
            // printf("*pLeft :>> %c, *pRight :>> %c\n", *pLeft, *pRight);
            // printf("pLeft :>> %p, pRight :>> %p\n", pLeft, pRight);
            // printf("&pLeft :>> %p\n", pLeft);
            // printf("&pRight :>> %p\n", pRight);
            // printf("*pRight :>> %c\n", *pRight);
            // pLeft++;
            // pLeft = pLeft + 1;
            // pRight--;

            if(*pLeft == *pRight){
                lenOfCurLongestPalSubStr+=2; 
                // puts("=======================");
                // printf("Match for %c, %c\n", *pLeft, *pRight);
                // puts("=======================");
                lenOfCurLongestPalSubStr++;
                pRight--;
                printf("%c ", *pLeft);
            }
            else{
                pRight--;
                break;
            }
            
            // if(lenOfCurLongestPalSubStr != 0){
            //     pLeft++;
            //     if (pLeft == pRight && *pLeft == *pRight) {
            //         printf("pLeft :>> %p, pRight :>> %p\n", pLeft, pRight);

            //         puts("=======================");
            //         printf("same index Match for %c, %c\n", *pLeft, *pRight);
            //         puts("=======================");
            //         lenOfCurLongestPalSubStr++; break;
            //     }
            //     else if (pLeft < pRight && *pLeft == *pRight && isStringEvenLength) {
            //         printf("pLeft :>> %p, pRight :>> %p\n", pLeft, pRight);

            //         puts("=======================");
            //         printf("different index Match for %c, %c\n", *pLeft, *pRight);
            //         puts("=======================");
            //         lenOfCurLongestPalSubStr+=2; break;
            //     }
            //     else {
            //         pLeft--;
            //         printf("pLeft-- :>> %p\n", pLeft);
            //     }
            // }
            
        }
    
    // printf("lenOfCurLongestPalSubStr,  *lenOfLongestPalSubStr:>> %d, %d\n", lenOfCurLongestPalSubStr, *lenOfLongestPalSubStr);
    if (lenOfCurLongestPalSubStr > *lenOfLongestPalSubStr){
        *lenOfLongestPalSubStr = lenOfCurLongestPalSubStr;
    }
    
    // puts("####################");
    }
}

int maxOfTwoNums(int one, int two){
    return one >= two ? one : two;
}

// recursive memoization approach => TC = O(n*m)
int calculateLongestPalSubStr(char* string, char* reverseStr, int** memArr, int sIdx, int rsIdx) {
    if(sIdx < 0 || rsIdx < 0) {
        return 0;
    }

    if(memArr[sIdx][rsIdx] != -1) {
        return memArr[sIdx][rsIdx];
    }

    if (string[sIdx] == reverseStr[rsIdx]) {
        printf("%c ", string[sIdx]);
        memArr[sIdx][rsIdx] = 1 + calculateLongestPalSubStr(string, reverseStr, memArr, sIdx-1, rsIdx-1);
    }
    else {
        memArr[sIdx][rsIdx] = maxOfTwoNums(calculateLongestPalSubStr(string, reverseStr, memArr, sIdx-1, rsIdx),
                                           calculateLongestPalSubStr(string, reverseStr, memArr, sIdx, rsIdx-1));
    }

    return memArr[sIdx][rsIdx];
}

int main (int argc, char *argv[]) {
    // char string[] = "babad";
    char string[] = "bbbab";
    char* reverseStr = "dabab";
    // char string[] = "bbabcbcbcab";

    printf("size of string :>> %lu\n", sizeof(string));

    int stringSize = strlen(string);
    int sIdx = stringSize;
    int rsIdx = stringSize;

    int** memArr = malloc(stringSize*sizeof(int*));

    for (int i = 0; i < stringSize; i++){
        memArr[i] = malloc(stringSize*sizeof(int));
        for(int j = 0; j < stringSize; j++){
            memArr[i][j] = -1;
        }
    }

    // int lenOfLongestPalSubStr = 0;
    // longestPalSubStr(string, stringSize, &lenOfLongestPalSubStr);

    int lenOfLongestPalSubStr = calculateLongestPalSubStr(string, reverseStr, memArr, sIdx-1, rsIdx-1);

    printf("\nlength of longestPalSubStr:>> %d\n", lenOfLongestPalSubStr);
    
    return EXIT_SUCCESS;
}