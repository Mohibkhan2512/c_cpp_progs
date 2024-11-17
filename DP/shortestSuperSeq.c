#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxOfTwoNums(int one, int two){
    return one >= two ? one : two;
}

int shortestSuperSeq(char* strOne, char* strTwo, int strOneIdx, int strTwoIdx, int** memArr) {
    for(int i = 1; i <= strOneIdx; i++){
        for(int j = 1; j <= strTwoIdx; j++){
            if(strOne[i-1] == strTwo[j-1]){
                memArr[i][j] = 1 + memArr[i-1][j-1];
            }
            else{
                memArr[i][j] = maxOfTwoNums(memArr[i-1][j], memArr[i][j-1]);
            }
        }
    }

    return memArr[strOneIdx][strTwoIdx];
}  

void printShortestSuperSeq(int** memArr, char* strOne, char* strTwo, int strLenOne, int strLenTwo){
    int i = strLenOne; int j = strLenTwo;
    // int maxLengthOfArray = strLenOne >= strLenTwo ? strLenOne : strLenTwo;
    int maxLengthOfArray = strLenOne + strLenTwo;
    char ShortestSupSeq[maxLengthOfArray+1];
    ShortestSupSeq[maxLengthOfArray] = '\0';
    int sIdx =  0;

    for(int i = 0; i < maxLengthOfArray; i++){
        ShortestSupSeq[i] = '\0';
    }
    
    while(i > 0 && j > 0){
        if(strOne[i-1] == strTwo[j-1]){
            // printf("Match for strOne[i-1], strTwo[j-1] :>> %c, %c\n", strOne[i-1], strTwo[j-1]);
            ShortestSupSeq[sIdx] = strOne[i-1];
            // printf("sIdx, i, j :>> %d, %d, %d\n", sIdx, i, j);
            sIdx++; i--; j--;
        }
        else{
            if(memArr[i-1][j] >= memArr[i][j-1]){
                ShortestSupSeq[sIdx] = strOne[i-1];
                sIdx++; i--;
            }
            else{
                ShortestSupSeq[sIdx] = strTwo[j-1];
                sIdx++; j--;
            }
        }
    }

    while (i > 0) {
        ShortestSupSeq[sIdx] = strOne[i-1]; i--;
    }
    while (j > 0) {
        ShortestSupSeq[sIdx] = strTwo[j-1]; j--;
    }

    printf("Shortest Super Sequence: ");
    for(int i = maxLengthOfArray; i >= 0; i--){
        printf("%c ", ShortestSupSeq[i]);
    }

}

int main (int argc, char *argv[]) {
    char* strOne = "brute";
    char* strTwo = "groot";
    int strLenOne = strlen(strOne);
    int strLenTwo = strlen(strTwo);
    int** memArr = malloc((strLenOne + 1)*sizeof(int*));

    for (int i = 0; i < strLenOne + 1; i++) {
        memArr[i] = malloc((strLenTwo + 1)*sizeof(int));
    }

    for(int i = 0; i < strLenOne + 1; i++) memArr[i][0] = 0;
    for(int i = 0; i < strLenTwo + 1; i++) memArr[0][i] = 0;

    int lenOfLCSS = shortestSuperSeq(strOne, strTwo, strLenOne, strLenTwo, memArr);

    printf("lenOfLCSS :>> %d\n", lenOfLCSS);

    int lenOfShortestSuperSeq = strLenOne + strLenTwo - lenOfLCSS;

    printf("lenOfShortestSuperSeq :>> %d\n", lenOfShortestSuperSeq);

    printShortestSuperSeq(memArr, strOne, strTwo, strLenOne, strLenTwo);

    puts("\nMem table after tabulation solution: \n");
    for (int i = 0; i <= strLenOne; i++) {
        for (int j = 0; j <= strLenTwo; j++) {
            printf("\t%d", memArr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i <= strLenOne; i++) {
        free(memArr[i]);
    }
    free(memArr);


    return EXIT_SUCCESS;
}