#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxOfTwoNums(int one, int two) {
    return one > two ? one : two; 
}

int longestSubString(char* stringOne, char* stringTwo, int** memArr, int stringOneIdx, int stringTwoIdx, int* maxLength) {
    if (stringOneIdx < 0 || stringTwoIdx < 0) {
        return 0; // Base case: if either index is negative, return 0
    }
    if (memArr[stringOneIdx][stringTwoIdx] != -1) {
        return memArr[stringOneIdx][stringTwoIdx]; // Return cached result if available
    }

    if (stringOne[stringOneIdx] == stringTwo[stringTwoIdx]) {
        // printf("Match for stringOne[stringOneIdx],  stringTwo[stringTwoIdx]:>> %c, %c\n", stringOne[stringOneIdx], stringTwo[stringTwoIdx]);
        memArr[stringOneIdx][stringTwoIdx] = 1 + longestSubString(stringOne, stringTwo, memArr, stringOneIdx - 1, stringTwoIdx - 1, maxLength);
        *maxLength = maxOfTwoNums(*maxLength,memArr[stringOneIdx][stringTwoIdx]);
        // printf("maxLength :>> %d\n", *maxLength);
    } else {
        memArr[stringOneIdx][stringTwoIdx] = 0;
        memArr[stringOneIdx-1][stringTwoIdx] = longestSubString(stringOne, stringTwo, memArr, stringOneIdx - 1, stringTwoIdx, maxLength);
        memArr[stringOneIdx][stringTwoIdx-1] = longestSubString(stringOne, stringTwo, memArr, stringOneIdx, stringTwoIdx - 1, maxLength);
    }

    return memArr[stringOneIdx][stringTwoIdx];
}

int longestSubStringTabulation(char* stringOne, char* stringTwo, int** memArr, int stringOneIdx, int stringTwoIdx) {
    // Initialize the first row and column of the memoization array
    for (int i = 0; i <= stringOneIdx; i++) {
        memArr[i][0] = 0; // If stringTwo is empty
    }
    for (int j = 0; j <= stringTwoIdx; j++) {
        memArr[0][j] = 0; // If stringOne is empty
    }

    // Fill the memoization table
    int maxLength = 0;
    for (int i = 1; i <= stringOneIdx; i++) {
        for (int j = 1; j <= stringTwoIdx; j++) {
            if (stringOne[i - 1] == stringTwo[j - 1]) {
                // printf("%c ", stringOne[i-1]);
                memArr[i][j] = 1 + memArr[i - 1][j - 1]; // Characters match
                maxLength = maxOfTwoNums(maxLength, memArr[i][j]);
            } else {
                memArr[i][j] = 0; // Take max from left or above
            }
        }
    }

    return maxLength; // Return the length of LCS
}

void printLCSS(int** memArr, char* stringOne, char* stringTwo, int stringOneSize, int stringTwoSize) {
    int maxArraySize = (stringOneSize <= stringTwoSize) ? stringTwoSize : stringOneSize;

    char LCSS[maxArraySize + 1]; // +1 for null terminator
    LCSS[maxArraySize] = '\0'; // Initialize the last element as null terminator

    int i = stringOneSize, j = stringTwoSize, index = maxArraySize - 1;

    while (i > 0 && j > 0) {
        if (stringOne[i - 1] == stringTwo[j - 1]) {
            LCSS[index] = stringOne[i - 1];
            // printf("match => %c\n", stringOne[i - 1]);
            index--;
            i--;
            j--;
        } else {
            // printf("No match => %c, %c \n", stringOne[i - 1], stringTwo[j - 1]);

            if (memArr[i - 2][j - 1] >= memArr[i - 1][j - 2]) {
                // printf("memArr[i - 1][j]:%d >= memArr[i][j - 1]:%d\n", memArr[i - 2][j - 1], memArr[i - 1][j - 2]);
                i--; 
            } else {
                j--; 
            }
        }
    }

    // Print the LCS in the correct order
    printf("\nLongest Common Subsequence: ");
    for (int k = 0; k < maxArraySize; k++) {
        printf("%c", LCSS[k]); // Print the LCS characters
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // char* stringOne = "AGGTAB";
    // char* stringTwo = "GXTXAYB";
    char* stringOne = "abcjklp";
    char* stringTwo = "acjkp";
    int stringOneSize = strlen(stringOne);
    int stringTwoSize = strlen(stringTwo);

    // Allocate memory for the memoization array 
    int** memArr = malloc((stringOneSize + 1) * sizeof(int*));
    for (int i = 0; i <= stringOneSize; i++) {
        memArr[i] = malloc((stringTwoSize + 1) * sizeof(int));
        for (int j = 0; j <= stringTwoSize; j++) {
            memArr[i][j] = -1; // Initialize memoization array
        }
    }

    // Calculate LCS using the recursive approach
    int maxLength = longestSubString(stringOne, stringTwo, memArr, stringOneSize - 1, stringTwoSize - 1, &maxLength);
    printf("Len of LCSS (recursive) :>> %d\n", maxLength);
    // printLCSS(memArr, stringOne, stringTwo, stringOneSize, stringTwoSize);

    puts("Mem table after recursive solution: \n");
    for (int i = 0; i <= stringOneSize; i++) {
        for (int j = 0; j <= stringTwoSize; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Calculate LCS using the tabulation approach
    int lenUsingBottomUpLCSS = longestSubStringTabulation(stringOne, stringTwo, memArr, stringOneSize, stringTwoSize);
    printf("Len of LCSS (tabulation) :>> %d\n", lenUsingBottomUpLCSS);

    puts("Mem table after tabulation solution: \n");
    for (int i = 0; i <= stringOneSize; i++) {
        for (int j = 0; j <= stringTwoSize; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i <= stringOneSize; i++) {
        free(memArr[i]);
    }
    free(memArr);

    return EXIT_SUCCESS;
}
