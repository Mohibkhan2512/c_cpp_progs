#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool wordBreak(char* string, char* wordDict[], int numStrings, int maxStringSize) {
    char* stringInDict;
    int iString = 0;
    int iSID = 0;
    int iMatchString = 0;
    for (int i = 0; i < numStrings; i++) {
        printf("wordDict[i] :>> %s\n", wordDict[i]); 
        // for (int j = 0; j < maxStringSize; j++) {
        //     if (wordDict[i][j] != '\0') {
        //         printf("wordDict[i][j] :>> %c\n", wordDict[i][j]);
        //     } else {
        //         break;
        //     }
        // }
        stringInDict = wordDict[i];
        while (string[iString] != '\0' && stringInDict[iSID] != '\0') {
            // printf("iString :>> %d\n", iString);
            if(string[iString] == stringInDict[iSID]) {
                iMatchString++;
                iString++;
                iSID++;
            } else{
                iString++;
            }
            if (stringInDict[iSID] == '\0' && iMatchString == iSID) {
                printf("iString :>> %d\n", iString);
                printf("iSID, iMatchString :>> %d, %d\n", iSID, iMatchString);
                // return true;
            }
        }
    }

    return false;
}

int main (int argc, char *argv[]) {
    int numStrings = 2;
    int maxStringSize = 20;
    // char* string = "neetleetcode";
    char* string = "ilikenotsamsung";

    char** wordDict = malloc(sizeof(char*));

    for (int i = 0; i < numStrings; i++) {
        wordDict[i] = malloc(maxStringSize*sizeof(char*));
    }

    // strcpy(wordDict[0], "i");
    strcpy(wordDict[0], "like");
    strcpy(wordDict[1], "samsung");
    // strcpy(wordDict[1], "code");

    bool result = wordBreak(string, wordDict, numStrings, maxStringSize);
    printf("isTrue: %s\n", result ? "true" : "false");


    return EXIT_SUCCESS;
}