#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxOfTwoNums(int one, int two){
    return one >= two ? one : two;
}

int minInsertionForPalString(char* str, char* rstr, int strIdx, int rstrIdx, int** memArr){
    if(strIdx < 0 || rstrIdx < 0){
        return 0;
    }
    if(memArr[strIdx][rstrIdx] != -1){
        return memArr[strIdx][rstrIdx];
    }
    if(str[strIdx] == rstr[rstrIdx]){
        memArr[strIdx][rstrIdx] = 1 + minInsertionForPalString(str, rstr, strIdx-1, rstrIdx-1, memArr);
    }
    else{
        memArr[strIdx][rstrIdx] = maxOfTwoNums(minInsertionForPalString(str, rstr, strIdx-1, rstrIdx-1, memArr), 
                                               minInsertionForPalString(str, rstr, strIdx-1, rstrIdx-1, memArr));
    }

    return memArr[strIdx][rstrIdx];
}

int main (int argc, char *argv[]) {
    char* string = "abcaa";
    int stringLen = strlen(string);
    char reverse[stringLen];

    int** memArr = malloc(stringLen*sizeof(int*));

    for (int i = 0; i < stringLen; i++){
        memArr[i] = malloc(stringLen*sizeof(int));
        for(int j = 0; j < stringLen; j++){
            memArr[i][j] = -1;
        }
    }

    int j = 0;
    for (int i = stringLen-1; i >= 0; i--){
        reverse[j] = string[i]; j++;
    }

    int maxLenghtPalindromeSubStr = minInsertionForPalString(string, reverse, strlen(string)-1, strlen(reverse)-1, memArr);

    printf("Min insertions to make the string palindrome :>> %d\n", (stringLen-maxLenghtPalindromeSubStr));

    return EXIT_SUCCESS;
}