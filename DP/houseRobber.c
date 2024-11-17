#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (a >= b ? a : b)

int houseRobberMaxProfitSpaceOpt(int* hval, int selectedHouse){
    int pick, notPick, prev = hval[0], prev2 = 0, cur;
    for(int i = 0; i <= selectedHouse; i++){
        if(i == 0){
            pick = hval[i];
            notPick = INT_MIN;
        }
        else if(i == 1){
            pick = hval[i];
            notPick = prev;
        }
        else{
            pick = hval[i] + prev2;
            notPick = prev;
        }
        // printf("pick, notPick :>> %d, %d\n", pick, notPick);
        cur = max(pick, notPick);
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int houseRobberMaxProfitCircularAdj(int* hval, int nSize){
    int firstIncluded[nSize-1];
    int lastIncluded[nSize-1];

    for(int i = 0; i < nSize; i++){
        // printf("i :>> %d\n", i);
        if(i != nSize-1) firstIncluded[i] = hval[i];
        if(i != 0) lastIncluded[i-1] = hval[i];
    }

    printf("\nfirstIncluded :>> ");
    for(int i = 0; i < nSize-1; i++){
        printf("  %d", firstIncluded[i]);
    }

    printf("\nlastIncluded :>> ");
    for(int i = 0; i < nSize-1; i++){
        printf("  %d", lastIncluded[i]);
    }

    return max(houseRobberMaxProfitSpaceOpt(firstIncluded, nSize-2), 
               houseRobberMaxProfitSpaceOpt(lastIncluded, nSize-2));
}

int houseRobberMaxProfitBottomUp(int* hval, int selectedHouse, int* memArr){
    int pick, notPick;
    for(int i = 0; i <= selectedHouse; i++){
        if(i == 0){
            pick = hval[i];
            notPick = INT_MIN;
        }
        else if(i == 1){
            pick = hval[i];
            notPick = memArr[i-1];
        }
        else{
            pick = hval[i] + memArr[i-2];
            notPick = memArr[i-1];
        }
        // printf("pick, notPick :>> %d, %d\n", pick, notPick);
        memArr[i] = max(pick, notPick);
    }

    return memArr[selectedHouse];
}

int houseRobberMaxProfit(int* hval, int selectedHouse, int* memArr){
    if(selectedHouse == 0) return hval[selectedHouse];
    if(selectedHouse < 1) return 0;
    if(memArr[selectedHouse] != -1) return memArr[selectedHouse];

    int pick = hval[selectedHouse] + houseRobberMaxProfit(hval, selectedHouse-2, memArr);
    int notPick = houseRobberMaxProfit(hval, selectedHouse-1, memArr);

    // printf("pick, notPick :>> %d, %d\n", pick, notPick);

    return memArr[selectedHouse] = max(pick, notPick);
}

int main (int argc, char *argv[]) {
    // int hval[] = {5, 5, 10, 100, 10, 5};
    int hval[] = {3, 2, 7, 10};
    int nSize = sizeof(hval)/sizeof(hval[0]);
    int memArr[nSize+1];

    for (int i = 0; i < nSize+1; i++) {
        memArr[i] = -1;
    }

    // for (int i = 0; i < nSize+1; i++) {
    //     memArr[i] = 0;
    // }

    // int maxProfit = houseRobberMaxProfit(hval, nSize-1, memArr);
    // int maxProfit = houseRobberMaxProfitBottomUp(hval, nSize-1, memArr);
    // int maxProfit = houseRobberMaxProfitSpaceOpt(hval, nSize-1);
    
    int maxProfit = houseRobberMaxProfitCircularAdj(hval, nSize);

    printf("\nmaxProfit :>> %d\n", maxProfit);

    for (int i = 0; i < nSize+1; i++) {
        // printf("memArr[i] :>> %d\n", memArr[i]); ;
    }

    return EXIT_SUCCESS;
}