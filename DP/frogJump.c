#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a <= b ? a : b)

int frogJumpBottomUp_K_Jumps(int* arr, int nSize, int* memArr, int kjumps){
    int minJumpEnergyCost;
    int curJumpEnergyCost = 0;
    for(int i = 1; i < nSize; i++){
        minJumpEnergyCost = INT_MAX;
        for(int k = 1; k <= kjumps; k++){
            if(i-k >= 0){
                curJumpEnergyCost = abs(arr[i] - arr[i-k]) + memArr[i-k];
                minJumpEnergyCost = min(minJumpEnergyCost, curJumpEnergyCost);
            } 
        }
        memArr[i] = minJumpEnergyCost;
    }

    return memArr[nSize-1];
}

int frogJumpBottomUp(int* arr, int nSize, int* memArr){
    int minJump;
    for(int i = 1; i < nSize; i++){
        if (i > 1){
            minJump = min(abs(arr[i] - arr[i-1]) + memArr[i-1],
                          abs(arr[i] - arr[i-2]) + memArr[i-2]);
        }
        else{
            minJump = min(abs(arr[i] - arr[i-1]) + memArr[i-1],
                          INT_MAX);
        }

        memArr[i] = minJump;
    }

    return memArr[nSize-1];
}

int frogjump(int* arr, int curJump, int* memArr){
    if(curJump == 0) return 0;
    // curJump might be 1 f(2-1, 2-2) call, but we can't do curjump-2, 
    // hence handle that scenario as base case
    if(curJump == 1) return abs(arr[0] - arr[1]); 

    if(memArr[curJump] != -1) return memArr[curJump];

    int minJump = min(abs(arr[curJump] - arr[curJump-1]) + frogjump(arr, curJump-1, memArr),
                      abs(arr[curJump] - arr[curJump-2]) + frogjump(arr, curJump-2, memArr));

    return memArr[curJump] = minJump;
}

int main (int argc, char *argv[]) {
    int arr[] = {10, 20, 30, 10};
    int nSize = sizeof(arr)/sizeof(arr[0]);

    int memArr[nSize+1];

    // for(int i = 0; i < nSize+1; i++){
    //     memArr[i] = -1;
    // }

    for(int i = 0; i < nSize+1; i++){
        memArr[i] = 0;
    }

    // int minEnergyForFrogToReachDest = frogjump(arr, nSize-1, memArr);

    // int minEnergyForFrogToReachDest = frogJumpBottomUp(arr, nSize, memArr);

    int minEnergyForFrogToReachDest = frogJumpBottomUp_K_Jumps(arr, nSize, memArr, 2);

    printf("minEnergyForFrogToReachDest :>> %d\n", minEnergyForFrogToReachDest);

    return EXIT_SUCCESS;
}